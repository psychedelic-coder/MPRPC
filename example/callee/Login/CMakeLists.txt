set(CMAKE_BUILD_TYPE "Debug")
set(SRC_LIST userservice.cc ../../../mprpc/src/user.pb.cc)

add_executable(provider ${SRC_LIST})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/mprpc)
target_link_libraries(provider PUBLIC mprpc mymuduo protobuf mylogger)