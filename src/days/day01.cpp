#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include "dayXX.h"

void day01_part1(){
    std::ifstream inputStream("./input/day01.txt");
    std::string curLine;
    int distance = 0;
    int locationsA[1000]; //Input text has 1000 lines
    int locationsB[1000];
    int lineNum = 0;

    while(std::getline(inputStream, curLine)){
        locationsA[lineNum] = std::stoi(curLine.substr(0,5)); //just substring the numbers out since everything is so uniform
        locationsB[lineNum] = std::stoi(curLine.substr(8,5));
        lineNum++;
    }
    inputStream.close();

    std::sort(std::begin(locationsA), std::end(locationsA));
    std::sort(std::begin(locationsB), std::end(locationsB));

    for(int i=0; i < 1000; i++){
        distance += std::abs(locationsA[i] - locationsB[i]);
    }

    std::cout << "[Day 1 Part 1] Total distance: " << distance << "\n";
}

void day01_part2(){
    std::ifstream inputStream("./input/day01.txt");
    std::string curLine;
    int similarity = 0;
    int locationsA[1000]; //Input text has 1000 lines
    int locationsB[1000];
    int lineNum = 0;

    int curMult = 0;
    int curA = -1;
    int bPos = 0;
    int bPosOffset = 0;

    while(std::getline(inputStream, curLine)){
        locationsA[lineNum] = std::stoi(curLine.substr(0,5)); //just substring the numbers out since everything is so uniform
        locationsB[lineNum] = std::stoi(curLine.substr(8,5));
        lineNum++;
    }
    inputStream.close();

    std::sort(std::begin(locationsA), std::end(locationsA));
    std::sort(std::begin(locationsB), std::end(locationsB));

    //Go through locationsA, with bPos progressing only after finding similar values
    //The multiplier is the number of B offsets we were able to make for one number
    for(int i=0; i < 1000; i++){
        if(curA != locationsA[i]){
            curA = locationsA[i];
            bPosOffset = 0;
            curMult = 0;

            while(bPos + bPosOffset < 1000){ //bPos "progression"
                if(locationsB[bPos + bPosOffset] < curA){ //play catchup
                    bPosOffset++;
                }else if(locationsB[bPos + bPosOffset] == curA){
                    curMult++;
                    bPosOffset++;
                }else if(locationsB[bPos + bPosOffset] > curA){ //We passed it, we're done
                    break;
                }
            }

            bPos += bPosOffset;
            similarity += curA * curMult;
        }else{
            similarity += curA * curMult; //it's the same number, so we reuse the multiplier
        }
    }

    std::cout << "[Day 1 Part 2] Similarity score: " << similarity << "\n";

}