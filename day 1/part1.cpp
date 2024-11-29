#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>

void getCoord(const std::vector<std::string>& strSep) {
    int x = 0;
    int y = 0;
    int yaw = 0;

    for (const auto& command : strSep) {
        switch (command[0]) {
            case 'R':
                yaw += 90;
                break;
            case 'L':
                yaw -= 90;
                break;
            default:
                std::cerr << "Error1!" << std::endl;
                return;
        }

        if (yaw >= 360) yaw -= 360;
        if (yaw < 0) yaw += 360;

        int step = std::stoi(command.substr(1));

        switch (yaw) {
            case 0:
                y += step;
                break;
            case 90:
                x += step;
                break;
            case 180:
                y -= step;
                break;
            case 270:
                x -= step;
                break;
            default:
                std::cerr << "Error2! yaw = " << yaw << std::endl;
                return;
        }
    }

    std::cout << "Result = " << (std::abs(x) + std::abs(y))
              << "; x = " << x << "; y = " << y << std::endl;
}

int main() {
    std::ifstream file("day 1/input.txt.txt");
    if (!file) {
        std::cerr << "File is not found" << std::endl;
        return 1;
    }

    std::string line;
    std::getline(file, line);
    file.close();

    std::vector<std::string> strSep;
    std::istringstream stream(line);
    std::string command;
    while (std::getline(stream, command, ',')) {
        command.erase(std::remove(command.begin(), command.end(), ' '), command.end());
        strSep.push_back(command);
    }

    getCoord(strSep);

    return 0;
}
