#include "../exercise.h"

struct Fibonacci {
    unsigned long long cache[128];
    int cached;

    // TODO: 实现正确的缓存优化斐波那契计算
    unsigned long long get(int i) {
        for (int j = 0; j < cached; ++j) {
            if (j == i) {
                return cache[j];
            }
        }
        ASSERT(i < 128, "i should be less than 128");
        cache[i] = (i < 2) ? i : (get(i - 1) + get(i - 2));
        cached = std::max(cached, i + 1);
        ASSERT(cached <= 128, "cached should not exceed 128");
        return cache[i];
    }
};

int main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    Fibonacci fib{{0, 1}, 2};
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}
