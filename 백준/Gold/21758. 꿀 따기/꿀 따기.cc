#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N;
int Bee[100001];
int BeeSum[100001];

int main(){
    cin >> N;

    for (int i=1; i<=N; i++)
    {
        cin >> Bee[i];
        BeeSum[i] = Bee[i] + BeeSum[i-1];
    }

    int MaxResult = 0;

    // 1. ㅂ ㅂ 꿀통
    for (int i=2; i<=N-1; i++)
    {
        MaxResult = max(MaxResult, BeeSum[N] - BeeSum[1] - Bee[i] + BeeSum[N] - BeeSum[i]);
    }

    // 2. ㅂ 꿀통 ㅂ
    for (int i=2; i<=N-1; i++)
    {
        MaxResult = max(MaxResult, BeeSum[i] + BeeSum[N-1] - BeeSum[i-1] - Bee[1]);
    }

    // 3. 꿀통 ㅂ ㅂ
    for (int i=2; i<=N-1; i++)
    {
        MaxResult = max(MaxResult, BeeSum[i-1] - Bee[i] + BeeSum[N-1] );
    }

    cout << MaxResult;



    
}
