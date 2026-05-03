/**
 * @problem: Sieve of Eratosthenes
 * @time_complexity: O(N log(log N))
 * @space_complexity: O(N)
 * @systems_pov: Avoids `std::vector<bool>` bit-shifting overhead by using 
 * `std::vector<char>` for direct, uncompressed 1-byte memory access. 
 * Inner loop starts exactly at i*i to avoid redundantly overwriting cache lines.
 */

#include <iostream>
#include <vector>
#include <chrono>

// Systems-Style: Fast I/O
auto fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

namespace SystemsSolver {
    
    void sieve(int n) {
        if (n < 2) return;

        // SYSTEMS TRICK 1: Using 'char' (1 byte) instead of 'bool' (1 bit)
        // This prevents the CPU from doing bitwise decompression on every read/write.
        std::vector<char> is_prime(n + 1, 1); 
        is_prime[0] = is_prime[1] = 0; // 0 and 1 are not prime

        // SYSTEMS TRICK 2: Loop bounds bound by integer multiplication
        for (long long i = 2; i * i <= n; i++) {
            
            if (is_prime[i]) {
                // SYSTEMS TRICK 3: Start at i * i, not i + i.
                // If i is 5, we don't need to cross out 10, 15, or 20. 
                // They were already crossed out by 2 and 3! We start straight at 25.
                for (long long j = i * i; j <= n; j += i) {
                    is_prime[j] = 0; 
                }
            }
        }

        // Let's just count them to prove it worked (Printing 10 million numbers takes too long)
        int prime_count = 0;
        for (int i = 2; i <= n; i++) {
            if (is_prime[i]) prime_count++;
        }
        
        std::cout << "Found " << prime_count << " primes up to " << n << ".\n";
    }
}

int main() {
    int num = 10000000; // Let's test 10 MILLION!
    
    // Start the strict stopwatch
    auto start = std::chrono::high_resolution_clock::now();
    
    SystemsSolver::sieve(num);
    
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate latency in milliseconds
    std::cout << "Latency: " << std::chrono::duration<double, std::milli>(end-start).count() << " ms\n";
    
    return 0;
}
