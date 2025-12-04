#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream inputFile("../inputs/aoc4input.txt");
    std::string line;
    std::vector<std::vector<char>> gd;
    int pt = 0;

    while (std::getline(inputFile, line)) { // read input
        std::vector<char> ln;
        for (char& in : line) {
            ln.push_back(in);
        }
        gd.push_back(ln);
    }

    for (int i = 0; i < gd.size(); i++) {
        for (int j = 0; j < gd.at(i).size(); j++) {
            if (gd.at(i).at(j) != '.') {
                int ct = 0;
                std::vector<char> ab;
                std::vector<char> bl;
                if (i != 0) {
                    ab = gd.at(i-1);
                }
                if (i < gd.size() - 1) {
                    bl = gd.at(i+1);
                }

                // checking the same line
                if (j != 0) {
                    if (gd.at(i).at(j-1) != '.') {
                        ct++;
                    }
                }
                if (j < gd.at(i).size() - 1) {
                    if (gd.at(i).at(j+1) != '.') {
                        ct++;
                    }
                }

                if (!ab.empty()) {
                    if (ab.at(j) != '.') {
                        ct++;
                    }
                    if (j != 0) {
                        if (ab.at(j-1) != '.') {
                            ct++;
                        }
                    }
                    if (j < ab.size() - 1) {
                        if (ab.at(j+1) != '.') {
                            ct++;
                        }
                    }
                }

                if (!bl.empty()) {
                    if (bl.at(j) != '.') {
                        ct++;
                    }
                    if (j != 0) {
                        if (bl.at(j-1) != '.') {
                            ct++;
                        }
                    }
                    if (j < bl.size() - 1) {
                        if (bl.at(j+1) != '.') {
                            ct++;
                        }
                    }
                }
                if (ct < 4) {
                    pt++;
                    std::cout<<ct<<" position: "<<i<<","<<j<<std::endl;
                }
            }
        }
    }

    std::cout<<pt<<std::endl;
    return 0;
}
