#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& arr, int val, int start, int end) {
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] < val) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    return start;
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        
        int insertPos = binarySearch(arr, key, 0, i);
        
        for (int j = i; j > insertPos; --j) {
            arr[j] = arr[j - 1];
        }
        
        arr[insertPos] = key;
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6};

    cout << "Original Array:";
    for (int num : arr) {
        cout << " " << num;
    }
    cout << endl;

    insertionSort(arr);

    cout << "Sorted Array:";
    for (int num : arr) {
        cout << " " << num;
    }
    cout << endl;

    return 0;
}