#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef unordered_map<int, int> umii;

vi input_vector()
{
    int n;
    cin >> n;

    vi v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    return v;
}

void print_vec(vi &v)
{
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << "\n";
}

void print_freq_map(umii &freq_map)
{
    for (pair<int, int> key_value : freq_map)
    {
        cout << key_value.first << ": " << key_value.second << "\n";
    }
}

vi find_mode(vi &v) // O(n + 2m) ~ O(n), k=3
{
    vi mode;
    // create freq map
    umii freq_map;
    for (int x : v) // O(n)
    {
        freq_map[x]++;
    }

    // find the highest freq
    int max_freq = 0;
    for (auto [key, freq] : freq_map) // O (m)
    {
        if (freq < max_freq)
        {
            continue;
        }
        if (freq > max_freq)
        {
            max_freq = freq;
            mode = vi();
        }
        mode.push_back(key);
    }

    // push the highest freq key to mode vi
    // for (auto [key, freq] : freq_map) // O(m)
    // {
    //     if (freq == max_freq)
    //     {
    //         mode.push_back(key);
    //     }
    // }

    // print_freq_map(freq_map);
    // add all elements to mode vi with highest freq
    return mode;
}

void solve()
{
    vi v = input_vector();
    vi mode = find_mode(v);
    print_vec(mode);
}

int main()
{
    solve();
}