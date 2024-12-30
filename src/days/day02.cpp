#include <fstream>
#include <iostream>
#include <cmath>
#include "dayXX.h"

void day02_part1(){
    std::ifstream inputStream("./input/day02.txt");
    std::string curLine;
    int safeReports = 0;

    while(std::getline(inputStream, curLine)){
        int readings[8];
        int readingsLength = 0;
        int numStart = 0;

        //Split by space and convert to int
        //Could do the safety checks here but this'll keep the code simpler
        for(int i=0; i<curLine.length(); i++){
            if(curLine.at(i) == ' '){
                readings[readingsLength] = std::stoi(curLine.substr(numStart, i - numStart));
                numStart = i+1;
                readingsLength++;
            }else if(i == curLine.length()-1){
                readings[readingsLength] = std::stoi(curLine.substr(numStart, i - numStart + 1));
                readingsLength++;
            }
        }

        bool isSafe = true;
        for(int i=0; i<readingsLength; i++){
            if(i == 0){
                continue;
            }else if(i == 1){ //only check level differences
                int delta = std::abs(readings[i-1] - readings[i]);
                if(delta < 1 || delta > 3){
                    isSafe = false;
                    break;
                }
            }else{ //check level diff and increasing/decreasing consistencey
                int delta = std::abs(readings[i-1] - readings[i]);
                if(delta < 1 || delta > 3){
                    isSafe = false;
                    break;
                }

                int diff1 = readings[i-1] - readings[i];
                int diff2 = readings[i-2] - readings[i-1];
                if((diff1 < 0 && diff2 > 0) || (diff1 > 0 && diff2 < 0)){
                    isSafe = false;
                    break;
                }
            }
        }

        if(isSafe){
            safeReports++;
        }
    }
    inputStream.close();

    std::cout << "[Day 2 part 1] Safe reports: " << safeReports << "\n";
}

void day02_part2(){
    std::cout << "Day 2 part 2 boilerplate\n";
}