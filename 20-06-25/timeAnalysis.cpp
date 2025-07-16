#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n = 6;
    long x = 1e8, i; // number of repetitions
    int lsb = n & -n, b;

    auto start = high_resolution_clock::now();
    for (i = 0; i < x; ++i) {
        b = log2(n & -n);
    }
    auto stop = high_resolution_clock::now();

    auto totalDuration = duration_cast<nanoseconds>(stop - start);
    double averageTime = static_cast<double>(totalDuration.count()) / x;

    cout << "Least Significant Bit (value): " << lsb << endl;
    cout << "Position (0-based): " << b << endl;
    cout << "Total time for " << x << " iterations: " << totalDuration.count() << " ns" << endl;
    cout << "Average time per run: " << averageTime << " ns" << endl;

    return 0;
}
