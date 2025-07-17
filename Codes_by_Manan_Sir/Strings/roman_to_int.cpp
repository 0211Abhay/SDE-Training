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

void populate_map(unordered_map<char, int> &values)
{
    values['I'] = 1, values['V'] = 5;
    values['X'] = 10, values['L'] = 50;
    values['C'] = 100, values['D'] = 500;
    values['M'] = 1000;
}

int roman_to_int(string s)
{
    unordered_map<char, int> values;
    int ans = 0;
    populate_map(values);
    int l = s.length();
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] == 'I' && i < (l - 1) && (s[i + 1] == 'V' || s[i + 1] == 'X')) ||
            (s[i] == 'X' && i < (l - 1) && (s[i + 1] == 'L' || s[i + 1] == 'C')) ||
            (s[i] == 'C' && i < (l - 1) && (s[i + 1] == 'D' || s[i + 1] == 'M')))
        {
            ans += values[s[i + 1]] - values[s[i]];
            i++;
            continue;
        }
        ans += values[s[i]];
    }
    return ans;
}

void solve()
{
    string s;
    cin >> s;
    cout << roman_to_int(s) << '\n';
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