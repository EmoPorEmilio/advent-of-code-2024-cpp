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

std::string readFile(const std::string& path) {
    std::ifstream file(path);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

std::vector<std::pair<int, int>> extractNumbers(const std::string& content) {
   std::vector<std::pair<int, int>> numbers;
   std::regex pattern(R"(mul\((\d+),(\d+)\))");
   
   auto words_begin = std::sregex_iterator(content.begin(), content.end(), pattern);
   auto words_end = std::sregex_iterator();
   
   for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
       std::smatch match = *i;
       int num1 = std::stoi(match[1]);
       int num2 = std::stoi(match[2]);
       numbers.push_back({num1, num2});
   }
   
   return numbers;
}

std::vector<int> getProducts(const std::vector<std::pair<int, int>>& pairs) {
   std::vector<int> products;
   for (const auto& p : pairs) {
       products.push_back(p.first * p.second);
   }
   return products;
}

int main() {
    freopen("output_a.txt", "w", stdout);

    std::ifstream file("input.txt");
    if (!file) {
        std::cerr << "Failed to open file\n";
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();

    auto pairs = extractNumbers(content);
    auto products = getProducts(pairs);
    int sum = std::accumulate(products.begin(), products.end(), 0);
    
    std::cout << sum << std::endl;

    return 0;               

}