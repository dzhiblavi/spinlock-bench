add_library(dlib-test INTERFACE)
add_library(dlib::test ALIAS dlib-test)

target_include_directories(dlib-test INTERFACE $<BUILD_INTERFACE:${DLIB_SOURCE_DIR}/test/include/>)
target_include_directories(dlib-test SYSTEM INTERFACE $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/test/include/>)
