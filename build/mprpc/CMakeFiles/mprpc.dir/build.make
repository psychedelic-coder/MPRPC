# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/liuchen/项目/MPRPC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liuchen/项目/MPRPC/build

# Include any dependencies generated for this target.
include mprpc/CMakeFiles/mprpc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include mprpc/CMakeFiles/mprpc.dir/compiler_depend.make

# Include the progress variables for this target.
include mprpc/CMakeFiles/mprpc.dir/progress.make

# Include the compile flags for this target's objects.
include mprpc/CMakeFiles/mprpc.dir/flags.make

mprpc/CMakeFiles/mprpc.dir/src/MprpcApplication.cc.o: mprpc/CMakeFiles/mprpc.dir/flags.make
mprpc/CMakeFiles/mprpc.dir/src/MprpcApplication.cc.o: /home/liuchen/项目/MPRPC/mprpc/src/MprpcApplication.cc
mprpc/CMakeFiles/mprpc.dir/src/MprpcApplication.cc.o: mprpc/CMakeFiles/mprpc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liuchen/项目/MPRPC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object mprpc/CMakeFiles/mprpc.dir/src/MprpcApplication.cc.o"
	cd /home/liuchen/项目/MPRPC/build/mprpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT mprpc/CMakeFiles/mprpc.dir/src/MprpcApplication.cc.o -MF CMakeFiles/mprpc.dir/src/MprpcApplication.cc.o.d -o CMakeFiles/mprpc.dir/src/MprpcApplication.cc.o -c /home/liuchen/项目/MPRPC/mprpc/src/MprpcApplication.cc

mprpc/CMakeFiles/mprpc.dir/src/MprpcApplication.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mprpc.dir/src/MprpcApplication.cc.i"
	cd /home/liuchen/项目/MPRPC/build/mprpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liuchen/项目/MPRPC/mprpc/src/MprpcApplication.cc > CMakeFiles/mprpc.dir/src/MprpcApplication.cc.i

mprpc/CMakeFiles/mprpc.dir/src/MprpcApplication.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mprpc.dir/src/MprpcApplication.cc.s"
	cd /home/liuchen/项目/MPRPC/build/mprpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liuchen/项目/MPRPC/mprpc/src/MprpcApplication.cc -o CMakeFiles/mprpc.dir/src/MprpcApplication.cc.s

mprpc/CMakeFiles/mprpc.dir/src/MprpcConfig.cc.o: mprpc/CMakeFiles/mprpc.dir/flags.make
mprpc/CMakeFiles/mprpc.dir/src/MprpcConfig.cc.o: /home/liuchen/项目/MPRPC/mprpc/src/MprpcConfig.cc
mprpc/CMakeFiles/mprpc.dir/src/MprpcConfig.cc.o: mprpc/CMakeFiles/mprpc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liuchen/项目/MPRPC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object mprpc/CMakeFiles/mprpc.dir/src/MprpcConfig.cc.o"
	cd /home/liuchen/项目/MPRPC/build/mprpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT mprpc/CMakeFiles/mprpc.dir/src/MprpcConfig.cc.o -MF CMakeFiles/mprpc.dir/src/MprpcConfig.cc.o.d -o CMakeFiles/mprpc.dir/src/MprpcConfig.cc.o -c /home/liuchen/项目/MPRPC/mprpc/src/MprpcConfig.cc

mprpc/CMakeFiles/mprpc.dir/src/MprpcConfig.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mprpc.dir/src/MprpcConfig.cc.i"
	cd /home/liuchen/项目/MPRPC/build/mprpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liuchen/项目/MPRPC/mprpc/src/MprpcConfig.cc > CMakeFiles/mprpc.dir/src/MprpcConfig.cc.i

mprpc/CMakeFiles/mprpc.dir/src/MprpcConfig.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mprpc.dir/src/MprpcConfig.cc.s"
	cd /home/liuchen/项目/MPRPC/build/mprpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liuchen/项目/MPRPC/mprpc/src/MprpcConfig.cc -o CMakeFiles/mprpc.dir/src/MprpcConfig.cc.s

mprpc/CMakeFiles/mprpc.dir/src/RpcProvider.cc.o: mprpc/CMakeFiles/mprpc.dir/flags.make
mprpc/CMakeFiles/mprpc.dir/src/RpcProvider.cc.o: /home/liuchen/项目/MPRPC/mprpc/src/RpcProvider.cc
mprpc/CMakeFiles/mprpc.dir/src/RpcProvider.cc.o: mprpc/CMakeFiles/mprpc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liuchen/项目/MPRPC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object mprpc/CMakeFiles/mprpc.dir/src/RpcProvider.cc.o"
	cd /home/liuchen/项目/MPRPC/build/mprpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT mprpc/CMakeFiles/mprpc.dir/src/RpcProvider.cc.o -MF CMakeFiles/mprpc.dir/src/RpcProvider.cc.o.d -o CMakeFiles/mprpc.dir/src/RpcProvider.cc.o -c /home/liuchen/项目/MPRPC/mprpc/src/RpcProvider.cc

mprpc/CMakeFiles/mprpc.dir/src/RpcProvider.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mprpc.dir/src/RpcProvider.cc.i"
	cd /home/liuchen/项目/MPRPC/build/mprpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liuchen/项目/MPRPC/mprpc/src/RpcProvider.cc > CMakeFiles/mprpc.dir/src/RpcProvider.cc.i

mprpc/CMakeFiles/mprpc.dir/src/RpcProvider.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mprpc.dir/src/RpcProvider.cc.s"
	cd /home/liuchen/项目/MPRPC/build/mprpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liuchen/项目/MPRPC/mprpc/src/RpcProvider.cc -o CMakeFiles/mprpc.dir/src/RpcProvider.cc.s

mprpc/CMakeFiles/mprpc.dir/src/user.pb.cc.o: mprpc/CMakeFiles/mprpc.dir/flags.make
mprpc/CMakeFiles/mprpc.dir/src/user.pb.cc.o: /home/liuchen/项目/MPRPC/mprpc/src/user.pb.cc
mprpc/CMakeFiles/mprpc.dir/src/user.pb.cc.o: mprpc/CMakeFiles/mprpc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liuchen/项目/MPRPC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object mprpc/CMakeFiles/mprpc.dir/src/user.pb.cc.o"
	cd /home/liuchen/项目/MPRPC/build/mprpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT mprpc/CMakeFiles/mprpc.dir/src/user.pb.cc.o -MF CMakeFiles/mprpc.dir/src/user.pb.cc.o.d -o CMakeFiles/mprpc.dir/src/user.pb.cc.o -c /home/liuchen/项目/MPRPC/mprpc/src/user.pb.cc

mprpc/CMakeFiles/mprpc.dir/src/user.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mprpc.dir/src/user.pb.cc.i"
	cd /home/liuchen/项目/MPRPC/build/mprpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liuchen/项目/MPRPC/mprpc/src/user.pb.cc > CMakeFiles/mprpc.dir/src/user.pb.cc.i

mprpc/CMakeFiles/mprpc.dir/src/user.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mprpc.dir/src/user.pb.cc.s"
	cd /home/liuchen/项目/MPRPC/build/mprpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liuchen/项目/MPRPC/mprpc/src/user.pb.cc -o CMakeFiles/mprpc.dir/src/user.pb.cc.s

# Object files for target mprpc
mprpc_OBJECTS = \
"CMakeFiles/mprpc.dir/src/MprpcApplication.cc.o" \
"CMakeFiles/mprpc.dir/src/MprpcConfig.cc.o" \
"CMakeFiles/mprpc.dir/src/RpcProvider.cc.o" \
"CMakeFiles/mprpc.dir/src/user.pb.cc.o"

# External object files for target mprpc
mprpc_EXTERNAL_OBJECTS =

/home/liuchen/项目/MPRPC/lib/libmprpc.a: mprpc/CMakeFiles/mprpc.dir/src/MprpcApplication.cc.o
/home/liuchen/项目/MPRPC/lib/libmprpc.a: mprpc/CMakeFiles/mprpc.dir/src/MprpcConfig.cc.o
/home/liuchen/项目/MPRPC/lib/libmprpc.a: mprpc/CMakeFiles/mprpc.dir/src/RpcProvider.cc.o
/home/liuchen/项目/MPRPC/lib/libmprpc.a: mprpc/CMakeFiles/mprpc.dir/src/user.pb.cc.o
/home/liuchen/项目/MPRPC/lib/libmprpc.a: mprpc/CMakeFiles/mprpc.dir/build.make
/home/liuchen/项目/MPRPC/lib/libmprpc.a: mprpc/CMakeFiles/mprpc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liuchen/项目/MPRPC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library /home/liuchen/项目/MPRPC/lib/libmprpc.a"
	cd /home/liuchen/项目/MPRPC/build/mprpc && $(CMAKE_COMMAND) -P CMakeFiles/mprpc.dir/cmake_clean_target.cmake
	cd /home/liuchen/项目/MPRPC/build/mprpc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mprpc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
mprpc/CMakeFiles/mprpc.dir/build: /home/liuchen/项目/MPRPC/lib/libmprpc.a
.PHONY : mprpc/CMakeFiles/mprpc.dir/build

mprpc/CMakeFiles/mprpc.dir/clean:
	cd /home/liuchen/项目/MPRPC/build/mprpc && $(CMAKE_COMMAND) -P CMakeFiles/mprpc.dir/cmake_clean.cmake
.PHONY : mprpc/CMakeFiles/mprpc.dir/clean

mprpc/CMakeFiles/mprpc.dir/depend:
	cd /home/liuchen/项目/MPRPC/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liuchen/项目/MPRPC /home/liuchen/项目/MPRPC/mprpc /home/liuchen/项目/MPRPC/build /home/liuchen/项目/MPRPC/build/mprpc /home/liuchen/项目/MPRPC/build/mprpc/CMakeFiles/mprpc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : mprpc/CMakeFiles/mprpc.dir/depend

