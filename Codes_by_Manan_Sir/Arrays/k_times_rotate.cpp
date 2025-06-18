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

void rotate_vector(vector<int> &v) // O(n), k=1
{
    int n = v.size();
    int temp = v[n - 1];
    for (int i = n - 2; i >= 0; i--) // (n-1)
    {
        v[i + 1] = v[i];
    }
    v[0] = temp;
}

void k_rotate_vector(vector<int> &v, int k) // O(kn)
{
    k = k % v.size();
    while (k--) // k * n
    {
        rotate_vector(v); // n
    }
}

void k_rotate_vector_faster(vector<int> &v, int k) // O(k+n)
{
    int n = v.size();
    k = k % v.size();
    vector<int> temp(k); // SC: O(k)
    // first backup of last k elements
    for (int i = n - k; i < n; i++) // k
    {
        temp[i - (n - k)] = v[i];
    }

    // shift initial (n-k) elements
    for (int i = n - k - 1; i >= 0; i--) // n-k
    {
        v[i + k] = v[i];
    }

    // copy the k elements to start
    for (int i = 0; i < k; i++) // k
    {
        v[i] = temp[i];
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
    int k;
    cin >> k;
    k_rotate_vector_faster(v, k);
    print_vec(v);
}

int main()
{
    solve();
}