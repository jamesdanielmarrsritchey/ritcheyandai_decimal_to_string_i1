#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

std::string getCmdOption(char ** begin, char ** end, const std::string & option)
{
    char ** itr = std::find(begin, end, option);
    if (itr != end && ++itr != end)
    {
        return std::string(*itr);
    }
    return "";
}

int main(int argc, char* argv[]) {
    std::vector<std::string> args(argv, argv + argc);
    std::string decimal = getCmdOption(argv, argv + argc, "--decimal");
    std::string delimiter = getCmdOption(argv, argv + argc, "--delimiter");

    if (delimiter.empty()) {
        delimiter = " "; // default delimiter is space
    }

    if (!decimal.empty()) {
        size_t pos = 0;
        std::string token;
        while ((pos = decimal.find(delimiter)) != std::string::npos) {
            token = decimal.substr(0, pos);
            std::cout << static_cast<char>(std::stoi(token));
            decimal.erase(0, pos + delimiter.length());
        }
        std::cout << static_cast<char>(std::stoi(decimal));
        std::cout << std::endl;
    } else {
        std::cout << "No decimal representation was given." << std::endl;
    }

    return 0;
}