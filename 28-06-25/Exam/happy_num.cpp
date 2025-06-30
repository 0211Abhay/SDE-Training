int count_square_sum(int n){
    int temp = n;
    int ans =0;

    while(temp){
        ans += (temp %10) * (temp%10);
        temp/=10;
    }
    return ans;
}
    bool isHappy(int n) {
        int temp = n;
        int ans = 0;
        int count = 8;
        
        while(count-- && temp){
            int ans = count_square_sum(temp);
            cout << temp << " " << ans << " " << count << endl;
            if(ans == 1){
                return true;
            }
            temp = ans;
            
        }
        return false;


    }