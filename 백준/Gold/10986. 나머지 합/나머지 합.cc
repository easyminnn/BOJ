#include <iostream>
#include <vector> 

using namespace std;

int N, M;
long long int arr[1000001];
long long int remain[1000];
int main(){
    cin >> N >> M;

    for (int i=1; i<=N; i++){
        cin >> arr[i];
        arr[i] = (arr[i-1] +arr[i]) % M;
        remain[arr[i]] ++;
    }

    long long int result = remain[0];

    for (int i=0; i<1000; i++)
    {   
        
        if (remain[i] >= 2)
        {
            result += remain[i] * (remain[i]- 1) / 2;
        }
    }
    

    cout << result ;

    



}