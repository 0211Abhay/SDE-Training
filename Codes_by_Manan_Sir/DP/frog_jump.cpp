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

int min_energy_recursive(vi &v, int i)
{
    if (i < 2)
    {
        return (i == 0) ? 0 : abs(v[1] - v[0]);
    }
    int e1 = min_energy_recursive(v, i - 1) + abs(v[i] - v[i - 1]);
    int e2 = min_energy_recursive(v, i - 2) + abs(v[i] - v[i - 2]);
    return min(e1, e2);
}

int helper(vi &v, int i, vi &memo)
{
    if (i < 2 || memo[i] != 0)
    {
        return memo[i];
    }
    int e1 = helper(v, i - 1, memo) + abs(v[i] - v[i - 1]);
    int e2 = helper(v, i - 2, memo) + abs(v[i] - v[i - 2]);
    return (memo[i] = min(e1, e2));
}

int min_energy_memoised(vi &v)
{
    int n = v.size();
    vi memo(n, 0);
    memo[0] = 0, memo[1] = abs(v[1] - v[0]);
    return helper(v, n - 1, memo);
}

int min_energy_tabulated(vi &v)
{
    int n = v.size();
    if (n < 2)
    {
        return 0;
    }
    vi dp(n, -1);
    dp[0] = 0, dp[1] = abs(v[1] - v[0]);
    for (int i = 2; i < n; i++)
    {
        int e1 = dp[i - 1] + abs(v[i] - v[i - 1]);
        int e2 = dp[i - 2] + abs(v[i] - v[i - 2]);
        dp[i] = min(e1, e2);
    }
    return dp[n - 1];
}

int min_energy_space_optimised(vi &v)
{
    int n = v.size();
    if (n < 2)
    {
        return 0;
    }
    int prev2 = 0, prev = abs(v[1] - v[0]);
    for (int i = 2; i < n; i++)
    {
        int e1 = prev + abs(v[i] - v[i - 1]);
        int e2 = prev2 + abs(v[i] - v[i - 2]);
        int curr = min(e1, e2);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

void solve()
{
    vi v = input_vector();
    cout << min_energy_space_optimised(v) << "\n";
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