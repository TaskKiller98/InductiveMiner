include_directories(../src)

include_directories(.)

add_executable(tests
        # test sources
        Tools_test.cpp
        Components_test.cpp
        Inductive_test.cpp
        # task sources
        ../src/tools/Event.cpp
        ../src/tools/Footprint.cpp
        ../src/tools/Trace.cpp
        ../src/components/Component.cpp
        ../src/components/Node.cpp
        ../src/components/Petri_net.cpp
        ../src/Inductive_miner_algorithm.cpp
        # gtest sources
        gtest/gtest-all.cc
        gtest/gtest_main.cc
        )

# add pthread for unix systems
if (UNIX)
    target_link_libraries(tests pthread)
endif ()