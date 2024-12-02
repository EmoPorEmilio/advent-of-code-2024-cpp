#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int calculate_distance(int x1, int x2) {
    return abs(x1 - x2);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output_b.txt", "w", stdout);

    int x, y;
    vector<int> left, right;

    while (cin >> x >> y) {
        left.push_back(x);
        right.push_back(y);
    }

    int similarity_score = 0;
    for (int value : left) {
        int count = 0;
        for (int value2 : right) {
            if (value == value2) {
                count++;
            }
        }
        similarity_score += count * value;
    }

    printf("%d\n", similarity_score);

    return 0;               

}