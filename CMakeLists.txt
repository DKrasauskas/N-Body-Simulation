cmake_minimum_required(VERSION 3.26)
project(test)

set(CMAKE_CXX_STANDARD 17)
add_executable(test main.cpp
        utils/parser.h
        utils/Vertices.h
        config/Window.h
        GPU/Shaders/Shader.cpp
        GPU/Shaders/Shader.h
        CPU/Render/Render.cpp
        CPU/Render/Render.h
        CPU/Objects/Obj/Obj.h
        CPU/Objects/Obj/Shapes.cpp
        CPU/Objects/Obj/Shapes.h
        utils/spheres.h
        CPU/Objects/Obj/ElementaryShapes.cpp
        CPU/Objects/Obj/ElementaryShapes.h
        CPU/Objects/Obj/Generator.h
        CPU/Objects/Obj/SP.h
        CPU/Render/Program.h
        CPU/Objects/Shapes/Shapes.cpp
        CPU/Objects/Shapes/Shapes.h
        CPU/Objects/Item.cpp
        CPU/Objects/Item.h
        CPU/Controls/Mouse.cpp
        CPU/Controls/Mouse.h
        CPU/Controls/Camera.cpp
        CPU/Controls/Camera.h
        CPU/Transformations/Rotations/Quaternions.cpp
        CPU/Transformations/Rotations/Quaternions.h
        CPU/Transformations/Basis.cpp
        CPU/Transformations/Basis.h
        CPU/Controls/Settings.h
        CPU/Objects/Features.h
        CPU/Physics.cpp
        CPU/Physics.h
        CPU/DataStructures.cpp
        CPU/DataStructures.h
        CPU/Objects/Shapes/Feature.cpp
        CPU/Objects/Shapes/Feature.h
        Glad/glad.c
)
target_link_libraries(test lib/glfw3)
