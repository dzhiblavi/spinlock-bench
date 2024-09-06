add_executable(bench.spinlocks bench.cpp)

target_link_libraries(
  bench.spinlocks PRIVATE
  benchmark::benchmark dlib::options dlib::test dlib::spinlock)
