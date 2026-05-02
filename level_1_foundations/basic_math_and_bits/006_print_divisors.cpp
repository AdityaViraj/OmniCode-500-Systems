/**
 * @problem: Print all Divisors
 * @time_complexity: O(sqrt(N)) + O(K log K) where K is the number of divisors (for sorting).
 * @space_complexity: O(K) to store the divisors before printing.
 * @systems_pov: Avoids std::sqrt() to stay out of the FPU. Uses std::vector::reserve() 
 * to prevent expensive heap reallocations while storing the divisors.
 */

#include <iostream>
#include <vector>
#include <algorithm> // For std::sort
#include <chrono>

// Systems-Style: Fast I/O
auto fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

namespace SystemsSolver {
    
    void print_divisors(int n) {
        if (n <= 0) return;

        std::vector<int> divisors;
        
        // SYSTEMS TRICK: Pre-allocate memory.
        // A 32-bit integer rarely has more than 100 divisors.
        // This prevents the vector from constantly resizing on the heap.
        divisors.reserve(100); 

        // SYSTEMS TRICK: 'i * i <= n' instead of 'i <= sqrt(n)'
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                divisors.push_back(i); // Add the first half of the pair
                
                // Add the second half of the pair, but make sure we 
                // don't add the square root twice (e.g., 6x6)
                if (i != n / i) {
                    divisors.push_back(n / i);
                }
            }
        }

        // The math trick generates them out of order (e.g., 1, 36, 2, 18)
        // We use std::sort to print them cleanly
        std::sort(divisors.begin(), divisors.end());

        std::cout << "Divisors of " << n << ": ";
        for (int div : divisors) {
            std::cout << div << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    int num = 36; 
    
    auto start = std::chrono::high_resolution_clock::now();
    SystemsSolver::print_divisors(num);
    auto end = std::chrono::high_resolution_clock::now();
    
    // std::cerr << "Latency: " << std::chrono::duration<double, std::micro>(end-start).count() << "us\n";
    
    return 0;
}
