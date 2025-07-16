#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    const int LIMIT = 10000000;
    unordered_map<int, vector<pair<int, int>>> cubeSums;

    // Precompute all a^3 + b^3 for a <= b and store their pairs
    for (int a = 1; a * a * a < LIMIT; ++a) {
        for (int b = a;a*a*a + b*b*b< LIMIT ; ++b) {
            int sum = a*a*a + b*b*b;
            if (sum >= LIMIT) break;
            cubeSums[sum].emplace_back(a, b);
        }
    }

    // Collect all numbers with at least two distinct (a, b) pairs
    vector<int> ramanujanNumbers;
    for (const auto& entry : cubeSums) {
        if (entry.second.size() >= 2) {
            ramanujanNumbers.push_back(entry.first);
        }
    }

    // Sort and print the results
    sort(ramanujanNumbers.begin(), ramanujanNumbers.end());
    cout << "Ramanujan numbers less than " << LIMIT << ":\n";
    for (int num : ramanujanNumbers) {
        cout << num << "\n";
    }

    cout << "--------------------------------" <<endl;

     for (int num : ramanujanNumbers) {
        cout << num << " = ";
        const auto& pairs = cubeSums[num];
        for (size_t i = 0; i < pairs.size(); ++i) {
            cout << pairs[i].first << "^3 + " << pairs[i].second << "^3";
            if (i != pairs.size() - 1) cout << " = ";
        }
        cout << endl;
    }
        cout << "--------------------------------" <<endl;
        cout << ramanujanNumbers.size();
    return 0;
}
