#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
typedef vector<int> vi;
typedef unordered_map<string, vs> umsvs;

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

void populate_crush_map(umsvs &crush_map)
{
    crush_map["Kishan"] = {"Nirali"};
    crush_map["Jay"] = {"Abhi"};
    crush_map["Vivek"] = {"Ruhee"};
    crush_map["Nidhi"] = {"Abhi"};
    crush_map["Akshay"] = {"Diya", "Nirali", "Tanvi"};
}

void print_crush_list(vs &crush_list)
{
    for (string crush : crush_list)
    {
        cout << crush << ", ";
    }
    cout << "\n";
}

void print_crush_map(umsvs &crush_map)
{
    umsvs::iterator itr;
    for (itr = crush_map.begin(); itr != crush_map.end(); itr++)
    {
        // string student = itr->first;
        // vs crush_list = itr->second;
        cout << itr->first << ": ";
        print_crush_list(itr->second);
    }
}

void solve()
{
    // vector<int> v = input_vector();
    umsvs crush_map;
    populate_crush_map(crush_map);
    print_crush_map(crush_map);
}

int main()
{
    solve();
}