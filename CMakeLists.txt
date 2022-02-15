cmake_minimum_required(VERSION 3.16)
project(dll_learn)

set(CMAKE_CXX_STANDARD 20)

add_definitions(-DVAR="./cmake/libout/debug/")
find_path(my_dll_path NAMES "my_dll.dll" PATHS "${CMAKE_CACHEFILE_DIR}/lib_out/Debug" NO_DEFAULT_PATH)

if("${my_dll_path}" STREQUAL "my_dll_path-NOTFOUND")
    set(dll_path "./my_dll.dll")
else()
    string(CONCAT dll_path ${my_dll_path} "/my_dll.dll")
    add_definitions(-DMY_DLL="${dll_path}")
endif()
message("my_dll is: ${dll_path}")

ADD_SUBDIRECTORY(lib)

add_executable(run_dll run_dll.cpp)
