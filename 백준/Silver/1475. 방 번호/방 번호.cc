#include <iostream>

using namespace std;

int numArr[10];
int main(){
    int n;
    cin >> n;

    while(n >9){
        int temp = n % 10; //나머지 
        n = n/10;

        numArr[temp] +=1;
    }
    numArr[n] +=1;
    int max = 0;
    int maxindex = 10;
    numArr[6] +=numArr[9];

    if (numArr[6] % 2 ==0){
        numArr[6] /=2;
        numArr[9] = numArr[6];
    }
    else{
        numArr[6] /=2;
        numArr[6]++;
        numArr[9] = numArr[6];
    }

    for(int i =0; i<=9; i++){
        if (max< numArr[i]) {
            max = numArr[i];
        }
    }

    cout <<max;
}
