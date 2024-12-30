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
    std::cout << "Day 1 part 2 boilerplate\n";
}