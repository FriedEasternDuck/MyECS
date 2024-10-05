cmake_minimum_required(VERSION 3.29)
project(MyECS)

set(CMAKE_CXX_STANDARD 20)

add_executable(MyECS main.cpp
        Code/src/EntityManager.cpp
        Code/includes/EntityManager.h
        Code/src/Components.cpp
        Code/includes/Components.h
        Code/src/Scene.cpp
        Code/includes/Scene.h
        Code/src/ComponentPool.cpp
        Code/includes/ComponentPool.h
        Code/src/PhysicsSystem.cpp
        Code/includes/PhysicsSystem.h
        Code/includes/SystemBase.h)


find_package(glad CONFIG REQUIRED)
target_link_libraries(MyECS PRIVATE glad::glad)
find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(MyECS PRIVATE glfw)
find_package(glm CONFIG REQUIRED)
target_link_libraries(MyECS PRIVATE glm::glm)