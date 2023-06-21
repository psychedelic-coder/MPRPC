file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cc include/*.h)
add_library(mylogger ${srcs})
target_include_directories(mylogger PUBLIC include)
# mylogger最终编译成静态库，设置动态库的路径,放在根目录的lib文件夹下
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/mylogger)

find_package(Threads REQUIRED)

target_link_libraries(mylogger PUBLIC Threads::Threads)

#enable_testing() # 打开测试

add_subdirectory(test) # 添加test子目录