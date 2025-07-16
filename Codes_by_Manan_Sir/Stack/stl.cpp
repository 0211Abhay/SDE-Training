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

void populate(stack<int> &s)
{
    forn(i, 3)
    {
        s.push(i + 1);
    }
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

void solve()
{
    stack<int> s1, s2;
    populate(s1);
    forn(i, 3)
    {
        s2.push(i + 4);
    }
    // swap(s1, s2);
    s1.swap(s2);
    print_stack(s1);
    print_stack(s2);
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