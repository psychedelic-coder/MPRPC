set(CMAKE_BUILD_TYPE "Debug")
set(SRC_LIST friendservice.cc ../../../mprpc/src/friend.pb.cc)

add_executable(get_f_list ${SRC_LIST})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/mprpc)
target_link_libraries(get_f_list PUBLIC mprpc mymuduo protobuf mylogger)