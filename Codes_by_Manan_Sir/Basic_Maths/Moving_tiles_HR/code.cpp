#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    int l, s1, s2, query_count;
    long long q;
    cin >> l >> s1 >> s2 >> query_count;
    forn(i, query_count)
    {
        cin >> q;
        cout << (sqrt(2) * l - sqrt(2 * q)) / abs(s1 - s2) << "\n";
    }
}