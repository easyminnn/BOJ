#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;
int newList[500];
int N; // 카드의 수


void makeNewArr(int i, int inum, int j, int jnum)
{
    int gap = (jnum - inum) / (j-i);
    newList[0] = inum - i * gap;

    for (int i=1; i<N; i++)
    {
        newList[i] = newList[0] + i * gap;
    }

}

int main(){
    int cardList[501];
    int result;
    int minresult = 500;

    cin >> N;
    for (int i=0; i<N; i++)
        cin >> cardList[i];

    
    for (int i=0; i<N-1; i++)
    {
        for (int j=i+1; j<N; j++)
        {
            result = 0;
            if (abs(cardList[j]-cardList[i]) % (j-i) == 0) 
            {
                makeNewArr(i, cardList[i], j, cardList[j]);
                for (int k=0; k<N; k++)
                {
                    if (newList[k] != cardList[k]) result++;
                }
                if (result < minresult) minresult = result;
            }
        }
    }
    cout << minresult;
    


}