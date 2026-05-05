#include <iostream>
using namespace std;

// Function to compute binomial coefficient C(2n, n)
unsigned long long binomialCoeff(int n, int k) {
    unsigned long long res = 1;
    // Compute C(n, k) using multiplicative formula
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

// Function to return nth Catalan number
unsigned long long catalan_formula(int n) {
    return binomialCoeff(2 * n, n) / (n + 1);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "\nCatalan Numbers using formula:\n";
    for (int i = 0; i < n; i++)
        cout << catalan_formula(i) << " ";
    cout << endl;

    return 0;
}
