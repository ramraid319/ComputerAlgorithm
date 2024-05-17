#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int RabinKarp(const vector<char>& P, const vector<char>& T) {
    const int MOD = 113;
    if (P.size() > T.size()) return -1;

    vector<char> charSet;
    bool charSet_dp[26] = {false};

    for (char c : T) {
        if (!charSet_dp[c - 'A']) {
            charSet_dp[c - 'A'] = true;
            charSet.push_back(c);
        }
    }

    int key = 0, comp = 0, cnt = 0;
    int charSetSize = charSet.size();

    for (char c : P) {
        key = (key * charSetSize + (c - 'A')) % MOD;
    }

    for (size_t i = 0; i <= T.size() - P.size(); i++) {
        cnt++;
        comp = 0;
        for (size_t j = 0; j < P.size(); j++) {
            comp = (comp * charSetSize + (T[i + j] - 'A')) % MOD;
        }

        if (key == comp) {
            bool match = true;
            for (size_t j = 0; j < P.size(); j++) {
                cnt++;
                if (P[j] != T[i + j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                return cnt;
            }
        }
    }

    return cnt;
}

vector<int> KMP_preprocessing(const vector<char>& P) {
    int n = P.size();
    vector<int> SP(n);
    SP[0] = -1;
    int k = -1;

    for (int i = 1; i < n; i++) {
        while (k >= 0 && P[i] != P[k + 1]) {
            k = SP[k];
        }
        if (P[i] == P[k + 1]) {
            k++;
        }
        SP[i] = k;
    }
    return SP;
}

int KMP(const vector<char>& P, const vector<char>& T) {
    int m = P.size();
    int n = T.size();
    if (m > n) return -1;
    
    int k = -1;
    int cnt = 0;

    vector<int> SP = KMP_preprocessing(P);

    for (int i = 0; i < n; i++) {
        while (k >= 0 && T[i] != P[k + 1]) {
            k = SP[k];
            cnt++;
        }
        if (T[i] == P[k + 1]) {
            k++;
        }
        cnt++;
        if (k == m - 1) {
            return cnt;
        }
    }
    return cnt;
}

void badCharHeuristic(const vector<char>& P, int size, int badchar[256]) {
    fill(badchar, badchar + 256, -1);
    for (int i = 0; i < size; i++) {
        badchar[(int)P[i]] = i;
    }
}

int BoyerMoore(const vector<char>& P, const vector<char>& T) {
    int m = P.size();
    int n = T.size();
    if (m > n) return -1;
    
    int cnt = 0;
    int badchar[256];
    badCharHeuristic(P, m, badchar);

    int s = 0;
    while (s <= (n - m)) {
        int j = m - 1;
        while (j >= 0 && P[j] == T[s + j]) {
            j--;
            cnt++;
        }
        if (j < 0) {
            return cnt;
        } else {
            cnt++;
            s += max(1, j - badchar[T[s + j]]);
        }
    }
    return cnt;
}

int main() {
    int pat_num, txt_num;
    vector<char> P, T;
    
    cin >> pat_num;
    for (int i = 0; i < pat_num; i++) {
        string tmp;
        cin >> tmp;
        for (char c : tmp) {
            P.push_back(c);
        }
    }
    
    cin >> txt_num;
    for (int i = 0; i < txt_num; i++) {
        string tmp;
        cin >> tmp;
        for (char c : tmp) {
            T.push_back(c);
        }
    }

    vector<pair<int, string>> order;

    order.push_back(make_pair(RabinKarp(P, T), "RK"));
    order.push_back(make_pair(KMP(P, T), "KMP"));
    order.push_back(make_pair(BoyerMoore(P, T), "BM"));

    sort(order.begin(), order.end());

    if (order[0].first == order[1].first) {
        order[0].second = "0";
        order[1].second = "0";
    }

    if (order[1].first == order[2].first) {
        order[1].second = "0";
        order[2].second = "0";
    }

    for (auto it : order) {
        cout << it.second << " ";
    }

    return 0;
}