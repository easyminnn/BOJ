#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long  arr[2][100];

int main(){
    int N;
    arr[0][0] = 1;
    arr[0][1] = 1;
    arr[1][1] = 0;
    
    for (int i=2; i<92; i++ ){
        arr[0][i] = arr[0][i-1] + arr[1][i-1];
        arr[1][i] = arr[0][i-1];
    }
    cin >> N;
    cout << arr[0][N-1]+arr[1][N-1] ;
}