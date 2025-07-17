#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) // O(n) -> O(sqrt(n))
{
    // bool divisor_count = false;
    // n = 1, i = 2
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i <= n / i; i++) // sqrt(n) * 1 = O(sqrt(n))
    {
        if (n % i == 0)
        {
            // divisor_count = true;
            // break;
            return false;
        }
    }
    // return (divisor_count == 0);
    // return !(divisor_count > 0);
    return true;
}

bool isPrimeFaster(int n) // O(sqrt(n)), k=0.5
{
    if (n < 2)
    {
        return false;
    }
    if (n == 2)
    {
        return true;
    }
    if (n % 2 == 0)
    {
        return false;
    }
    for (int i = 3; i <= (n / i); i += 2) // sqrt(n)/2
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    cout << isPrime(n) << "\n";
    // listArmstrong(n);
}

int main()
{
    solve();
}