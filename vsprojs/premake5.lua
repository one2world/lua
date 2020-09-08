workspace "LuaSourceView"
	configurations { 
		"LuaDLL", 
		"LuacExe", 
		"LuaExe", 
		-- "CsXluaTest"
	}

	platforms {"Win32", "Win64"}


filter { "platforms:Win32" }
    system "Windows"
    architecture "x86"

filter { "platforms:Win64" }
    system "Windows"
    architecture "x86_64"


project "LuaDLL"
	kind "SharedLib"
	language "C"
	
	files {"../src/*.h", "../src/*.c"}
	removefiles {"../src/lua.c", "../src/luac.c"} 	

	--@ debug or release
	filter "Debug*"
		targetdir "outputs/dll/debug"
		defines {"DEBUG"}
		symbols "On"

	filter "Release*"
		targetdir "outputs/dll/release"
		defines {"NDEBUG"}
		symbols "On"

project "LuacExe"
	kind "ConsoleApp"
	language "C"
	
	files {"../src/*.c", "../src/*.h"}
	-- dependson { "LuaDLL"}
	removefiles {"../src/lua.c","../src/lua.h"} 	


	--@ debug or release
	filter "Debug*"
		targetdir "outputs/cexe/debug"
		defines {"DEBUG"}
		symbols "On"

	filter "Release*"
		targetdir "outputs/cexe/release"
		defines {"NDEBUG"}
		symbols "On"


project "LuaExe"
	kind "ConsoleApp"
	language "C"
	
	files {"../src/lua.c", "../src/*.h"}
	-- dependson { "LuaDLL"}
	removefiles {"../src/luac.c"} 	
	--@ debug or release
	filter "Debug*"
		targetdir "outputs/exe/debug"
		defines {"DEBUG"}
		symbols "On"

	filter "Release*"
		targetdir "outputs/exe/release"
		defines {"NDEBUG"}
		symbols "On"


-- project "CsXluaTest"
-- 	kind "ConsoleApp"
-- 	language "C#"
	
-- 	files {"**/LuaDLL.cs", "main.cs"}
-- 	links {"XluaDLL"}
-- 	-- removefiles{"**/Xlua/Examples/**"}
-- 	--@ debug or release
-- 	filter "Debug*"
-- 		targetdir "outputs/debug"
-- 		defines {"DEBUG"}
-- 		symbols "On"

-- 	filter "Release*"
-- 		targetdir "outputs/release"
-- 		defines {"NDEBUG"}
-- 		symbols "On"
