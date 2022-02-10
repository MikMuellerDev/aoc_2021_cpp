#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int part1(vector<int> &list)
{
    int incremented = 0;
    for (int i = 0; i < (int)list.size(); i++)
    {
        if (i > 0 && list.at(i) > list.at(i - 1))
        {
            incremented++;
        }
    }
    return incremented;
}

int part2(vector<int> &list)
{
    int incremented = 0;
    vector<int> input;
    for (int i = 0; i < (int)list.size(); i++)
    {
        if (i < (int)list.size() && i + 1 < (int)list.size() && i + 2 < (int)list.size())
        {
            input.push_back(list.at(i) + list.at(i + 1) + list.at(i + 2));
        }
    }

    return part1(input);
}

int main()
{
    string line;
    ifstream inputFile("input.txt");
    vector<int> list;
    while (getline(inputFile, line))
    {
        list.push_back(stoi(line));
    }
    inputFile.close();

    cout << "Increments Part1: " << part1(list) << endl;
    cout << "Increments Part2: " << part2(list) << endl;

    return 0;
}