#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

void counting_sort_all(std::vector<int>& arr) {
    if (arr.empty()) return;  
    int mn = *std::min_element(arr.begin(), arr.end());
    int mx = *std::max_element(arr.begin(), arr.end());
    int lower = mn;
    int offset = 0;
    if (lower < 0) {
        offset = std::abs(mn);
        for (int& item : arr) {
            item += offset;
        }
        mn = *std::min_element(arr.begin(), arr.end());
        mx = *std::max_element(arr.begin(), arr.end());
    }
    std::vector<int> counter(mx + 1, 0);

    for (int item : arr) {
        counter[item]++;
    }
    arr.clear();
    for (int num = 0; num <= mx; ++num) {
        arr.insert(arr.end(), counter[num], num);
    }

    if (lower < 0) {
        for (int& item : arr) {
            item -= offset;
        }
    }
}
int main() {
    std::vector<int> numbers; 
    int num;
    std::string input;          
    std::getline(std::cin, input);  
    std::stringstream ss(input);   
    while (ss >> num) {
        numbers.push_back(num);
    }
    if (numbers.empty()) {
        std::cout << "error:" << std::endl;  
        return 1;
    }
    counting_sort_all(numbers); 
    for (int x : numbers) {
        std::cout << x << " ";  
    }
    return 0;
}