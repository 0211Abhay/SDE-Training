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

vi merge(vi &a, vi &b)
{
    int m = a.size(), n = b.size();
    vi c(m + n);
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            c[k++] = a[i++];
        }
        else
        {
            c[k++] = b[j++];
        }
    }
    // if (i == m)
    // {
    while (j < n)
    {
        c[k++] = b[j++];
    }
    // }
    // if (j == n)
    // {
    while (i < m)
    {
        c[k++] = a[i++];
    }
    // }
    return c;
}

void solve()
{
    vi a = input_vector();
    vi b = input_vector();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vi c = merge(a, b);
    print_vec(c);
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