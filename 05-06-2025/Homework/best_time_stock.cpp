#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int lowest_val = prices[0];
        int highest_val = -1;
        for(int i=1;i<prices.size() ; i++){
            if (prices[i]>prices[i-1]){
                highest_val = prices[i];
                maxP = max(maxP, highest_val - lowest_val);
            }
            else if(prices[i] < lowest_val) {
                lowest_val = prices[i];
            }
        }
        return maxP;
    }

    int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter stock prices for each day:\n";
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }

    int result = maxProfit(prices);
    cout << "Output: " << result << endl;

    return 0;
}