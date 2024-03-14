set(SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})

file(GLOB_RECURSE HEADER ${SOURCE_DIR}/*.h)
file(GLOB_RECURSE SOURCE ${SOURCE_DIR}/*.cpp)
list(REMOVE_ITEM SOURCE ${SOURCE_DIR}/python_interface.cpp)

find_package(pybind11 REQUIRED)

# CMAKE_INSTALL_PREFIX=$(python3 -c “import sys; print(sys.prefix)”)
pybind11_add_module(redmax python_interface.cpp ${HEADER} ${SOURCE})

find_package(Eigen3 REQUIRED)

# Includes.
target_include_directories(redmax PRIVATE ${EXTERNAL_HEADER})
target_include_directories(redmax PRIVATE ${SOURCE_DIR}/)
target_link_libraries(redmax PRIVATE sdfgen)
target_link_libraries(redmax PRIVATE Eigen3::Eigen)
# 
# # Add libs.

set(CMAKE_CXX_STANDARD_LIBRARIES -ldl)
set(CMAKE_VERBOSE_MAKEFILE ON)

