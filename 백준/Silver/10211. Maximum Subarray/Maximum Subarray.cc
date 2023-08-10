#include <iostream>   
using namespace std;
 
int arr[1001];   
int dp[1001];   // dp[i]는 i를 포함하는 부분 수열의 최대 합

int getMax(int a, int b) {
    if (a >= b) return a;
    else return b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    cin >> t;

    while (t--) { 
        cin >> n;

        int max = -987654321;   

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            
            dp[i] = getMax(dp[i - 1] + arr[i], arr[i]); 
            max = getMax(max, dp[i]);
             
        }
        cout << max << "\n";
    }
}