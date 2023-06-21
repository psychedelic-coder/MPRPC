#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -fPIE")
file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cc include/*.h)
add_library(mprpc ${srcs})
#target_compile_options(mprpc PUBLIC -fpie)
target_link_libraries(mprpc PUBLIC mymuduo pthread mylogger)
#动态库mprpc target头文件搜索路径为include文件夹
target_include_directories(mprpc PUBLIC include)
# 最终编译成so动态库，设置动态库的路径,放在根目录的lib文件夹下
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/mprpc)
# 设置项目库文件搜索路径
link_directories((${PROJECT_SOURCE_DIR}/lib))
