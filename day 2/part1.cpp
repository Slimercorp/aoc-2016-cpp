#include <fstream>
#include <iostream>

int calculateDigit(const std::string &line, int &posX, int &posY) {
    int keyPad[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
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

        if (tempPosX >= 0 && tempPosX < 3 && tempPosY >= 0 && tempPosY < 3) {
            posX = tempPosX;
            posY = tempPosY;
        }
    }

    return keyPad[posX][posY];
}

int main() {
    std::ifstream file("day 2/input.txt");
    std::string line;
    int posX = 1;
    int posY = 1;
    while (std::getline(file, line)) {
        int digit = calculateDigit(line, posX, posY);
        std::cout << digit;
    }

    std::cout << std::endl;
    file.close();

    return 0;
}
