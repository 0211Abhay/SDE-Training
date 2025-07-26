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

void rotate_vector(vector<int> &v)
{
    int n = v.size();
    int temp = v[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        v[i + 1] = v[i];
    }
    v[0] = temp;
}

void print_vec(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\t";
    }
    cout << "\n";
}

void solve()
{
    vector<int> v = input_vector();
    rotate_vector(v);
    print_vec(v);
}

int main()
{
    solve();
}