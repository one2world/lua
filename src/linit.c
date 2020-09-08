/*
** $Id: linit.c $
** Initialization of libraries for lua.c and other clients
** See Copyright Notice in lua.h
*/


#define linit_c
#define LUA_LIB

/*
** If you embed Lua in your program and need to open the standard
** libraries, call luaL_openlibs in your program. If you need a
** different set of libraries, copy this file to your project and edit
** it to suit your needs.
**
** You can also *preload* libraries, so that a later 'require' can
** open the library, which is already linked to the application.
** For that, do the following code:
**
**  luaL_getsubtable(L, LUA_REGISTRYINDEX, LUA_PRELOAD_TABLE);
**  lua_pushcfunction(L, luaopen_modname);
**  lua_setfield(L, -2, modname);
**  lua_pop(L, 1);  // remove PRELOAD table
*/

#include "lprefix.h"


#include <stddef.h>

#include "lua.h"

#include "lualib.h"
#include "lauxlib.h"


/*
** these libs are loaded by lua.c and are readily available to any Lua
** program
*/
static const luaL_Reg loadedlibs[] = {
  {LUA_GNAME, luaopen_base},
  {LUA_LOADLIBNAME, luaopen_package},
  {LUA_COLIBNAME, luaopen_coroutine},
  {LUA_TABLIBNAME, luaopen_table},
  {LUA_IOLIBNAME, luaopen_io},
  {LUA_OSLIBNAME, luaopen_os},
  {LUA_STRLIBNAME, luaopen_string},
  {LUA_MATHLIBNAME, luaopen_math},
  {LUA_UTF8LIBNAME, luaopen_utf8},
  {LUA_DBLIBNAME, luaopen_debug},
  {NULL, NULL}
};

/** 加载lua库方法
*@detail  导出的openlibs函数
*@param[in] luaState
除了base TODO
* <table>
* <tr><th>lua方法 <th>加载库方法 </tr>
* <tr><td>_G  <td>luaopen_base</tr>
* <tr><td>package  <td>luaopen_package</tr>
* <tr><td>coroutine  <td>luaopen_coroutine</tr>
* <tr><td>table <td>luaopen_table</tr>
* <tr><td>io  <td>luaopen_io</tr>
* <tr><td>os  <td>luaopen_os</tr>
* <tr><td>string <td>luaopen_string</tr>
* <tr><td>math  <td>luaopen_math</tr>
* <tr><td>utf8  <td>luaopen_utf8</tr>
* <tr><td>debug  <td>luaopen_debug</tr>
* </table>
*/
LUALIB_API void luaL_openlibs (lua_State *L) {
  const luaL_Reg *lib;
  /* "require" functions from 'loadedlibs' and set results to global table */
  for (lib = loadedlibs; lib->func; lib++) {
    luaL_requiref(L, lib->name, lib->func, 1);
    lua_pop(L, 1);  /* remove lib */
  }
}

