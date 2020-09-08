/**@mainpage  lua5.4 release源码学习
* <table>
* <tr><th>Project  <td>Lua-5.4 source code 
* <tr><th>Author   <td>lyg 
* </table>
* @section   项目介绍
* 专注于完全吃透 lua源代码, 未来功能：
* <table>
* <tr><th>序号	<th>功能	<th>涉及模块		</tr>
* <tr><td>1	<td>解释器加密	<td>lua代码解析</tr>
* <tr><td>2	<td>内存碎片优化	<td>gc模块</tr>
* <tr><td>3	<td>TODO	<td>TODO</tr>
* </table>
* @section   学习顺序  
* -# 按照程序使用lua的调用顺序（luaL_newstate->luaL_openlibs->逻辑代码->lua_close）
* -# 功能模块 lua_State luaL_openlibs loadfile require dofile dostring call gc vm
* 
**********************************************************************************
*/