#include <iostream>
#include <algorithm>
#include <deque>
#include <cstring>

using namespace std;

int N, M;
int GetNum[50];
int num[50];
deque <int> dq;

int main(){
    
    cin >> N >> M;
    int cnt =0;

    for (int j=1; j<=N; j++){
            dq.push_back(j); // 최초의 덱 만들기
        }
    for (int i=0 ; i< M ; i++){
        cin >> GetNum[i];  // 추출해야하는 수를 받기

       

        int index;
        for (int k = 0; k < dq.size(); ++k) {
			if (dq[k] == GetNum[i]) {
				index = k;
				break;
			}
        } //GetNum의 index 찾기
        int tmp ;
        if (index < dq.size() - index + 1){
            //왼쪽
            
            while(1){
                //왼쪽으로 한 칸 이동 : 
                tmp = dq.front();
                if (tmp == GetNum[i]) 
                {   
                    dq.pop_front();
                    break;
                } 
                cnt ++;
                dq.pop_front();
                dq.push_back(tmp);
            }

        }

        else{

            while(1){
                //오른쪽으로 한 칸 이동:
                tmp = dq.back();
                cnt ++;
                dq.pop_back();
                dq.push_front(tmp);
                if (tmp == GetNum[i]) 
                {   
                    dq.pop_front();
                    break;      
                }
            }
        }



    }

    cout << cnt ;




}