#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T;
int N;
int ans;
vector <pair<int, int>> app;


bool compare(const pair<int, int> &a, const pair<int, int> &b)
{

    return a.second < b.second; 
}


int main(){
   
    cin >> T;
    while(T--){
        cin >> N;
        
        int x, y;
        ans = 1;
        
        for(int i=0; i<N; i++)
        {
            cin >> x >> y;
            app.push_back({x,y});
        }
        
        sort(app.begin(), app.end());
        int temp = 0;
        
        for (int i=1; i<N; i++)
        {
            if (app[temp].second > app[i].second) 
            {
                ans++;
                temp = i;
            }
            
        }
        
        cout << ans << "\n";
        app.clear();

  
    }
}
    
    
    

