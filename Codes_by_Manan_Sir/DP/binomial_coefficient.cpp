#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
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

void print_vvi(vvi &memo)
{
    for (vi &v : memo)
    {
        print_vec(v);
    }
}

int nCr_loop(int n, int r)
{
    // loop from right for both numerator and denominator
    // for advanced code, do via modulo inverse
    return 1;
}

int nCr_recursive(int n, int r)
{
    r = min(r, n - r);
    if (r < 0) // (r > n) is redundant
    {
        return 0;
    }
    if (r == 0) // (r == n), (n == 0) is redundant
    {
        return 1;
    }
    return nCr_recursive(n - 1, r) + nCr_recursive(n - 1, r - 1);
}

void initialize_memo(vvi &memo)
{
    int n = memo.size() - 1;
    forn(i, n + 1)
    {
        memo[i] = vi(i + 1, 0);
        memo[i].front() = 1, memo[i].back() = 1;
    }
}

int helper(int n, int r, vvi &memo)
{
    if (r < 0) // (r > n) is redundant
    {
        return 0;
    }
    if (r == 0) // (r == n), (n == 0) is redundant
    {
        return 1;
    }
    if (memo[n][r] != 0)
    {
        return memo[n][r];
    }
    memo[n][r] = helper(n - 1, r, memo) + helper(n - 1, r - 1, memo);
    return memo[n][r];
}

int nCr_memo(int n, int r)
{
    r = min(r, n - r);
    vvi memo(n + 1);
    initialize_memo(memo);
    // print_vvi(memo);

    return helper(n, r, memo);
}

int nCr_tabulation(int n, int r)
{
    r = min(r, n - r);
    if (r < 0) // (r > n) is redundant
    {
        return 0;
    }
    if (r == 0) // (r == n), (n == 0) is redundant
    {
        return 1;
    }

    vvi memo(n + 1);
    initialize_memo(memo);
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= min(n, r); j++)
        {
            memo[i][j] = memo[i - 1][j] + memo[i - 1][j - 1];
        }
    }
    return (memo[n][r] = memo[n - 1][r] + memo[n - 1][r - 1]);
}

int nCr_space_optimised(int n, int r)
{
    r = min(r, n - r);
    if (r < 0) // (r > n) is redundant
    {
        return 0;
    }
    if (r == 0) // (r == n), (n == 0) is redundant
    {
        return 1;
    }

    // vvi memo(n + 1);
    vi prev({1});
    // initialize_memo(memo);
    // cout << "Updated code.\n";
    for (int i = 1; i < n; i++)
    {
        vi curr(i + 1, 0);
        curr.front() = 1, curr.back() = 1;
        for (int j = 1; j <= min(i / 2, r); j++)
        {
            int upper_term = prev[(i - 1) / 2];
            if (j <= (i - 1) / 2)
            {
                upper_term = prev[j];
            }
            // int upper_term = (j < i) ? prev[j] : 1;
            curr[j] = upper_term + prev[j - 1];
        }
        cout << "i: " << i << ";\n";
        print_vec(prev);
        print_vec(curr);
        cout << "\n";
        prev = curr;
    }
    return (prev[r] + prev[r - 1]);
}

void solve()
{
    int n, r;
    cin >> n >> r;
    cout << nCr_space_optimised(n, r) << "\n";
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