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

string reverseWords(string s)
{
    string ans = "", temp = "";
    int n = s.size();

    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] != ' ')
        {
            if (temp == "" && ans != "")
            {
                ans += " ";
            }
            temp = s[i] + temp;
        }
        if (s[i] == ' ' || i == 0)
        {
            ans += temp;
            temp = "";
        }
        // if (i==0) {
        //     ans += temp;
        //     temp = "";
        // }
    }
    return ans;
}

void solve()
{
    string s;
    getline(cin, s);
    cout << reverseWords(s) << "\n";
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