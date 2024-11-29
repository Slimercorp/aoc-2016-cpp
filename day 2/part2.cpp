#include <fstream>
#include <iostream>

char calculateChar(const std::string &line, int &posX, int &posY) {
    char keyPad[5][5] = {{'0', '0', '1', '0', '0'},
                        {'0', '2', '3', '4', '0'},
                        {'5', '6', '7', '8', '9'},
                        {'0', 'A', 'B', 'C', '0'},
                        {'0', '0', 'D', '0', '0'}};
    for (char c: line) {
        int tempPosX = posX;
        int tempPosY = posY;

        switch (c) {
            case 'D':
                tempPosX++;
                break;
            case 'U':
                tempPosX--;
                break;
            case 'L':
                tempPosY--;
                break;
            case 'R':
                tempPosY++;
                break;
            default:
                std::cerr << "Invalid character: " << c << std::endl;
        }

        if (tempPosX >= 0 && tempPosX < 5 && tempPosY >= 0 && tempPosY < 5 && keyPad[tempPosX][tempPosY] != '0') {
            posX = tempPosX;
            posY = tempPosY;
        }
    }

    return keyPad[posX][posY];
}

int main() {
    std::ifstream file("day 2/input.txt");
    std::string line;
    int posX = 2;
    int posY = 0;
    while (std::getline(file, line)) {
        char digit = calculateChar(line, posX, posY);
        std::cout << digit;
    }

    std::cout << std::endl;
    file.close();

    return 0;
}
