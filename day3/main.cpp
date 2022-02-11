#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int part1()
{
    string line;
    ifstream inputFile("input.txt");

    vector<string> input;

    while (getline(inputFile, line))
    {
        input.push_back(line);
    }
    inputFile.close();

    int byteLen = input[0].length();

    vector<char> gamma;
    vector<char> epsilon;
    for (int bitPos = 0; bitPos < byteLen; bitPos++)
    {
        int count0 = 0;
        int count1 = 0;
        for (int line = 0; line < (int)input.size(); line++)
        {
            char bit = input[line][bitPos];
            switch (bit)
            {
            case '0':
                count0++;
                break;
            case '1':
                count1++;
                break;
            default:
                cout << "ERROR: INVALID BIT: " << bit;
                break;
            }
        }
        if (count1 > count0)
        {
            gamma.push_back('1');
            epsilon.push_back('0');
        }
        else
        {
            gamma.push_back('0');
            epsilon.push_back('1');
        }
    }

    int gammaDecimal = stoull(string(gamma.begin(), gamma.end()), 0, 2);
    int epsilonDecimal = stoull(string(epsilon.begin(), epsilon.end()), 0, 2);

    return gammaDecimal * epsilonDecimal;
}

int main()
{
    printf("Part 1: %d\n", part1());
}