cmake_minimum_required(VERSION 2.6)
project(automy-basic)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC -pthread")

include_directories(
	/usr/include/automy/
)

file(GLOB GENERATED_SOURCE_FILES generated/src/*.cpp)

add_library(automy_basic SHARED
	${GENERATED_SOURCE_FILES}
	src/Image.cpp
	src/Image8.cpp
	src/Image16.cpp
	src/Image32.cpp
	src/ImageF32.cpp
	src/ImageF64.cpp
	src/ImageFrame.cpp
)

target_include_directories(automy_basic PUBLIC include generated/include PRIVATE src/)

target_link_libraries(automy_basic automy_math vnx_base png jpeg)

install(DIRECTORY include/ DESTINATION include/automy)
install(DIRECTORY generated/include/ DESTINATION include/automy)
install(DIRECTORY interface/ DESTINATION interface/automy/basic)

install(TARGETS automy_basic DESTINATION lib)
