// #include<bits/stdc++.h>
// using namespace std;
// // int countTotalSetBits(int n) {
// //     n++; // To include 'n' in range 0..n

// //     int count = 0;
// //     for (int i = 0; (1 << i) <= n; i++) {
// //         int totalPairs = n / (1 << (i + 1));
// //         count += totalPairs * (1 << i);
// //         int remainder = n % (1 << (i + 1));
// //         if (remainder > (1 << i))
// //             count += remainder - (1 << i);
// //     }

// //     return count;
// // }
// int countSetBits(int n) {
//     if (n == 0)
//         return 0;

//     // Find the most significant bit position
//     int x = log2(n);

//     // Bits till 2^x - 1
//     int bitsUpto2PowerX = x * (1 << (x - 1));

//     // Set bits from 2^x to n
//     int msb2PowerXToN = n - (1 << x) + 1;

//     // Remaining part: from n - 2^x
//     int rest = n - (1 << x);

//     return bitsUpto2PowerX + msb2PowerXToN + countSetBits(rest);
// }

// int main(){
//     int n;
//     cin >> n;
//     cout<<pow(2,n)<<endl;
//     cout << pow(2,n-1)*n;
// }


#include <iostream>
#include <cmath>
using namespace std;

int countTotalSetBits(int n) {
    if (n == 0)
        return 0;

    // Find the position of the most significant bit (MSB)
    int x = log2(n);

    // Count of set bits from 0 to 2^x - 1
    int bitsUpTo2PowX = x * (1 << (x - 1));

    // Count of set bits from 2^x to n
    int msb2PowXToN = n - (1 << x) + 1;

    // Remaining numbers: recurse on the leftover part
    int remaining = n - (1 << x);

    return bitsUpTo2PowX + msb2PowXToN + countTotalSetBits(remaining);
}

int main() {
    int n;
    cin >> n;
    cout << "Total set bits from 0 to " << n << " = " << countTotalSetBits(n) << endl;
    return 0;
}
