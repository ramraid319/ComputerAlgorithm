// ref : https://blog.naver.com/honey_gguri/222045386773

#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int dist;

typedef struct _node {//노드
    int x, y;//좌표
    int G, H;//g(node), h(node)
    pair<int, int> parent;//역추적에 쓰일 이전 노드
} node;

// 상, 하, 좌, 우 이동을 위한 배열
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

struct cmp {//우선순위 큐 비교 함수
    bool operator()(const node u, const node v) {
        if (u.G + u.H > v.G + v.H) return true;//F는 작은게 위로 오게
        else if (u.G + u.H == v.G + v.H) {//F가 같다면 G가 큰게 위로 오게
            if (u.G < v.G) return true;
            else return false;
        }
        else return false;
    }
};

int Astar(vector<vector<int>> M, pair<int, int> start, pair<int, int> goal) {
    priority_queue<node, vector<node>, cmp> open;

    vector<vector<bool>> close(m, vector<bool>(n, 0));
    vector<node> close_list;
    node s_node;

    s_node.x = start.second;
    s_node.y = start.first;
    s_node.G = 0;
    s_node.H = sqrt(pow((goal.second - s_node.x) * 3, 2) + pow((goal.first - s_node.y) * 3, 2));
    s_node.parent = make_pair(-1, -1);

    open.push(s_node);
    close[s_node.y][s_node.x] = true;

    while (open.size()) {
        int x = open.top().x;
        int y = open.top().y;
        int G = open.top().G;

        close_list.push_back(open.top());
        open.pop();
        dist = G; // 현재 노드까지의 최단 거리로 업데이트

        if (x == goal.second && y == goal.first) {
            return dist;
        }

        node add;
        for (int i = 0; i < 4; i++)
        {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n) {
                if (M[nextY][nextX] != 0 && close[nextY][nextX] == false) {
                    add.x = nextX;
                    add.y = nextY;
                    add.G = G + 3;
                    add.H = sqrt(pow((goal.second - add.x) * 3, 2) + pow((goal.first - add.y) * 3, 2));
                    add.parent = make_pair(y, x);
                    close[nextY][nextX] = true;
                    open.push(add);
                }
            }
        }
    }
    return -1; // 경로를 찾을 수 없을 때
}

int main()
{
    cin >> m >> n;

    vector<vector<int>> M(m, vector<int>(n, 1));

    // init zero
    int zero_num;
    cin >> zero_num;
    for (int i = 0; i < zero_num; i++)
    {
        int tmp, x, y;
        cin >> tmp >> x >> y;
        M[y][x] = 0;
    }

    string tmp;

    // init s, t
    int s_x, s_y;
    cin >> tmp >> s_x >> s_y;
    node s;
    s.x = s_x;
    s.y = s_y;

    int t_x, t_y;
    cin >> tmp >> t_x >> t_y;
    node t;
    t.x = t_x;
    t.y = t_y;

    // init obs
    int obs_num = 0;
    cin >> tmp >> obs_num;

    for (int i = 0; i < obs_num; i++) {
        int x_1, y_1, x_2, y_2;
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        for (int y = min(y_1, y_2); y <= max(y_1, y_2); y++) {
            for (int x = min(x_1, x_2); x <= max(x_1, x_2); x++) {
                M[y][x] = 0;
            }
        }
    }

    cout << Astar(M, make_pair(s.y, s.x), make_pair(t.y, t.x));

    return 0;
}
