#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef vector<pdi> vpdi;

#define forn(i, n) for (int i = 0; i < n; i++)
#define pb push_back
#define mp make_pair

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

double vedic_sqrt(int n)
{
    int base = sqrt(n);
    int diff = n - base * base;
    return (base) + (diff / (2.0 * base));
}

double get_deviation(double val, double guess)
{
    double diff = abs(val - guess);
    double deviation = diff / val * 100;
    return deviation;
}

vpdi list_deviations(int range)
{
    vpdi deviation_list;
    forn(i, range)
    {
        int n = i + 1;
        double my_sqrt = vedic_sqrt(n);
        double deviation = get_deviation(sqrt(n), my_sqrt);
        if (deviation > 1)
        {
            deviation_list.pb(mp(deviation, n));
            // cout << n << ": " << deviation << "\n";
        }
    }
    return deviation_list;
}

void print_vpdi(vpdi &deviation_list)
{
    for (pdi &p : deviation_list)
    {
        cout << p.second << ": " << p.first << "\n";
    }
}

void playground()
{
    multimap<int, int> m = {{2, 3}, {1, 2}, {1, 1}};
    for (pii p : m)
    {
        cout << p.first << " " << p.second << "\n";
    }
    // m[2] = 3;
    // m[1] = 2;
}

void solve()
{
    // cout << get_deviation(10, 10.1) << "\n";
    // cout << vedic_sqrt(18) << "\n";
    playground();
    // int n;
    // cin >> n;
    // vpdi deviation_list = list_deviations(n);
    // sort(deviation_list.begin(), deviation_list.end(),
    //      greater<pdi>());
    // print_vpdi(deviation_list);
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