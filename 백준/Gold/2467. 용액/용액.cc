#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

int N;
long long liquid[100001];

int main(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> liquid[i];
    }

    
        int l = 0;
        int r = N-1;
        int min_r, min_l;
        int result = liquid[r] + liquid[l];
        while(r > l){
            if(abs(result) >= abs(liquid[l] + liquid[r])){
                result = liquid[r] + liquid[l];
                min_r = r;
                min_l = l;
 
            }
            
            if(liquid[l] + liquid[r] < 0) l++;
            else r--;   
        }

        cout << liquid[min_l] << " " << liquid[min_r] << "\n";
        return 0;
    

}