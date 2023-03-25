aux_source_directory(. tcpClient)

add_library(tcpClient ${tcpClient})

target_include_directories(tcpClient PRIVATE ./include)
