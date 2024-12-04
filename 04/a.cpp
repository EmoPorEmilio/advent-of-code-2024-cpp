#include <iostream>
#include <regex>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <utility>
#include <numeric>
using namespace std;


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output_a.txt", "w", stdout);
    string line;
    int sum = 0;
    vector<vector<char>> matrix;
    while (getline(cin, line)) {        
        istringstream iss(line);
        char current;
        vector<char> row;
        while (iss >> current) {
            row.push_back(current);
        }
        matrix.push_back(row);
    }

    string xmas = "";

    vector<pair<int, int>> coordinates_of_x;


    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 'X') {
                coordinates_of_x.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < coordinates_of_x.size(); i++) {
        int x = coordinates_of_x[i].first;
        int y = coordinates_of_x[i].second;

        if (x - 1 >= 0 && matrix[x - 1][y] == 'M' && x - 2 >= 0 && matrix[x - 2][y] == 'A' && x - 3 >= 0 && matrix[x - 3][y] == 'S') {
            sum += 1;
        }
        if (x + 1 < matrix.size() && matrix[x + 1][y] == 'M' && x + 2 < matrix.size() && matrix[x + 2][y] == 'A' && x + 3 < matrix.size() && matrix[x + 3][y] == 'S') {
            sum += 1;
        }
        if (y - 1 >= 0 && matrix[x][y - 1] == 'M' && y - 2 >= 0 && matrix[x][y - 2] == 'A' && y - 3 >= 0 && matrix[x][y - 3] == 'S') {
            sum += 1;
        }
        if (y + 1 < matrix[x].size() && matrix[x][y + 1] == 'M' && y + 2 < matrix[x].size() && matrix[x][y + 2] == 'A' && y + 3 < matrix[x].size() && matrix[x][y + 3] == 'S') {
            sum += 1;
        }
        if (x - 1 >= 0 && y - 1 >= 0 && matrix[x - 1][y - 1] == 'M' && x - 2 >= 0 && y - 2 >= 0 && matrix[x - 2][y - 2] == 'A' && x - 3 >= 0 && y - 3 >= 0 && matrix[x - 3][y - 3] == 'S') {
            sum += 1;
        }
        if (x - 1 >= 0 && y + 1 < matrix[x].size() && matrix[x - 1][y + 1] == 'M' && x - 2 >= 0 && y + 2 < matrix[x].size() && matrix[x - 2][y + 2] == 'A' && x - 3 >= 0 && y + 3 < matrix[x].size() && matrix[x - 3][y + 3] == 'S') {
            sum += 1;
        }
        if (x + 1 < matrix.size() && y - 1 >= 0 && matrix[x + 1][y - 1] == 'M' && x + 2 < matrix.size() && y - 2 >= 0 && matrix[x + 2][y - 2] == 'A' && x + 3 < matrix.size() && y - 3 >= 0 && matrix[x + 3][y - 3] == 'S') {
            sum += 1;
        }
        if (x + 1 < matrix.size() && y + 1 < matrix[x].size() && matrix[x + 1][y + 1] == 'M' && x + 2 < matrix.size() && y + 2 < matrix[x].size() && matrix[x + 2][y + 2] == 'A' && x + 3 < matrix.size() && y + 3 < matrix[x].size() && matrix[x + 3][y + 3] == 'S') {
            sum += 1;
        }

    }



    std::cout << sum << std::endl;
    return 0;               

}