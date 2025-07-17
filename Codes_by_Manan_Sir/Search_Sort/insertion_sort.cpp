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

void insertion_sort(vi &v)
{
    int n = v.size();
    for (int i = 1; i < v.size(); i++)
    {
        // int temp = v[i], j;
        for (int j = i; j >= 1 && v[j] < v[j - 1]; j--)
        {
            swap(v[j], v[j - 1]);
            // if (v[j] > v[j + 1])
            // {
            //     swap(v[j], v[j + 1]);
            // }
            // else
            // {
            //     break;
            // }
        }
        // v[j + 1] = temp;
    }
}

void solve()
{
    vi v = input_vector();
    insertion_sort(v);
    print_vec(v);
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