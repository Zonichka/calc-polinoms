# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\User\CLionProjects\calc_polinoms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\User\CLionProjects\calc_polinoms\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/calc_polinoms.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/calc_polinoms.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/calc_polinoms.dir/flags.make

CMakeFiles/calc_polinoms.dir/main.cpp.obj: CMakeFiles/calc_polinoms.dir/flags.make
CMakeFiles/calc_polinoms.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\CLionProjects\calc_polinoms\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/calc_polinoms.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\calc_polinoms.dir\main.cpp.obj -c C:\Users\User\CLionProjects\calc_polinoms\main.cpp

CMakeFiles/calc_polinoms.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/calc_polinoms.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\User\CLionProjects\calc_polinoms\main.cpp > CMakeFiles\calc_polinoms.dir\main.cpp.i

CMakeFiles/calc_polinoms.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/calc_polinoms.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\User\CLionProjects\calc_polinoms\main.cpp -o CMakeFiles\calc_polinoms.dir\main.cpp.s

# Object files for target calc_polinoms
calc_polinoms_OBJECTS = \
"CMakeFiles/calc_polinoms.dir/main.cpp.obj"

# External object files for target calc_polinoms
calc_polinoms_EXTERNAL_OBJECTS =

calc_polinoms.exe: CMakeFiles/calc_polinoms.dir/main.cpp.obj
calc_polinoms.exe: CMakeFiles/calc_polinoms.dir/build.make
calc_polinoms.exe: CMakeFiles/calc_polinoms.dir/linklibs.rsp
calc_polinoms.exe: CMakeFiles/calc_polinoms.dir/objects1.rsp
calc_polinoms.exe: CMakeFiles/calc_polinoms.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\User\CLionProjects\calc_polinoms\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable calc_polinoms.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\calc_polinoms.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/calc_polinoms.dir/build: calc_polinoms.exe

.PHONY : CMakeFiles/calc_polinoms.dir/build

CMakeFiles/calc_polinoms.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\calc_polinoms.dir\cmake_clean.cmake
.PHONY : CMakeFiles/calc_polinoms.dir/clean

CMakeFiles/calc_polinoms.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\User\CLionProjects\calc_polinoms C:\Users\User\CLionProjects\calc_polinoms C:\Users\User\CLionProjects\calc_polinoms\cmake-build-debug C:\Users\User\CLionProjects\calc_polinoms\cmake-build-debug C:\Users\User\CLionProjects\calc_polinoms\cmake-build-debug\CMakeFiles\calc_polinoms.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/calc_polinoms.dir/depend

