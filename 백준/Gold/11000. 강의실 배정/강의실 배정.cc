#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <set>


using namespace std;

int N;
pair <int, int> p[200000];

int main(){

    cin >> N;
    for (int i=0; i<N; i++){
        int x, y;
        cin >> x >> y; 
        p[i].first = x;
        p[i].second = y;
    }
    sort(p, p+N);
    priority_queue <int, vector<int>, greater<int>> pq;

    pq.push(p[0].second);

    for (int i=1; i<N; i++){
       if (p[i].first < pq.top()){ //top에 있는 것과 시간이 겹친다면(강의실추가)
            pq.push(p[i].second);
        }
        else{ //겹치지 않는다면 
            pq.pop();
            pq.push(p[i].second);
        }
    }


    cout << pq.size();





}