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

void merge(vi &v, int l, int r)
{
    int m = l + (r - l) / 2;
    vi temp(r - l + 1);
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r)
    {
        if (v[i] < v[j])
        {
            temp[k++] = v[i++];
        }
        else
        {
            temp[k++] = v[j++];
        }
    }
    while (i <= m)
    {
        temp[k++] = v[i++];
    }
    while (j <= r)
    {
        temp[k++] = v[j++];
    }
    for (int i = 0; i < temp.size(); i++)
    {
        v[l + i] = temp[i];
    }
}

void merge_sort(vi &v, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int m = l + (r - l) / 2;
    merge_sort(v, l, m);
    merge_sort(v, m + 1, r);
    merge(v, l, r);
}

void solve()
{
    vi v = input_vector();
    merge_sort(v, 0, v.size() - 1);
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