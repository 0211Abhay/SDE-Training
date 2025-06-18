#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) // O(n)
{
    // bool no_of_divisor = false; // 1
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i * i <= (n); i++) // sqrt(n) * 1 = O(sqrt(n))
    {
        if (n % i == 0) // O(1)
        {
            return false;
            // no_of_divisor = true;
            // break;
        }
    }
    // return !(no_of_divisor); // 1
    return true;
}

bool isPrimeFaster(int n) // 0.5 * O(sqrt(n))
{
    if (n < 2)
    {
        return false;
    }
    if (n % 2 == 0)
    {
        return (n == 2);
        // if (n == 2)
        // {
        //     return true;
        // }
        // else
        // {
        //     return false;
        // }
    }
    for (int i = 3; i * i <= (n); i += 2) // sqrt(n)/2 * 1 = O(sqrt(n)), k = 0.5
    {
        if (n % i == 0) // O(1)
        {
            return false;
        }
    }
    return true;
}

bool isPrime_fastest(int n)
{
    // code here
    if (n < 2)
    {
        return false;
    }
    if (n < 4)
    {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }
    for (int i = 5; i <= (n / i); i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

void primeList(int range)
{
    for (int i = 1; i <= range; i++) // n * sqrt(n)/2 = n^(3/2) * (0.5)
    {
        if (isPrimeFaster(i)) // sqrt(n)/2
        {
            cout << i << ", ";
        }
    }
    cout << "\n";
}

void solve()
{
    // int n;
    // cin >> n;
    // cout << isPrimeFaster(n) << "\n";
    // primeList(n);
    __int128_t a;
    cout << 0 << ' ' << INT_MAX << '\n';
}

int main()
{
    solve();
}