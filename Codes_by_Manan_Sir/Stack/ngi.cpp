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

void print_stack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << "\t";
        s.pop();
    }
    cout << "\n";
}

vi get_ngi(vi &v)
{
    stack<int> s;
    vector<int> res(v.size());
    for (int i = v.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && v[s.top()] <= v[i])
        {
            s.pop();
        }
        res[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    return res;
}

void solve()
{
    vi v = input_vector();
    vi nge = get_ngi(v);
    print_vec(nge);
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