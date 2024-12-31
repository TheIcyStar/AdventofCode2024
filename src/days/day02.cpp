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



/**
 * Removes an element from the array, shifts remaining items in place, and sets `size` to the new size
 * Note: 1 indexed removal position
 * (Similar to std::vector.erase)
 */
void removeFromArray(int* array, int size, int pos){
    for(int i=pos-1; i < size-1; i++){
        array[i] = array[i+1];
    }
}

/**
 * Returns true if the levels are safe
 */
bool isValid(const int* readings, const int size){
    for(int i=1; i<size; i++){
        if(i == 1){ //only check level differences
            int delta = std::abs(readings[i-1] - readings[i]);
            if(delta < 1 || delta > 3){
                return false;
            }
        }else{ //check level diff and increasing/decreasing consistencey
            int delta = std::abs(readings[i-1] - readings[i]);
            if(delta < 1 || delta > 3){
                return false;
            }

            int diff1 = readings[i-1] - readings[i];
            int diff2 = readings[i-2] - readings[i-1];
            if((diff1 < 0 && diff2 > 0) || (diff1 > 0 && diff2 < 0)){
                return false;
            }
        }
    }

    return true;
}

void day02_part2(){
    std::ifstream inputStream("./input/day02.txt");
    std::string curLine;
    int safeReports = 0;

    while(std::getline(inputStream, curLine)){
        int readings[8];
        int readingsLength = 0;
        int numStart = 0;

        //Split by space and convert to int
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

        //Check if what we have right now is good
        if(isValid(readings, readingsLength)){
            safeReports++;
            continue;
        }

        //Check if removing one of the readings makes it good
        int *dampened = new int[readingsLength];
        for(int i=0; i < readingsLength; i++){
            std::copy(readings, readings+readingsLength, dampened);
            removeFromArray(dampened, readingsLength, i+1);
            if(isValid(dampened, readingsLength - 1)){
                safeReports++;
                break;
            }
        }

    }
    inputStream.close();

    std::cout << "[Day 2 part 2] Safe reports: " << safeReports << "\n";
}
