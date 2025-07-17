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

int count_bits(int n)
{
    int count = 0;
    while (n > 0)
    {
        count++;
        n >>= 1;
    }
    return count;
}

int count_set_bits(int n)
{
    int count = 0;
    while (n > 0)
    {
        if (n & 1 == 1)
        {
            count++;
        }
        n >>= 1;
    }
    return count;
}

int msb(int n)
{
    return count_bits(n) - 1;
}

int lsb(int n)
{
    int index = 0;
    while (n > 0)
    {
        if (n & 1)
        {
            return index;
        }
        index++;
        n >>= 1;
    }
    return -1;
}

void solve()
{
    int n;
    cin >> n;
    cout << msb(n) << "\t" << lsb(n) << "\n";
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