#include <bits/stdc++.h>
using namespace std;


long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> arr(n + 2, 0);  

    for (int i = 0; i < queries.size(); i++) {
        int a = queries[i][0];
        int b = queries[i][1];
        int k = queries[i][2];

        arr[a] += k;
        arr[b + 1] -= k;
    }

    long sum = 0, maxSum = 0;
    for (int i = 1; i <= n; i++) {
        sum += arr[i];
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

int main() {
    int n, m;
    cout << "Enter size of array (n): ";
    cin >> n;

    cout << "Enter number of queries: ";
    cin >> m;

    vector<vector<int>> queries(m, vector<int>(3));
    cout << "Enter queries in format (a b k):\n";
    for (int i = 0; i < m; ++i) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }

    long result = arrayManipulation(n, queries);
    cout << "Maximum value after all operations: " << result << endl;

    return 0;
}
