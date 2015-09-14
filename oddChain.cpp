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

int bigNumHailstone(vector<int> bigNum){
    int count = 0;
    bool isItOne = false;
    while(!isItOne){
    isItOne = true;
    if(bigNum[bigNum.size() - 1] & 1){
        bigNumMultiplyByX(bigNum, 3);
        bigNumAddOne(bigNum);
    }
    else {
        bigEvenNumDivideBy2(bigNum);
    }
    for(int i = 0; i < bigNum.size() - 1; i++){
        if(bigNum[i]) isItOne = false;
    }
    if(bigNum[bigNum.size() - 1] != 1) isItOne = false;
    count++;
    }
    return count;
}


int main(){
vector<int> n(100, 0);
n[n.size() - 1] = 1;
int longest = 0;
while(n[0] < 10){
    bigNumMultiplyByX(n, 2);
    bigNumAddOne(n);
    bool nonzeroBeg = false;
        for(int i = 0; i < n.size(); i++){
            if(n[i]) nonzeroBeg = true;
            if(nonzeroBeg){
                cout << n[i];
            }
        }
        cout << " Hailstone count: " << bigNumHailstone(n);
        if(bigNumHailstone(n) > longest) longest = bigNumHailstone(n);
        cout << endl << endl;
}

cout << " Size: " << n.size() << endl;
cout << " Longest: " << longest << endl;
}
