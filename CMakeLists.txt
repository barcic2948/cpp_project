cmake_minimum_required(VERSION 3.0.0)
project(main VERSION 0.1.0)

include(CTest)
enable_testing()

set(SFML_DIR "C:\\Users\\barci\\Desktop\\SFML-2.5.1")
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(main main.cpp src/game.cpp src/components/component.h  src/components/button.cpp src/components/custom_text.cpp)

target_link_libraries(main sfml-graphics sfml-audio)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set_property(TARGET main PROPERTY CXX_STANDARD 17)
