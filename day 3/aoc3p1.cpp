#include <iostream>
#include <fstream>

int main() { // precon: there's only ints
    int result = 0;

    std::ifstream inputFile("../inputs/aoc3input.txt");
    std::string line;
    while (std::getline(inputFile, line)) {
        std::string hi;
        std::string lo;
        int key = 0;
        for (int i = 9; i > 0; i--) {
            key = line.find(std::to_string(i));
            if (key != std::string::npos && key <= line.size() - 2) {
                hi = line.at(key);
                break;
            }
        }
        line = line.substr(key + 1);
        for (int i = 9; i > 0; i--) {
            key = line.find(std::to_string(i));
            if (key != std::string::npos) {
                lo = line.at(key);
                break;
            }
        }
        std::cout<<std::stoi(hi + lo)<<std::endl;
        result += std::stoi(hi + lo);
    }

    std::cout << result << std::endl;

    return 0;
}