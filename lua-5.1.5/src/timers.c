#include "lua.h"
#include <time.h>

int lclock(lua_State *l) {
	lua_pushnumber(l,clock());
	return 1;
}

LUALIB_API int luaopen_timers(lua_State *l) {
	lua_pushnumber(l,CLOCKS_PER_SEC);
	lua_setglobal(l,"CLOCKS_PER_SEC");
	lua_register(l,"clock",lclock);
	return 0;
}
