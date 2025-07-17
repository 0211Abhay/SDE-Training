#include <bits/stdc++.h>
using namespace std;

int no_of_digits(int n) // log(n)
{
    int count = 0;
    while (n > 0) // _ * 1 = c
    {
        count++;
        n /= 10;
    }
    return count;
}

bool isArmstrong(int n) // O(log(n)), k=2
{
    int power = no_of_digits(n); // O(log(n))
    int sum = 0, n_copy = n;
    while (n > 0) // O (log(n))
    {
        int digit = n % 10;
        sum += pow(digit, power);
        n /= 10;
    }
    return (sum == n_copy);
}

void listArmstrong(int range)
{
    for (int i = 1; i <= range; i++)
    {
        if (isArmstrong(i))
        {
            cout << i << ", ";
        }
    }
    cout << "\n";
}

void solve()
{
    int n;
    cin >> n;
    // cout << isArmstrong(n) << "\n";
    listArmstrong(n);
}

int main()
{
    solve();
}