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

vvi get_power_set(vi &v)
{
    vvi power_set;
    int n = v.size();
    // for (int i = 0; i < (1 << n); i++)
    forn(i, (1 << n))
    {
        vi subset;
        forn(k, n)
        {
            int mask = 1 << k;
            if (i & mask)
            {
                subset.push_back(v[k]);
            }
        }
        power_set.push_back(subset);
    }
    return power_set;
}

void print_power_set(vvi &v)
{
    for (vi &v1 : v)
    {
        print_vec(v1);
    }
}

void solve()
{
    vi v = input_vector();
    vvi power_set = get_power_set(v);
    print_power_set(power_set);
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