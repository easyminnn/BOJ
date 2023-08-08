#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    
    vector <pair <int, int>> p1; // 조건을 만족하는 값을 저장.
    int p_left= 0;
    int p_right = 0; //투 포인터
    
    for (int i=1; i<sequence.size(); i++){
        sequence[i] += sequence[i-1]; 
    }
    
    while (p_left <= p_right && p_right < sequence.size()){
        int pSum;
        
        if (p_left == 0) pSum = sequence[p_right];
        else  pSum = sequence[p_right] - sequence[p_left - 1];
        
        if (pSum == k){
            p1.push_back({p_left, p_right});
            p_left++;
            p_right++;
        }
        else if (pSum > k){
            p_left++;
        }
        else p_right++;
        
    }
    pair <int, int> minresult = {0, 1000000};
    
    for(int i=0; i<p1.size(); i++){
        if (p1[i].second-p1[i].first < minresult.second-minresult.first){
            minresult.first = p1[i].first;
            minresult.second = p1[i].second;
        }
        
    }

    return {minresult.first, minresult.second};
}