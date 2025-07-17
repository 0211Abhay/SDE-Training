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

int approach_sorting(vi &v)
{
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size() - 1; i += 2)
    {
        if (v[i] != v[i + 1])
        {
            return v[i];
        }
    }
    return v[v.size() - 1];
}

int approach_map(vi &nums)
{
    int n = nums.size();
    unordered_map<int, int> freq_map;
    for (int x : nums)
    {
        freq_map[x]++;
    }
    // for(auto [num, freq]:freq_map) {
    for (pair<int, int> pair1 : freq_map)
    {
        if (pair1.second % 2 == 1)
        {
            return pair1.first;
        }
    }
    return -1;
}

int approach_set(vi &nums)
{
    int n = nums.size();
    unordered_set<int> single;
    for (int x : nums)
    {
        if (single.find(x) != single.end())
        {
            single.erase(x);
        }
        else
        {
            single.insert(x);
        }
    }
    return (*single.begin());
}

int approach_bits(vi &nums)
{
    int single = 0;
    for (int x : nums)
    {
        single ^= x;
    }
    return single;
}

void solve()
{
    vi v = input_vector();
    cout << approach_sorting(v) << "\n";
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