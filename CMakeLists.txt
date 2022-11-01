cmake_minimum_required(VERSION 3.23)
project(Fractals)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(SOURCE_FILES main.cpp App.cpp App.hpp Fractal.hpp Settings.hpp Julia.cpp Julia.hpp Fractal.cpp Mandelbrot.cpp Mandelbrot.hpp BurningShip.cpp BurningShip.hpp Newton.cpp Newton.hpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

set(OPENMP_LIBRARIES "/opt/homebrew/Cellar/libomp/15.0.3/lib/libomp.dylib")
set(OPENMP_INCLUDES "/opt/homebrew/Cellar/libomp/15.0.3/include")
include_directories(${OPENMP_INCLUDES})
target_link_libraries(${PROJECT_NAME} ${OPENMP_LIBRARIES})