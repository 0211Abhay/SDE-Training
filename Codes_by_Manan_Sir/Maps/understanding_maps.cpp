#include <bits/stdc++.h>
using namespace std;

vector<int> input_vector()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    return v;
}

void print_vec(vector<int> &v)
{
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << "\t";
    // }
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << "\n";
}

void populate_increment(map<int, int> &m)
{
    m[1] = 2;
    m[2] = 3;
    m[0] = 1;
}

void print_map(map<int, int> &m)
{
    // Way 1
    // map<int, int>::iterator itr;
    // for (itr = m.begin(); itr != m.end(); itr++)
    // {
    //     // pair<int, int> key_value = (*itr);
    //     int key = itr->first; // (*itr).first
    //     int value = itr->second;
    //     cout << key << ": " << value << "\n";
    // }

    // Way 2
    // for (pair<int, int> key_value : m)
    // {
    //     cout << key_value.first << ": " << key_value.second << '\n';
    // }

    for (auto [key, value] : m)
    {
        cout << key << ": " << value << "\n";
    }
}

void solve()
{
    // vector<int> v = input_vector();
    map<int, int> increment;
    populate_increment(increment);
    print_map(increment);
}

int main()
{
    solve();
}