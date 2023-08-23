#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int dp[101];
int arr[101];
int LISNum = 0;

void LIS(){ //LIS : O(n^2)
    
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 1; j--)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        LISNum = max(dp[i], LISNum);
    }
 
    
}
int main(){

    priority_queue <pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    cin >> n;
    for (int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        pq.push({x,y});
    }
    int index=0;
    while(!pq.empty()){
        index++;
        arr[index] = pq.top().second;
        pq.pop();
    }

    LIS();

    cout << n - LISNum;
}