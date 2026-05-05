#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

typedef vector<int> vi;
typedef map<int, int> mii;

#define forn(i, n) for (int i = 0; i < n; i++)
#define pb push_back

vi input_vector()
{
    int n;
    cin >> n;
    vi v(n);
    forn(i, n)
    {
        cin >> v[i];
    }
    return v;
}

void print_vec(vi &v)
{
    forn(i, v.size())
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

// Naive recursive Catalan
int catalan(int n){
    if(n <= 1) return 1;
    int result = 0;
    for(int i = 0; i < n ; i++){
        result += catalan(i) * catalan(n - i - 1);
    }
    return result;
}
unsigned long long  catalan_memo(int n, vector<unsigned long long> &memo){
    if(memo[n] != -1){
        return memo[n];
    }
    if(n <= 1){
        return memo[n] = 1;
    }

    memo[n] = 0;
    for(int i = 0; i < n ; i++){

        memo[n] += catalan_memo(i, memo) * catalan_memo(n - i - 1, memo);

    }
    return memo[n];
}

void solve()
{
    int n;
    cin >> n;
    vector<unsigned long long> memo(n+1, -1);
    memo[0] = memo[1] = 1;
    // Start time
    auto start = high_resolution_clock::now();

    unsigned long long  result = catalan_memo(n, memo);
    cout << "Catalan(" << n << ") = " << result << endl;

    // End time
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(end - start);

    cout << "Time taken: " << duration.count() << " s" << endl;
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
