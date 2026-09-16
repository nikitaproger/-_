#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
void insertionSort(vector<int> & arr) {
	int n =  static_cast<int>(arr.size());
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    insertionSort(numbers);
    for (int x : numbers) {
        cout << x << " ";
    }
    return 0;
}