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

double myPow(double x, int n)
{
    // cout << x << "\t" << n << "\n";
    if (n == 1)
    {
        return x;
    }
    if (n % 2 == 1)
    {
        return x * myPow(x * x, n / 2);
    }
    return myPow(x * x, n / 2);
    // return val * val;
}

void solve()
{
    int n;
    double x;
    cin >> x >> n;
    cout << myPow(x, n) << "\n";
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