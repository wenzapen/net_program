# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wen/vscode_c++/net_program

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wen/vscode_c++/net_program/build

# Include any dependencies generated for this target.
include src/CMakeFiles/httpserver_demo.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/httpserver_demo.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/httpserver_demo.dir/flags.make

src/CMakeFiles/httpserver_demo.dir/acceptor.c.o: src/CMakeFiles/httpserver_demo.dir/flags.make
src/CMakeFiles/httpserver_demo.dir/acceptor.c.o: ../src/acceptor.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wen/vscode_c++/net_program/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/httpserver_demo.dir/acceptor.c.o"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/httpserver_demo.dir/acceptor.c.o   -c /home/wen/vscode_c++/net_program/src/acceptor.c

src/CMakeFiles/httpserver_demo.dir/acceptor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/httpserver_demo.dir/acceptor.c.i"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wen/vscode_c++/net_program/src/acceptor.c > CMakeFiles/httpserver_demo.dir/acceptor.c.i

src/CMakeFiles/httpserver_demo.dir/acceptor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/httpserver_demo.dir/acceptor.c.s"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wen/vscode_c++/net_program/src/acceptor.c -o CMakeFiles/httpserver_demo.dir/acceptor.c.s

src/CMakeFiles/httpserver_demo.dir/buffer.c.o: src/CMakeFiles/httpserver_demo.dir/flags.make
src/CMakeFiles/httpserver_demo.dir/buffer.c.o: ../src/buffer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wen/vscode_c++/net_program/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/CMakeFiles/httpserver_demo.dir/buffer.c.o"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/httpserver_demo.dir/buffer.c.o   -c /home/wen/vscode_c++/net_program/src/buffer.c

src/CMakeFiles/httpserver_demo.dir/buffer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/httpserver_demo.dir/buffer.c.i"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wen/vscode_c++/net_program/src/buffer.c > CMakeFiles/httpserver_demo.dir/buffer.c.i

src/CMakeFiles/httpserver_demo.dir/buffer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/httpserver_demo.dir/buffer.c.s"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wen/vscode_c++/net_program/src/buffer.c -o CMakeFiles/httpserver_demo.dir/buffer.c.s

src/CMakeFiles/httpserver_demo.dir/channel.c.o: src/CMakeFiles/httpserver_demo.dir/flags.make
src/CMakeFiles/httpserver_demo.dir/channel.c.o: ../src/channel.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wen/vscode_c++/net_program/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/CMakeFiles/httpserver_demo.dir/channel.c.o"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/httpserver_demo.dir/channel.c.o   -c /home/wen/vscode_c++/net_program/src/channel.c

src/CMakeFiles/httpserver_demo.dir/channel.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/httpserver_demo.dir/channel.c.i"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wen/vscode_c++/net_program/src/channel.c > CMakeFiles/httpserver_demo.dir/channel.c.i

src/CMakeFiles/httpserver_demo.dir/channel.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/httpserver_demo.dir/channel.c.s"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wen/vscode_c++/net_program/src/channel.c -o CMakeFiles/httpserver_demo.dir/channel.c.s

src/CMakeFiles/httpserver_demo.dir/channel_map.c.o: src/CMakeFiles/httpserver_demo.dir/flags.make
src/CMakeFiles/httpserver_demo.dir/channel_map.c.o: ../src/channel_map.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wen/vscode_c++/net_program/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/CMakeFiles/httpserver_demo.dir/channel_map.c.o"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/httpserver_demo.dir/channel_map.c.o   -c /home/wen/vscode_c++/net_program/src/channel_map.c

src/CMakeFiles/httpserver_demo.dir/channel_map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/httpserver_demo.dir/channel_map.c.i"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wen/vscode_c++/net_program/src/channel_map.c > CMakeFiles/httpserver_demo.dir/channel_map.c.i

src/CMakeFiles/httpserver_demo.dir/channel_map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/httpserver_demo.dir/channel_map.c.s"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wen/vscode_c++/net_program/src/channel_map.c -o CMakeFiles/httpserver_demo.dir/channel_map.c.s

src/CMakeFiles/httpserver_demo.dir/event_loop.c.o: src/CMakeFiles/httpserver_demo.dir/flags.make
src/CMakeFiles/httpserver_demo.dir/event_loop.c.o: ../src/event_loop.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wen/vscode_c++/net_program/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object src/CMakeFiles/httpserver_demo.dir/event_loop.c.o"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/httpserver_demo.dir/event_loop.c.o   -c /home/wen/vscode_c++/net_program/src/event_loop.c

src/CMakeFiles/httpserver_demo.dir/event_loop.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/httpserver_demo.dir/event_loop.c.i"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wen/vscode_c++/net_program/src/event_loop.c > CMakeFiles/httpserver_demo.dir/event_loop.c.i

src/CMakeFiles/httpserver_demo.dir/event_loop.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/httpserver_demo.dir/event_loop.c.s"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wen/vscode_c++/net_program/src/event_loop.c -o CMakeFiles/httpserver_demo.dir/event_loop.c.s

src/CMakeFiles/httpserver_demo.dir/event_loop_thread.c.o: src/CMakeFiles/httpserver_demo.dir/flags.make
src/CMakeFiles/httpserver_demo.dir/event_loop_thread.c.o: ../src/event_loop_thread.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wen/vscode_c++/net_program/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object src/CMakeFiles/httpserver_demo.dir/event_loop_thread.c.o"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/httpserver_demo.dir/event_loop_thread.c.o   -c /home/wen/vscode_c++/net_program/src/event_loop_thread.c

src/CMakeFiles/httpserver_demo.dir/event_loop_thread.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/httpserver_demo.dir/event_loop_thread.c.i"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wen/vscode_c++/net_program/src/event_loop_thread.c > CMakeFiles/httpserver_demo.dir/event_loop_thread.c.i

src/CMakeFiles/httpserver_demo.dir/event_loop_thread.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/httpserver_demo.dir/event_loop_thread.c.s"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wen/vscode_c++/net_program/src/event_loop_thread.c -o CMakeFiles/httpserver_demo.dir/event_loop_thread.c.s

src/CMakeFiles/httpserver_demo.dir/http_request.c.o: src/CMakeFiles/httpserver_demo.dir/flags.make
src/CMakeFiles/httpserver_demo.dir/http_request.c.o: ../src/http_request.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wen/vscode_c++/net_program/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object src/CMakeFiles/httpserver_demo.dir/http_request.c.o"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/httpserver_demo.dir/http_request.c.o   -c /home/wen/vscode_c++/net_program/src/http_request.c

src/CMakeFiles/httpserver_demo.dir/http_request.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/httpserver_demo.dir/http_request.c.i"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wen/vscode_c++/net_program/src/http_request.c > CMakeFiles/httpserver_demo.dir/http_request.c.i

src/CMakeFiles/httpserver_demo.dir/http_request.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/httpserver_demo.dir/http_request.c.s"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wen/vscode_c++/net_program/src/http_request.c -o CMakeFiles/httpserver_demo.dir/http_request.c.s

src/CMakeFiles/httpserver_demo.dir/http_response.c.o: src/CMakeFiles/httpserver_demo.dir/flags.make
src/CMakeFiles/httpserver_demo.dir/http_response.c.o: ../src/http_response.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wen/vscode_c++/net_program/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object src/CMakeFiles/httpserver_demo.dir/http_response.c.o"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/httpserver_demo.dir/http_response.c.o   -c /home/wen/vscode_c++/net_program/src/http_response.c

src/CMakeFiles/httpserver_demo.dir/http_response.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/httpserver_demo.dir/http_response.c.i"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wen/vscode_c++/net_program/src/http_response.c > CMakeFiles/httpserver_demo.dir/http_response.c.i

src/CMakeFiles/httpserver_demo.dir/http_response.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/httpserver_demo.dir/http_response.c.s"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wen/vscode_c++/net_program/src/http_response.c -o CMakeFiles/httpserver_demo.dir/http_response.c.s

src/CMakeFiles/httpserver_demo.dir/http_server.c.o: src/CMakeFiles/httpserver_demo.dir/flags.make
src/CMakeFiles/httpserver_demo.dir/http_server.c.o: ../src/http_server.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wen/vscode_c++/net_program/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object src/CMakeFiles/httpserver_demo.dir/http_server.c.o"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/httpserver_demo.dir/http_server.c.o   -c /home/wen/vscode_c++/net_program/src/http_server.c

src/CMakeFiles/httpserver_demo.dir/http_server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/httpserver_demo.dir/http_server.c.i"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wen/vscode_c++/net_program/src/http_server.c > CMakeFiles/httpserver_demo.dir/http_server.c.i

src/CMakeFiles/httpserver_demo.dir/http_server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/httpserver_demo.dir/http_server.c.s"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wen/vscode_c++/net_program/src/http_server.c -o CMakeFiles/httpserver_demo.dir/http_server.c.s

src/CMakeFiles/httpserver_demo.dir/poll_dispatcher.c.o: src/CMakeFiles/httpserver_demo.dir/flags.make
src/CMakeFiles/httpserver_demo.dir/poll_dispatcher.c.o: ../src/poll_dispatcher.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wen/vscode_c++/net_program/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object src/CMakeFiles/httpserver_demo.dir/poll_dispatcher.c.o"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/httpserver_demo.dir/poll_dispatcher.c.o   -c /home/wen/vscode_c++/net_program/src/poll_dispatcher.c

src/CMakeFiles/httpserver_demo.dir/poll_dispatcher.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/httpserver_demo.dir/poll_dispatcher.c.i"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wen/vscode_c++/net_program/src/poll_dispatcher.c > CMakeFiles/httpserver_demo.dir/poll_dispatcher.c.i

src/CMakeFiles/httpserver_demo.dir/poll_dispatcher.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/httpserver_demo.dir/poll_dispatcher.c.s"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wen/vscode_c++/net_program/src/poll_dispatcher.c -o CMakeFiles/httpserver_demo.dir/poll_dispatcher.c.s

src/CMakeFiles/httpserver_demo.dir/tcp_connection.c.o: src/CMakeFiles/httpserver_demo.dir/flags.make
src/CMakeFiles/httpserver_demo.dir/tcp_connection.c.o: ../src/tcp_connection.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wen/vscode_c++/net_program/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object src/CMakeFiles/httpserver_demo.dir/tcp_connection.c.o"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/httpserver_demo.dir/tcp_connection.c.o   -c /home/wen/vscode_c++/net_program/src/tcp_connection.c

src/CMakeFiles/httpserver_demo.dir/tcp_connection.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/httpserver_demo.dir/tcp_connection.c.i"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wen/vscode_c++/net_program/src/tcp_connection.c > CMakeFiles/httpserver_demo.dir/tcp_connection.c.i

src/CMakeFiles/httpserver_demo.dir/tcp_connection.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/httpserver_demo.dir/tcp_connection.c.s"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wen/vscode_c++/net_program/src/tcp_connection.c -o CMakeFiles/httpserver_demo.dir/tcp_connection.c.s

src/CMakeFiles/httpserver_demo.dir/tcp_server.c.o: src/CMakeFiles/httpserver_demo.dir/flags.make
src/CMakeFiles/httpserver_demo.dir/tcp_server.c.o: ../src/tcp_server.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wen/vscode_c++/net_program/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object src/CMakeFiles/httpserver_demo.dir/tcp_server.c.o"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/httpserver_demo.dir/tcp_server.c.o   -c /home/wen/vscode_c++/net_program/src/tcp_server.c

src/CMakeFiles/httpserver_demo.dir/tcp_server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/httpserver_demo.dir/tcp_server.c.i"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wen/vscode_c++/net_program/src/tcp_server.c > CMakeFiles/httpserver_demo.dir/tcp_server.c.i

src/CMakeFiles/httpserver_demo.dir/tcp_server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/httpserver_demo.dir/tcp_server.c.s"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wen/vscode_c++/net_program/src/tcp_server.c -o CMakeFiles/httpserver_demo.dir/tcp_server.c.s

src/CMakeFiles/httpserver_demo.dir/thread_pool.c.o: src/CMakeFiles/httpserver_demo.dir/flags.make
src/CMakeFiles/httpserver_demo.dir/thread_pool.c.o: ../src/thread_pool.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wen/vscode_c++/net_program/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object src/CMakeFiles/httpserver_demo.dir/thread_pool.c.o"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/httpserver_demo.dir/thread_pool.c.o   -c /home/wen/vscode_c++/net_program/src/thread_pool.c

src/CMakeFiles/httpserver_demo.dir/thread_pool.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/httpserver_demo.dir/thread_pool.c.i"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wen/vscode_c++/net_program/src/thread_pool.c > CMakeFiles/httpserver_demo.dir/thread_pool.c.i

src/CMakeFiles/httpserver_demo.dir/thread_pool.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/httpserver_demo.dir/thread_pool.c.s"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wen/vscode_c++/net_program/src/thread_pool.c -o CMakeFiles/httpserver_demo.dir/thread_pool.c.s

src/CMakeFiles/httpserver_demo.dir/utils.c.o: src/CMakeFiles/httpserver_demo.dir/flags.make
src/CMakeFiles/httpserver_demo.dir/utils.c.o: ../src/utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wen/vscode_c++/net_program/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object src/CMakeFiles/httpserver_demo.dir/utils.c.o"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/httpserver_demo.dir/utils.c.o   -c /home/wen/vscode_c++/net_program/src/utils.c

src/CMakeFiles/httpserver_demo.dir/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/httpserver_demo.dir/utils.c.i"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wen/vscode_c++/net_program/src/utils.c > CMakeFiles/httpserver_demo.dir/utils.c.i

src/CMakeFiles/httpserver_demo.dir/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/httpserver_demo.dir/utils.c.s"
	cd /home/wen/vscode_c++/net_program/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wen/vscode_c++/net_program/src/utils.c -o CMakeFiles/httpserver_demo.dir/utils.c.s

# Object files for target httpserver_demo
httpserver_demo_OBJECTS = \
"CMakeFiles/httpserver_demo.dir/acceptor.c.o" \
"CMakeFiles/httpserver_demo.dir/buffer.c.o" \
"CMakeFiles/httpserver_demo.dir/channel.c.o" \
"CMakeFiles/httpserver_demo.dir/channel_map.c.o" \
"CMakeFiles/httpserver_demo.dir/event_loop.c.o" \
"CMakeFiles/httpserver_demo.dir/event_loop_thread.c.o" \
"CMakeFiles/httpserver_demo.dir/http_request.c.o" \
"CMakeFiles/httpserver_demo.dir/http_response.c.o" \
"CMakeFiles/httpserver_demo.dir/http_server.c.o" \
"CMakeFiles/httpserver_demo.dir/poll_dispatcher.c.o" \
"CMakeFiles/httpserver_demo.dir/tcp_connection.c.o" \
"CMakeFiles/httpserver_demo.dir/tcp_server.c.o" \
"CMakeFiles/httpserver_demo.dir/thread_pool.c.o" \
"CMakeFiles/httpserver_demo.dir/utils.c.o"

# External object files for target httpserver_demo
httpserver_demo_EXTERNAL_OBJECTS =

src/libhttpserver_demo.a: src/CMakeFiles/httpserver_demo.dir/acceptor.c.o
src/libhttpserver_demo.a: src/CMakeFiles/httpserver_demo.dir/buffer.c.o
src/libhttpserver_demo.a: src/CMakeFiles/httpserver_demo.dir/channel.c.o
src/libhttpserver_demo.a: src/CMakeFiles/httpserver_demo.dir/channel_map.c.o
src/libhttpserver_demo.a: src/CMakeFiles/httpserver_demo.dir/event_loop.c.o
src/libhttpserver_demo.a: src/CMakeFiles/httpserver_demo.dir/event_loop_thread.c.o
src/libhttpserver_demo.a: src/CMakeFiles/httpserver_demo.dir/http_request.c.o
src/libhttpserver_demo.a: src/CMakeFiles/httpserver_demo.dir/http_response.c.o
src/libhttpserver_demo.a: src/CMakeFiles/httpserver_demo.dir/http_server.c.o
src/libhttpserver_demo.a: src/CMakeFiles/httpserver_demo.dir/poll_dispatcher.c.o
src/libhttpserver_demo.a: src/CMakeFiles/httpserver_demo.dir/tcp_connection.c.o
src/libhttpserver_demo.a: src/CMakeFiles/httpserver_demo.dir/tcp_server.c.o
src/libhttpserver_demo.a: src/CMakeFiles/httpserver_demo.dir/thread_pool.c.o
src/libhttpserver_demo.a: src/CMakeFiles/httpserver_demo.dir/utils.c.o
src/libhttpserver_demo.a: src/CMakeFiles/httpserver_demo.dir/build.make
src/libhttpserver_demo.a: src/CMakeFiles/httpserver_demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wen/vscode_c++/net_program/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking C static library libhttpserver_demo.a"
	cd /home/wen/vscode_c++/net_program/build/src && $(CMAKE_COMMAND) -P CMakeFiles/httpserver_demo.dir/cmake_clean_target.cmake
	cd /home/wen/vscode_c++/net_program/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/httpserver_demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/httpserver_demo.dir/build: src/libhttpserver_demo.a

.PHONY : src/CMakeFiles/httpserver_demo.dir/build

src/CMakeFiles/httpserver_demo.dir/clean:
	cd /home/wen/vscode_c++/net_program/build/src && $(CMAKE_COMMAND) -P CMakeFiles/httpserver_demo.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/httpserver_demo.dir/clean

src/CMakeFiles/httpserver_demo.dir/depend:
	cd /home/wen/vscode_c++/net_program/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wen/vscode_c++/net_program /home/wen/vscode_c++/net_program/src /home/wen/vscode_c++/net_program/build /home/wen/vscode_c++/net_program/build/src /home/wen/vscode_c++/net_program/build/src/CMakeFiles/httpserver_demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/httpserver_demo.dir/depend

