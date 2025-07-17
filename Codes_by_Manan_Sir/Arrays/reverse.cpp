#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // reverse
    // int i = 0, j = n - 1;
    // while (i < j)
    // {
    //     // int temp = a[i];
    //     // a[i] = a[j];
    //     // a[j] = temp;
    //     swap(a[i], a[j]);
    //     i++;
    //     j--;
    // }

    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        swap(a[i], a[j]);
    }

    // print array
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
    cout << "\n";
}