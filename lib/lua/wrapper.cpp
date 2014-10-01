#define LIBNAME "lib"
#define LIBTYPE "type"
#define LIBVERSION "version"

static int Fname(lua_State *L)
{
    double a=lua_tonumber(L,1);
    double b=lua_tonumber(L,2);
    lua_pushnumber(L, a+b);
    return 1;
}

static const luaL_Reg R[] =
{
    { "name", Fname },
    { NULL,     NULL    }
};

extern "C"
int luaopen_lib(lua_State *L)
{
    luaL_newmetatable(L,LIBTYPE);
    lua_setglobal(L,LIBNAME);
    luaL_register(L,LIBNAME,R);
    lua_pushliteral(L,"version");
    lua_pushliteral(L,LIBVERSION);
    lua_settable(L,-3);
    lua_pushliteral(L,"__index");
    lua_pushvalue(L,-2);
    lua_settable(L,-3);
    return 1;
}