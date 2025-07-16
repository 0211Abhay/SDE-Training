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

void print_arr(int *a, int n)
{
    //
}

// void print_vi(vi v)
// {
//     forn(i, v.size())
//     {
//         cout << v[i] << "\t";
//     }
//     cout << "\n";
// }

// void print_vi(vi &v)
// {
//     // forn(i, v.size())
//     // {
//     //     cout << v[i] << " ";
//     // }
//     // cout << "\n";
//     forn(i, v.size())
//     {
//         cout << v[i] << "\t";
//     }
//     cout << "\n";
// }

void print_vi(vi *v)
{
    forn(i, (*v).size())
    {
        // cout << *((*v) + i) << "\t"; // right it
        // cout << v->at(i) << "\t";
        // cout << (*v)[i] << "\t";
    }
    cout << "\n";
}

void solve()
{
    vi v = input_vector();
    print_vi(&v);
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