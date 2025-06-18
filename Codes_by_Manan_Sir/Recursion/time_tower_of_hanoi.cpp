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

int tower_of_hanoi(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return tower_of_hanoi(n - 1) + 1 + tower_of_hanoi(n - 1);
    // return 2 * tower_of_hanoi(n - 1) + 1;
}

int tower_of_hanoi_fastest(int n)
{
    return (1 << n) - 1;
}

void solve()
{
    int n = 1000;
    // cin >> n;
    // cout << tower_of_hanoi(n) << "\n";
    tower_of_hanoi_fastest(n);
    // int a;
}

int main()
{
    fastIO;
    int t = 1;
    int frequency = 1e8;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    auto start = high_resolution_clock::now();
    forn(i, frequency)
    {
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << duration.count() / frequency << " nano seconds.\n";
}