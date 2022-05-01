cmake_minimum_required(VERSION 3.12)

project(minecraft VERSION 0.01)

add_executable(minecraft main.cpp)

add_subdirectory(extern/glfw)
add_subdirectory(glad)

target_include_directories(${PROJECT_NAME}
     PRIVATE extern/glfw/include
)

target_link_directories(${PROJECT_NAME} 
     PRIVATE extern/glfw/src
)

target_link_libraries(${PROJECT_NAME} 
     glfw
     glad
)
