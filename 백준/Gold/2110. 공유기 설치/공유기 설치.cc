#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

int N, C; //N : 집의개수, C: 
vector <int> router; // 집 저장

int ShareCount(int mid){

    int prev = router[0];
    int count = 1;
    
    for(int i=1; i<N; i++){
        if (router[i] - prev >= mid){
            count++;
            prev = router[i];
        }
    }

    return count;
}
int main(){
    cin >> N >> C;
    for (int i=0; i<N; i++){
        int x;
        cin >> x;
        router.push_back(x);
    }
    int ans;
    sort(router.begin(), router.end());

    int l_gap = 1; 
    int r_gap = router[N-1];

    while(l_gap <= r_gap){
        int mid_gap = (l_gap + r_gap) / 2;

        if(ShareCount(mid_gap) >= C){
            ans = mid_gap;
            
            l_gap = mid_gap+1;
        }
        else{
            r_gap = mid_gap - 1;
        }
    }

    cout << ans;

}
