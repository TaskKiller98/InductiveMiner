include_directories(../src)

include_directories(.)

add_executable(tests
        # list tests
        Algortihm_B_test.cpp
        # list sources
        ../src/Inductive_miner_algorithm.cpp
        ../src/Inductive_miner_algorithm.h
        # gtest sources
        gtest/gtest-all.cc
        gtest/gtest_main.cc
        )

# add pthread for unix systems
if (UNIX)
    target_link_libraries(tests pthread)
endif ()