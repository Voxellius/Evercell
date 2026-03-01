cmake_minimum_required(VERSION 3.15)
project(EvercellSDL2Target LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)

file(GLOB EVERCELL_SOURCES
    ${CMAKE_SOURCE_DIR}/../../src/*.cpp
    ${CMAKE_SOURCE_DIR}/../../src/*.h
)

add_library(Evercell STATIC ${EVERCELL_SOURCES})
set_target_properties(Evercell PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(Evercell PUBLIC ${CMAKE_SOURCE_DIR}/../../src)

find_package(SDL2 REQUIRED)
include_directories(evercell ${SDL2_INCLUDE_DIRS})

file(GLOB SOURCES
    ${CMAKE_SOURCE_DIR}/*.cpp
    ${CMAKE_SOURCE_DIR}/*.h
    ${CMAKE_SOURCE_DIR}/../../profiles/3510i/*.h
    ${CMAKE_SOURCE_DIR}/../../personalities/evercell/build/*.h
)

add_executable(evercell ${SOURCES})
target_include_directories(Evercell PUBLIC ${CMAKE_SOURCE_DIR}/../../profiles/3510i)
target_include_directories(Evercell PUBLIC ${CMAKE_SOURCE_DIR}/../../personalities/evercell/build)
target_link_libraries(evercell PRIVATE Evercell ${SDL2_LIBRARIES})