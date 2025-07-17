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

void rotate_vec(vector<int> &v) // O(n)
{
    int n = v.size();
    int temp = v[n - 1];
    for (int i = n - 2; i >= 0; i--) // (n-1)
    {
        v[i + 1] = v[i];
    }
    v[0] = temp;
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

void rotate_k_times(vector<int> &v, int k) //  O(kn)
{
    // k %= (v.size());
    for (int i = 0; i < k; i++) // k * n
    {
        rotate_vec(v); // O(n)
    }
}

void rotate_k_times_faster(vector<int> &v, int k) //  O(k + n)
{
    // copy last k elements into temp
    vector<int> temp(k);
    int n = v.size();
    for (int i = n - k; i < n; i++) // O(k)
    {
        temp[i - (n - k)] = v[i];
    }

    // shift (n-k) elements k places right
    for (int i = n - k - 1; i >= 0; i--) // O(n-k)
    {
        v[i + k] = v[i];
    }

    // insert k elements at the beginning
    for (int i = 0; i < k; i++) // O(k)
    {
        v[i] = temp[i];
    }
}

void solve()
{
    vector<int> v = input_vector();
    int k;
    cin >> k;

    rotate_k_times_faster(v, k);
    print_vec(v);
}

int main()
{
    solve();
}