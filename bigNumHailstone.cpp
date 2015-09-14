/*

File: bigNumHailstone.cpp
By: Ellis, M. J.
Creation: September 9, 2015
Last updated:
    By Ellis, M.J.
    September 13, 2015

*/
#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

/*
Reads in a large number from user input. Will update using a string-to-vector function later.
*/
void readInBigNum(vector<int> &bigNum){
    int input;
    cout << "Enter digits of large number: ";
    while(cin >> input) bigNum.push_back(input); /*any noninteger entered will end the loop.
    For now we're presuming one digit per integer entered. */
}

/*
Writes out a large number from a vector.
*/
void writeBigNum(vector<int> &bigNum){
        bool nonzeroBeg = false;
        for(int i = 0; i < bigNum.size(); i++){
            if(bigNum[i]) nonzeroBeg = true;
            if(nonzeroBeg){
                cout << bigNum[i];
            }
        }
}

/*
Takes a large number (as a vector) and divides it by two. Presumes it is even, as it updates a vector<int>. If odd it would return answer - .5.
*/
void bigEvenNumDivideBy2(vector<int> &bigEvenNum){
    for(int j = bigEvenNum.size() - 1; j >= 0; j--){
        bigEvenNum[j] /= 2;
        if(j){
            if(bigEvenNum[j-1] & 1) bigEvenNum[j] += 5;
        }
    }
}

/*
Takes a vector<int> and an int factor. Multiplies the number stored in the vector by the factor given.
Currently not designed for dealing with factors larger than 10.
*/
void bigNumMultiplyByX(vector<int> &bigNum, int factor){
    for(int j = bigNum.size() - 1; j >= 0; j--){
        bigNum[j] *= factor;
        if(j != bigNum.size() - 1 && bigNum[j + 1]){
            bigNum[j] += bigNum[j + 1] / 10;
            bigNum[j + 1] %= 10;
        }
    }
}

/*
Adds one to a large number passed as vector<int>.
Will update later as function to add any amount, but one is all needed for Hailstone.
*/
void bigNumAddOne(vector<int> &bigNum){
    bigNum[bigNum.size() - 1]++;
    for(int j = bigNum.size() - 1; bigNum[j] == 10; j--){
        bigNum[j] = 0;
        if(!j) bigNum.insert(bigNum.begin(), 0);
        bigNum[j-1]++;
    }
}

/*
Main function.
Uses functions above to read in a large number (Of a theoretically unlimited number of digits),
 and returns the corresponding Hailstone sequence, stopping at 1.
 Can potentially break if for some (As of yet undetermined) number the sequence at some point adds several digits at the beginning,
 as the first "digit" in the large number is held to the same constraints as a normal int, and it is not built to add more digits when needed.
 (Though there is an extra 0 at the beginning of the vector, and even if the first digit becomes quite large, the program should still process
  the whole number correctly.)
*/
int main(){
    vector<int> bigNum = {0};
    bool isItOne = false; //tracks whether or not the number is 1.
    readInBigNum(bigNum);
    cout << "Your starting number: ";
    writeBigNum(bigNum);
    while(!isItOne){ //runs until the number given reduces to 1.
    isItOne = true;
    cout << ' ';
    if(bigNum[bigNum.size() - 1] & 1){ //Tests for oddness in the number.
        bigNumMultiplyByX(bigNum, 3); //Multiplies by three...
        bigNumAddOne(bigNum); //and adds one, as the Hailstone sequence usually does.
    }
    else {
        bigEvenNumDivideBy2(bigNum); //Else is even, so it divides by two.
    }
    writeBigNum(bigNum); //Returns results after every step.
    for(int i = 0; i < bigNum.size() - 1; i++){
        if(bigNum[i]) isItOne = false; //Reads through from the first to second-to-last digit, returning isItOne back to false if there is anything besides 0.
    }
    if(bigNum[bigNum.size() - 1] != 1) isItOne = false; //Checks the last number and sets isItOne to false if anything besides 1.
    } //At this point isItOne can only be true if bigNum == {... 0, 1}
    return 0;
}
