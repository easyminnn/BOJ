#include <iostream> 
#include <algorithm>

using namespace std;

int n;
long long int addArr[1000001];


int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        addArr[1] = 1;
        addArr[2] = 2;
        addArr[3]  = 4;
        if (n<4) {
            cout << addArr[n] <<"\n" ;
        }
        else{
            for (int i=4; i<=n; i++)
            {
                addArr[i] = addArr[i-3]  + addArr[i-2] + addArr[i-1] ;
                addArr[i] = addArr[i] % 1000000009;
            }
            cout << addArr[n] <<"\n" ;
        }
    }

}