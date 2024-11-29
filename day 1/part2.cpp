#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <sstream>
#include <algorithm>

void getCoord(const std::vector<std::string>& strSep) {
    int x = 0, y = 0, yaw = 0;
    std::unordered_map<std::string, int> visited;
    int counter = 0;

    while (true) {
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

            for (int k = 0; k < step; ++k) {
                switch (yaw) {
                    case 0:
                        ++y;
                        break;
                    case 90:
                        ++x;
                        break;
                    case 180:
                        --y;
                        break;
                    case 270:
                        --x;
                        break;
                    default:
                        std::cerr << "Error2! yaw = " << yaw << std::endl;
                        return;
                }

                std::string coord = std::to_string(x) + ";" + std::to_string(y);

                if (visited.find(coord) != visited.end()) {
                    std::cout << "Result = " << (std::abs(x) + std::abs(y))
                              << "; x = " << x << "; y = " << y
                              << "; counter = " << counter << std::endl;
                    return;
                }

                visited[coord] = 1;
                ++counter;
            }
        }
    }
}

int main() {
    // Открываем файл
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
