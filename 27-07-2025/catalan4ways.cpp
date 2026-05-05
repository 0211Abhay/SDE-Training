#include <iostream>
#include <vector>
using namespace std;

// 1. Recursive Approach
int catalan_recursive(int n) {
    if (n <= 1) return 1;
    int res = 0;
    for (int i = 0; i < n; i++)
        res += catalan_recursive(i) * catalan_recursive(n - i - 1);
    return res;
}

// 2. DP - Memoization
int catalan_memo(int n, vector<int> &dp) {
    if (n <= 1) return 1;
    if (dp[n] != -1) return dp[n];
    
    dp[n] = 0;
    for (int i = 0; i < n; i++)
        dp[n] += catalan_memo(i, dp) * catalan_memo(n - i - 1, dp);
    return dp[n];
}

// 3. DP - Tabulation
vector<int> catalan_tabulation(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++)
        for (int j = 0; j < i; j++)
            dp[i] += dp[j] * dp[i - j - 1];

    return dp;
}

// 4. Tabulation with Space Optimization
vector<int> catalan_space_optimized(int n) {
    vector<int> catalan(n + 1, 0);
    catalan[0] = catalan[1] = 1;

    for (int i = 2; i <= n; i++) {
        catalan[i] = 0;
        for (int j = 0; j < i; j++)
            catalan[i] += catalan[j] * catalan[i - j - 1];
    }
    return catalan;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "\n1. Recursive Approach:\n";
    for (int i = 0; i < n; i++)
        cout << catalan_recursive(i) << " ";
    cout << "\n";

    cout << "\n2. DP - Memoization:\n";
    vector<int> memo(n + 1, -1);
    for (int i = 0; i < n; i++)
        cout << catalan_memo(i, memo) << " ";
    cout << "\n";

    cout << "\n3. DP - Tabulation:\n";
    vector<int> tab = catalan_tabulation(n - 1);
    for (int i = 0; i < n; i++)
        cout << tab[i] << " ";
    cout << "\n";

    cout << "\n4. Space Optimized Tabulation:\n";
    vector<int> opt = catalan_space_optimized(n - 1);
    for (int i = 0; i < n; i++)
        cout << opt[i] << " ";
    cout << "\n";

    return 0;
}
