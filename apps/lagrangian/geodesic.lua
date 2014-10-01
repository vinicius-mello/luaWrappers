dofile("modules.lua")
require("lagrangian")
require("win")

function vec(t) 
  local m=#t
  local a=array.double(m)
  for i=1,m do
    a:set(i-1,t[i])
  end
  return a	  
end

function symbols(a) 
  for i=1,#a do
    _G[a[i]]=ginac.symbol(a[i])
  end
end

symbols {"x", "y", "dx", "dy"}

L=4*(dx*dx+dy*dy)/(1-x*x-y*y)^2
L:print()
idyn=iteration_map(L,{x,y},{dx,dy},0.05,{})

q0=vec {0.2,0.5}
p0=vec {-0.5,-0.35}

cnv = win.New("geodesic")

-- chamada quando a janela OpenGL é redimensionada
function cnv:Reshape(width, height)
	--print("resize")
  gl.Viewport(0, 0, width, height) -- coloca o viewport ocupando toda a janela
  gl.MatrixMode('PROJECTION')      -- seleciona matriz de projeção matrix
  gl.LoadIdentity()                -- carrega a matriz identidade
  gl.MatrixMode('MODELVIEW')       -- seleciona matriz de modelagem
  gl.LoadIdentity()                -- carrega a matriz identidade
end

points={}
points.x={}
points.y={}

function cnv:Display()
  gl.Clear('COLOR_BUFFER_BIT,DEPTH_BUFFER_BIT')
  gl.MatrixMode('MODELVIEW')       -- seleciona matriz de modelagem
  gl.LoadIdentity()         
  gl.PointSize(4.0)
  gl.Color(1,0,0)
  gl.Begin('POINTS')
  local n
  if #points.x<=100 then n=1 else n=#points.x-99 end
  for i=n,#points.x do
    gl.Vertex(points.x[i],points.y[i])
  end
  gl.End()
end

-- chamada quando a janela OpenGL é criada
function cnv:Init()
	--print("map")
  gl.ClearColor(0.0,0.0,0.0,0.0)                  -- cor de fundo preta
  gl.ClearDepth(1.0)                              -- valor do z-buffer
  gl.Disable('DEPTH_TEST')                         -- habilita teste z-buffer
  gl.Enable('CULL_FACE')                         
  gl.ShadeModel('FLAT')
end

-- chamada quando uma tecla é pressionada
function cnv:Keyboard(key,x,y)
    if key==27 then
        os.exit()
    end
end

function Step()
  local x=q0:get(0)
  local y=q0:get(1)
  points.x[#points.x+1]=x
  points.y[#points.y+1]=y
  idyn(q0,p0)
  glut.PostRedisplay()
end

glut.IdleFunc(Step)

win.Loop()
