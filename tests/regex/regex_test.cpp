#include <cassert>
#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include <exception>

int main() {
    std::regex regExpr("(\\-)?(\\d)+");
    std::string line;

    std::ifstream f_accepted("regex_accepted_input.txt");
    if (f_accepted.is_open()) {
        while (std::getline(f_accepted, line)) {
            assert(std::regex_match(line, regExpr) == true);
        }
        f_accepted.close();
    } else {
        throw std::runtime_error("Couldn't open regex_accepted_input.txt");
    }

    std::ifstream f_rejected("regex_rejected_input.txt");
    if (f_rejected.is_open()) {
        while (std::getline(f_rejected, line)) {
            assert(std::regex_match(line, regExpr) == false);
        }
        f_rejected.close();
    } else {
        throw std::runtime_error("Couldn't open regex_rejected_input.txt");
    }
    return 0;
}
