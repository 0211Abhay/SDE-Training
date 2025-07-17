#include <bits/stdc++.h>
using namespace std;

struct Sde2
{
    double d;  // 8
    int i;     // 4
    char c[4]; // 4
};

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
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        // cout << a[i] << "\t";
        cout << v[i] << "\t";
    }
    cout << "\n";
}

void playing_with_structs()
{
    Sde2 obj1, obj2;
    obj1.d = 1.2;

    obj2.i = 1;
    obj2.d = 2;

    Sde2 *p1 = &obj1, *p2 = &obj2;
    cout << (p2 - p1) << '\n';
    cout << (p1++) << "\t" << (p2++) << "\n";
    cout << (p1++) << "\t" << (p2++) << "\n";
}

void populate_p1(Sde2 *p1)
{
    p1->d = 4.0;
    p1->i = 1;
    p1->c[0] = '1';
    p1->c[1] = '2';
    p1->c[2] = '3';
    p1->c[3] = '4';
}

void array_of_struct()
{
    // int a[5];
    Sde2 collection[3];
    Sde2 *p1 = &collection[0], *p2 = &collection[1];
    populate_p1(p1);
    cout << (p1++) << "\t" << (p2++) << "\n";
    // cout << p2 - p1 << "\n";
}

void playing_with_pointers()
{
    // playing_with_structs();
    array_of_struct();
}

void solve()
{
    playing_with_pointers();
}

int main()
{
    solve();
}