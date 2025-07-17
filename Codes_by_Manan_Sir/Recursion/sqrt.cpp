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

double get_deviation(int n, double guess)
{
    double est = guess * guess;
    double diff = abs(n - est);
    double perc_diff = diff / n * 100;
    return perc_diff;
}

double my_sqrt(int n)
{
    double guess = 1;
    while (get_deviation(n, guess) >= 0.0001)
    {
        double div = n / guess;
        double avg = (guess + div) / 2;
        cout << guess << "\t" << div << "\t" << avg << "\n";
        guess = avg;
    }
    return guess;
}

void solve()
{
    int n;
    cin >> n;
    cout << my_sqrt(n) << "\n";
    // cout << get_deviation(102, 10) << "\n";
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