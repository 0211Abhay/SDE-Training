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

bool helper(vi &v, int x, int l, int r)
{
    if (l > r)
    {
        return false;
    }
    int mid = (l + r) / 2;
    if (v[mid] == x)
    {
        return true;
    }
    if (v[mid] < x)
    {
        return helper(v, x, mid + 1, r);
    }
    return helper(v, x, l, mid - 1);
}

bool my_binary_search(vi &v, int x)
{
    return helper(v, x, 0, v.size() - 1);
}

bool binary_search_iteration(vi &v, int x)
{
    int l = 0, r = v.size() - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (v[mid] == x)
        {
            return true;
        }
        if (v[mid] < x)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return false;
}

void built_in_functions()
{
    vi v({1, 2, 4, 5});
    cout << *lower_bound(v.begin(), v.end(), 3) << "\n";
}

void solve()
{
    // vi v = input_vector();
    // sort(v.begin(), v.end());
    // int x;
    // cin >> x;
    // cout << binary_search_iteration(v, x) << "\n";
    built_in_functions();
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