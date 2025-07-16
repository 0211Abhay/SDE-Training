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

int max_vector(vector<int> v)
{
    int max_arr = v[0], n = v.size();
    for (int i = 0; i < n; i++)
    {
        max_arr = max(v[i], max_arr);
    }
    return max_arr;
}

int main()
{
    vector<int> v = input_vector();
    // finding max
    // int max_arr = max_vector(v);

    // printing output
    cout << max_vector(v) << "\n";
}