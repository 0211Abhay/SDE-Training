#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef map<int, int> mii;
typedef map<double, int, greater<double>> mdid;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef vector<pii> vpii;
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

double get_deviation(int n, double guess)
{
    double right_val = sqrt(n);
    double diff = abs(right_val - guess);
    double perc_diff = diff / right_val * 100;
    return perc_diff;
}

double get_sqrt_vedic(int n)
{
    int perfect_root = sqrt(n);
    int diff = n - perfect_root * perfect_root;
    double ans = perfect_root + (diff / (2.0 * perfect_root));
    return ans;
}

void print_mdid(mdid &deviations_list)
{
    for (auto [deviation, n] : deviations_list)
    {
        cout << n << ":\t" << deviation << "\n";
    }
}

vpdi list_deviations(int range, double tolerance = 5)
{
    // mdid deviations_list;
    vpdi deviations_list;
    forn(i, range)
    {
        int n = i + 1;
        double vedic_sqrt = get_sqrt_vedic(n);
        double deviation = get_deviation(n, vedic_sqrt);
        if (deviation > tolerance)
        {
            // cout << n << "\t" << deviation << "\n";
            // deviations_list[n] = deviation;
            // deviations_list[deviation] = n;
            deviations_list.pb(mp(deviation, n));
        }
    }
    return deviations_list;
}

void playground()
{
    vpii dummy;
    dummy.push_back(mp(1, 2));
    dummy.push_back(mp(2, 3));
    sort(dummy.begin(), dummy.end(), greater<pii>());
    for (pii &p : dummy)
    {
        cout << p.first << ", " << p.second << "\n";
    }
}

void print_vpdi(vpdi &deviations_list)
{
    for (pdi &p : deviations_list)
    {
        cout << p.second << ":\t" << p.first << "\n";
    }
}

void solve()
{
    // playground();
    int n;
    double tolerance;
    cin >> n >> tolerance;
    // cout << get_sqrt_vedic(18) << "\n";
    vpdi deviations_list = list_deviations(n, tolerance);
    sort(deviations_list.begin(), deviations_list.end(), greater<pdi>());
    // print_mdid(deviations_list);
    print_vpdi(deviations_list);
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