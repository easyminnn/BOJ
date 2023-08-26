#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>


using namespace std;
long long N, C; // 물건개수, 최대무게
long long stuff[31];
vector <long long> part1;
vector <long long> part2;
long long cnt = 0;

void dfs(int start, int end, vector <long long>& part, long long sum){
    if(start > end){
        part.push_back(sum);
        return ;
    }
    else { //dfs 2개 : 해당 인덱스(start)를 더해, 말아? 
        dfs(start + 1, end, part, sum); 
        dfs(start + 1, end, part, sum + stuff[start]);
    }
}


int main(){
    cin.tie(NULL);
    cin >> N >> C;
    for (int i=0; i<N; i++){
        cin >> stuff[i];
    }

    dfs(0,N/2, part1, 0);
    dfs(N/2 + 1, N-1, part2, 0);
    sort(part2.begin(), part2.end());
    
    for (int i=0; i < part1.size(); i++){
        cnt += upper_bound(part2.begin(), part2.end(), C - part1[i]) - part2.begin();
    }

    cout << cnt;


}