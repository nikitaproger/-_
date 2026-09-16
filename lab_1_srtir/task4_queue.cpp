#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
int main() {
    vector<int> numbers;
    int num;
    int count = 0;
    int n;
	cin >> n;
	cin.ignore(); 
	string input;
	getline(cin, input);
    stringstream ss(input);
    while (ss >> num) {
        numbers.push_back(num);
    }
    if (numbers.empty()) {
        cout << "eror:" << endl;
        return 1;
    }
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
                swapped = true; 
                count++;
            }
        }
        if (!swapped) {
            break;
        }
    }
	cout << count;
    return 0;
}