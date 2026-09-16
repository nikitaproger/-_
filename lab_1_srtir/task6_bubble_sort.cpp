#include <iostream>
#include <vector>
#include <random>
#include <utility>
#include <string>
#include <sstream>
int getRandomIndex(int left, int right) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(left, right);
    return dis(gen);
}
void quick_sort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int val = arr[getRandomIndex(left, right)];
    int l = left;
    int r = right;
    while (l <= r) {
        while (l <= right && arr[l] < val) {
            l++;
        }
        while (r >= left && arr[r] > val) {
            r--;
        }
        if (l <= r) {
            std::swap(arr[l], arr[r]);
            l++;
            r--;
        }
    }
    if (left < r) {
        quick_sort(arr, left, r);
    }
    if (l < right) {
        quick_sort(arr, l, right);
    }
}
int main() {
    std::vector<int> numbers;
    int num;
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::string input;
    std::getline(std::cin, input);
    std::stringstream ss(input);
    while (ss >> num) {
        numbers.push_back(num);
    }
    if (!numbers.empty()) {
        quick_sort(numbers, 0, static_cast<int>(numbers.size()) - 1);
    }
    for (int x : numbers) {
        std::cout << x << " ";
    }
    return 0;
}