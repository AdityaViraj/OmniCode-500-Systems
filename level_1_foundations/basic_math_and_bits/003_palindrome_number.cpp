/**
 * @problem: Check Palindrome Number
 * @time_complexity: O(log10(N) / 2) - We only iterate through half of the digits.
 * @space_complexity: O(1) - Pure ALU math, zero memory allocations.
 * @systems_pov: Avoids string conversion. By only reversing half the number, 
 * we cut CPU cycles by 50% and completely eliminate the risk of integer overflow.
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
    bool is_palindrome(int x) {
        // Edge Case 1: Negative numbers are never palindromes (e.g., -121 reversed is 121-)
        // Edge Case 2: Numbers ending in 0 cannot be palindromes (unless the number is exactly 0)
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversed_half = 0;
        
        // We know we've reached the middle of the number when the original 
        // number is less than or equal to the reversed half.
        while (x > reversed_half) {
            reversed_half = (reversed_half * 10) + (x % 10);
            x /= 10;
        }

        // If the number has an EVEN amount of digits, x == reversed_half (e.g., 1221 -> 12 == 12)
        // If the number has an ODD amount of digits, we drop the middle digit using reversed_half / 10
        // (e.g., 12321 -> x = 12, reversed_half = 123 -> 123 / 10 = 12)
        return x == reversed_half || x == reversed_half / 10;
    }
}


int main() {
    int num = 12321;
    
    // RAII Profiling
    auto start = std::chrono::high_resolution_clock::now();
    bool result = SystemsSolver::is_palindrome(num);
    auto end = std::chrono::high_resolution_clock::now();

    if (result) {
        std::cout << num << " is a Palindrome.\n";
    } else {
        std::cout << num << " is NOT a Palindrome.\n";
    }
    
    // std::cerr << "Latency: " << std::chrono::duration<double, std::micro>(end-start).count() << "us\n";
    
    return 0;
}
