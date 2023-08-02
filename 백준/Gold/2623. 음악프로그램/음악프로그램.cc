#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
vector <int> edge[100001]; //간선 
int inDegree[100001]; // 진입차수
vector <int> result;

void TopoLogicalSort(){

    queue <int> q;

    for (int i=1; i<=N; i++){
        if (inDegree[i] == 0)
        q.push(i);
    }
    
    while(!q.empty()){

        int cur = q.front();
        result.push_back(cur);
        q.pop(); 
        
       

        
        for (int j=0; j<edge[cur].size(); j++){
            int next = edge[cur][j];
            if(--inDegree[next] == 0) q.push(next);
        }
    }

}


int main(){

    cin >> N >> M;
    for (int i =0; i< M; i++){
        int num;
        cin >> num;
        for (int j=0; j<num; j++){
            int pdlist[1001];
            cin >> pdlist[j];
            if (j>=1){
                edge[pdlist[j-1]].push_back(pdlist[j]);
                inDegree[pdlist[j]]++;
            }
        }
    }

    TopoLogicalSort();


    if(result.size() != N ) cout << 0;
    else{
        for (int i=0; i<result.size(); i++)
        {
            cout << result[i] << "\n";
        }
    }
}