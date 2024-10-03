#include <iostream>
#include <chrono>

template<void op()>
void measureTime() {
    const auto start{std::chrono::steady_clock::now()};
    op();
    const auto end{std::chrono::steady_clock::now()};
    const std::chrono::nanoseconds elapsed_time{end - start};
    std::cout << "Took time: " << elapsed_time.count() << " ns." << std::endl;
}

template<typename T, T op()>
void measureTime() {
    const auto start{std::chrono::steady_clock::now()};
    std::cout << "Result: " << op() << std::endl;
    const auto end{std::chrono::steady_clock::now()};
    const std::chrono::nanoseconds elapsed_time{end - start};
    std::cout << "Took time: " << elapsed_time.count() << " ns." << std::endl;
}

void print_sum() {
    std::cout << "Result: " << 1234 + 4321 << std::endl;
}

int return_sum() {
    return 1234 + 4321;
}

int main() {
    measureTime<print_sum>();
    measureTime<int, return_sum>();
    
    return 0;
}