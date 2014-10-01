dofile("modules.lua")
require("array")
require("vdb")

vdb.initialize()

function fill(arr,tbl) 
	for i=1,#tbl do
		for j=1,#tbl[1] do
			arr:set(i-1,j-1,tbl[i][j])
		end
	end
end

vtx=array.float(4,3)
idx=array.int(4,3)

--  2
--  | \
--  |  \
--  0 _ 1
--   \  |
--     \3 

fill(vtx, {{0,0,0},{1,0,0},{0,1,0},{0,0,1}})
fill(idx, {{0,1,3},{0,2,1},{0,3,2},{1,2,3}})

sdf=vdb.signed_distance(vtx,idx,0.01)
sdf:write("tetra.vdb")
--print(sdf:dist(0.3333,0.3333,0.3333))
