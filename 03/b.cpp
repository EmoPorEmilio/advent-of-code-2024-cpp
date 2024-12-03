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

int calculateSum(const std::string& content) {
   std::regex pattern(R"((?:don't\(\)|do\(\)|mul\(\d+,\d+\)))");
   auto words_begin = std::sregex_iterator(content.begin(), content.end(), pattern);
   auto words_end = std::sregex_iterator();
   
   bool enabled = true;
   int total = 0;
   std::regex mul_pattern(R"(mul\((\d+),(\d+)\))");
   
   for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
       std::string match = i->str();
       if (match == "do()") enabled = true;
       else if (match == "don't()") enabled = false;
       else if (enabled) {
           std::smatch mul_match;
           if (std::regex_match(match, mul_match, mul_pattern)) {
               int num1 = std::stoi(mul_match[1]);
               int num2 = std::stoi(mul_match[2]);
               total += num1 * num2;
           }
       }
   }
   
   return total;
}



int main() {
    freopen("output_b.txt", "w", stdout);

    std::ifstream file("input.txt");
    if (!file) {
        std::cerr << "Failed to open file\n";
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();

    std::cout << calculateSum(content) << std::endl;
    return 0;               

}