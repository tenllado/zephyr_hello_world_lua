#include <zephyr.h>
#include <fs/fs.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

void main(void)
{
	lua_State *L;

	printk("Starting lua code\n");
	L = luaL_newstate();
  	luaL_openlibs(L);
  	luaL_dostring(L, "print('Hello from Lua')");
	lua_close(L);
	printk("Test Done!\n");
}
