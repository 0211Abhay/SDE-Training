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

void check_set_bit(int n, int index)
{
    int mask = 1 << index;
    int result = (n & mask);
    if (result == 0)
    {
        cout << "Bit is 0.\n";
    }
    else
    {
        cout << "Bit is 1.\n";
    }
}

int set_bit(int n, int index)
{
    int mask = 1 << index;
    int result = n | mask;
    return result;
}

int reset_bit(int n, int index)
{
    int mask = ~(1 << index);
    int result = n & mask;
    return result;
}

int flip_bit(int n, int index)
{
    int mask = (1 << index);
    int result = n ^ mask;
    return result;
}

void solve()
{
    int a, index;
    cin >> a >> index;
    // check_set_bit(a, index);
    cout << flip_bit(a, index) << "\n";
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