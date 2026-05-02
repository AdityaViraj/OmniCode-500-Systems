/**
 * @problem: Reverse a Number
 * @time_complexity: O(log10(N)) - Time scales with the number of digits.
 * @space_complexity: O(1) - In-place ALU math, zero memory allocations.
 * @systems_pov: Avoids dynamic memory (no std::string conversion). Implements 
 * early-branch overflow prediction to safely catch 32-bit integer limits 
 * without relying on undefined behavior.
 */

#include <iostream>
#include <chrono>
#include <limits> // Required for system-level bounds checking

// Systems-Style: I/O Optimization
auto fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

namespace SystemsSolver {
    int reverse_number(int x) {
        int reversed = 0;
        
        while (x != 0) {
            int pop = x % 10; // Extract the last digit
            x /= 10;          // Shift the original number right

            // --- Systems-Level Overflow Protection ---
            // INT_MAX is 2147483647. If reversed > 214748364, the next *10 will overflow.
            // If reversed == 214748364, pushing a digit > 7 will overflow.
            if (reversed > std::numeric_limits<int>::max() / 10 || 
               (reversed == std::numeric_limits<int>::max() / 10 && pop > 7)) {
                return 0; // Return 0 on overflow (Standard competitive programming rule)
            }
            
            // INT_MIN is -2147483648. Same logic for negative bounds.
            if (reversed < std::numeric_limits<int>::min() / 10 || 
               (reversed == std::numeric_limits<int>::min() / 10 && pop < -8)) {
                return 0; // Return 0 on underflow
            }

            // Safe to push the digit
            reversed = (reversed * 10) + pop;
        }
        
        return reversed;
    }
}

int main() {
    int num = -12345;
    
    // RAII Profiling
    auto start = std::chrono::high_resolution_clock::now();
    int result = SystemsSolver::reverse_number(num);
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Original: " << num << "\n";
    std::cout << "Reversed: " << result << "\n";
    
    // std::cerr << "Latency: " << std::chrono::duration<double, std::micro>(end-start).count() << "us\n";
    
    return 0;
}
