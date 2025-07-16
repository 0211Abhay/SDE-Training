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

stack<int> get_increasing_stack_umang(vi &v)
{
    stack<int> s;
    for (int &x : v)
    {
        while (!s.empty() && x < s.top())
        {
            s.pop();
        }
        s.push(x);
    }
    return s;
}

stack<int> get_increasing_stack(vi &v)
{
    stack<int> s;
    for (int &x : v)
    {
        while (!s.empty() && x < s.top())
        {
            s.pop();
        }
        s.push(x);
    }
    return s;
}

stack<int> get_decreasing_stack(vi &v)
{
    stack<int> s;
    for (int &x : v)
    {
        while (!s.empty() && x > s.top())
        {
            s.pop();
        }
        s.push(x);
    }
    return s;
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
    vi v = input_vector();

    // stack<int> inc = get_increasing_stack(v);
    stack<int> dec = get_decreasing_stack(v);
    // print_stack(inc);
    print_stack(dec);
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