/*

File: bigNumHailstone.cpp
By: Ellis, M. J.
Creation: September 9, 2015
Last updated:
    By Ellis, M.J.
    September 9, 2015

*/
#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

const int SIZE = 100;

void bigEvenNumDivideBy2(vector<int> &bigEvenNum){
    for(int j = bigEvenNum.size() - 1; j >= 0; j--){
        bigEvenNum[j] /= 2;
        if(j){
            if(bigEvenNum[j-1] & 1) bigEvenNum[j] += 5;
        }
    }
}

void bigNumMultiplyByX(vector<int> &bigNum, int x){
    for(int j = bigNum.size() - 1; j >= 0; j--){
        bigNum[j] *= x;
        if(j != bigNum.size() - 1 && bigNum[j + 1]){
            bigNum[j] += bigNum[j + 1] / 10;
            bigNum[j + 1] %= 10;
        }
    }
}

void bigNumAddOne(vector<int> &bigNum){
    bigNum[bigNum.size() - 1]++;
    for(int j = bigNum.size() - 1; bigNum[j] == 10; j--){
        bigNum[j] = 0;
        if(!j) bigNum.insert(bigNum.begin(), 0);
        bigNum[j-1]++;
    }
}

int main(){
    vector<int> bigNum = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 7, 9, 4, 0, 0, 3, 9, 3, 6, 8, 9, 7, 1, 7, 4, 5, 9, 1, 2, 4, 2, 2, 3};
    bool isItOne = false;
/*    srand(time(NULL));
    for(int i = 0; i < SIZE; i++) bigNum[i] = rand() % 10;
 */   cout << "Your starting number: ";
    for(int i = 0; i < bigNum.size(); i++){
        cout << bigNum[i];
    }
    while(!isItOne){
    isItOne = true;
    cout << ' ';
    if(bigNum[bigNum.size() - 1] & 1){
        bigNumMultiplyByX(bigNum, 3);
        bigNumAddOne(bigNum);
    }
    else {
        bigEvenNumDivideBy2(bigNum);
    }
        bool nonzeroBeg = false;
        for(int i = 0; i < bigNum.size(); i++){
            if(bigNum[i]) nonzeroBeg = true;
            if(nonzeroBeg){
                cout << bigNum[i];
            }
    }
    for(int i = 0; i < bigNum.size() - 1; i++){
        if(bigNum[i]) isItOne = false;
    }
    if(bigNum[bigNum.size() - 1] != 1) isItOne = false;
    }
    return 0;
}
