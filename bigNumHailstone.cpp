/*

File: bigNumHailstone.cpp
By: Ellis, M. J.
Creation: September 9, 2015
Last updated:
    By Ellis, M.J.
    September 12, 2015

*/
#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void readInBigNum(vector<int> &bigNum){
    int input;
    cout << "Enter digits of large number: ";
    while(cin >> input) bigNum.push_back(input); //any noninteger entered will end the loop. For now we're presuming one digit per integer entered, though that can be fixed with a separate function later.

}

void writeBigNum(vector<int> &bigNum){
        bool nonzeroBeg = false;
        for(int i = 0; i < bigNum.size(); i++){
            if(bigNum[i]) nonzeroBeg = true;
            if(nonzeroBeg){
                cout << bigNum[i];
            }
        }
}

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
    vector<int> bigNum = {0};
    bool isItOne = false;
/*    srand(time(NULL));
    for(int i = 0; i < SIZE; i++) bigNum[i] = rand() % 10;
 */
    readInBigNum(bigNum);
    cout << "Your starting number: ";
    writeBigNum(bigNum);
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
    writeBigNum(bigNum);
    for(int i = 0; i < bigNum.size() - 1; i++){
        if(bigNum[i]) isItOne = false;
    }
    if(bigNum[bigNum.size() - 1] != 1) isItOne = false;
    }
    return 0;
}
