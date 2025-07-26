#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef map<int, int> mii;
typedef pair<int, int> pii;

#define forn(i, n) for (int i = 0; i < n; i++)
#define pb push_back

vi input_vector()
{
    int n;
    cin >> n;
    vi v(n);
    forn(i, n)
    {
        cin >> v[i];
    }
    return v;
}

void print_vec(vi &v)
{
    forn(i, v.size())
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

int fibonacci(int n)
{
    if (n < 2)
    {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// vector<int> memo(101, -1);

int fib_memoized(int n, vi &memo)
{
    if (memo[n] != -1)
    {
        return memo[n];
    }
    return (memo[n] = fib_memoized(n - 1, memo) + fib_memoized(n - 2, memo));
    // return memo[n];
}

int fib_tabulation(int n)
{
    vi memo(n + 1, -1);
    memo[0] = 0, memo[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        memo[i] = memo[i - 1] + memo[i - 2];
    }
    return memo[n];
}

int fib_space_optimised(int n)
{
    if (n < 2)
    {
        return n;
    }

    int prev2 = 0, prev = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev2 + prev;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

void solve()
{
    int n;
    cin >> n;
    // vi memo(n + 1, -1);
    // memo[0] = 0, memo[1] = 1;
    // cout << fib_memoized(n, memo) << '\n';
    cout << fib_space_optimised(n) << "\n";
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}