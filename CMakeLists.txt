cmake_minimum_required(VERSION 3.12)

project(minecraft VERSION 0.01)

add_executable(minecraft main.cpp)

add_subdirectory(extern/glfw)
add_subdirectory(glad)
add_subdirectory(src)

target_include_directories(${PROJECT_NAME}
     PRIVATE extern/glfw/include
     # PRIVATE src
)

target_link_directories(${PROJECT_NAME} 
     PRIVATE extern/glfw/src
)

target_link_libraries(${PROJECT_NAME} 
     PUBLIC glfw
     PUBLIC glad
     PUBLIC src
)
