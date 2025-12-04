#include <iostream>
#include <fstream>

int main() {
    long long result = 0;
    int digits = 12;

    std::ifstream inputFile("../inputs/aoc3input.txt");
    std::string line;
    while (std::getline(inputFile, line)) {
        std::string hl;
        for (int i = digits - 1; i >= 0; i--) {
            int nk = 0;
            for (int k = 9; k > 0; k--) {
                nk = line.find(std::to_string(k));
                if (nk != std::string::npos && nk <= line.size() - (i + 1)) {
                    hl += line.at(nk);
                    line = line.substr(nk + 1);
                    break;
                }
            }
        }

        result += std::stoll(hl);
    }

    std::cout << result << std::endl;

    return 0;
}
