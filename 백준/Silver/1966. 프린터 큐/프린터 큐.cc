#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>

using namespace std;

int T, N, M; // N: 문서의 개수, M: 현재 큐에서 몇 번쨰에 놓여 있는지? 

bool compare(int a, int b){
    return a > b;

}

int main(){
    cin >> T;


    while(T--){
        cin >> N >> M;
        deque <pair<int, int>> dq;
        int SortedDocs[101];
        queue <int> MaxNum; // 최대값 문서 관리 대장. 

        for (int i=0; i<N; i++){
            cin >> SortedDocs[i];
            dq.push_back({SortedDocs[i], i});
        }
        
        sort(SortedDocs, SortedDocs+N, compare);
        for (int i=0; i<N; i++){
            MaxNum.push(SortedDocs[i]);
        }

       
        
        int count = 0;
        while(1){
            // 처음 값이 가장 크거나 같다면, count 확인 후 MaxNum pop하기. 큐에서도 pop.
    
            if (dq.front().first >= MaxNum.front()){
                count++;
                MaxNum.pop();
                if (dq.front().second == M){
                    break;
                }
                dq.pop_front();
            }

            else{
                int a = dq.front().first;
                int b = dq.front().second;
                dq.pop_front();
                dq.push_back({a, b});
            }

            // 이게 아니라면 이 값을 가장 마지막으로 보내기. 그리고 count 1 증가. 
            
            // 이렇게 pop된 숫자가 SortedDocs.second == M 이다 . 그러면 while문을 멈추고 이 count를 반환. 
        }

        cout << count << "\n";

    }

}