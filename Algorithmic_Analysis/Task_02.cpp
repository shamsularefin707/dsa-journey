//Analysis of O(2^n) via Tower of Hanoi
#include <iostream> 
#include <vector>
#include <iomanip>
#include <chrono>
#include <cmath>

using namespace std;

// Using unsigned long long to prevent quick integer overflow
unsigned long long MoveCount = 0;

// Optimized recursion: Remount printing for benchmark performance
void towerOfHanoi(int n, char src, char dest, char aux) {
    if (n == 0) return; 

    towerOfHanoi(n - 1, src, aux, dest); 
    MoveCount++;
    // Disabled cout to measure algorithmic execution speed instead of console I/O
    // cout << "Move disk " << n << " from " << src << " to " << dest << "\n"; 
    towerOfHanoi(n - 1, aux, dest, src); 
}

int main() {
    vector<int> input = {5, 10, 15, 20, 25, 35, 40, 45, 50, 100, 10000};

    cout << left
         << setw(15) << "Input Size (n)"
         << setw(20) << "Time Taken (ms)"
         << setw(25) << "Move Count"
         << endl;
    cout << string(60, '-') << endl;

    for (int n : input) {
        MoveCount = 0; 
        
        // SAFEGUARD: Skip actual recursive execution for n > 25 to prevent system freeze
        if (n > 25) {
            // Compute theoretical move count: (2^n) - 1
            double theoreticalMoves = pow(2.0, n) - 1.0;

            cout << left
                 << setw(15) << n
                 << setw(20) << "Skipped (>25)"
                 << setw(25) << scientific << setprecision(3) << theoreticalMoves
                 << endl;
            continue;
        }

        auto start = chrono::high_resolution_clock::now();
        towerOfHanoi(n, 'A', 'C', 'B'); 
        auto end = chrono::high_resolution_clock::now();
        
        chrono::duration<double, std::milli> elapsed = end - start;

        cout << left
             << setw(15) << n
             << setw(20) << fixed << setprecision(4) << elapsed.count()
             << setw(25) << MoveCount
             << endl;
    }
    return 0;
}