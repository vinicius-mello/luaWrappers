#define LIBNAME  "glfw"
#define LIBTYPE "glfw"
#define LIBVERSION "3"
#include <cstdlib>
extern "C" {
#include "lua.h"
#include "lauxlib.h"
#define lua_swap(L) lua_insert(L, -2)
}
#include <GLFW/glfw3.h>

typedef struct luaL_IntegerConstant {
  const char *name;
  lua_Integer i;
} luaL_IntegerConstant;

static const luaL_IntegerConstant C[] = {
 {   "RELEASE", GLFW_RELEASE},
 {   "PRESS", GLFW_PRESS},
 {   "REPEAT", GLFW_REPEAT},
 {   "KEY_UNKNOWN", GLFW_KEY_UNKNOWN},
 {   "KEY_SPACE", GLFW_KEY_SPACE},
 {   "KEY_APOSTROPHE", GLFW_KEY_APOSTROPHE},
 {   "KEY_COMMA", GLFW_KEY_COMMA},
 {   "KEY_MINUS", GLFW_KEY_MINUS},
 {   "KEY_PERIOD", GLFW_KEY_PERIOD},
 {   "KEY_SLASH", GLFW_KEY_SLASH},
 {   "KEY_0", GLFW_KEY_0},
 {   "KEY_1", GLFW_KEY_1},
 {   "KEY_2", GLFW_KEY_2},
 {   "KEY_3", GLFW_KEY_3},
 {   "KEY_4", GLFW_KEY_4},
 {   "KEY_5", GLFW_KEY_5},
 {   "KEY_6", GLFW_KEY_6},
 {   "KEY_7", GLFW_KEY_7},
 {   "KEY_8", GLFW_KEY_8},
 {   "KEY_9", GLFW_KEY_9},
 {   "KEY_SEMICOLON", GLFW_KEY_SEMICOLON},
 {   "KEY_EQUAL", GLFW_KEY_EQUAL},
 {   "KEY_A", GLFW_KEY_A},
 {   "KEY_B", GLFW_KEY_B},
 {   "KEY_C", GLFW_KEY_C},
 {   "KEY_D", GLFW_KEY_D},
 {   "KEY_E", GLFW_KEY_E},
 {   "KEY_F", GLFW_KEY_F},
 {   "KEY_G", GLFW_KEY_G},
 {   "KEY_H", GLFW_KEY_H},
 {   "KEY_I", GLFW_KEY_I},
 {   "KEY_J", GLFW_KEY_J},
 {   "KEY_K", GLFW_KEY_K},
 {   "KEY_L", GLFW_KEY_L},
 {   "KEY_M", GLFW_KEY_M},
 {   "KEY_N", GLFW_KEY_N},
 {   "KEY_O", GLFW_KEY_O},
 {   "KEY_P", GLFW_KEY_P},
 {   "KEY_Q", GLFW_KEY_Q},
 {   "KEY_R", GLFW_KEY_R},
 {   "KEY_S", GLFW_KEY_S},
 {   "KEY_T", GLFW_KEY_T},
 {   "KEY_U", GLFW_KEY_U},
 {   "KEY_V", GLFW_KEY_V},
 {   "KEY_W", GLFW_KEY_W},
 {   "KEY_X", GLFW_KEY_X},
 {   "KEY_Y", GLFW_KEY_Y},
 {   "KEY_Z", GLFW_KEY_Z},
 {   "KEY_LEFT_BRACKET", GLFW_KEY_LEFT_BRACKET},
 {   "KEY_BACKSLASH", GLFW_KEY_BACKSLASH},
 {   "KEY_RIGHT_BRACKET", GLFW_KEY_RIGHT_BRACKET},
 {   "KEY_GRAVE_ACCENT", GLFW_KEY_GRAVE_ACCENT},
 {   "KEY_WORLD_1", GLFW_KEY_WORLD_1},
 {   "KEY_WORLD_2", GLFW_KEY_WORLD_2},
 {   "KEY_ESCAPE", GLFW_KEY_ESCAPE},
 {   "KEY_ENTER", GLFW_KEY_ENTER},
 {   "KEY_TAB", GLFW_KEY_TAB},
 {   "KEY_BACKSPACE", GLFW_KEY_BACKSPACE},
 {   "KEY_INSERT", GLFW_KEY_INSERT},
 {   "KEY_DELETE", GLFW_KEY_DELETE},
 {   "KEY_RIGHT", GLFW_KEY_RIGHT},
 {   "KEY_LEFT", GLFW_KEY_LEFT},
 {   "KEY_DOWN", GLFW_KEY_DOWN},
 {   "KEY_UP", GLFW_KEY_UP},
 {   "KEY_PAGE_UP", GLFW_KEY_PAGE_UP},
 {   "KEY_PAGE_DOWN", GLFW_KEY_PAGE_DOWN},
 {   "KEY_HOME", GLFW_KEY_HOME},
 {   "KEY_END", GLFW_KEY_END},
 {   "KEY_CAPS_LOCK", GLFW_KEY_CAPS_LOCK},
 {   "KEY_SCROLL_LOCK", GLFW_KEY_SCROLL_LOCK},
 {   "KEY_NUM_LOCK", GLFW_KEY_NUM_LOCK},
 {   "KEY_PRINT_SCREEN", GLFW_KEY_PRINT_SCREEN},
 {   "KEY_PAUSE", GLFW_KEY_PAUSE},
 {   "KEY_F1", GLFW_KEY_F1},
 {   "KEY_F2", GLFW_KEY_F2},
 {   "KEY_F3", GLFW_KEY_F3},
 {   "KEY_F4", GLFW_KEY_F4},
 {   "KEY_F5", GLFW_KEY_F5},
 {   "KEY_F6", GLFW_KEY_F6},
 {   "KEY_F7", GLFW_KEY_F7},
 {   "KEY_F8", GLFW_KEY_F8},
 {   "KEY_F9", GLFW_KEY_F9},
 {   "KEY_F10", GLFW_KEY_F10},
 {   "KEY_F11", GLFW_KEY_F11},
 {   "KEY_F12", GLFW_KEY_F12},
 {   "KEY_F13", GLFW_KEY_F13},
 {   "KEY_F14", GLFW_KEY_F14},
 {   "KEY_F15", GLFW_KEY_F15},
 {   "KEY_F16", GLFW_KEY_F16},
 {   "KEY_F17", GLFW_KEY_F17},
 {   "KEY_F18", GLFW_KEY_F18},
 {   "KEY_F19", GLFW_KEY_F19},
 {   "KEY_F20", GLFW_KEY_F20},
 {   "KEY_F21", GLFW_KEY_F21},
 {   "KEY_F22", GLFW_KEY_F22},
 {   "KEY_F23", GLFW_KEY_F23},
 {   "KEY_F24", GLFW_KEY_F24},
 {   "KEY_F25", GLFW_KEY_F25},
 {   "KEY_KP_0", GLFW_KEY_KP_0},
 {   "KEY_KP_1", GLFW_KEY_KP_1},
 {   "KEY_KP_2", GLFW_KEY_KP_2},
 {   "KEY_KP_3", GLFW_KEY_KP_3},
 {   "KEY_KP_4", GLFW_KEY_KP_4},
 {   "KEY_KP_5", GLFW_KEY_KP_5},
 {   "KEY_KP_6", GLFW_KEY_KP_6},
 {   "KEY_KP_7", GLFW_KEY_KP_7},
 {   "KEY_KP_8", GLFW_KEY_KP_8},
 {   "KEY_KP_9", GLFW_KEY_KP_9},
 {   "KEY_KP_DECIMAL", GLFW_KEY_KP_DECIMAL},
 {   "KEY_KP_DIVIDE", GLFW_KEY_KP_DIVIDE},
 {   "KEY_KP_MULTIPLY", GLFW_KEY_KP_MULTIPLY},
 {   "KEY_KP_SUBTRACT", GLFW_KEY_KP_SUBTRACT},
 {   "KEY_KP_ADD", GLFW_KEY_KP_ADD},
 {   "KEY_KP_ENTER", GLFW_KEY_KP_ENTER},
 {   "KEY_KP_EQUAL", GLFW_KEY_KP_EQUAL},
 {   "KEY_LEFT_SHIFT", GLFW_KEY_LEFT_SHIFT},
 {   "KEY_LEFT_CONTROL", GLFW_KEY_LEFT_CONTROL},
 {   "KEY_LEFT_ALT", GLFW_KEY_LEFT_ALT},
 {   "KEY_LEFT_SUPER", GLFW_KEY_LEFT_SUPER},
 {   "KEY_RIGHT_SHIFT", GLFW_KEY_RIGHT_SHIFT},
 {   "KEY_RIGHT_CONTROL", GLFW_KEY_RIGHT_CONTROL},
 {   "KEY_RIGHT_ALT", GLFW_KEY_RIGHT_ALT},
 {   "KEY_RIGHT_SUPER", GLFW_KEY_RIGHT_SUPER},
 {   "KEY_MENU", GLFW_KEY_MENU},
 {   "KEY_LAST", GLFW_KEY_LAST},

 {   "MOD_SHIFT", GLFW_MOD_SHIFT},
 {   "MOD_CONTROL", GLFW_MOD_CONTROL},
 {   "MOD_ALT", GLFW_MOD_ALT},
 {   "MOD_SUPER", GLFW_MOD_SUPER},

 {   "MOUSE_BUTTON_1", GLFW_MOUSE_BUTTON_1},
 {   "MOUSE_BUTTON_2", GLFW_MOUSE_BUTTON_2},
 {   "MOUSE_BUTTON_3", GLFW_MOUSE_BUTTON_3},
 {   "MOUSE_BUTTON_4", GLFW_MOUSE_BUTTON_4},
 {   "MOUSE_BUTTON_5", GLFW_MOUSE_BUTTON_5},
 {   "MOUSE_BUTTON_6", GLFW_MOUSE_BUTTON_6},
 {   "MOUSE_BUTTON_7", GLFW_MOUSE_BUTTON_7},
 {   "MOUSE_BUTTON_8", GLFW_MOUSE_BUTTON_8},
 {   "MOUSE_BUTTON_LAST", GLFW_MOUSE_BUTTON_LAST},
 {   "MOUSE_BUTTON_LEFT", GLFW_MOUSE_BUTTON_LEFT},
 {   "MOUSE_BUTTON_RIGHT", GLFW_MOUSE_BUTTON_RIGHT},
 {   "MOUSE_BUTTON_MIDDLE", GLFW_MOUSE_BUTTON_MIDDLE},

 {   "JOYSTICK_1", GLFW_JOYSTICK_1},
 {   "JOYSTICK_2", GLFW_JOYSTICK_2},
 {   "JOYSTICK_3", GLFW_JOYSTICK_3},
 {   "JOYSTICK_4", GLFW_JOYSTICK_4},
 {   "JOYSTICK_5", GLFW_JOYSTICK_5},
 {   "JOYSTICK_6", GLFW_JOYSTICK_6},
 {   "JOYSTICK_7", GLFW_JOYSTICK_7},
 {   "JOYSTICK_8", GLFW_JOYSTICK_8},
 {   "JOYSTICK_9", GLFW_JOYSTICK_9},
 {   "JOYSTICK_10", GLFW_JOYSTICK_10},
 {   "JOYSTICK_11", GLFW_JOYSTICK_11},
 {   "JOYSTICK_12", GLFW_JOYSTICK_12},
 {   "JOYSTICK_13", GLFW_JOYSTICK_13},
 {   "JOYSTICK_14", GLFW_JOYSTICK_14},
 {   "JOYSTICK_15", GLFW_JOYSTICK_15},
 {   "JOYSTICK_16", GLFW_JOYSTICK_16},
 {   "JOYSTICK_LAST", GLFW_JOYSTICK_LAST},

 {   "NOT_INITIALIZED", GLFW_NOT_INITIALIZED},
 {   "NO_CURRENT_CONTEXT", GLFW_NO_CURRENT_CONTEXT},
 {   "INVALID_ENUM", GLFW_INVALID_ENUM},
 {   "INVALID_VALUE", GLFW_INVALID_VALUE},
 {   "OUT_OF_MEMORY", GLFW_OUT_OF_MEMORY},
 {   "API_UNAVAILABLE", GLFW_API_UNAVAILABLE},
 {   "VERSION_UNAVAILABLE", GLFW_VERSION_UNAVAILABLE},
 {   "PLATFORM_ERROR", GLFW_PLATFORM_ERROR},
 {   "FORMAT_UNAVAILABLE", GLFW_FORMAT_UNAVAILABLE},

 {   "FOCUSED", GLFW_FOCUSED},
 {   "ICONIFIED", GLFW_ICONIFIED},
 {   "RESIZABLE", GLFW_RESIZABLE},
 {   "VISIBLE", GLFW_VISIBLE},
 {   "DECORATED", GLFW_DECORATED},

 {   "RED_BITS", GLFW_RED_BITS},
 {   "GREEN_BITS", GLFW_GREEN_BITS},
 {   "BLUE_BITS", GLFW_BLUE_BITS},
 {   "ALPHA_BITS", GLFW_ALPHA_BITS},
 {   "DEPTH_BITS", GLFW_DEPTH_BITS},
 {   "STENCIL_BITS", GLFW_STENCIL_BITS},
 {   "ACCUM_RED_BITS", GLFW_ACCUM_RED_BITS},
 {   "ACCUM_GREEN_BITS", GLFW_ACCUM_GREEN_BITS},
 {   "ACCUM_BLUE_BITS", GLFW_ACCUM_BLUE_BITS},
 {   "ACCUM_ALPHA_BITS", GLFW_ACCUM_ALPHA_BITS},
 {   "AUX_BUFFERS", GLFW_AUX_BUFFERS},
 {   "STEREO", GLFW_STEREO},
 {   "SAMPLES", GLFW_SAMPLES},
 {   "SRGB_CAPABLE", GLFW_SRGB_CAPABLE},
 {   "REFRESH_RATE", GLFW_REFRESH_RATE},

 {   "CLIENT_API", GLFW_CLIENT_API},
 {   "CONTEXT_VERSION_MAJOR", GLFW_CONTEXT_VERSION_MAJOR},
 {   "CONTEXT_VERSION_MINOR", GLFW_CONTEXT_VERSION_MINOR},
 {   "CONTEXT_REVISION", GLFW_CONTEXT_REVISION},
 {   "CONTEXT_ROBUSTNESS", GLFW_CONTEXT_ROBUSTNESS},
 {   "OPENGL_FORWARD_COMPAT", GLFW_OPENGL_FORWARD_COMPAT},
 {   "OPENGL_DEBUG_CONTEXT", GLFW_OPENGL_DEBUG_CONTEXT},
 {   "OPENGL_PROFILE", GLFW_OPENGL_PROFILE},

 {   "OPENGL_API", GLFW_OPENGL_API},
 {   "OPENGL_ES_API", GLFW_OPENGL_ES_API},

 {   "NO_ROBUSTNESS", GLFW_NO_ROBUSTNESS},
 {   "NO_RESET_NOTIFICATION", GLFW_NO_RESET_NOTIFICATION},
 {   "LOSE_CONTEXT_ON_RESET", GLFW_LOSE_CONTEXT_ON_RESET},

 {   "OPENGL_ANY_PROFILE", GLFW_OPENGL_ANY_PROFILE},
 {   "OPENGL_CORE_PROFILE", GLFW_OPENGL_CORE_PROFILE},
 {   "OPENGL_COMPAT_PROFILE", GLFW_OPENGL_COMPAT_PROFILE},

 {   "CURSOR", GLFW_CURSOR},
 {   "STICKY_KEYS", GLFW_STICKY_KEYS},
 {   "STICKY_MOUSE_BUTTONS", GLFW_STICKY_MOUSE_BUTTONS},

 {   "CURSOR_NORMAL", GLFW_CURSOR_NORMAL},
 {   "CURSOR_HIDDEN", GLFW_CURSOR_HIDDEN},
 {   "CURSOR_DISABLED", GLFW_CURSOR_DISABLED},

 {   "CONNECTED", GLFW_CONNECTED},
 {   "DISCONNECTED", GLFW_DISCONNECTED},

 {   NULL, 0} };



static void lua_objinregistry(lua_State *L, void * ptr, int i) {
    lua_pushlightuserdata(L,ptr);
    lua_gettable(L,LUA_REGISTRYINDEX);
    if(lua_isnil(L,-1)) {
        lua_pop(L,1);
        lua_pushlightuserdata(L,ptr);
        lua_pushvalue(L,i);
        lua_settable(L,LUA_REGISTRYINDEX);
    }
}

static GLFWmonitor *  lua_tomonitor(lua_State *L, int i)
{
    lua_pushliteral(L,"__ptr__");
    lua_gettable(L,i);
    GLFWmonitor * monitor=(GLFWmonitor *)lua_touserdata(L,-1);
    lua_pop(L,1);
    return monitor;
}

static GLFWwindow *  lua_towindow(lua_State *L, int i)
{
    lua_pushliteral(L,"__ptr__");
    lua_gettable(L,i);
    GLFWwindow * window=(GLFWwindow *)lua_touserdata(L,-1);
    lua_pop(L,1);
    return window;
}

static void error_callback(int error, const char* description)
{
    GLFWwindow * window=glfwGetCurrentContext();
    lua_State *L=(lua_State *)glfwGetWindowUserPointer(window);
    lua_pushliteral(L,"__GLFWErrorCallback");
    lua_gettable(L,LUA_REGISTRYINDEX);
    lua_pushinteger(L,error);
    lua_pushstring(L,description);
    lua_call(L,2,0);
}

static void monitor_callback(GLFWmonitor * monitor, int event)
{
    GLFWwindow * window=glfwGetCurrentContext();
    lua_State *L=(lua_State *)glfwGetWindowUserPointer(window);
    lua_objinregistry(L,monitor,0);
    lua_pushliteral(L,"__GLFWMonitorCallback");
    lua_gettable(L,LUA_REGISTRYINDEX);
    lua_pushinteger(L,event);
    lua_call(L,2,0);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    lua_State * L=(lua_State *)glfwGetWindowUserPointer(window);
    lua_objinregistry(L,window,0);
    lua_pushliteral(L,"__KeyCallback");
    lua_gettable(L,-2);
    lua_swap(L);
    lua_pushinteger(L,key);
    lua_pushinteger(L,scancode);
    lua_pushinteger(L,action);
    lua_pushinteger(L,mods);
    lua_call(L,5,0);
}

static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    lua_State * L=(lua_State *)glfwGetWindowUserPointer(window);
    lua_objinregistry(L,window,0);
    lua_pushliteral(L,"__FramebufferSizeCallback");
    lua_gettable(L,-2);
    lua_swap(L);
    lua_pushinteger(L,width);
    lua_pushinteger(L,height);
    lua_call(L,3,0);
}

static void refresh_callback(GLFWwindow* window)
{
    lua_State * L=(lua_State *)glfwGetWindowUserPointer(window);
    lua_objinregistry(L,window,0);
    lua_pushliteral(L,"__WindowRefreshCallback");
    lua_gettable(L,-2);
    lua_swap(L);
    lua_call(L,1,0);
}

static void close_callback(GLFWwindow* window)
{
    lua_State * L=(lua_State *)glfwGetWindowUserPointer(window);
    lua_objinregistry(L,window,0);
    lua_pushliteral(L,"__WindowCloseCallback");
    lua_gettable(L,-2);
    lua_swap(L);
    lua_call(L,1,0);
}

static void focus_callback(GLFWwindow* window, int focused)
{
    lua_State * L=(lua_State *)glfwGetWindowUserPointer(window);
    lua_objinregistry(L,window,0);
    lua_pushliteral(L,"__WindowFocusCallback");
    lua_gettable(L,-2);
    lua_swap(L);
    lua_pushinteger(L,focused);
    lua_call(L,2,0);
}

static void iconify_callback(GLFWwindow* window, int iconified)
{
    lua_State * L=(lua_State *)glfwGetWindowUserPointer(window);
    lua_objinregistry(L,window,0);
    lua_pushliteral(L,"__WindowIconifyCallback");
    lua_gettable(L,-2);
    lua_swap(L);
    lua_pushinteger(L,iconified);
    lua_call(L,2,0);
}

static void pos_callback(GLFWwindow* window, int xpos, int ypos)
{
    lua_State * L=(lua_State *)glfwGetWindowUserPointer(window);
    lua_objinregistry(L,window,0);
    lua_pushliteral(L,"__WindowPosCallback");
    lua_gettable(L,-2);
    lua_swap(L);
    lua_pushinteger(L,xpos);
    lua_pushinteger(L,ypos);
    lua_call(L,3,0);
}

static void size_callback(GLFWwindow* window, int width, int height)
{
    lua_State * L=(lua_State *)glfwGetWindowUserPointer(window);
    lua_objinregistry(L,window,0);
    lua_pushliteral(L,"__WindowSizeCallback");
    lua_gettable(L,-2);
    lua_swap(L);
    lua_pushinteger(L,width);
    lua_pushinteger(L,height);
    lua_call(L,3,0);
}

static void char_callback(GLFWwindow* window, unsigned int codepoint)
{
    lua_State * L=(lua_State *)glfwGetWindowUserPointer(window);
    lua_objinregistry(L,window,0);
    lua_pushliteral(L,"__CharCallback");
    lua_gettable(L,-2);
    lua_swap(L);
    lua_pushinteger(L,codepoint);
    lua_call(L,2,0);
}

static void enter_callback(GLFWwindow* window, int entered)
{
    lua_State * L=(lua_State *)glfwGetWindowUserPointer(window);
    lua_objinregistry(L,window,0);
    lua_pushliteral(L,"__CursorEnterCallback");
    lua_gettable(L,-2);
    lua_swap(L);
    lua_pushinteger(L,entered);
    lua_call(L,2,0);
}

static void cursorpos_callback(GLFWwindow* window, double xpos, double ypos)
{
    lua_State * L=(lua_State *)glfwGetWindowUserPointer(window);
    lua_objinregistry(L,window,0);
    lua_pushliteral(L,"__CursorPosCallback");
    lua_gettable(L,-2);
    lua_swap(L);
    lua_pushnumber(L,xpos);
    lua_pushnumber(L,ypos);
    lua_call(L,3,0);
}

static void mousebutton_callback(GLFWwindow* window, int button, int action, int mods)
{
    lua_State * L=(lua_State *)glfwGetWindowUserPointer(window);
    lua_objinregistry(L,window,0);
    lua_pushliteral(L,"__MouseButtonCallback");
    lua_gettable(L,-2);
    lua_swap(L);
    lua_pushnumber(L,button);
    lua_pushnumber(L,action);
    lua_pushnumber(L,mods);
    lua_call(L,4,0);
}

static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    lua_State * L=(lua_State *)glfwGetWindowUserPointer(window);
    lua_objinregistry(L,window,0);
    lua_pushliteral(L,"__ScrollCallback");
    lua_gettable(L,-2);
    lua_swap(L);
    lua_pushnumber(L,xoffset);
    lua_pushnumber(L,yoffset);
    lua_call(L,3,0);
}

static int FSetErrorCallback(lua_State *L)
{
    glfwSetErrorCallback(error_callback);
    lua_pushliteral(L,"__GLFWErrorCallback");
    lua_pushvalue(L,1);
    lua_settable(L,LUA_REGISTRYINDEX);
    return 0;
}

static int FCreateWindow(lua_State *L)
{
    int narg=lua_gettop(L);
    int width=lua_tointeger(L,1);
    int height=lua_tointeger(L,2);
    const char * title=lua_tostring(L,3);
    GLFWmonitor * monitor=NULL;
    if(narg>=4)
        monitor=lua_tomonitor(L,4);
    GLFWwindow * share=NULL;
    if(narg==5)
        share=lua_towindow(L,5);
    GLFWwindow * window=glfwCreateWindow(width,height,title,monitor,share);
    glfwSetWindowUserPointer(window,L);
    lua_newtable(L);
    lua_pushliteral(L,"__ptr__");
    lua_pushlightuserdata(L,window);
    lua_settable(L,-3);
    lua_pushliteral(L,"width");
    lua_pushinteger(L,width);
    lua_settable(L,-3);
    lua_pushliteral(L,"height");
    lua_pushinteger(L,height);
    lua_settable(L,-3);
    lua_pushliteral(L,"title");
    lua_pushstring(L,title);
    lua_settable(L,-3);
    lua_getglobal(L,LIBNAME);
    lua_setmetatable(L,-2);
    return 1;
}

static int FGetPrimaryMonitor(lua_State *L)
{
    lua_newtable(L);
    lua_pushliteral(L,"__ptr__");
    lua_pushlightuserdata(L,glfwGetPrimaryMonitor());
    lua_settable(L,-3);
    lua_getglobal(L,LIBNAME);
    lua_setmetatable(L,-2);
    return 1;
}

static int FDestroyWindow(lua_State *L)
{
    GLFWwindow * window=lua_towindow(L,1);
    glfwDestroyWindow(window);
    lua_pushlightuserdata(L,window);
    lua_pushnil(L);
    lua_settable(L,LUA_REGISTRYINDEX);
    return 0;
}

static int FMakeContextCurrent(lua_State *L)
{
    glfwMakeContextCurrent(lua_towindow(L,1));
    return 0;
}

static int FGetCurrentContext(lua_State *L)
{
    GLFWwindow * window=glfwGetCurrentContext();
    lua_objinregistry(L,window,0);
    return 1;
}

static int FWindowShouldClose(lua_State *L)
{
    lua_pushboolean(L,glfwWindowShouldClose(lua_towindow(L,1)));
    return 1;
}

static int FExtensionSupported(lua_State *L)
{
    lua_pushboolean(L,glfwExtensionSupported(lua_tostring(L,1)));
    return 1;
}

static int FSwapInterval(lua_State *L)
{
    glfwSwapInterval(lua_tointeger(L,1));
    return 0;
}

static int FSetWindowShouldClose(lua_State *L)
{
    glfwSetWindowShouldClose(lua_towindow(L,1),lua_toboolean(L,2));
    return 0;
}

static int FSetWindowTitle(lua_State *L)
{
    glfwSetWindowTitle(lua_towindow(L,1),lua_tostring(L,2));
    return 0;
}

static int FGetWindowPos(lua_State *L)
{
    int xpos;
    int ypos;
    glfwGetWindowPos(lua_towindow(L,1),&xpos,&ypos);
    lua_pushinteger(L,xpos);
    lua_pushinteger(L,ypos);
    return 2;
}

static int FGetWindowSize(lua_State *L)
{
    int width;
    int height;
    glfwGetWindowSize(lua_towindow(L,1),&width,&height);
    lua_pushinteger(L,width);
    lua_pushinteger(L,height);
    return 2;
}

static int FSetWindowSize(lua_State *L)
{
    glfwSetWindowSize(lua_towindow(L,1),lua_tointeger(L,2),lua_tointeger(L,3));
    return 0;
}

static int FSetWindowPos(lua_State *L)
{
    glfwSetWindowPos(lua_towindow(L,1),lua_tointeger(L,2),lua_tointeger(L,3));
    return 0;
}

static int FIconifyWindow(lua_State *L)
{
    glfwIconifyWindow(lua_towindow(L,1));
    return 0;
}

static int FRestoreWindow(lua_State *L)
{
    glfwRestoreWindow(lua_towindow(L,1));
    return 0;
}

static int FShowWindow(lua_State *L)
{
    glfwShowWindow(lua_towindow(L,1));
    return 0;
}

static int FHideWindow(lua_State *L)
{
    glfwHideWindow(lua_towindow(L,1));
    return 0;
}

static int FGetWindowAttrib(lua_State *L)
{
    lua_pushinteger(L,glfwGetWindowAttrib(lua_towindow(L,1),lua_tointeger(L,2)));
    return 1;
}

static int FSetKeyCallback(lua_State *L)
{
    GLFWwindow * window=lua_towindow(L,1);
    glfwSetKeyCallback(window, key_callback);
    lua_objinregistry(L,window,1);
    lua_pushliteral(L,"__KeyCallback");
    lua_pushvalue(L,2);
    lua_settable(L,1);
    return 0;
}

static int FSetWindowPosCallback(lua_State *L)
{
    GLFWwindow * window=lua_towindow(L,1);
    glfwSetWindowPosCallback(window, pos_callback);
    lua_objinregistry(L,window,1);
    lua_pushliteral(L,"__WindowPosCallback");
    lua_pushvalue(L,2);
    lua_settable(L,1);
    return 0;
}

static int FSetWindowSizeCallback(lua_State *L)
{
    GLFWwindow * window=lua_towindow(L,1);
    glfwSetWindowSizeCallback(window, size_callback);
    lua_objinregistry(L,window,1);
    lua_pushliteral(L,"__WindowSizeCallback");
    lua_pushvalue(L,2);
    lua_settable(L,1);
    return 0;
}

static int FSetWindowCloseCallback(lua_State *L)
{
    GLFWwindow * window=lua_towindow(L,1);
    glfwSetWindowCloseCallback(window, close_callback);
    lua_objinregistry(L,window,1);
    lua_pushliteral(L,"__WindowCloseCallback");
    lua_pushvalue(L,2);
    lua_settable(L,1);
    return 0;
}

static int FSetWindowRefreshCallback(lua_State *L)
{
    GLFWwindow * window=lua_towindow(L,1);
    glfwSetWindowRefreshCallback(window, refresh_callback);
    lua_objinregistry(L,window,1);
    lua_pushliteral(L,"__WindowRefreshCallback");
    lua_pushvalue(L,2);
    lua_settable(L,1);
    return 0;
}

static int FSetWindowFocusCallback(lua_State *L)
{
    GLFWwindow * window=lua_towindow(L,1);
    glfwSetWindowFocusCallback(window, focus_callback);
    lua_objinregistry(L,window,1);
    lua_pushliteral(L,"__WindowFocusCallback");
    lua_pushvalue(L,2);
    lua_settable(L,1);
    return 0;
}

static int FSetWindowIconifyCallback(lua_State *L)
{
    GLFWwindow * window=lua_towindow(L,1);
    glfwSetWindowIconifyCallback(window, iconify_callback);
    lua_objinregistry(L,window,1);
    lua_pushliteral(L,"__WindowIconifyCallback");
    lua_pushvalue(L,2);
    lua_settable(L,1);
    return 0;
}

static int FSetCharCallback(lua_State *L)
{
    GLFWwindow * window=lua_towindow(L,1);
    glfwSetCharCallback(window, char_callback);
    lua_objinregistry(L,window,1);
    lua_pushliteral(L,"__CharCallback");
    lua_pushvalue(L,2);
    lua_settable(L,1);
    return 0;
}

static int FSetMouseButtonCallback(lua_State *L)
{
    GLFWwindow * window=lua_towindow(L,1);
    glfwSetMouseButtonCallback(window, mousebutton_callback);
    lua_objinregistry(L,window,1);
    lua_pushliteral(L,"__MouseButtonCallback");
    lua_pushvalue(L,2);
    lua_settable(L,1);
    return 0;
}

static int FSetCursorPosCallback(lua_State *L)
{
    GLFWwindow * window=lua_towindow(L,1);
    glfwSetCursorPosCallback(window, cursorpos_callback);
    lua_objinregistry(L,window,1);
    lua_pushliteral(L,"__CursorPosCallback");
    lua_pushvalue(L,2);
    lua_settable(L,1);
    return 0;
}

static int FSetCursorEnterCallback(lua_State *L)
{
    GLFWwindow * window=lua_towindow(L,1);
    glfwSetCursorEnterCallback(window, enter_callback);
    lua_objinregistry(L,window,1);
    lua_pushliteral(L,"__CursorEnterCallback");
    lua_pushvalue(L,2);
    lua_settable(L,1);
    return 0;
}

static int FSetScrollCallback(lua_State *L)
{
    GLFWwindow * window=lua_towindow(L,1);
    glfwSetScrollCallback(window, scroll_callback);
    lua_objinregistry(L,window,1);
    lua_pushliteral(L,"__ScrollCallback");
    lua_pushvalue(L,2);
    lua_settable(L,1);
    return 0;
}

static int FSetMonitorCallback(lua_State *L)
{
    GLFWmonitor * monitor=lua_tomonitor(L,1);
    glfwSetMonitorCallback(monitor_callback);
    lua_objinregistry(L,monitor,1);
    lua_pushliteral(L,"__GLFWMonitorCallback");
    lua_pushvalue(L,2);
    lua_settable(L,LUA_REGISTRYINDEX);
    return 0;
}

static int FGetFramebufferSize(lua_State *L)
{
    int width;
    int height;
    glfwGetFramebufferSize(lua_towindow(L,1),&width,&height);
    lua_pushinteger(L,width);
    lua_pushinteger(L,height);
    return 2;
}

static int FSetFramebufferSizeCallback(lua_State *L)
{
    GLFWwindow * window=lua_towindow(L,1);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    lua_objinregistry(L,window,1);
    lua_pushliteral(L,"__FramebufferSizeCallback");
    lua_pushvalue(L,2);
    lua_settable(L,1);
    return 0;
}

static int FGetTime(lua_State *L)
{
    lua_pushnumber(L,glfwGetTime());
    return 1;
}

static int FSetTime(lua_State *L)
{
    glfwSetTime(lua_tonumber(L,1));
    return 0;
}

static int FJoystickPresent(lua_State *L)
{
    lua_pushinteger(L,glfwJoystickPresent(lua_tointeger(L,1)));
    return 1;
}

static int FGetJoystickAxes(lua_State *L)
{
    int count;
    const float * axes=glfwGetJoystickAxes(lua_tointeger(L,1),&count);
    lua_newtable(L);
    for(int i=0;i<count;++i) {
        lua_pushinteger(L,i+1);
        lua_pushnumber(L,axes[i]);
        lua_settable(L,-3);
    }
    return 1;
}

static int FGetJoystickButtons(lua_State *L)
{
    int count;
    const unsigned char * states=glfwGetJoystickButtons(lua_tointeger(L,1),&count);
    lua_newtable(L);
    for(int i=0;i<count;++i) {
        lua_pushinteger(L,i+1);
        lua_pushinteger(L,states[i]);
        lua_settable(L,-3);
    }
    return 1;
}

static int FGetJoystickName(lua_State *L)
{
    lua_pushstring(L,glfwGetJoystickName(lua_tointeger(L,1)));
    return 1;
}

static int FGetInputMode(lua_State *L)
{
    lua_pushinteger(L,glfwGetInputMode(lua_towindow(L,1),lua_tointeger(L,2)));
    return 1;
}

static int FSetInputMode(lua_State *L)
{
    glfwSetInputMode(lua_towindow(L,1),lua_tointeger(L,2),lua_tointeger(L,3));
    return 0;
}

static int FGetKey(lua_State *L)
{
    lua_pushinteger(L,glfwGetKey(lua_towindow(L,1),lua_tointeger(L,2)));
    return 1;
}

static int FGetMouseButton(lua_State *L)
{
    lua_pushinteger(L,glfwGetMouseButton(lua_towindow(L,1),lua_tointeger(L,2)));
    return 1;
}

static int FGetCursorPos(lua_State *L)
{
    double xpos;
    double ypos;
    glfwGetCursorPos(lua_towindow(L,1),&xpos,&ypos);
    lua_pushnumber(L,xpos);
    lua_pushnumber(L,ypos);
    return 2;
}

static int FSetCursorPos(lua_State *L)
{
    glfwSetCursorPos(lua_towindow(L,1),lua_tonumber(L,2),lua_tonumber(L,3));
    return 0;
}

static int FSwapBuffers(lua_State *L)
{
    glfwSwapBuffers(lua_towindow(L,1));
    return 0;
}

static int FPollEvents(lua_State *L)
{
    glfwPollEvents();
    return 0;
}


static int FWaitEvents(lua_State *L)
{
    glfwWaitEvents();
    return 0;
}

static int FGetMonitors(lua_State *L)
{
    int nmonitors;
    GLFWmonitor **  monitors=glfwGetMonitors(&nmonitors);
    lua_newtable(L);
    for(int i=0;i<nmonitors;++i) {
        lua_pushinteger(L,i+1);
        lua_newtable(L);
        lua_pushliteral(L,"__ptr__");
        lua_pushlightuserdata(L,monitors[i]);
        lua_settable(L,-3);
        lua_getglobal(L,LIBNAME);
        lua_setmetatable(L,-2);
        lua_settable(L,-3);
    }
    return 1;
}

static int FGetClipboardString(lua_State *L)
{
    lua_pushstring(L,glfwGetClipboardString(lua_towindow(L,1)));
    return 1;
}

static int FSetClipboardString(lua_State *L)
{
    glfwSetClipboardString(lua_towindow(L,1),lua_tostring(L,2));
    return 0;
}

static int FInit(lua_State *L)
{
    lua_pushinteger(L,glfwInit());
    return 1;
}

static int FTerminate(lua_State *L)
{
    glfwTerminate();
    return 0;
}

static int FGetVersion(lua_State *L)
{
    int  major;
    int minor;
    int rev;
    glfwGetVersion(&major,&minor,&rev);
    lua_pushinteger(L,major);
    lua_pushinteger(L,minor);
    lua_pushinteger(L,rev);
    return 3;
}

static int FGetVersionString(lua_State *L)
{
    lua_pushstring(L,glfwGetVersionString());
    return 1;
}

static int FDefaultWindowHints(lua_State *L)
{
    glfwDefaultWindowHints();
    return 0;
}

static int FWindowHint(lua_State *L)
{
    glfwWindowHint(lua_tointeger(L,1),lua_tointeger(L,2));
    return 0;
}

static const luaL_Reg R[] =
{
    { "Init", FInit },
    { "Terminate", FTerminate },
    { "SetErrorCallback", FSetErrorCallback },
    { "CreateWindow", FCreateWindow },
    { "GetPrimaryMonitor", FGetPrimaryMonitor },
    { "DestroyWindow", FDestroyWindow },
    { "MakeContextCurrent", FMakeContextCurrent },
    { "GetCurrentContext", FGetCurrentContext },
    { "WindowShouldClose", FWindowShouldClose },
    { "SetWindowShouldClose", FSetWindowShouldClose },
    { "SetWindowTitle", FSetWindowTitle },
    { "GetWindowPos", FGetWindowPos },
    { "GetWindowSize", FGetWindowSize },
    { "SetWindowPos", FSetWindowPos },
    { "SetWindowSize", FSetWindowSize },
    { "IconifyWindow", FIconifyWindow },
    { "ShowWindow", FShowWindow },
    { "RestoreWindow", FRestoreWindow },
    { "HideWindow", FHideWindow },
    { "GetWindowAttrib", FGetWindowAttrib },
    { "GetFramebufferSize", FGetFramebufferSize },
    { "SetFramebufferSizeCallback", FSetFramebufferSizeCallback },
    { "SetKeyCallback", FSetKeyCallback },
    { "SetWindowPosCallback", FSetWindowPosCallback },
    { "SetWindowSizeCallback", FSetWindowSizeCallback },
    { "SetWindowCloseCallback", FSetWindowCloseCallback },
    { "SetWindowRefreshCallback", FSetWindowRefreshCallback },
    { "SetWindowFocusCallback", FSetWindowFocusCallback },
    { "SetWindowIconifyCallback", FSetWindowIconifyCallback },
    { "SetCharCallback", FSetCharCallback },
    { "SetMouseButtonCallback", FSetMouseButtonCallback },
    { "SetCursorPosCallback", FSetCursorPosCallback },
    { "SetCursorEnterCallback", FSetCursorEnterCallback },
    { "SetScrollCallback", FSetScrollCallback },
    { "SetMonitorCallback", FSetMonitorCallback },
    { "GetTime", FGetTime },
    { "SetTime", FSetTime },
    { "GetInputMode", FGetInputMode },
    { "SetInputMode", FSetInputMode },
    { "JoystickPresent", FJoystickPresent },
    { "GetJoystickAxes", FGetJoystickAxes },
    { "GetJoystickButtons", FGetJoystickButtons },
    { "GetJoystickName", FGetJoystickName },
    { "GetKey", FGetKey },
    { "GetMouseButton", FGetMouseButton },
    { "GetCursorPos", FGetCursorPos },
    { "SetCursorPos", FSetCursorPos },
    { "SwapBuffers", FSwapBuffers },
    { "PollEvents", FPollEvents },
    { "WaitEvents", FWaitEvents },
    { "GetMonitors", FGetMonitors },
    { "GetClipboardString", FGetClipboardString },
    { "SetClipboardString", FSetClipboardString },
    { "ExtensionSupported", FExtensionSupported },
    { "SwapInterval", FSwapInterval },
    { "GetVersion", FGetVersion},
    { "GetVersionString", FGetVersionString },
    { "DefaultWindowHints", FDefaultWindowHints },
    { "WindowHint", FWindowHint },
//    { "",  },
//    { "",  },
    { NULL,     NULL    }
};




extern "C"
int luaopen_glfw(lua_State *L)
{
    luaL_newmetatable(L,LIBTYPE);
    lua_setglobal(L,LIBNAME);
    luaL_register(L,LIBNAME,R);
    lua_pushliteral(L,"version");
    lua_pushliteral(L,LIBVERSION);
    lua_settable(L,-3);
    for(const luaL_IntegerConstant * p=C;p->name!=NULL;++p) {
        lua_pushstring(L,p->name);
        lua_pushinteger(L,p->i);
        lua_settable(L,-3);
    }
    lua_pushliteral(L,"__index");
    lua_pushvalue(L,-2);
    lua_settable(L,-3);
    return 1;
}