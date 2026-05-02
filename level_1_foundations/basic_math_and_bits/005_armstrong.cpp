/**
 * @problem: Armstrong Numbers
 * @time_complexity: O(log10(N)) for digit counting + O(log(exp)) for power calculation.
 * @space_complexity: O(1) - Pure integer ALU math.
 * @systems_pov: Implements Fast Binary Exponentiation using bitwise 
 * shifts to completely avoid the overhead of floating-point std::pow().
 */

#include <iostream>
#include <chrono>

// Systems-Style: Fast I/O to skip OS synchronization locks
auto fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

namespace SystemsSolver {
    
    /**
     * @brief Fast Binary Exponentiation (O(log N))
     * Calculates base^exp using binary representation rather than a slow for-loop.
     */
    int fast_pow(int base, int exp) {
        int result = 1;
        
        while (exp > 0) {
            // NEW THING 1: Bitwise AND. 
            // Checks if the last binary bit is a 1 (meaning the number is odd).
            // If yes, we multiply our result by the current base multiplier.
            if (exp & 1) {
                result *= base;
            }
            
            // NEW THING 2: Square the base.
            // This transforms the base sequence from x^1 -> x^2 -> x^4 -> x^8
            base *= base;
            
            // NEW THING 3: Bitwise Right Shift.
            // Shifting binary bits right by 1 space exactly divides the number by 2.
            // E.g., 1101 (13) becomes 0110 (6).
            exp >>= 1; 
        }
        return result;
    }

    bool is_armstrong(int n) {
        if (n < 0) return false; // Armstrong numbers are strictly positive
        
        int original = n;
        int temp = n;
        int num_digits = 0;
        
        // Pass 1: Count how many digits the number has
        while (temp > 0) {
            num_digits++;
            temp /= 10;
        }
        
        // Pass 2: Extract digits and apply our Fast Pow
        temp = original;
        int sum = 0;
        
        while (temp > 0) {
            int digit = temp % 10;
            sum += fast_pow(digit, num_digits); // ALU-only execution
            temp /= 10;
        }
        
        return sum == original;
    }
}

int main() {
    int num = 153; 
    
    auto start = std::chrono::high_resolution_clock::now();
    bool result = SystemsSolver::is_armstrong(num);
    auto end = std::chrono::high_resolution_clock::now();

    if (result) {
        std::cout << num << " is an Armstrong Number.\n";
    } else {
        std::cout << num << " is NOT an Armstrong Number.\n";
    }
    
    // Check our latency for fun!
    // std::cerr << "Latency: " << std::chrono::duration<double, std::micro>(end-start).count() << "us\n";
    
    return 0;
}
