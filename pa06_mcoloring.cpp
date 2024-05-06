// TODO : 모든 색을 썼는지 확인

#include <iostream>
#include <vector>

using namespace std;

int cnt = 0, comp = 0;

int n = 0, m = 0;

// false : 인접 노드와 비교했을 때 색이 같으면
bool isValid(int** arr, vector<int> color, int i, int c) {
    bool res = true;
    for (int j = 0; j < n; j++)
    {
        if (arr[i][j] == 1 && color[j] == c) { return false; }
    }
    return true;
}

void coloring(int** arr, vector<int> color, vector<bool> isColor, int i, int c) {
    comp++;
    if (isValid(arr, color, i, c))
    {
        color[i] = c;
        if (i == n-1) {
            cnt++;
            // check color used
            for (int k = 0; k < n; k++)
            {
                isColor[color[k]-1] = true;
            }
            for (int k = 0; k < m; k++)
            {
                if (isColor[k] == false)
                {
                    cnt--;
                    break;
                }
            }
        } 
        else {
            for (int j = 1; j <= m; j++)
            {
                coloring(arr, color, isColor, i+1, j);
            }
        }
    }
    color.pop_back();

}

int main() {
    cin >> n >> m;

    // init array
    int** arr = new int*[n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];    

    // init color
    vector<int> color;
    color.assign(n, 0);
    vector<bool> isColor;
    isColor.assign(m, false);

    // start
    for (int i = 1; i <= m; i++)
    {
        coloring(arr, color, isColor, 0, i);
    }

    if(cnt == 0)
        cout << "no";
    else
        cout << cnt << endl << comp;

    return 0;
}