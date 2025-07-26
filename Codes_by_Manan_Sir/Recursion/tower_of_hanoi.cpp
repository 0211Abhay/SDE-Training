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

int tower_of_hanoi(int n)
{
    if (n == 0)
    {
        return 0;
    }
    // return tower_of_hanoi(n - 1) + 1 + tower_of_hanoi(n - 1);
    return 2 * tower_of_hanoi(n - 1) + 1;
}

void solve()
{
    int n;
    cin >> n;
    cout << tower_of_hanoi(n) << "\n";
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