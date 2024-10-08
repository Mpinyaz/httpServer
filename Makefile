# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.30.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.30.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/eltonmpinyuri/Documents/CHub/networkprogramming

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/eltonmpinyuri/Documents/CHub/networkprogramming

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake cache editor..."
	/usr/local/Cellar/cmake/3.30.1/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.30.2/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/eltonmpinyuri/Documents/CHub/networkprogramming/CMakeFiles /Users/eltonmpinyuri/Documents/CHub/networkprogramming//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/eltonmpinyuri/Documents/CHub/networkprogramming/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named networkprogramming

# Build rule for target.
networkprogramming: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 networkprogramming
.PHONY : networkprogramming

# fast build rule for target.
networkprogramming/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/networkprogramming.dir/build.make CMakeFiles/networkprogramming.dir/build
.PHONY : networkprogramming/fast

src/client.o: src/client.c.o
.PHONY : src/client.o

# target to build an object file
src/client.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/networkprogramming.dir/build.make CMakeFiles/networkprogramming.dir/src/client.c.o
.PHONY : src/client.c.o

src/client.i: src/client.c.i
.PHONY : src/client.i

# target to preprocess a source file
src/client.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/networkprogramming.dir/build.make CMakeFiles/networkprogramming.dir/src/client.c.i
.PHONY : src/client.c.i

src/client.s: src/client.c.s
.PHONY : src/client.s

# target to generate assembly for a file
src/client.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/networkprogramming.dir/build.make CMakeFiles/networkprogramming.dir/src/client.c.s
.PHONY : src/client.c.s

src/errorhandling.o: src/errorhandling.c.o
.PHONY : src/errorhandling.o

# target to build an object file
src/errorhandling.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/networkprogramming.dir/build.make CMakeFiles/networkprogramming.dir/src/errorhandling.c.o
.PHONY : src/errorhandling.c.o

src/errorhandling.i: src/errorhandling.c.i
.PHONY : src/errorhandling.i

# target to preprocess a source file
src/errorhandling.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/networkprogramming.dir/build.make CMakeFiles/networkprogramming.dir/src/errorhandling.c.i
.PHONY : src/errorhandling.c.i

src/errorhandling.s: src/errorhandling.c.s
.PHONY : src/errorhandling.s

# target to generate assembly for a file
src/errorhandling.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/networkprogramming.dir/build.make CMakeFiles/networkprogramming.dir/src/errorhandling.c.s
.PHONY : src/errorhandling.c.s

src/main.o: src/main.c.o
.PHONY : src/main.o

# target to build an object file
src/main.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/networkprogramming.dir/build.make CMakeFiles/networkprogramming.dir/src/main.c.o
.PHONY : src/main.c.o

src/main.i: src/main.c.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/networkprogramming.dir/build.make CMakeFiles/networkprogramming.dir/src/main.c.i
.PHONY : src/main.c.i

src/main.s: src/main.c.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/networkprogramming.dir/build.make CMakeFiles/networkprogramming.dir/src/main.c.s
.PHONY : src/main.c.s

src/server.o: src/server.c.o
.PHONY : src/server.o

# target to build an object file
src/server.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/networkprogramming.dir/build.make CMakeFiles/networkprogramming.dir/src/server.c.o
.PHONY : src/server.c.o

src/server.i: src/server.c.i
.PHONY : src/server.i

# target to preprocess a source file
src/server.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/networkprogramming.dir/build.make CMakeFiles/networkprogramming.dir/src/server.c.i
.PHONY : src/server.c.i

src/server.s: src/server.c.s
.PHONY : src/server.s

# target to generate assembly for a file
src/server.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/networkprogramming.dir/build.make CMakeFiles/networkprogramming.dir/src/server.c.s
.PHONY : src/server.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... networkprogramming"
	@echo "... src/client.o"
	@echo "... src/client.i"
	@echo "... src/client.s"
	@echo "... src/errorhandling.o"
	@echo "... src/errorhandling.i"
	@echo "... src/errorhandling.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/server.o"
	@echo "... src/server.i"
	@echo "... src/server.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

