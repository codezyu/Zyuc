# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2021.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2021.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\1书籍\编译原理\ZyuC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\1书籍\编译原理\ZyuC\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ZyuC.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ZyuC.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ZyuC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ZyuC.dir/flags.make

CMakeFiles/ZyuC.dir/main.cpp.obj: CMakeFiles/ZyuC.dir/flags.make
CMakeFiles/ZyuC.dir/main.cpp.obj: ../main.cpp
CMakeFiles/ZyuC.dir/main.cpp.obj: CMakeFiles/ZyuC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\1书籍\编译原理\ZyuC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ZyuC.dir/main.cpp.obj"
	D:\MingGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ZyuC.dir/main.cpp.obj -MF CMakeFiles\ZyuC.dir\main.cpp.obj.d -o CMakeFiles\ZyuC.dir\main.cpp.obj -c D:\1书籍\编译原理\ZyuC\main.cpp

CMakeFiles/ZyuC.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ZyuC.dir/main.cpp.i"
	D:\MingGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\1书籍\编译原理\ZyuC\main.cpp > CMakeFiles\ZyuC.dir\main.cpp.i

CMakeFiles/ZyuC.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ZyuC.dir/main.cpp.s"
	D:\MingGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\1书籍\编译原理\ZyuC\main.cpp -o CMakeFiles\ZyuC.dir\main.cpp.s

CMakeFiles/ZyuC.dir/Parser/GrammerReWrite.cpp.obj: CMakeFiles/ZyuC.dir/flags.make
CMakeFiles/ZyuC.dir/Parser/GrammerReWrite.cpp.obj: ../Parser/GrammerReWrite.cpp
CMakeFiles/ZyuC.dir/Parser/GrammerReWrite.cpp.obj: CMakeFiles/ZyuC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\1书籍\编译原理\ZyuC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ZyuC.dir/Parser/GrammerReWrite.cpp.obj"
	D:\MingGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ZyuC.dir/Parser/GrammerReWrite.cpp.obj -MF CMakeFiles\ZyuC.dir\Parser\GrammerReWrite.cpp.obj.d -o CMakeFiles\ZyuC.dir\Parser\GrammerReWrite.cpp.obj -c D:\1书籍\编译原理\ZyuC\Parser\GrammerReWrite.cpp

CMakeFiles/ZyuC.dir/Parser/GrammerReWrite.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ZyuC.dir/Parser/GrammerReWrite.cpp.i"
	D:\MingGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\1书籍\编译原理\ZyuC\Parser\GrammerReWrite.cpp > CMakeFiles\ZyuC.dir\Parser\GrammerReWrite.cpp.i

CMakeFiles/ZyuC.dir/Parser/GrammerReWrite.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ZyuC.dir/Parser/GrammerReWrite.cpp.s"
	D:\MingGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\1书籍\编译原理\ZyuC\Parser\GrammerReWrite.cpp -o CMakeFiles\ZyuC.dir\Parser\GrammerReWrite.cpp.s

# Object files for target ZyuC
ZyuC_OBJECTS = \
"CMakeFiles/ZyuC.dir/main.cpp.obj" \
"CMakeFiles/ZyuC.dir/Parser/GrammerReWrite.cpp.obj"

# External object files for target ZyuC
ZyuC_EXTERNAL_OBJECTS =

ZyuC.exe: CMakeFiles/ZyuC.dir/main.cpp.obj
ZyuC.exe: CMakeFiles/ZyuC.dir/Parser/GrammerReWrite.cpp.obj
ZyuC.exe: CMakeFiles/ZyuC.dir/build.make
ZyuC.exe: CMakeFiles/ZyuC.dir/linklibs.rsp
ZyuC.exe: CMakeFiles/ZyuC.dir/objects1.rsp
ZyuC.exe: CMakeFiles/ZyuC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\1书籍\编译原理\ZyuC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ZyuC.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ZyuC.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ZyuC.dir/build: ZyuC.exe
.PHONY : CMakeFiles/ZyuC.dir/build

CMakeFiles/ZyuC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ZyuC.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ZyuC.dir/clean

CMakeFiles/ZyuC.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\1书籍\编译原理\ZyuC D:\1书籍\编译原理\ZyuC D:\1书籍\编译原理\ZyuC\cmake-build-debug D:\1书籍\编译原理\ZyuC\cmake-build-debug D:\1书籍\编译原理\ZyuC\cmake-build-debug\CMakeFiles\ZyuC.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ZyuC.dir/depend
