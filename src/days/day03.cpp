#include <fstream>
#include <iostream>
#include <map>
#include "dayXX.h"

enum matchingState {
    MATCHING, //Finding an instance of "mul("
    INSIDE //Past "mul(", now getting numbers
};
std::map<char, int> matchTable = { {'m', 4}, {'u', 3}, {'l', 2}, {'(', 1} };

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
    std::streambuf* pInputBuf = inputStream.rdbuf();
    int sum = 0;

    matchingState state = MATCHING;
    pInputBuf->seekoff(4);
    while(pInputBuf->snextc() != EOF){
        // char curChar = pInputBuf->sgetc();

        if(state == MATCHING){

        }
    }




    inputStream.close();

    std::cout << "Day 3 part 1 boilerplate\n";
}

void day03_part2(){
    std::cout << "Day 3 part 2 boilerplate\n";
}