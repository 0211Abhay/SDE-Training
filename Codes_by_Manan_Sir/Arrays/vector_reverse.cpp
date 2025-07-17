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
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        // cout << a[i] << "\t";
        cout << v[i] << "\t";
    }
    cout << "\n";
}

int main()
{
    vector<int> v = input_vector();

    // reverse
    reverse_vec(v);

    // print array
    print_vec(v);
}