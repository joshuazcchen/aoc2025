#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

std::string getBasePattern(const std::string& s) { 
    size_t n = s.size();
    for (size_t d = 1; d <= n / 2; d++) {
        if (n % d != 0) continue;
        std::string pattern = s.substr(0, d);
        std::string constructed;
        constructed.reserve(n);
        for (size_t i = 0; i < n / d; i++)
            constructed += pattern;
        if (constructed == s)
            return pattern;
    }
    return s;
}

int main() {
    std::ifstream inputFile("../inputs/aoc2input.txt");

    std::string ranges;
    std::getline(inputFile, ranges);
    long long out = 0;

    std::vector<std::vector<std::string>> rangeArray;
    std::string token;
    std::istringstream rangeStream(ranges);
    while (std::getline(rangeStream, token, ',')) {
        int midPoint = token.find("-");
        if (midPoint != std::string::npos) {
            rangeArray.push_back(std::vector<std::string>{token.substr(0,midPoint), token.substr(midPoint,
                token.size())});
        }
    }
    
    for (std::vector<std::string>& it : rangeArray) { // TO GET P1 SOLUTION, REPLACE CHECK FOR BASE PATTERN. I'm too tired to do this myself honestly.
        if (it.at(1).at(0) == '-') {
            it.at(1).erase(0,1);   
        }
        for (int i = 1; i < std::stoll(it.at(1)); i++) {
            long long k = std::stoll(std::to_string(i) + std::to_string(i));
            if (it.at(1).size() > 1) {
            std::string base = getBasePattern(std::to_string(i));
                if (base != std::to_string(i)) {
                    continue;
                }
            }
            if (k >= std::stoll(it.at(0)) && k <= std::stoll(it.at(1))) {
                out += k;
            } else if (k >= stoll(it.at(1))) {
                break;
            } else if (k < std::stoll(it.at(0))) {
                while (k <= std::stoll(it.at(1))) {
                    if (it.at(1).size() > 1) {
                        std::string base = getBasePattern(std::to_string(i));
                        if (base != std::to_string(i)) {
                            break;
                        }
                    }
                    k = std::stoll(std::to_string(k) + std::to_string(i));
                    if (k >= std::stoll(it.at(0)) && k <= std::stoll(it.at(1))) {
                        out += k;
                    } else if (k >= stoll(it.at(1))) {
                        break;
                    } else if (k > std::stoll(it.at(0))) {
                        break;
                    }
                }
            }
        }
    }
    std::cout<<out;
}