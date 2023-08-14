#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <set>

using namespace std;

int T, K;


int main(){
    priority_queue <long long, vector<long long>, greater<long long>> chapter;
    cin >> T;
    while(T--){
        cin >> K;
        long long result = 0;
        for (int i=0; i<K; i++){
            int x;
            cin >> x;
            
            chapter.push(x);
        }
        
        while(chapter.size() != 1){
            long long first = chapter.top();
            chapter.pop();
            long long second = chapter.top();
            chapter.push(second+first);
            result+=second + first;
            chapter.pop();
        }

       
        while(!chapter.empty()) chapter.pop();

        cout << result << "\n";
        


    }


}