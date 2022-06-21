cmake_minimum_required(VERSION 3.17)

project(Wither VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3 -ggdb")

include_directories(
    ./
    ./include
)

link_libraries(boost_iostreams)

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Gui)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
# qt_standard_project_setup()

file(GLOB_RECURSE SRC
    main.cpp
    src/*.cpp
)

configure_file(WitherConfig.h.in WitherConfig.h)

add_executable(${PROJECT_NAME} ${SRC})

target_include_directories(Wither PUBLIC
    "${PROJECT_BINARY_DIR}"
)

target_link_libraries(Wither PRIVATE Qt6::Core)
target_link_libraries(Wither PRIVATE Qt6::Gui)
target_link_libraries(Wither PRIVATE Qt6::Widgets)
