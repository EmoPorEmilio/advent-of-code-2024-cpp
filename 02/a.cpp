#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

int calculate_distance(int x1, int x2) {
    return abs(x1 - x2);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output_a.txt", "w", stdout);
    string line;
    int sum = 0;
    while (getline(cin, line)) {        
        istringstream iss(line);
        int current;
        int prev = -1;
        bool valid = true;
        bool checked = false;
        bool ascending = true;
        while (iss >> current && valid) {
            if (prev != -1) {
                if (prev == current) {
                    valid = false;
                }
                if (calculate_distance(prev, current) > 3) {
                    valid = false;
                }
                if (!checked) {
                    if (prev > current) {
                        ascending = false;
                    }
                    else {
                        ascending = true;
                    }
                    checked = true;
                }
                else {
                    if (ascending && prev > current) {
                        valid = false;
                    }
                    if (!ascending && prev < current) {
                        valid = false;
                    }
                }
                if (!valid) {
                    break;
                }
            }
            prev = current;
        }
        if (valid) {
            sum += 1;
        }
    }
    printf("%d\n", sum);

    return 0;               

}