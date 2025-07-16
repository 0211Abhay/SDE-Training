#include <iostream>
using namespace std;

void primeFactors(int n) {
    // Step 1: Print the number of 2s that divide n
    while (n % 2 == 0) {
        cout << 2 << " ";
        n /= 2;
    }

    // Step 2: Check for odd factors up to sqrt(n)
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }

    // Step 3: If n is still greater than 2, it's a prime number
    if (n > 2)
        cout << n;

    cout << endl;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Prime factors of " << number << " are: ";
    primeFactors(number);
    return 0;
}
