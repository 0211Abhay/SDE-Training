#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef unordered_map<string, vs> umsvs;
typedef pair<string, vs> psvs;

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

void populate_crush_map(umsvs &crush_map)
{
    crush_map["Sonu"] = {"Jeet"};
    crush_map["Harsh"] = {"Anjali", "Sneha", "Nishi"};
    crush_map["Krupali"] = {"Jeet", "Aditya"};
    crush_map["Mihir"] = {"Sneha", "Aditya"};
    crush_map["Yasin"] = {"Nishi"};
}

void print_crush_list(vs &crush_list)
{
    for (string crush : crush_list)
    {
        cout << crush << ", ";
    }
    cout << "\n";
}

void print_map(umsvs &crush_map)
{
    // Way 3
    for (psvs key_value : crush_map)
    {
        string student = key_value.first;
        vs crush_list = key_value.second;
        cout << student << ": ";
        print_crush_list(crush_list);
    }
}

void playing_with_maps()
{
    umsvs crush_map;
    populate_crush_map(crush_map);
    print_map(crush_map);
}

void solve()
{
    playing_with_maps();
}

int main()
{
    solve();
}