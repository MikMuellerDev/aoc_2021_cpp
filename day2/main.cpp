#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    string line;
    ifstream inputFile("input.txt");
    while (getline(inputFile, line))
    {
        size_t pos = 0;
        string token;
        while ((pos = line.find(" ")) != std::string::npos)
        {
            token = line.substr(0, pos);
            string instruction = token;
            line.erase(0, pos + 1);
        }
        int modifier = stoi(line);
    }
    inputFile.close();
    return 0;
}