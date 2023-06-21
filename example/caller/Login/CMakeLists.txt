set(CMAKE_BUILD_TYPE "Debug")
set(SRC_LIST calluserservice.cc)

add_executable(caller ${SRC_LIST})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/mprpc)
target_link_libraries(caller PUBLIC mprpc mymuduo protobuf mylogger)