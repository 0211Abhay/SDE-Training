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

void selection_sort(vi &v)
{
    forn(i, v.size() - 1)
    {
        int min_index = i;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j] < v[min_index])
            {
                min_index = j;
            }
        }
        swap(v[i], v[min_index]);
    }
}

void solve()
{
    vi v = input_vector();
    selection_sort(v);
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