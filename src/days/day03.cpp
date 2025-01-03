#include <fstream>
#include <iostream>
#include <map>
#include "dayXX.h"

enum matchingState {
    MATCHING, //Finding an instance of "mul("
    INSIDE //Past "mul(", now getting numbers
};
const std::string pattern = "mul(";
const std::map<char, int> matchTable = { {'m', 3}, {'u', 2}, {'l', 1}, {'(', 1} };

/**
 * Takes in a string like `"mul(3,5)"` and returns an int result.
 * Note: Does zero input sanitization
 */
int doStringMult(std::string expression){
    return -1;
}


void day03_part1(){
    // std::ifstream inputStream("./input/day03.txt");
    std::ifstream inputStream("./input/test.txt");
    matchingState state = MATCHING;
    bool commaFound = false;
    int sum = 0;

    inputStream.seekg(3, std::ios_base::cur);

    while(!inputStream.eof()){
        char curChar = inputStream.peek();

        //Use Boyer-Moore algo for finding the start of the multiply statement
        if(state == MATCHING){
            bool noMatch = false;
            for(int i=3; i>=0; i--){
                if(curChar == pattern[i]){
                    inputStream.seekg(-1, std::ios_base::cur);
                    curChar = inputStream.peek();
                    continue;

                }else if(!matchTable.contains(curChar)){
                    inputStream.seekg(4, std::ios_base::cur);
                    noMatch = true;
                    break;

                }else{
                    inputStream.seekg(matchTable.at(curChar), std::ios_base::cur);
                    noMatch = true;
                    break;
                }
            }

            //Start the matching again (offset has already been set above)
            if(noMatch){ continue; }

            //Otherwise, we found a match!
            inputStream.seekg(1, std::ios_base::cur);
            state = INSIDE;
        }else if(state == INSIDE){
            //valid characters test
            if((curChar <= 48 || curChar >= 57) && curChar != ',' && curChar != ')'){
                state = MATCHING;
                commaFound = false;
                continue;
            }
            if(curChar == ','){
                if(commaFound){
                    state = MATCHING;
                    commaFound = false;
                    continue;
                }else{
                    commaFound = true;
                    //todo: store first number here
                }
            }
            //left off: finished dealing with bad chars and commas
            //up next: use char[] buffers for numbers read maybe?
            //and then close off the mult thing from ')'


            inputStream.seekg(1, std::ios_base::cur);
        }
    }




    inputStream.close();

    std::cout << "Day 3 part 1 boilerplate\n";
}

void day03_part2(){
    std::cout << "Day 3 part 2 boilerplate\n";
}