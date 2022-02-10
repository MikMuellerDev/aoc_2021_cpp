#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int part1() {
string line;
    ifstream inputFile("input.txt");

    int posX = 0;
    int posY = 0;

    while (getline(inputFile, line))
    {
        size_t pos = 0;
        string token;
        string instruction;
        while ((pos = line.find(" ")) != string::npos)
        {
            token = line.substr(0, pos);
            instruction = token;
            line.erase(0, pos + 1);
        }
        int modifier = stoi(line);

        if (instruction == "forward") {
            posX += modifier;
        } else if (instruction == "down") {
            posY += modifier;
        } else if (instruction == "up") {
            posY -= modifier;
        } else {
            printf("Error, invalid statement");
        }
    }
    inputFile.close();
    return  posX * posY;
}

int part2() {
string line;
    ifstream inputFile("input.txt");

    int aim = 0;
    int posY = 0;
    int posX = 0;

    while (getline(inputFile, line))
    {
        size_t pos = 0;
        string token;
        string instruction;
        while ((pos = line.find(" ")) != string::npos)
        {
            token = line.substr(0, pos);
            instruction = token;
            line.erase(0, pos + 1);
        }
        int modifier = stoi(line);

        if (instruction == "forward") {
            posX += modifier;
            posY += aim * modifier;
        } else if (instruction == "down") {
            aim += modifier;
        } else if (instruction == "up") {
            aim -= modifier;
        } else {
            printf("Error, invalid statement");
        }
    }
    inputFile.close();
    return  posX * posY;
}

int main()
{
    printf("Part 1: %d\n", part1());
    printf("Part 2: %d\n", part2());
}