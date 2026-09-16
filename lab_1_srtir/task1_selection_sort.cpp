#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
void SelectionSort(vector<int>& arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int Min_id = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[Min_id]) {
                Min_id = j;
            }
        }
        if (Min_id != i) {
            swap(arr[i], arr[Min_id]);
        }
    }
}
int main() {
    vector<int> numbers;
    int num;
    string input;
    getline(cin, input);
    stringstream ss(input);
    while (ss >> num) {
        numbers.push_back(num);
    }
    if (numbers.empty()) {
        cout << "error:" << endl;
        return 1;
    }
    int n = numbers.size();
    SelectionSort(numbers, n);
    for (int x : numbers) {
        cout << x << " ";
    }
    return 0;
}