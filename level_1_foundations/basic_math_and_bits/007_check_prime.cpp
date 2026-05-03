/**
 * @problem: Check if a Number is Prime
 * @time_complexity: O(sqrt(N)) - Loop bounds are mathematically minimized.
 * @space_complexity: O(1) - Pure integer ALU math.
 * @systems_pov: Implements early-exit branch prediction to skip the loop 
 * for 66% of all integers (multiples of 2 and 3). Avoids std::sqrt() in the 
 * loop condition to bypass the Floating-Point Unit (FPU).
 */

#include <iostream>
#include <chrono>

// Systems-Style: Fast I/O
auto fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

namespace SystemsSolver {
    
    bool is_prime(int n) {
        // Early Exits: Handle edge cases instantly
        if (n <= 1) return false;
        if (n == 2 || n == 3) return true;
        
        // Branch Prediction optimization: 
        // If it's even or divisible by 3, exit immediately. 
        // This avoids starting the loop for 66% of all numbers.
        if (n % 2 == 0 || n % 3 == 0) return false;
        
        // SYSTEMS TRICK: 'i * i <= n' instead of 'i <= sqrt(n)'
        // We start at 5 because we already checked 2, 3, and 4 (via % 2).
        // We increment by 6 because all primes are of the form 6k ± 1.
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        
        return true;
    }
}

int main() {
    int num = 1000000007; // A famous massive prime number used in Competitive Programming
    
    auto start = std::chrono::high_resolution_clock::now();
    bool result = SystemsSolver::is_prime(num);
    auto end = std::chrono::high_resolution_clock::now();

    if (result) {
        std::cout << num << " is a Prime Number.\n";
    } else {
        std::cout << num << " is NOT a Prime Number.\n";
    }
    
    // Optional: See how fast we process a 1-billion digit number
    // std::cerr << "Latency: " << std::chrono::duration<double, std::micro>(end-start).count() << "us\n";
    
    return 0;
}
