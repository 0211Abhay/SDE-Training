#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
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

void print_primes(vb &primes)
{
    int count = 0;
    forn(i, primes.size())
    {
        if (primes[i])
        {
            count++;
            cout << i << " ";
        }
    }
    cout << "\n"
         << count << "\n";
}

void list_primes(int range)
{
    vb primes(range + 1, true);
    primes[0] = primes[1] = false;
    for (int p = 2; p <= range / p; p++)
    {
        if (primes[p])
        {
            for (int i = p * p; i <= range; i += p)
            {
                primes[i] = false;
            }
        }
    }
    print_primes(primes);
}

void solve()
{
    int range;
    cin >> range;
    list_primes(range);
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