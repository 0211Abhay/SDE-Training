#include<bits/stdc++.h>
using namespace std;
int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        while (left < right) {
            cout << left << " " << right << " " << shift << endl;
            left >>= 1;
            right >>= 1;
            shift++;
        }
        cout << shift <<" "<< (left << shift)<<endl;
        return left << shift;
    }
int main()
{
    int left,right;
    cin >> left;
    cin >> right;
    int ans = rangeBitwiseAnd(left,right);

    
}