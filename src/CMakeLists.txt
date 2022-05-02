add_library(src InputEvent.cpp)

target_link_libraries(src
     PUBLIC glfw
     PUBLIC glad
     # PUBLIC source
)