#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0;     
    int j = 0;   
    int k = left; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);      
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right); 
}
void mergeSort(vector<int>& arr) {
    mergeSort(arr, 0, arr.size() - 1);
}
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
    mergeSort(numbers);
    for (int x : numbers) {
        cout << x << " ";
    }
    return 0;
}