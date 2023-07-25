#include <iostream>
#include <vector> 

using namespace std;

int T, N;
long long int f[1000001]; // f[i] = i의 약수의 합


int main(){

    // T(태스트케이스의 개수) 를 먼저 넣는다면, 시간초과가 걸리므로
    // 미리 f값을 1000000까지 for문 하나로 구하는 방식으로 접근하는 것이 좋다, 
    // 더군다나 1000000(백만) 까지의 약수의 합을 구해야 하므로, 시간초과를 내지 않는
    // "에라토스테네스의 체" 를 이용하는 것이 좋다!(이에 대한 개념은 나무위키 참고)

    for (int i=1; i<=1000000; i++)
    {
        for (int j=1; j * i<=1000000; j++)
        {
            f[j*i] += i;
        }
        f[i] += f[i-1];

    }


    cin.tie(0);
    cout.tie(0);
    cin >> T;

    while(T--)
    {
        cin >> N; 
        cout << f[N] << "\n";
    }




}