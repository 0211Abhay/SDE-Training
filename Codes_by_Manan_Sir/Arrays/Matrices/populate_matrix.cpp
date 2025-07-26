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

void populate_matrix(vvi &v)
{
    // int count = 1;
    forn(i, v.size())
    {
        forn(j, v[0].size())
        {
            v[i][j] = i * v[0].size() + j + 1;
        }
    }
}

void print_vvi(vvi &v)
{
    for (vi &row : v)
    {
        for (int &x : row)
        {
            cout << x << "\t";
        }
        cout << "\n";
    }
}

void solve()
{
    int m, n;
    cin >> m >> n;
    vvi v(m, vi(n));
    populate_matrix(v);
    print_vvi(v);
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