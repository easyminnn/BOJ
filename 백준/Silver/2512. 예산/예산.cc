#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

int N; // 지방의 수 
int RequestMoney[10001]; // 각 지방별 예산요청액 
int high = 0; //상한액 

int main(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >>RequestMoney[i];
        if (high < RequestMoney[i]) high = RequestMoney[i];
    }
    long long SumRequest; // 총 예산
    long long sum = 0; // 계산해야하는 예산
    cin >> SumRequest;

    int low = 0;
    int mid, result ;


    while(high >= low ){
        mid = (high + low ) / 2 ;    
        //cout << low << " " << mid <<  " " << high << "\n";
        sum = 0;
        
        for (int i=0; i< N; i++){
            sum += min(RequestMoney[i], mid);
        }

        if (sum <=SumRequest){ // 예산액을 초과하지 않는 경우(넉넉할 떄 )
            low = mid+1;
            result = mid;
        }
        else // 예산액을 초과하는 경우 
            high = mid-1;
        
        

    }

    cout << result;




}