#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;
#define INF 1000001

int N;
vector <int> A;
int num[1000001]; // 수열의 길이를 만족하는 숫자 중 가장 작은 숫자를 저장. 
int D[1000001]; // 해당 숫자까지 보았을 때, 가능한 가장 큰 수열의 길이를 저장. 

int main(){

    cin >> N;
    for (int i=0; i<N; i++){
        int x;
        cin >> x;
        A.push_back(x);
    }
    
    for (int i=1; i<sizeof(num)/sizeof(int); i++){
        num[i] = INF;
    }

    D[0] = 1;
    num[0] = 0;
    num[1] = A[0];
    int max_length = 1;
    for (int i=1; i<N; i++){
        if (D[i] > D[i-1]){
            D[i] = D[i-1] + 1;
            num[D[i]] = min(A[i], num[D[i]]);
        }
        else {
            int index = lower_bound(num, num+sizeof(num)/sizeof(int), A[i]) - num;
            if (index == 0) index ++;
            num[index] = A[i];
            D[i] = index;

        }
        if (D[i] > max_length) max_length = D[i];
         
    }

    cout << max_length;

}