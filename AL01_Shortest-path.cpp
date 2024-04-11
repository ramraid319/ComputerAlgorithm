#include <iostream>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f;
int P[7][7] = {                     // by Algorithm 3.4 (Foundations of Algorithms 5th.)
    {0, 0, 5, 2, 4, 0, 6},
    {0, 0, 5, 0, 4, 1, 4},
    {2, 0, 0, 2, 4, 1, 4},
    {2, 0, 5, 0, 0, 1, 0},
    {2, 4, 0, 0, 0, 1, 4},
    {2, 4, 5, 7, 4, 0, 0},
    {2, 4, 5, 0, 4, 1, 0}
};

void path(int q, int r) {
    if(P[q][r] != 0) {
        path(q, P[q][r]);
        cout << "v" << P[q][r];
        path(P[q][r], r);
    }
}
int main() {
    path(6, 2);

    return 0;
}