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

void populate_matrix_horizontally(vvi &v)
{
    int m = v.size(), n = v[0].size();
    int val = 1;
    forn(i, m)
    {
        forn(j, n)
        {
            v[i][j] = val++;
        }
    }
}

void populate_matrix_vertically(vvi v)
{
    //
}

void print_matrix(vvi &v)
{
    forn(i, v.size())
    {
        forn(j, v[0].size())
        {
            cout << v[i][j] << "\t";
        }
        cout << "\n";
    }
}

void solve()
{
    int m, n;
    char type;
    cin >> m >> n >> type;
    vvi v(m, vi(n));
    if (type == 'H')
    {
        populate_matrix_horizontally(v);
    }
    else if (type == 'V')
    {
        populate_matrix_vertically(v);
    }
    print_matrix(v);
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