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
    bool switch_read = false;
    vector<pair<int, int>> pairs;
    vector<vector<int>> updates;

    while (getline(cin, line)) {        
        if (line.length() == 0) {
            switch_read = true;
        }
        else if (switch_read == true) {
            vector<int> update;
            int i = 0;
            while (line.length() > i + 1) {
                update.push_back(stoi(line.substr(i, 2)));
                i += 3;
            }
            updates.push_back(update);
        }
        else {
            int first = stoi(line.substr(0, 2));
            int second = stoi(line.substr(3, 2));
            pairs.push_back({first, second});
        }
    }

    vector<vector<int>> correct_updates;
    vector<vector<int>> incorrect_updates;

    for (int up = 0; up < updates.size(); up++) {
        bool correct = true;
        const vector<int>& sequence = updates[up];
        
        for (const auto& pair : pairs) {
            int first_pos = -1;
            int second_pos = -1;
            
            for (int i = 0; i < sequence.size(); i++) {
                if (sequence[i] == pair.first) first_pos = i;
                if (sequence[i] == pair.second) second_pos = i;
            }
            
            if (first_pos != -1 && second_pos != -1 && second_pos < first_pos) {
                correct = false;
                break;
            }
        }
        
        if (correct) {
            correct_updates.push_back(sequence);
        } else {
            incorrect_updates.push_back(sequence);
        }
    }

    for (auto& sequence : incorrect_updates) {
        bool changes;
        do {
            changes = false;
            for (const auto& pair : pairs) {
                auto first_it = find(sequence.begin(), sequence.end(), pair.first);
                auto second_it = find(sequence.begin(), sequence.end(), pair.second);

                if (first_it != sequence.end() && second_it != sequence.end() && 
                    second_it < first_it) {
                    iter_swap(first_it, second_it);
                    changes = true;
                }
            }
        } while (changes); // Repeat until no more changes needed
    }


    int sum = 0;
    for (const auto& update : incorrect_updates) {
        int middle_index = update.size() / 2;
        sum += update[middle_index];
    }

    cout << sum << endl;
    
    return 0;               
}