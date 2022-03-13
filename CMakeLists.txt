cmake_minimum_required(VERSION 3.10)

project(seedTable-build)

find_package(Boost COMPONENTS program_options REQUIRED)

find_package(ZLIB REQUIRED)
find_path(ZLIB_INCLUDE_DIR zlib.h)
include_directories(${ZLIB_INCLUDE_DIR})

include(${TBB_DIR}/cmake/TBBBuild.cmake)
tbb_build(TBB_ROOT ${TBB_DIR} CONFIG_DIR TBB_DIR MAKE_ARGS tbb_cpf=1)
find_package(TBB REQUIRED tbbmalloc tbbmalloc_proxy tbb_preview)

add_executable (SankOff
    src/sankoff.cpp
    src/main.cpp)

target_link_libraries(SankOff PRIVATE ${Boost_LIBRARIES} ${ZLIB_LIBRARIES} ${TBB_IMPORTED_TARGETS})