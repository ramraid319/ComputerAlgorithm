#include <iostream>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f;
int P[7][7] = {
    {0, 4, INF, INF, INF, 10, INF},
    {3, 0, INF, 18, INF, INF, INF},
    {INF, 6, 0, INF, INF, INF, INF},
    {INF, 5, 15, 0, 2, 19, 5},
    {INF, INF, 12, 1, 0, INF, INF},
    {INF, INF, INF, INF, INF, 0, 10},
    {INF, INF, INF, 8, INF, INF, 0}
};

void path(int q, int r) {
    if(P[q][r] != 0 && P[q][r] != INF) {
        path(q, P[q][r]);
        cout << "v" << P[q][r];
        path(P[q][r], r);
    }
}
int main() {
    path(6, 2);

    return 0;
}