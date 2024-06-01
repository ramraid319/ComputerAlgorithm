#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

int distance(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void backtrack(vector<pair<int, Point>>& locations, Point current, vector<int>& order, vector<bool>& picked_up, vector<bool>& delivered, int carried_orders, int total_distance, int& min_total_distance, vector<int>& best_order) {
    if (order.size() == locations.size()) {
        if (total_distance < min_total_distance || (total_distance == min_total_distance && order < best_order)) {
            min_total_distance = total_distance;
            best_order = order;
        }
        return;
    }

    vector<int> candidates;
    for (size_t i = 0; i < locations.size(); ++i) {
        int id = abs(locations[i].first);
        if ((locations[i].first > 0 && !picked_up[id] && carried_orders < 2) ||
            (locations[i].first < 0 && picked_up[id] && !delivered[id])) {
            candidates.push_back(i);
        }
    }

    sort(candidates.begin(), candidates.end(), [&](int a, int b) {
        return locations[a].first < locations[b].first;
    });

    for (int i : candidates) {
        int id = abs(locations[i].first);
        int dist = distance(current, locations[i].second);

        if (total_distance + dist >= min_total_distance) continue;

        order.push_back(locations[i].first);
        if (locations[i].first > 0) {
            picked_up[id] = true;
            ++carried_orders;
        } else {
            delivered[id] = true;
            --carried_orders;
        }

        backtrack(locations, locations[i].second, order, picked_up, delivered, carried_orders, total_distance + dist, min_total_distance, best_order);

        order.pop_back();
        if (locations[i].first > 0) {
            picked_up[id] = false;
            --carried_orders;
        } else {
            delivered[id] = false;
            ++carried_orders;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int size;
    cin >> size;

    vector<pair<int, Point>> locations;

    for (int i = 1; i <= size; ++i) {
        Point restaurant, delivery;
        cin >> restaurant.x >> restaurant.y;
        locations.push_back(make_pair(i, restaurant));

        cin >> delivery.x >> delivery.y;
        locations.push_back(make_pair(-i, delivery));
    }

    Point start = {500, 500};
    vector<int> order;
    int carried_orders = 0;
    vector<bool> picked_up(size + 1, false);
    vector<bool> delivered(size + 1, false);

    int min_total_distance = numeric_limits<int>::max();
    vector<int> best_order;

    backtrack(locations, start, order, picked_up, delivered, carried_orders, 0, min_total_distance, best_order);

    for (int idx : best_order) {
        cout << idx << " ";
    }
    cout << endl;
    cout << min_total_distance << endl;

    return 0;
}
