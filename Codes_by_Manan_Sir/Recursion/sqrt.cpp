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

double get_deviation(int n, double root)
{
    double est = root * root;
    double diff = abs(n - est);
    double perc_diff = diff / n * 100;
    return perc_diff;
}

double helper(int n, double guess)
{
    while (get_deviation(n, guess) >= 0.01)
    {
        double div = n / guess;
        cout << guess << "\t" << div << "\n";
        double avg = (guess + div) / 2.0;
        guess = avg;
    }
    return guess;
}

double my_sqrt(int n)
{
    double guess = 1;
    return helper(n, guess);
}

void solve()
{
    int n;
    cin >> n;
    cout << my_sqrt(n) << "\n";
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