#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void upVec(vector<int>& vec, int a, int b) {
    auto s = vec.begin() + a;
    auto e = vec.begin() + b + 1;
    reverse(s, e);
    for (int i = a; i < b + 1; i++)
        vec[i] = -vec[i];
}
bool check(vector<int> vec, int k){
    bool tmp = true;
    for (int i = 0; i < k; i++){
        if (vec[i] != i+1){
            tmp = false;
            return tmp;
        }
    }
    return tmp;
}
void init(int& s, int& e, vector<int> vec, int k){
    for (int i = 0; i < k; i++){
        if (vec[i] != i + 1){
            s = i;
            break;
        }
    }
    for (int i = k - 1; i >= s; i--){
        if (vec[i] != i + 1){
            e = i;
            break;
        }
    }
}
vector<int> f1(vector<int>& vec, int k) {
    int s, e;
    init(s, e, vec, k);
    int ep;
    for (s, ep = e; s <= ep; ep--){
        if(vec[ep]==-(s+1)) upVec(vec, s, ep);
    }
    return vec;
}
vector<int> f2(vector<int>& vec, int k) {
    int s, e;
    init(s, e, vec, k);
    int sp;
    for (sp = s; sp <= e; sp++){
        if(vec[sp]==-(e+1)) upVec(vec, sp, e);
    }
    return vec;
}
vector<int> f3(vector<int>& vec, int k) {
    int s, e;
    init(s, e, vec, k);
    int ep;
    for (s, ep = e; s <= ep; ep--){
        if(vec[ep]==(s+1)) upVec(vec, ep, e);
    }
    return vec;
}
vector<int> f4(vector<int>& vec, int k) {
    int s, e;
    init(s, e, vec, k);
    int sp;
    for (sp = s; sp <= e; sp++){
        if(vec[sp]==(e+1)) upVec(vec, s, sp);
    }
    return vec;
}
int boong(vector<int> vec, int k) {
    vector<int> t1(vec), t2;
    t1 = f1(t1, k);
    if (check(t1, k))
        return 1;
    else {
        t1 = vec;
        t1 = f1(t1, k);
        if (check(t1, k))
            return 2;
        else {
            t2 = f2(t1, k);
            if(check(t2, k))
                return 2;
        }
    }
    t1 = vec;
    t1 = f2(t1, k);
    if (check(t1, k))
        return 1;
    else {
        t1 = vec;
        t1 = f2(t1, k);
        if (check(t1, k))
            return 2;
        else {
            t2 = f2(t1, k);
            if(check(t2, k))
                return 2;
        }
    }
    t1 = vec;
    t1 = f3(t1, k);
    t2 = f1(t1, k);
    if (check(t2, k))
        return 2;
    t1 = vec;
    t1 = f4(t1, k);
    t2 = f2(t1, k);
    if (check(t2, k))
        return 2;
    else
        return 3;
}
int main() {
    int k;
    cin >> k;    
    for(int test = 0; test < 5; test++){
        vector<int> vec;
        int cnt = 0;
        for(int i = 0; i < k; i++){
            int tmp;
            cin >> tmp;
            vec.push_back(tmp);
        }
        cnt = boong(vec, k);
        if (cnt == 1)
            cout << "one\n";
        else if (cnt == 2)
            cout << "two\n";
        else
            cout << "over\n";
    }
    return 0;
}