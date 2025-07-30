#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef pair<int, int> pii;

#define forn(i, n) for (int i = 0; i < n; i++)
#define pb push_back

void print_vec(vi &v)
{
    forn(i, v.size())
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void take_input(vi &values, vi &weights)
{
    forn(i, values.size())
    {
        cin >> values[i];
    }
    forn(i, weights.size())
    {
        cin >> weights[i];
    }
}

int recursive_0_1_knapsack(vi &values, vi &weights, int W, int n)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (weights[n - 1] > W)
    {
        return recursive_0_1_knapsack(values, weights, W, n - 1);
    }
    int take = values[n - 1] + recursive_0_1_knapsack(values, weights, W - weights[n - 1], n - 1);
    int notTake = recursive_0_1_knapsack(values, weights, W, n - 1);
    return max(take, notTake);
}

void initialise_memo(vvi &memo, int n, int w0, int v0, int W)
{
    for (int i = w0; i <= W; i++)
    {
        memo[0][i] = v0;
    }
    forn(i, w0)
    {
        memo[0][i] = 0;
    }
    forn(i, n)
    {
        memo[i][0] = 0;
    }
}

int helper(vi &val, vi &wt, int W, int n, vvi &memo)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (memo[n - 1][W] != -1)
    {
        return memo[n - 1][W];
    }
    if (wt[n - 1] > W)
    {
        return (memo[n - 1][W] = helper(val, wt, W, n - 1, memo));
    }
    int take = val[n - 1] + helper(val, wt, W - wt[n - 1], n - 1, memo);
    int notTake = helper(val, wt, W, n - 1, memo);
    return (memo[n - 1][W] = max(take, notTake));
}

int memo_0_1_knapsack(vi &values, vi &weights, int W)
{
    int n = values.size();
    vvi memo(n, vi(W + 1, -1));
    initialise_memo(memo, n, weights[0], values[0], W);
    return helper(values, weights, W, n, memo);
}

int tabulated_0_1_knapsack(vi &val, vi &wt, int W)
{
    int n = val.size();
    if (n == 0 || W == 0)
    {
        return 0;
    }
    vvi memo(n, vi(W + 1, -1));
    initialise_memo(memo, n, wt[0], val[0], W);

    for (int i = 1; i < n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (wt[i] > w)
            {
                memo[i][w] = memo[i - 1][w];
            }
            int take = val[i] + memo[i - 1][w - wt[i]];
            int notTake = memo[i - 1][w];
            memo[i][w] = max(take, notTake);
        }
    }
    return memo[n - 1][W];
}

int space_optimised_0_1_knapsack(vi &val, vi &wt, int W)
{
    int n = val.size();
    if (n == 0 || W == 0)
    {
        return 0;
    }
    vi prev(W + 1, 0);
    for (int i = wt[0]; i <= W; i++)
    {
        prev[i] = val[0];
    }

    for (int i = 1; i < n; i++)
    {
        vi curr(W + 1, 0);
        for (int w = 1; w <= W; w++)
        {
            if (wt[i] > w)
            {
                curr[w] = prev[w];
            }
            int take = val[i] + prev[w - wt[i]];
            int notTake = prev[w];
            curr[w] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[W];
}

int dso_0_1_knapsack(vi &val, vi &wt, int W)
{ // dso: double space optimised
    int n = val.size();
    if (n == 0 || W == 0)
    {
        return 0;
    }
    vi prev(W + 1, 0);
    for (int i = wt[0]; i <= W; i++)
    {
        prev[i] = val[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int w = W; w > 0; w--)
        {
            if (wt[i] <= w)
            {
                int take = val[i] + prev[w - wt[i]];
                int notTake = prev[w];
                prev[w] = max(take, notTake);
            }
        }
    }
    return prev[W];
}

void solve()
{
    int n, W;
    cin >> n >> W;
    vi values(n), weights(n);
    take_input(values, weights);
    cout << space_optimised_0_1_knapsack(values, weights, W) << "\n";
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