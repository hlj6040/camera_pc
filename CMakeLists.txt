cmake_minimum_required(VERSION 3.16.3)

project(camera_project)

aux_source_directory(. cameraSrc)

add_subdirectory(tcpClient)

add_executable(camera ${cameraSrc})

target_include_directories(camera PRIVATE ./tcpClient/include)

target_link_libraries(camera tcpClient)