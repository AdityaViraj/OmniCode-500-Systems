/**
 * @problem: Count Digits
 * @time_complexity: O(log10(N))
 * @space_complexity: O(1)
 * @systems_pov: We use iterative integer division to keep variables in 
 * CPU registers, avoiding the memory overhead of converting to std::string.
 */

#include <iostream>
#include <chrono>

// Optimization: Faster I/O for competitive programming
auto fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

namespace SystemsSolver {
    int count_digits(long long n) {
        if (n == 0) return 1;
        if (n < 0) n = -n; // Handle negative inputs
        
        int count = 0;
        while (n > 0) {
            n /= 10; // ALU operation: integer division
            count++;
        }
        return count;
    }
}

int main() {
    long long num = 123456789;
    
    auto start = std::chrono::high_resolution_clock::now();
    int result = SystemsSolver::count_digits(num);
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Digits: " << result << "\n";
    // std::cerr << "Latency: " << std::chrono::duration<double, std::micro>(end-start).count() << "us\n";
    
    return 0;
}
