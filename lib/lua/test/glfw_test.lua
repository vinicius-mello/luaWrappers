dofile("modules.lua")
require("glfw")

glfw.Init()
local major,minor,rev=glfw.GetVersion()
print(major,minor,rev)
print(glfw.GetVersionString())

function error_callback(error,description)
	print(error,description)
end

function  key_callback(window,key,scancode,action,mode)
	if key == glfw.KEY_ESCAPE and action == glfw.PRESS then
        glfw.SetWindowShouldClose(window, true)
    end
end

glfw.SetErrorCallback(error_callback)

window = glfw.CreateWindow(640, 480, "Simple example")
glfw.MakeContextCurrent(window)

glfw.SetKeyCallback(window,key_callback)

print(window.__KeyCallback)

while not glfw.WindowShouldClose(window) do

	--glfw.SwapBuffers(window)
    glfw.PollEvents()
end

 glfw.DestroyWindow(window)
 glfw.Terminate()
