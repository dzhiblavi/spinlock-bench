#include "spinlock/naive.h"
#include "spinlock/test-then-cas.h"
#include "spinlock/yield.h"
#include "test/bench_lock.h"

#include <benchmark/benchmark.h>

namespace spinlock::bench {

size_t counter = 0;
std::mutex mutex;
NaiveSpinlock naive_spinlock;
TTCSpinlock ttc_spinlock;
YieldingSpinlock yielding_spinlock;

static void BM_standardMutex(benchmark::State& state) {
    test::benchLock(state, mutex, counter);
}

static void BM_naiveSpinlock(benchmark::State& state) {
    test::benchLock(state, naive_spinlock, counter);
}

static void BM_testThenCasSpinlock(benchmark::State& state) {
    test::benchLock(state, ttc_spinlock, counter);
}

static void BM_yieldingSpinlock(benchmark::State& state) {
    test::benchLock(state, yielding_spinlock, counter);
}

BENCHMARK(BM_standardMutex)->Threads(6)->UseRealTime();
BENCHMARK(BM_naiveSpinlock)->Threads(6)->UseRealTime();
BENCHMARK(BM_testThenCasSpinlock)->Threads(6)->UseRealTime();
BENCHMARK(BM_yieldingSpinlock)->Threads(6)->UseRealTime();

}  // namespace spinlock::bench

BENCHMARK_MAIN();
