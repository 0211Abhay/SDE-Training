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

bool isIsomorphic(string s, string t)
{
    if (s.length() != t.length())
    {
        return false;
    }
    unordered_map<char, char> encodings;
    // vector<bool> mapped(256,false);
    unordered_map<char, bool> mapped;
    for (int i = 0; i < s.length(); i++)
    {
        if (encodings[s[i]] && encodings[s[i]] != t[i])
        {
            return false;
        }
        if (encodings[s[i]])
        {
            continue;
        }
        // if (mapped[int(t[i])]) { return false; }
        if (mapped[t[i]])
        {
            return false;
        }
        encodings[s[i]] = t[i];
        // mapped[int(t[i])] = true;
        mapped[t[i]] = true;
    }
    return true;
}

void solve()
{
    string s, t;
    cin >> s >> t;
    cout << isIsomorphic(s, t) << "\n";
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