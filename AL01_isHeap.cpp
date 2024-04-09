#include <iostream>
#include <vector>

using namespace std;

// Function to check if the given array representing an almost complete binary tree is a max-heap
bool isHeap(const vector<int>& arr) {
    int n = arr.size();

    // Traverse each node starting from the last non-leaf node up to the root
    for (int i = (n / 2) - 1; i >= 0; --i) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        // Check if the current node is less than any of its children
        if (leftChild < n && arr[i] < arr[leftChild]) {
            return false;
        }
        if (rightChild < n && arr[i] < arr[rightChild]) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<int> tree = {90, 15, 10, 7, 12, 2, 7};

    if (isHeap(tree)) {
        cout << "The tree is a max-heap." << endl;
    } else {
        cout << "The tree is not a max-heap." << endl;
    }

    return 0;
}