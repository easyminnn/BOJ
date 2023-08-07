#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b) {
    string days[7] = {"THU","FRI","SAT","SUN","MON","TUE","WED"};
    int month[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int PassedDays = 0; 
    for (int i=0; i<a; i++){
        PassedDays += month[i];
    }
    PassedDays += b;
    PassedDays = PassedDays % 7;
    
    string answer = days[PassedDays];
    return answer;
}