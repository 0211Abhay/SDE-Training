#include<bits/stdc++.h>
using namespace std;
int chalkReplacer(vector<int>& chalk, int k) {
        // Find the sum of all elements.
        int sum = 0;
        for (int i = 0; i < chalk.size(); i++) {
            sum += chalk[i];
            if (sum > k) {
                break;
            }
        }
        // Find modulo of k with sum.
        k = k % sum;
        for (int i = 0; i < chalk.size(); i++) {
            if (k < chalk[i]) {
                return i;
            }
            k = k - chalk[i];
        }
        return 0;
    }
int main() {
    int n, k;
    cout << "Enter number of students: ";
    cin >> n;

    vector<int> chalk(n);
    cout << "Enter chalk used by each student:\n";
    for (int i = 0; i < n; ++i) {
        cin >> chalk[i];
    }

    cout << "Enter value of k: ";
    cin >> k;

    int result = chalkReplacer(chalk, k);
    cout << "Output: " << result << endl;

    return 0;
}