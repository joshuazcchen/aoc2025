#include <iostream>
#include <fstream>
#include <string>

int main() {
    int count = 0;
    int location = 50;
    std::ifstream inputFile("../inputs/aoc1input.txt");

    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            char access = line.at(0);
            line.erase(0,1);
            if (access == 'L') {
                if (location == 0) {
                    count--;
                }
                if (location - std::stoi(line) % 100 == 0 && std::stoi(line) >= 101) {
                    count++;
                }
                location -= std::stoi(line);
            } else {
                location += std::stoi(line);
            }

            if (location == 0) {
                    count++;
                    continue;
            }
            while (location >= 100 || location < 0) {
                if (location >= 100) {
                    location = location - 100;
                } else if (location < 0) {
                    location = 100 + location;
                } 
                count++;
            }
        }
        std::cout<<count;
    }
}