#pragma once

#include <atomic>

namespace spinlock {

class TTCSpinlock {
public:
    void lock() {
        while (flag_.test(std::memory_order_relaxed) ||
               flag_.test_and_set(std::memory_order_acquire)) {
        }
    }

    void unlock() {
        flag_.clear(std::memory_order_release);
    }

private:
    std::atomic_flag flag_ = false;
};

}  // namespace spinlock
