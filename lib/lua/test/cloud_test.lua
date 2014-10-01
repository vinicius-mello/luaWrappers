dofile("modules.lua")
require("array")
require("cloud")

a=array.float("array.in")
b=array.float(3)
cloud.barycenter(a,0,5,b)
print(b:get(0),b:get(1),b:get(2))
