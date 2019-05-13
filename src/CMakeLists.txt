cmake_minimum_required(VERSION 2.8)

find_package(Git QUIET)

execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        RESULT_VARIABLE GIT_SUBMOD_RESULT)

add_subdirectory(../grpc ${CMAKE_CURRENT_BINARY_DIR}/grpc EXCLUDE_FROM_ALL)
message(STATUS "Using gRPC via add_subdirectory.")

# After using add_subdirectory, we can now use the grpc targets directly from
# this build.
set(_PROTOBUF_LIBPROTOBUF libprotobuf)
set(_PROTOBUF_PROTOC $<TARGET_FILE:protoc>)
set(_GRPC_GRPCPP_UNSECURE grpc++_unsecure)
set(_GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:grpc_cpp_plugin>)

# Proto files
get_filename_component(proto_path "./proto" ABSOLUTE)
get_filename_component(petri_net_proto "./proto/petri_net.proto" ABSOLUTE)
get_filename_component(logs_proto "./proto/logs.proto" ABSOLUTE)
get_filename_component(mining_proto "./proto/mining.proto" ABSOLUTE)

# Generated sources
set(petri_net_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/petri_net.pb.cc")
set(petri_net_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/petri_net.grpc.pb.cc")

set(logs_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/logs.pb.cc")
set(logs_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/logs.grpc.pb.cc")

set(mining_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/mining.pb.cc")
set(mining_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/mining.grpc.pb.cc")

add_custom_command(
        OUTPUT "${petri_net_proto_srcs}" "${petri_net_grpc_srcs}"
        COMMAND ${_PROTOBUF_PROTOC}
        ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
        -I "${proto_path}"
        -I "${CMAKE_CURRENT_SOURCE_DIR}/../grpc/third_party/protobuf/src"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${petri_net_proto}"
        DEPENDS "${petri_net_proto}")

add_custom_command(
        OUTPUT "${logs_proto_srcs}" "${logs_grpc_srcs}"
        COMMAND ${_PROTOBUF_PROTOC}
        ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
        -I "${proto_path}"
        -I "${CMAKE_CURRENT_SOURCE_DIR}/../grpc/third_party/protobuf/src"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${logs_proto}"
        DEPENDS "${logs_proto}")

add_custom_command(
        OUTPUT "${mining_proto_srcs}" "${mining_grpc_srcs}"
        COMMAND ${_PROTOBUF_PROTOC}
        ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
        -I "${proto_path}"
        -I "${CMAKE_CURRENT_SOURCE_DIR}/../grpc/third_party/protobuf/src"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${mining_proto}"
        DEPENDS "${mining_proto}")

# Include generated *.pb.h files
include_directories("${CMAKE_CURRENT_BINARY_DIR}")

add_executable(
        main
        Inductive_miner_algorithm.cpp
        Inductive_miner_algorithm.h
        main.cpp
        tools/Event.cpp
        tools/Event.h
        tools/Footprint.cpp
        tools/Footprint.h
        tools/ProcessTree.h
        tools/ProcessTree.cpp
        tools/Trace.cpp
        tools/Trace.h
        components/Component.h
        components/Component.cpp
        components/Node.cpp
        components/Node.h
        components/Petri_net.h
        components/Petri_net.cpp
        ${petri_net_proto_srcs}
        ${petri_net_grpc_srcs}
        ${logs_proto_srcs}
        ${logs_grpc_srcs}
        ${mining_proto_srcs}
        ${mining_grpc_srcs}
)

target_link_libraries(main
        ${_GRPC_GRPCPP_UNSECURE}
        ${_PROTOBUF_LIBPROTOBUF})