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

int missing_num(vi &v)
{
    int n = v.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans ^= (v[i] ^ (i + 1));
        // ans ^= (i + 1);l
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     ans ^= i;
    // }
    return ans;
}

void solve()
{
    vi v = input_vector();
    cout << missing_num(v) << "\n";
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