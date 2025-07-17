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

int single_unique(vi &v)
{
    int ans = 0;
    for (int &x : v)
    {
        ans ^= x;
    }
    return ans;
}

vi get_uniques(vi &v)
{
    vi uniques;
    int ans = single_unique(v);
    int mask = ans & (-1 * ans);
    // vi v1, v2;
    int xor1 = 0, xor2 = 0;
    for (int &x : v)
    {
        if (x & mask)
        {
            // v1.push_back(x);
            xor1 ^= x;
        }
        else
        {
            // v2.push_back(x);
            xor2 ^= x;
        }
    }
    // uniques.push_back(single_unique(v1));
    // uniques.push_back(single_unique(v2));
    uniques.push_back(xor1);
    uniques.push_back(xor2);
    return uniques;
}

void solve()
{
    vi v = input_vector();
    vi uniques = get_uniques(v);
    // cout << approach_sorting(v) << "\n";
    print_vec(uniques);
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