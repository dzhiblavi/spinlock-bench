#pragma once

#include <benchmark/benchmark.h>
#include <mutex>

namespace test {

template <typename Lock>
concept Lockable = requires(Lock& lock) {
    { lock.lock() };
    { lock.unlock() };
};

template <Lockable Lock>
void benchLock(benchmark::State& state, Lock& lock, size_t& counter) {
    if (state.thread_index() == 0) {
        counter = 0;
    }

    for (auto _ : state) {
        std::lock_guard lg(lock);
        ++counter;
    }
}

}  // namespace test
