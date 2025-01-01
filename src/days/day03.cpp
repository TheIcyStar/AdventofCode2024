#include <fstream>
#include <iostream>
#include <map>
#include "dayXX.h"

enum matchingState {
    MATCHING, //Finding an instance of "mul("
    INSIDE    //Past "mul(", now getting numbers
};
const std::string pattern = "mul(";
const std::map<char, int> matchTable = { {'m', 3}, {'u', 2}, {'l', 1}, {'(', 1} };

//Bug: File can start with anything but 'mul('
//Turns out you can't seekg() your way back *into* a file, lol
void day03_part1(){
    std::ifstream inputStream("./input/day03.txt");
    matchingState state = MATCHING;
    bool commaFound = false;
    char numBuf[8];
    char curChar = 0;
    int num1, num2, numStartOffset;
    int sum = 0;

    inputStream.seekg(3, std::ios_base::cur);

    while(curChar != EOF){ //while !inputStream.eof()
        curChar = inputStream.peek();
        // std::cout << "tellg: " << inputStream.tellg() << "\n";

        //for finding the start of the multiply statement, we'll use the Boyer-Moore algo
        //but simplified because we have only one possible pattern
        if(state == MATCHING){
            bool noMatch = false;
            for(int i=3; i>=0; i--){
                if(!matchTable.contains(curChar)){
                    inputStream.seekg(4, std::ios_base::cur);
                    noMatch = true;
                    break;

                }else if(curChar == pattern[i]){
                    inputStream.seekg(-1, std::ios_base::cur);
                    curChar = inputStream.peek();
                    continue;

                }else{
                    inputStream.seekg((3-i) + matchTable.at(curChar), std::ios_base::cur);
                    noMatch = true;
                    break;
                }
            }

            //Start the matching again (offset has already been set above)
            if(noMatch){ continue; }

            //Otherwise, we found a match!
            inputStream.seekg(5, std::ios_base::cur);
            numStartOffset = 0;
            commaFound = false;
            state = INSIDE;


        }else if(state == INSIDE){
            //Handle numbers
            if(curChar >= 48 && curChar <= 57){
                numBuf[numStartOffset] = curChar;
                numStartOffset += 1;
                inputStream.seekg(1, std::ios_base::cur);

            //Handle invalid and valid commas
            }else if(curChar == ','){
                if(commaFound){
                    state = MATCHING;
                    commaFound = false;
                    continue;
                }
                commaFound = true;

                //Parse our number
                numBuf[numStartOffset] = '\0';
                num1 = std::stoi(numBuf);

                //start reading the next number
                numStartOffset = 0;
                inputStream.seekg(1, std::ios_base::cur);

            //Handle statement ending
            }else if(curChar == ')'){
                numBuf[numStartOffset] = '\0';
                num2 = std::stoi(numBuf);

                sum += num1 * num2;
                inputStream.seekg(1, std::ios_base::cur);
                state = MATCHING;

            //Handle invalid character
            }else{
                state = MATCHING;
                continue;
            }
        }
    }

    inputStream.close();
    std::cout << "[Day 3 part 1] Sum: " << sum << "\n";
}

void day03_part2(){
    std::cout << "Day 3 part 2 boilerplate\n";
}