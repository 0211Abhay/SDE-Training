#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define flf(i, a, b) for (int i = a; i < b; i++)
#define flb(i, a, b) for (int i = a; i > b; i--)
#define takeInt(n) \
    int n;         \
    cin >> n
#define forn(i, n) flf(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()

const int MOD = 1e9 + 7;
const long long INF = 1e18;

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

int lsb_method1(int n)
{
    int val = n ^ (n & (n - 1));
    return log2(val);
}

int lsb_method2(int n)
{
    int lsb = 0;
    while (n > 0)
    {
        if (n & 1)
        {
            return lsb;
        }
        lsb++;
        n >>= 1;
    }
    return -1;
}

int lsb_method3(int n)
{
    int val = (n & (-1 * n));
    return log2(val);
}

void solve()
{
    int ans = lsb_method3(1 << 30);
}

int main()
{
    fastIO;
    int t = 1e6;
    int frequency = t;
    // cin >> t;
    auto start = high_resolution_clock::now();
    while (t--)
    {
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << duration.count() / frequency << " nanoseconds \n";
}