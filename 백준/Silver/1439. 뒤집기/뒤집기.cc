#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

string s;

int main()
{
    cin >> s;
    int count1 = 0; 
    int count0 = 0;
    char forwardnum = s[0];
    if (forwardnum == '1') count1 ++;
    else count0++;
    
    for (int i=1; i<s.length(); i++)
    {   
        //cout << forwardnum << " " << count1 << " " << count0 << "\n"; 
        if (forwardnum != s[i] && forwardnum == '0') 
        {
            forwardnum = s[i];
            count1++;
        }
        else if (forwardnum != s[i] && forwardnum == '1') 
        {
            forwardnum = s[i];
            count0++;
        }
    }

    cout << min(count1, count0) ;












}