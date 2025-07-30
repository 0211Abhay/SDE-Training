#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef pair<int, int> pii;

#define forn(i, n) for (int i = 0; i < n; i++)
#define pb push_back
#define mp make_pair

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

int rec_min_coins(vi &coins, int amt, int i)
{
    // cout << amt << "\t" << i << "\n";
    if (i == 0)
    {
        // cout << amt << "\t" << coins[i] << '\n';
        return (amt % coins[i] != 0) ? (amt + 1) : (amt / coins[i]); //
    }
    if (amt < coins[i])
    {
        return rec_min_coins(coins, amt, i - 1);
    }
    int take = 1 + rec_min_coins(coins, amt - coins[i], i);
    int notTake = rec_min_coins(coins, amt, i - 1);
    // cout << take << "\t" << notTake << '\n';
    return min(take, notTake);
}

void print_collisions(map<pii, int> &collision_freq)
{
    for (pair<pii, int> row : collision_freq)
    {
        // cout << row.first.first << "\t" << row.first.second << "\n";
        if (row.second > 1)
        {
            cout << row.first.first << "\t" << row.first.second << "\t" << row.second << "\n";
        }
    }
}

void initialize_memo(vvi &memo, int amt, int val)
{
    forn(i, memo[0].size())
    {
        memo[0][i] = (i % val != 0) ? (amt + 1) : (i / val);
    }
    forn(i, memo.size())
    {
        memo[i][0] = 0;
    }
}

int helper(vi &coins, int amt, int i, vvi &memo, map<pii, int> &collision_freq)
{
    // base case
    collision_freq[mp(amt, i)]++;

    if (memo[i][amt] != -1)
    {
        return memo[i][amt];
    }
    if (amt % coins[i] == 0)
    {
        return (memo[i][amt] = amt / coins[i]);
    }

    if (amt < coins[i])
    {
        return helper(coins, amt, i - 1, memo, collision_freq);
    }
    int take = 1 + helper(coins, amt - coins[i], i, memo, collision_freq);
    int notTake = helper(coins, amt, i - 1, memo, collision_freq);
    // cout << take << "\t" << notTake << '\n';
    return (memo[i][amt] = min(take, notTake));
}

int memo_min_coins(vi &coins, int amt)
{
    int n = coins.size();
    vvi memo(n, vi(amt + 1, -1));
    initialize_memo(memo, amt, coins[0]);
    map<pii, int> collision_freq;
    // cout << collision_freq.size() << "\n";
    int ans = helper(coins, amt, n - 1, memo, collision_freq);
    // print_collisions(collision_freq);
    return ans;
}

int table_min_coins(vi &coins, int amt)
{
    int n = coins.size();
    vvi dp(n, vi(amt + 1, -1));
    initialize_memo(dp, amt, coins[0]);
    for (int i = 1; i < n; i++)
    {
        for (int A = 1; A < amt + 1; A++)
        {
            // amt -> A
            if (A % coins[i] == 0)
            {
                dp[i][A] = A / coins[i];
            }

            int take = INT_MAX;
            if (A >= coins[i])
            {
                take = 1 + dp[i][A - coins[i]];
            }
            int notTake = dp[i - 1][A];
            dp[i][A] = min(take, notTake);

            // if (A < coins[i])
            // {
            //     dp[i][A] = dp[i - 1][A];
            //     continue;
            // }
            // int take = 1 + dp[i][A - coins[i]];
            // int notTake = dp[i - 1][A];
            // dp[i][A] = min(take, notTake);
        }
    }
    return dp[n - 1][amt];
}

int so_min_coins(vi &coins, int amt)
{
    int n = coins.size();
    vi prev(amt + 1, -1);
    forn(i, amt + 1)
    {
        prev[i] = (i % coins[0] != 0) ? (amt + 1) : (i / coins[0]);
    }

    for (int i = 1; i < n; i++)
    {
        vi curr(amt + 1);
        for (int A = 1; A < amt + 1; A++)
        {
            if (A % coins[i] == 0)
            {
                curr[A] = A / coins[i];
            }

            int take = INT_MAX;
            if (A >= coins[i])
            {
                take = 1 + curr[A - coins[i]];
            }
            int notTake = prev[A];
            curr[A] = min(take, notTake);
        }
        prev = curr;
    }
    return prev[amt];
}

int dso_min_coins(vi &coins, int amt)
{ // dso -> double space optimized
    int n = coins.size();
    vi prev(amt + 1, -1);
    forn(i, amt + 1)
    {
        prev[i] = (i % coins[0] != 0) ? (amt + 1) : (i / coins[0]);
    }

    for (int i = 1; i < n; i++)
    {
        for (int A = amt; A > 0; A--)
        {
            if (A % coins[i] == 0)
            {
                prev[A] = A / coins[i];
            }

            int take = INT_MAX;
            if (A >= coins[i])
            {
                take = 1 + prev[A - coins[i]];
            }
            int notTake = prev[A];
            prev[A] = min(take, notTake);
        }
    }
    return prev[amt];
}

void solve()
{
    vi coins = input_vector();
    sort(coins.begin(), coins.end());
    int amt;
    cin >> amt;
    // cout << "Amount\tIndex\tFreq\n";
    int ans = dso_min_coins(coins, amt);
    cout << (ans > amt ? -1 : ans) << "\n";
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