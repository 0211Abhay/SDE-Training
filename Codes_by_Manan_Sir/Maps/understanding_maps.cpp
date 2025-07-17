#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)

vector<int> input_vector()
{
    int n;
    cin >> n;
    vector<int> v(n);
    forn(i, n)
    {
        cin >> v[i];
    }
    return v;
}

void reverse_vec(vector<int> &v)
{
    int n = v.size();
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        swap(v[i], v[j]);
    }
}

void print_vec(vector<int> &v)
{
    // int n = v.size();
    // for (int i = 0; i < n; i++)
    // {
    //     // cout << a[i] << "\t";
    //     cout << v[i] << "\t";
    // }
    for (int x : v)
    {
        cout << x << "\n";
    }
    cout << "\n";
}

void populate_map(map<int, int> &map1)
{
    map1[2] = 3;
    map1[0] = 1;
    map1[1] = 2;
}

void print_map(map<int, int> &map1)
{
    // Way 1
    // map<int, int>::iterator itr;
    // for (itr = map1.begin(); itr != map1.end(); itr++)
    // {
    //     pair<int, int> key_value = (*itr);
    //     int key = key_value.first;
    //     int value = key_value.second;
    //     cout << key << ": " << value << "\n";
    // }

    // Way 2
    // for (pair<int, int> key_value : map1)
    // {
    //     int key = key_value.first;
    //     int value = key_value.second;
    //     cout << key << ": " << value << "\n";
    // }

    // Way 3
    for (auto [key, value] : map1)
    {
        cout << key << ": " << value << "\n";
    }
}

void playing_with_maps()
{
    map<int, int> map1;
    populate_map(map1);
    print_map(map1);
}

void understanding_macros()
{
    // int n = 2;
    forn(i, 3)
    {
        cout << "Hello World\n";
    }
}

void solve()
{
    // playing_with_maps();
    understanding_macros();
}

int main()
{
    solve();
}