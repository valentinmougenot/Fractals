cmake_minimum_required(VERSION 3.23)
project(Fractals)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(SOURCE_FILES src/main.cpp src/App.cpp includes/App.hpp includes/Fractal.hpp includes/Settings.hpp src/Julia.cpp includes/Julia.hpp src/Fractal.cpp src/Mandelbrot.cpp includes/Mandelbrot.hpp src/BurningShip.cpp includes/BurningShip.hpp src/Newton.cpp includes/Newton.hpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio sfml-network)