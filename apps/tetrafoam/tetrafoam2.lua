dofile("modules.lua")
require("ply")
require("array")
require("vec")
require("lpt")
require("stl")
require("vdb")

vdb.initialize()


print("Reading header")
filename=arg[1]
mesh=ply.load(filename)
mesh:print_header()

max_level=14 -- max depth of tetrahedra tree
tunnel=true -- with tunnel
ratio=0.1 -- ratio of shrinking

vtx=array.float(mesh.vertex.size,3) -- array of vertices
idx=array.uint(mesh.face.size,3) -- array of faces

vert=array.double(12) -- vertices
pnt=array.double(3) -- point

out=stl.create("out.stl","lpt") -- output file

bb={
    xa=math.huge,
    xb=-math.huge,
    ya=math.huge,
    yb=-math.huge,
    za=math.huge,
    zb=-math.huge
}  --bounding box


function mesh.vertex_read_cb(i,reg)
    vtx:set(i,0,reg.x)
    vtx:set(i,1,reg.y)
    vtx:set(i,2,reg.z)
    bb.xa=math.min(bb.xa, reg.x)
    bb.xb=math.max(bb.xb, reg.x)
    bb.ya=math.min(bb.ya, reg.y)
    bb.yb=math.max(bb.yb, reg.y)
    bb.za=math.min(bb.za, reg.z)
    bb.zb=math.max(bb.zb, reg.z)
end

function mesh.face_read_cb(i,reg)
  for j=1,3 do
    idx:set(i,j-1,reg.vertex_indices[j])
  end
end

print("Processing ply")
mesh:read_data()
print("Bounding Box: ["..bb.xa..","..bb.xb.."]x["..bb.ya..","..bb.yb.."]x["..bb.za..","..bb.zb.."]")

-- bounding box center
bb.xm=(bb.xa+bb.xb)/2
bb.ym=(bb.ya+bb.yb)/2
bb.zm=(bb.za+bb.zb)/2

bb.scale=(math.max(bb.xb-bb.xa,bb.yb-bb.ya,bb.zb-bb.za)/2)*1.1

print("Scaling")

-- scaling coordinates
for i=1,mesh.vertex.size do
    vtx:set(i-1,0,(vtx:get(i-1,0)-bb.xm)/bb.scale)
    vtx:set(i-1,1,(vtx:get(i-1,1)-bb.ym)/bb.scale)
    vtx:set(i-1,2,(vtx:get(i-1,2)-bb.zm)/bb.scale)
end
-- all points are inside [-1,1]^3

-- build distance field
sdf=vdb.signed_distance(vtx,idx,0.01)

-- tetrahedra tree
tree=lpt.lpt3d_tree()

-- subdivide tetrahedra three until point p be inside of a
-- tetrahedron of level level
function subdivide_to(p,level)
    pnt:set(0,p[1])
    pnt:set(1,p[2])
    pnt:set(2,p[3])
    local leaf=tree:search(pnt:data())
    while leaf:simplex_level()<level do
        tree:compat_bisect(leaf)
        leaf=tree:search(pnt:data())
    end
    return leaf
end

print("Subdivide")
boundary={}
for i=1,mesh.vertex.size do
    local p={}
    p[1]=vtx:get(i-1,0)
    p[2]=vtx:get(i-1,1)
    p[3]=vtx:get(i-1,2)
    local leaf=subdivide_to(p,max_level)
    boundary[tree:id(leaf)]=true -- mark a tetrahedron as 'boundary' if it contains a mesh point
end

-- is the tetrahedron inside the mesh? non-robust implementation!
-- testing only vertices
function inside(tetra)
  local p=vec.new {0,0,0}
  for i=0,3 do
    p[1]=tetra:get(3*i)
    p[2]=tetra:get(3*i+1)
    p[3]=tetra:get(3*i+2)
    if sdf:dist(p[1],p[2],p[3])>0 then
      return false
    end
  end
  return true
end

--write face to stl file
function add_face(normal,a,b,c)
  out:write_facet(normal,a,b,c)
end

function draw_face(a,b,c)
  local va=vec.new(a)
  local vb=vec.new(b)
  local vc=vec.new(c)
  local normal=vec.cross(vb-va,vc-va)
  add_face(normal,a,b,c)
end

-- shrink a tetrahedron
function shrink(a,b,c,d)
  local as=(1-3*ratio)*a+ratio*b+ratio*c+ratio*d
  local bs=(1-3*ratio)*b+ratio*a+ratio*c+ratio*d
  local cs=(1-3*ratio)*c+ratio*a+ratio*b+ratio*d
  local ds=(1-3*ratio)*d+ratio*a+ratio*b+ratio*c
  return as,bs,cs,ds
end

-- emit a tetrahedron
function draw_tetra(cur)
  cur:simplex(vert:data())
  local a=vec.new {vert:get(0),vert:get(1),vert:get(2)}
  local b=vec.new {vert:get(3),vert:get(4),vert:get(5)}
  local c=vec.new {vert:get(6),vert:get(7),vert:get(8)}
  local d=vec.new {vert:get(9),vert:get(10),vert:get(11)}
  if cur:orientation()<0 then
    c,d=d,c
  end
  a,b,c,d=shrink(a,b,c,d)
  draw_face(a,b,c)
  draw_face(b,d,c)
  draw_face(a,d,b)
  draw_face(a,c,d)
end

-- emit the input mesh
for i=1,mesh.face.size do
  local ai,bi,ci=idx:get(i-1,0),idx:get(i-1,1),idx:get(i-1,2)
  local a=vec.new {vtx:get(ai,0),vtx:get(ai,1),vtx:get(ai,2)}
  local b=vec.new {vtx:get(bi,0),vtx:get(bi,1),vtx:get(bi,2)}
  local c=vec.new {vtx:get(ci,0),vtx:get(ci,1),vtx:get(ci,2)}
  draw_face(a,b,c)
end


-- get the i-th face of tetrahedron cur
function get_facei(cur,i)
  cur:simplex(vert:data())
  local vs={}
  vs[1]=vec.new {vert:get(0),vert:get(1),vert:get(2)}
  vs[2]=vec.new {vert:get(3),vert:get(4),vert:get(5)}
  vs[3]=vec.new {vert:get(6),vert:get(7),vert:get(8)}
  vs[4]=vec.new {vert:get(9),vert:get(10),vert:get(11)}
  vs[1],vs[2],vs[3],vs[4]=shrink(vs[1],vs[2],vs[3],vs[4])
  table.remove(vs,i+1)
  return vs[1],vs[2],vs[3]
end

-- emit the i-th face of tetrahedron cur
function draw_facei(cur,i)
  local a,b,c=get_facei(cur,i)
  if cur:orientation()*((-1)^(i%2))>0 then
    b,c=c,b
  end
  draw_face(a,b,c)
end

-- draw tunnel between cur and n
function draw_tunnel(cur,n,i)
  local j=tree:neighbor_index(cur,n)
  local b,c,d=get_facei(cur,i)
  local bl,cl,dl=get_facei(n,j)
  if cur:orientation()*((-1)^(i%2))>0 then
    c,d=d,c
    cl,dl=dl,cl
  end
  draw_face(bl,d,b)
  draw_face(bl,dl,d)
  draw_face(d,cl,c)
  draw_face(d,dl,cl)
  draw_face(c,bl,b)
  draw_face(c,cl,bl)
end

-- detect the tetrahedra inside mesh
insidetetra={}
tree:node_reset()
repeat
  if tree:node_is_leaf() then
    local cur=tree:node_code()
    local id=tree:node_id()
    if not boundary[id] then
      cur:simplex(vert:data())
      if inside(vert) then
        insidetetra[id]=true
      end
    end
  end
until not tree:node_next()

-- main loop
visited={}
tree:node_reset()
repeat
  if tree:node_is_leaf() then
    local cur=tree:node_code()
    local id=tree:node_id()
    if insidetetra[id] then
      if tunnel then -- with tunnel
        for i=0,3 do
          local n=lpt.lpt3d()
          tree:neighbor(cur,i,n)
          local nid=tree:id(n)
          if not insidetetra[nid] then
            draw_facei(cur,i)
          else
            if not visited[nid] then -- dont emit tunnel twice!
              draw_tunnel(cur,n,i)
            end
          end
        end
      else -- without tunnel
        draw_tetra(cur)
      end
    end
    visited[id]=true
  end
until not tree:node_next()

out:close()
