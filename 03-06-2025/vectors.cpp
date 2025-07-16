#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n];
    // vector<int> v;
    // cout << "Size of Vector: " << v.size() << "\n";
    // vector<int> v(n);
    vector<int> v(n, 0);
    // reading vector from user
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        // int temp;
        // cin >> temp;
        // v.push_back(temp);
        // v[i] = temp;
        // cout << "Size of Vector: " << v.size() << "\n";
    }

    // v.pop_back();
    // cout << "Size of Vector: " << v.size() << "\n";

    // int max_arr = a[0];

    // finding max
    int max_arr = v[0];
    for (int i = 0; i < n; i++)
    {
        // if (a[i] > max_arr)
        // {
        //     max_arr = a[i];
        // }
        // max_arr = max(a[i], max_arr);
        max_arr = max(v[i], max_arr);
    }

    // printing output
    cout << max_arr << "\n";
}