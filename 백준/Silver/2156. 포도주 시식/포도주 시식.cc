#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int grape[10001];
int sumgrape[10001];

int main()
{
    cin >> n;

    for (int i=1; i<=n; i++)
    {
            cin >> grape[i];  
    }
    sumgrape[0] = 0;
    sumgrape[1] = grape[1];
    sumgrape[2] = grape[1]+grape[2];
    for (int i=3; i<=n; i++)
    {
            sumgrape[i] = max(sumgrape[i-2]+grape[i], 
            max(sumgrape[i-3]+grape[i-1]+grape[i], sumgrape[i-1]));

            
    }
  
    cout << sumgrape[n];   
    
}