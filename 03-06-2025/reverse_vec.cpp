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

void reverse_vector(vector<int> &v)
{
    int n = v.size();
    int i = 0, j = n - 1;
    while (i < j)
    {
        swap(v[i], v[j]);
        i++;
        j--;
    }
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
    reverse_vector(v);
    print_vec(v);
}

int main()
{
    solve();
}