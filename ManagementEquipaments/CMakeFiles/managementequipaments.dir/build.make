# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.1.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.1.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\brkscosta\Documents\GitHub\ManagementEquipaments\ManagementEquipaments

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\brkscosta\Documents\GitHub\ManagementEquipaments\ManagementEquipaments

# Include any dependencies generated for this target.
include CMakeFiles/ManagementEquipaments.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ManagementEquipaments.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ManagementEquipaments.dir/flags.make

CMakeFiles/ManagementEquipaments.dir/main.c.obj: CMakeFiles/ManagementEquipaments.dir/flags.make
CMakeFiles/ManagementEquipaments.dir/main.c.obj: main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\brkscosta\Documents\GitHub\ManagementEquipaments\ManagementEquipaments\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ManagementEquipaments.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ManagementEquipaments.dir\main.c.obj   -c C:\Users\brkscosta\Documents\GitHub\ManagementEquipaments\ManagementEquipaments\main.c

CMakeFiles/ManagementEquipaments.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ManagementEquipaments.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\brkscosta\Documents\GitHub\ManagementEquipaments\ManagementEquipaments\main.c > CMakeFiles\ManagementEquipaments.dir\main.c.i

CMakeFiles/ManagementEquipaments.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ManagementEquipaments.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\brkscosta\Documents\GitHub\ManagementEquipaments\ManagementEquipaments\main.c -o CMakeFiles\ManagementEquipaments.dir\main.c.s

CMakeFiles/ManagementEquipaments.dir/main.c.obj.requires:

.PHONY : CMakeFiles/ManagementEquipaments.dir/main.c.obj.requires

CMakeFiles/ManagementEquipaments.dir/main.c.obj.provides: CMakeFiles/ManagementEquipaments.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\ManagementEquipaments.dir\build.make CMakeFiles/ManagementEquipaments.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/ManagementEquipaments.dir/main.c.obj.provides

CMakeFiles/ManagementEquipaments.dir/main.c.obj.provides.build: CMakeFiles/ManagementEquipaments.dir/main.c.obj


# Object files for target ManagementEquipaments
ManagementEquipaments_OBJECTS = \
"CMakeFiles/ManagementEquipaments.dir/main.c.obj"

# External object files for target ManagementEquipaments
ManagementEquipaments_EXTERNAL_OBJECTS =

ManagementEquipaments.exe: CMakeFiles/ManagementEquipaments.dir/main.c.obj
ManagementEquipaments.exe: CMakeFiles/ManagementEquipaments.dir/build.make
ManagementEquipaments.exe: CMakeFiles/ManagementEquipaments.dir/linklibs.rsp
ManagementEquipaments.exe: CMakeFiles/ManagementEquipaments.dir/objects1.rsp
ManagementEquipaments.exe: CMakeFiles/ManagementEquipaments.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\brkscosta\Documents\GitHub\ManagementEquipaments\ManagementEquipaments\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ManagementEquipaments.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ManagementEquipaments.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ManagementEquipaments.dir/build: ManagementEquipaments.exe

.PHONY : CMakeFiles/ManagementEquipaments.dir/build

CMakeFiles/ManagementEquipaments.dir/requires: CMakeFiles/ManagementEquipaments.dir/main.c.obj.requires

.PHONY : CMakeFiles/ManagementEquipaments.dir/requires

CMakeFiles/ManagementEquipaments.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ManagementEquipaments.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ManagementEquipaments.dir/clean

CMakeFiles/ManagementEquipaments.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\brkscosta\Documents\GitHub\ManagementEquipaments\ManagementEquipaments C:\Users\brkscosta\Documents\GitHub\ManagementEquipaments\ManagementEquipaments C:\Users\brkscosta\Documents\GitHub\ManagementEquipaments\ManagementEquipaments C:\Users\brkscosta\Documents\GitHub\ManagementEquipaments\ManagementEquipaments C:\Users\brkscosta\Documents\GitHub\ManagementEquipaments\ManagementEquipaments\CMakeFiles\managementequipaments.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ManagementEquipaments.dir/depend

