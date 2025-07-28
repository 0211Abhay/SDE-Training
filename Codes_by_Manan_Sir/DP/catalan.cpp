#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

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

unsigned long long catalan_recursive(int n)
{
    if (n < 2)
    {
        return 1;
    }
    unsigned long long ans = 0;
    forn(i, n)
    {
        ans += catalan_recursive(i) * catalan_recursive(n - 1 - i);
    }
    return ans;
}

int helper(int n, vi &memo)
{
    if (n < 2)
    {
        return 1;
    }
    if (memo[n])
    {
        return memo[n];
    }
    int ans = 0;
    forn(i, n)
    {
        ans += helper(i, memo) * helper(n - 1 - i, memo);
    }
    return (memo[n] = ans);
}

int catalan_memo(int n)
{
    vi memo(n + 1, 0);
    memo[0] = memo[1] = 1;
    return helper(n, memo);
}

int catalan_tabulation(int n)
{
    vi dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        forn(j, i / 2.0)
        {
            int ans = dp[j] * dp[i - 1 - j];
            ans <<= 1;
            dp[i] += ans;
            // if (j != i - 1 - j)
            // {
            //     dp[i] += dp[j] * dp[i - 1 - j];
            // }
        }
        if (i & 1)
        {
            dp[i] -= dp[i / 2] * dp[i / 2];
        }
    }
    return dp[n];
}

void find_times()
{
    forn(i, 35)
    {
        auto start = high_resolution_clock::now();
        unsigned long long val = catalan_memo(i);
        // cout << (i + 19) << "\t" << val << "\n";
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        cout << i << "\t" << val << "\t" << duration.count() << " ns.\n";
        if (duration.count() > 1100)
        {
            break;
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    cout << catalan_tabulation(n) << "\n";
    // find_times();
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