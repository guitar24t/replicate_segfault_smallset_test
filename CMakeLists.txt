cmake_minimum_required(VERSION 3.8)
set(PROJECT_NAME "testlib")
project(${PROJECT_NAME})

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -Wno-psabi)
endif()

find_package (wpimath REQUIRED CONFIG)
find_package (wpiutil REQUIRED CONFIG)
find_package (wpilibc REQUIRED CONFIG)
find_package (wpilibNewCommands REQUIRED CONFIG)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC
  /usr/local/include/wpimath
  /usr/local/include/wpiutil
  /usr/local/include/wpilibc
  /usr/local/include/wpilibNewCommands
)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O0")

target_link_libraries(${PROJECT_NAME} wpimath wpiutil wpilibc wpilibNewCommands /usr/local/lib/libpathplannerlib.a)
target_compile_features(${PROJECT_NAME} PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17