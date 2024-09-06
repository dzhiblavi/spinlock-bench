add_library(dlib-spinlock INTERFACE)
add_library(dlib::spinlock ALIAS dlib-spinlock)

target_include_directories(dlib-spinlock INTERFACE $<BUILD_INTERFACE:${DLIB_SOURCE_DIR}/include/spinlock/>)
target_include_directories(dlib-spinlock SYSTEM INTERFACE $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/include/spinlock/>)
