#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
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

int recursive_0_1_knapsack(vi &values, vi &weights, int W)
{
    return 0;
}

int memo_0_1_knapsack(vi &values, vi &weights, int W)
{
    return 0;
}

int tabulated_0_1_knapsack(vi &values, vi &weights, int W)
{
    return 0;
}

int space_optimised_0_1_knapsack(vi &values, vi &weights, int W)
{
    return 0;
}

void solve()
{
    int n, W;
    cin >> n >> W;
    vi values(n), weights(n);
    take_input(values, weights);
    cout << recursive_0_1_knapsack(values, weights, W) << "\n";
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