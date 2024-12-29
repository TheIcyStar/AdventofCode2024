#include <iostream>
#include <map>
#include "days/dayXX.h"

//Put all of the days' part 1 & 2 implementations into a map of function pointers
//Classes? Pff, nah. They're boring and we git gud by doing it the hard way 😎😎😎
typedef void (*dayPartImpl)();
const std::map<std::string, dayPartImpl> functionMap {
    {"0-1", day00_part1}, {"0-2", day00_part2},
};


int main(int argc, char* argv[]){
    if(argc != 3){
        std::cout
            << "Usage: " << argv[0] << " <day> <part>\n"
            << "For example, `" << argv[0] << " 5 2` will run day 5 part 2 with ./input/day05.txt as input.\n"
        ;
        return 1;
    }

    std::string day = argv[1];
    std::string part = argv[2];

    try {
        functionMap.at(day+"-"+part)();
    } catch(const std::out_of_range) {
        std::cout << "Invalid or unimplemented day and part combination\n";
        return 1;
    }

    return 0;
}