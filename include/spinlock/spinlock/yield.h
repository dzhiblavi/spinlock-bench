#pragma once

#include <atomic>
#include <ctime>

namespace spinlock {

class YieldingSpinlock {
public:
    void lock() {
        int counter = 0;

        while (flag_.test(std::memory_order_relaxed) ||
               flag_.test_and_set(std::memory_order_acquire)) {
            if (++counter == 8) {
                counter = 0;
                yield();
            }
        }
    }

    void unlock() {
        flag_.clear(std::memory_order_release);
    }

private:
    static void yield() {
        static constexpr std::timespec kNanosecond{0, 1};
        ::nanosleep(&kNanosecond, nullptr);
    }

    std::atomic_flag flag_ = false;
};

}  // namespace spinlock
