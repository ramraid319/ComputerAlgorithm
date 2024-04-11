#include <iostream>
using namespace std;

int cnt = 0;
int bin(int n, int k) {
    cnt++;
    if(k==0 || n==k)
        return 1;
    else
        return bin(n-1, k-1)+bin(n-1, k);
}
int main() {
    cout << bin(5, 2) << endl;
    cout << cnt;
    return 0;
}