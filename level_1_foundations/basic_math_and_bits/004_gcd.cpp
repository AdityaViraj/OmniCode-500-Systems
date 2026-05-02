/**
 * @problem: GCD / HCF (Greatest Common Divisor)
 * @time_complexity: O(log(min(a, b))) - Euclidean algorithm halves the size rapidly.
 * @space_complexity: O(1) - Pure iterative math, zero stack memory used.
 * @systems_pov: Avoiding recursion eliminates stack frame allocation overhead.
 * We use a tight iterative while-loop to keep the CPU instruction cache warm.
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
    int gcd(int a, int b) {
        // Iterative Euclidean Algorithm
        while (b != 0) {
            int temp = b;
            b = a % b; // The modulo operator finds the remainder
            a = temp;
        }
        return a; // When the remainder hits 0, 'a' holds our GCD
    }
}

int main() {
    int num1 = 12;
    int num2 = 18;
    
    // Start the stopwatch
    auto start = std::chrono::high_resolution_clock::now();
    
    // Call the logic
    int result = SystemsSolver::gcd(num1, num2);
    
    // Stop the stopwatch
    auto end = std::chrono::high_resolution_clock::now();

    // Print the result cleanly
    std::cout << "The GCD of " << num1 << " and " << num2 << " is: " << result << "\n";
    
    return 0;
}
