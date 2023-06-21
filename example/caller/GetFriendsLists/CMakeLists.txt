set(CMAKE_BUILD_TYPE "Debug")
set(SRC_LIST callfriendservice.cc)

add_executable(call_f_list ${SRC_LIST})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/mprpc)
target_link_libraries(call_f_list PUBLIC mprpc mymuduo protobuf mylogger)