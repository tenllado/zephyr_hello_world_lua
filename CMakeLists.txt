cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(lua_hello_world)

add_library(liblua STATIC
	lua/lapi.c
	lua/lauxlib.c
	lua/lbaselib.c
	lua/lcode.c
	lua/lcorolib.c
	lua/lctype.c
	lua/ldblib.c
	lua/ldebug.c
	lua/ldo.c
	lua/ldump.c
	lua/lfunc.c
	lua/lgc.c
	lua/linit.c
	lua/liolib.c
	lua/llex.c
	lua/lmathlib.c
	lua/lmem.c
    lua/loadlib.c
	lua/lobject.c
	lua/lopcodes.c
    lua/loslib.c
	lua/lparser.c
	lua/lstate.c
	lua/lstring.c
	lua/lstrlib.c
	lua/ltable.c
	lua/ltablib.c
	lua/ltm.c
	lua/lundump.c
    lua/lutf8lib.c
	lua/lvm.c
	lua/lzio.c
	)

target_include_directories(liblua
	INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/lua
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lua
	)

target_link_libraries(liblua zephyr_interface)

install(TARGETS liblua DESTINATION lib)

add_subdirectory(src)

