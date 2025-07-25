#include "../exercise.h"

// READ: Trivial type <https://learn.microsoft.com/zh-cn/cpp/cpp/trivial-standard-layout-and-pod-types?view=msvc-170>

struct FibonacciCache {
    unsigned long long cache[16];
    int cached;
};

// TODO: 实现正确的缓存优化斐波那契计算
static unsigned long long fibonacci(FibonacciCache &cache, int i) {
    for (int j = 0; j < cache.cached; ++j) {
        if (j == i) {
            return cache.cache[j];
        }
    }
    ASSERT(i < 16, "i should be less than 16");
    cache.cache[i] = (i < 2) ? i : (fibonacci(cache, i - 1) + fibonacci(cache, i - 2));
    cache.cached = std::max(cache.cached, i + 1);
    ASSERT(cache.cached <= 16, "cached should not exceed 16");
    return cache.cache[i];
}

int main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    // NOTICE: C/C++ 中，读取未初始化的变量（包括结构体变量）是未定义行为
    // READ: 初始化的各种写法 <https://zh.cppreference.com/w/cpp/language/initialization>
    FibonacciCache fib{{0, 1}, 0};
    ASSERT(fibonacci(fib, 10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fibonacci(fib, 10) << std::endl;
    return 0;
}
