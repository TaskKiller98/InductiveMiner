# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/70/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/70/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/gosha/Рабочий стол/projects/InductiveMiner"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug"

# Include any dependencies generated for this target.
include src/CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/main.dir/flags.make

src/CMakeFiles/main.dir/Inductive_miner_algorithm.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/Inductive_miner_algorithm.cpp.o: ../src/Inductive_miner_algorithm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/main.dir/Inductive_miner_algorithm.cpp.o"
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/Inductive_miner_algorithm.cpp.o -c "/home/gosha/Рабочий стол/projects/InductiveMiner/src/Inductive_miner_algorithm.cpp"

src/CMakeFiles/main.dir/Inductive_miner_algorithm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/Inductive_miner_algorithm.cpp.i"
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/gosha/Рабочий стол/projects/InductiveMiner/src/Inductive_miner_algorithm.cpp" > CMakeFiles/main.dir/Inductive_miner_algorithm.cpp.i

src/CMakeFiles/main.dir/Inductive_miner_algorithm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/Inductive_miner_algorithm.cpp.s"
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/gosha/Рабочий стол/projects/InductiveMiner/src/Inductive_miner_algorithm.cpp" -o CMakeFiles/main.dir/Inductive_miner_algorithm.cpp.s

src/CMakeFiles/main.dir/main.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/main.dir/main.cpp.o"
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/main.cpp.o -c "/home/gosha/Рабочий стол/projects/InductiveMiner/src/main.cpp"

src/CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/gosha/Рабочий стол/projects/InductiveMiner/src/main.cpp" > CMakeFiles/main.dir/main.cpp.i

src/CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/gosha/Рабочий стол/projects/InductiveMiner/src/main.cpp" -o CMakeFiles/main.dir/main.cpp.s

src/CMakeFiles/main.dir/tools/Event.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/tools/Event.cpp.o: ../src/tools/Event.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/main.dir/tools/Event.cpp.o"
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/tools/Event.cpp.o -c "/home/gosha/Рабочий стол/projects/InductiveMiner/src/tools/Event.cpp"

src/CMakeFiles/main.dir/tools/Event.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/tools/Event.cpp.i"
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/gosha/Рабочий стол/projects/InductiveMiner/src/tools/Event.cpp" > CMakeFiles/main.dir/tools/Event.cpp.i

src/CMakeFiles/main.dir/tools/Event.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/tools/Event.cpp.s"
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/gosha/Рабочий стол/projects/InductiveMiner/src/tools/Event.cpp" -o CMakeFiles/main.dir/tools/Event.cpp.s

src/CMakeFiles/main.dir/tools/Footprint.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/tools/Footprint.cpp.o: ../src/tools/Footprint.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/main.dir/tools/Footprint.cpp.o"
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/tools/Footprint.cpp.o -c "/home/gosha/Рабочий стол/projects/InductiveMiner/src/tools/Footprint.cpp"

src/CMakeFiles/main.dir/tools/Footprint.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/tools/Footprint.cpp.i"
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/gosha/Рабочий стол/projects/InductiveMiner/src/tools/Footprint.cpp" > CMakeFiles/main.dir/tools/Footprint.cpp.i

src/CMakeFiles/main.dir/tools/Footprint.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/tools/Footprint.cpp.s"
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/gosha/Рабочий стол/projects/InductiveMiner/src/tools/Footprint.cpp" -o CMakeFiles/main.dir/tools/Footprint.cpp.s

src/CMakeFiles/main.dir/tools/ProcessTree.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/tools/ProcessTree.cpp.o: ../src/tools/ProcessTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/main.dir/tools/ProcessTree.cpp.o"
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/tools/ProcessTree.cpp.o -c "/home/gosha/Рабочий стол/projects/InductiveMiner/src/tools/ProcessTree.cpp"

src/CMakeFiles/main.dir/tools/ProcessTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/tools/ProcessTree.cpp.i"
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/gosha/Рабочий стол/projects/InductiveMiner/src/tools/ProcessTree.cpp" > CMakeFiles/main.dir/tools/ProcessTree.cpp.i

src/CMakeFiles/main.dir/tools/ProcessTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/tools/ProcessTree.cpp.s"
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/gosha/Рабочий стол/projects/InductiveMiner/src/tools/ProcessTree.cpp" -o CMakeFiles/main.dir/tools/ProcessTree.cpp.s

src/CMakeFiles/main.dir/tools/Trace.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/tools/Trace.cpp.o: ../src/tools/Trace.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/main.dir/tools/Trace.cpp.o"
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/tools/Trace.cpp.o -c "/home/gosha/Рабочий стол/projects/InductiveMiner/src/tools/Trace.cpp"

src/CMakeFiles/main.dir/tools/Trace.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/tools/Trace.cpp.i"
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/gosha/Рабочий стол/projects/InductiveMiner/src/tools/Trace.cpp" > CMakeFiles/main.dir/tools/Trace.cpp.i

src/CMakeFiles/main.dir/tools/Trace.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/tools/Trace.cpp.s"
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/gosha/Рабочий стол/projects/InductiveMiner/src/tools/Trace.cpp" -o CMakeFiles/main.dir/tools/Trace.cpp.s

src/CMakeFiles/main.dir/components/Component.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/components/Component.cpp.o: ../src/components/Component.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/main.dir/components/Component.cpp.o"
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/components/Component.cpp.o -c "/home/gosha/Рабочий стол/projects/InductiveMiner/src/components/Component.cpp"

src/CMakeFiles/main.dir/components/Component.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/components/Component.cpp.i"
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/gosha/Рабочий стол/projects/InductiveMiner/src/components/Component.cpp" > CMakeFiles/main.dir/components/Component.cpp.i

src/CMakeFiles/main.dir/components/Component.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/components/Component.cpp.s"
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/gosha/Рабочий стол/projects/InductiveMiner/src/components/Component.cpp" -o CMakeFiles/main.dir/components/Component.cpp.s

src/CMakeFiles/main.dir/components/Node.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/components/Node.cpp.o: ../src/components/Node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/CMakeFiles/main.dir/components/Node.cpp.o"
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/components/Node.cpp.o -c "/home/gosha/Рабочий стол/projects/InductiveMiner/src/components/Node.cpp"

src/CMakeFiles/main.dir/components/Node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/components/Node.cpp.i"
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/gosha/Рабочий стол/projects/InductiveMiner/src/components/Node.cpp" > CMakeFiles/main.dir/components/Node.cpp.i

src/CMakeFiles/main.dir/components/Node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/components/Node.cpp.s"
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/gosha/Рабочий стол/projects/InductiveMiner/src/components/Node.cpp" -o CMakeFiles/main.dir/components/Node.cpp.s

src/CMakeFiles/main.dir/components/Petri_net.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/components/Petri_net.cpp.o: ../src/components/Petri_net.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/CMakeFiles/main.dir/components/Petri_net.cpp.o"
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/components/Petri_net.cpp.o -c "/home/gosha/Рабочий стол/projects/InductiveMiner/src/components/Petri_net.cpp"

src/CMakeFiles/main.dir/components/Petri_net.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/components/Petri_net.cpp.i"
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/gosha/Рабочий стол/projects/InductiveMiner/src/components/Petri_net.cpp" > CMakeFiles/main.dir/components/Petri_net.cpp.i

src/CMakeFiles/main.dir/components/Petri_net.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/components/Petri_net.cpp.s"
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/gosha/Рабочий стол/projects/InductiveMiner/src/components/Petri_net.cpp" -o CMakeFiles/main.dir/components/Petri_net.cpp.s

src/CMakeFiles/main.dir/__/test/Algortihm_B_test.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/__/test/Algortihm_B_test.cpp.o: ../test/Algortihm_B_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object src/CMakeFiles/main.dir/__/test/Algortihm_B_test.cpp.o"
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/__/test/Algortihm_B_test.cpp.o -c "/home/gosha/Рабочий стол/projects/InductiveMiner/test/Algortihm_B_test.cpp"

src/CMakeFiles/main.dir/__/test/Algortihm_B_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/__/test/Algortihm_B_test.cpp.i"
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/gosha/Рабочий стол/projects/InductiveMiner/test/Algortihm_B_test.cpp" > CMakeFiles/main.dir/__/test/Algortihm_B_test.cpp.i

src/CMakeFiles/main.dir/__/test/Algortihm_B_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/__/test/Algortihm_B_test.cpp.s"
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/gosha/Рабочий стол/projects/InductiveMiner/test/Algortihm_B_test.cpp" -o CMakeFiles/main.dir/__/test/Algortihm_B_test.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/Inductive_miner_algorithm.cpp.o" \
"CMakeFiles/main.dir/main.cpp.o" \
"CMakeFiles/main.dir/tools/Event.cpp.o" \
"CMakeFiles/main.dir/tools/Footprint.cpp.o" \
"CMakeFiles/main.dir/tools/ProcessTree.cpp.o" \
"CMakeFiles/main.dir/tools/Trace.cpp.o" \
"CMakeFiles/main.dir/components/Component.cpp.o" \
"CMakeFiles/main.dir/components/Node.cpp.o" \
"CMakeFiles/main.dir/components/Petri_net.cpp.o" \
"CMakeFiles/main.dir/__/test/Algortihm_B_test.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

src/main: src/CMakeFiles/main.dir/Inductive_miner_algorithm.cpp.o
src/main: src/CMakeFiles/main.dir/main.cpp.o
src/main: src/CMakeFiles/main.dir/tools/Event.cpp.o
src/main: src/CMakeFiles/main.dir/tools/Footprint.cpp.o
src/main: src/CMakeFiles/main.dir/tools/ProcessTree.cpp.o
src/main: src/CMakeFiles/main.dir/tools/Trace.cpp.o
src/main: src/CMakeFiles/main.dir/components/Component.cpp.o
src/main: src/CMakeFiles/main.dir/components/Node.cpp.o
src/main: src/CMakeFiles/main.dir/components/Petri_net.cpp.o
src/main: src/CMakeFiles/main.dir/__/test/Algortihm_B_test.cpp.o
src/main: src/CMakeFiles/main.dir/build.make
src/main: src/CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable main"
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/main.dir/build: src/main

.PHONY : src/CMakeFiles/main.dir/build

src/CMakeFiles/main.dir/clean:
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" && $(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/main.dir/clean

src/CMakeFiles/main.dir/depend:
	cd "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/gosha/Рабочий стол/projects/InductiveMiner" "/home/gosha/Рабочий стол/projects/InductiveMiner/src" "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug" "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src" "/home/gosha/Рабочий стол/projects/InductiveMiner/cmake-build-debug/src/CMakeFiles/main.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/CMakeFiles/main.dir/depend

