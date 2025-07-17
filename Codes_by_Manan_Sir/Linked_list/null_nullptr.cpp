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

void fun(int a)
{
    cout << "Int function called.\n";
}

void fun(double d)
{
    //
}

void fun(char *c)
{
    cout << "Char pointer function called.\n";
}

// void fun(int *a)
// {
//     //
// }

void solve()
{
    int a = 4;
    char c = 'z';
    char *ptr_c = &c;
    fun(nullptr);
    // fun(ptr_c);
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