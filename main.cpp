#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>
#include <vector>
#include <format>

template<typename T>
T generateRandomNumber(T min = 1, T max = 100) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<T> dis(min, max);
    return dis(gen);
}

int main(int argc, char* argv[]) {
    std::cout << "CTEST_FULL_OUTPUT\n";
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <iteration_count> <vector_max_size>\n";
        return 1;
    }

    int iteration_count = std::stoi(argv[1]);
    int vector_max_size = std::stoi(argv[2]);

    if (iteration_count <= 0 || vector_max_size <= 0) {
        std::cerr << "Both iteration count and size increment step size must be positive integers.\n";
        return 1;
    }

    const int STEP_COUNT = 16;
    int size_increment_step = vector_max_size / STEP_COUNT;
    
    std::vector<int> numbers;
    volatile int sink = 0;
    
    for (int i = 0; i < STEP_COUNT; i++)
    {
        for (int j = 0; j < size_increment_step; j++) numbers.push_back(generateRandomNumber(1, 10000));
        
        auto start = std::chrono::high_resolution_clock::now();
        for (int k = 0; k < iteration_count; k++) sink += numbers[(-k) % (long long)numbers.size() + (long long)numbers.size()];  
        auto seq_duration = std::chrono::high_resolution_clock::now() - start;

        start = std::chrono::high_resolution_clock::now();
        for (int k = 0; k < iteration_count; k++) sink += numbers[generateRandomNumber((size_t)0, numbers.size() - 1)];
        auto rand_duration = std::chrono::high_resolution_clock::now() - start;

        std::cout << std::format("Vector     size: {:>8} elements\n"
                                 "Sequential time: {:>8}\n"
                                 "Random     time: {:>8}\n",
                                 std::format("{:0.2f}{}", numbers.size() > 1000000 ? (double)numbers.size() / 1000000 : (double)numbers.size() / 1000, 
                                                          numbers.size() > 1000000 ? "M" : "K"),
                                 std::chrono::duration_cast<std::chrono::milliseconds>(seq_duration),
                                 std::chrono::duration_cast<std::chrono::milliseconds>(rand_duration)) << std::endl;
    }

    return 0;
}
