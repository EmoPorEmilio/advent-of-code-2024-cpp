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
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    int sum = 0;
    while (!left.empty() && !right.empty()) {
        sum += calculate_distance(left.back(), right.back());
        left.pop_back();
        right.pop_back();
    }
    printf("%d\n", sum);

    return 0;               

}