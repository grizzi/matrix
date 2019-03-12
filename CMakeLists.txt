cmake_minimum_required(VERSION 2.8)
project(matrix)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
add_library(matrix matrix.cpp)

add_executable(main main.cpp)
target_link_libraries(main matrix)

# make install to install targets
install(TARGETS matrix DESTINATION lib/)
install(TARGETS main DESTINATION bin/)
install(FILES matrix.h DESTINATION include/)
