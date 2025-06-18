#include<bits/stdc++.h>
using namespace std;
typedef map<double, int, greater<int>> mdid;
double get_deviation(int n, double guess){
    double right_val = sqrt(n);
    double diff = abs(right_val - guess);
    double perc_diff = diff / right_val *100;
    return perc_diff;
}

double  get_sqrt_vedic(int n){
    int perfect_root = sqrt(n);
    int diff = n - perfect_root * perfect_root;
    double ans = perfect_root + (diff / (2.0 * perfect_root));
    return  ans;
}
void print_deviation_list(mdid deviation_list){
    for(auto[deviation, n]: deviation_list){
        cout << deviation << " " 
    }

}
mdid list_deviations(int range, double tolernace = 5){
    mdid deviation_list;
    for(int i=2; i <= range ; i++){
        int n = i;
        double vedic_sqrt = get_sqrt_vedic(n);
        double deviation = get_deviation(n, vedic_sqrt);
        deviation_list[deviation] = n;
        if(deviation > tolernace){
            cout << n << " " <<  vedic_sqrt << " " << deviation << " \n" ;

        }
    }
    return deviation_list;
}
int main(){
    int n;
    cin >> n;
    double tolerance; 
    cin >> tolerance;

    list_deviations(n,tolerance);
}