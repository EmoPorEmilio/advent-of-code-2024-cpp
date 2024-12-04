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
    freopen("output_b.txt", "w", stdout);
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

    vector<pair<int, int>> coordinates_of_a;


    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 'A') {
                coordinates_of_a.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < coordinates_of_a.size(); i++) {
        int x = coordinates_of_a[i].first;
        int y = coordinates_of_a[i].second;

        if (x - 1 >= 0 && y - 1 >= 0 && x + 1 < matrix.size() && y + 1 < matrix[x].size())  {
            if ((matrix[x - 1][y - 1] == 'M' && matrix[x + 1][y + 1] == 'S') || (matrix[x + 1][y + 1] == 'M' && matrix[x - 1][y - 1] == 'S')) {
                sum += 1;
            }
            
            if ((matrix[x - 1][y + 1] == 'M' && matrix[x + 1][y - 1] == 'S') || (matrix[x + 1][y - 1] == 'M' && matrix[x - 1][y + 1] == 'S')) {
                sum += 1;
            }
        }
    }



    std::cout << sum << std::endl;
    return 0;               

}