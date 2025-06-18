#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int s = 0; 
        int e = letters.size() - 1;
        int mid;
        char ans = ' ';
        while (s <= e) {
            mid = s + (e - s) / 2;
            if (s == e && letters[mid] > target) return letters[s];
            else if (letters[mid] <= target) {
                s = mid + 1;
            } else {
                e = mid - 1;
                ans = letters[mid];
            }
        }
        if (ans != ' ') return ans;
        else return letters[0]; 
    }
};

int main() {
    int n;
    cout << "Enter number of letters: ";
    cin >> n;

    vector<char> letters(n);
    cout << "Enter sorted letters:\n";
    for (int i = 0; i < n; ++i) {
        cin >> letters[i];
    }

    char target;
    cout << "Enter target character: ";
    cin >> target;

    Solution sol;
    char result = sol.nextGreatestLetter(letters, target);

    cout << "Next greatest letter: " << result << endl;

    return 0;
}
