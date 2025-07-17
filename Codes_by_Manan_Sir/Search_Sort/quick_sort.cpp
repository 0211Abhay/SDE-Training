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

int partition(vi &v, int l, int r)
{
    int pivot = v[l], pi = l;
    int i = l + 1, j = r;
    while (i <= j)
    {
        // cout << i << "\t" << j << "\n";
        while (i < r && v[i] <= pivot)
        {
            i++;
        }
        while (j > l && v[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(v[i], v[j]);
        }
    }
    swap(v[pi], v[j]);
    return j;
}

void quick_sort(vi &v, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int pi = partition(v, l, r);
    quick_sort(v, l, pi - 1);
    quick_sort(v, pi + 1, r);
}

void solve()
{
    vi v = input_vector();
    quick_sort(v, 0, v.size() - 1);
    print_vec(v);
    // int pi = partition(v, 0, v.size() - 1);
    // print_vec(v);
    // cout << pi << "\n";
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