#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    int N; 

    queue <long long> q;
    int cnt = -1;

    cin >> N;

    for (int i=0; i<=9; i++){
        q.push(i);
        if (cnt == N){
            cout << i;
            return 0;
        }
    }
    long long x;

    while(cnt < N){
        if (q.empty()) break;
        x = q.front();
        
        int last = x % 10;
        q.pop();
        cnt++;
        for (int i=0; i<last; i++){
            q.push(x * 10 + i);
        }
    }

    if (cnt != N) cout << -1;
    else cout << x;



}