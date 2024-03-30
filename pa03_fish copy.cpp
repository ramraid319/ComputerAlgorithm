#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void updateVec(vector<int>& vec, int a, int b) {
    auto start = vec.begin() + a;
    auto end = vec.begin() + b + 1;
    reverse(start, end);
    for (size_t i = a; i < b + 1; i++)
        vec[i] = -vec[i];
}
bool checkSort(vector<int> vec, int size){
    bool tmp = true;
    for (size_t i = 0; i < size; i++){
        if (vec[i] != i+1){
            tmp = false;
            return tmp;
        }
    }
    return tmp;
}
void initStartEnd(int& start, int& end, vector<int> vec, int size){
    for (int i = 0; i < size; i++){
        if (vec[i] != i + 1){
            start = i;
            break;
        }
    }
    for (int i = size - 1; i >= start; i--){
        if (vec[i] != i + 1){
            end = i;
            break;
        }
    }
}
vector<int> form1(vector<int>& vec, int size) {
    int start, end;
    initStartEnd(start, end, vec, size);
    int e_pivot;
    for (start, e_pivot = end; start <= e_pivot; e_pivot--){
        if(vec[e_pivot]==-(start+1)) updateVec(vec, start, e_pivot);
    }
    return vec;
}

vector<int> form2(vector<int>& vec, int size) {
    int start, end;
    initStartEnd(start, end, vec, size);
    int s_pivot;
    for (s_pivot = start; s_pivot <= end; s_pivot++){
        if(vec[s_pivot]==-(end+1)) updateVec(vec, s_pivot, end);
    }
    return vec;
}

vector<int> form3(vector<int>& vec, int size) {
    int start, end;
    initStartEnd(start, end, vec, size);
    int e_pivot;
    for (start, e_pivot = end; start <= e_pivot; e_pivot--){
        if(vec[e_pivot]==(start+1)) updateVec(vec, e_pivot, end);
    }
    return vec;
}

vector<int> form4(vector<int>& vec, int size) {
    int start, end;
    initStartEnd(start, end, vec, size);
    int s_pivot;
    for (s_pivot = start; s_pivot <= end; s_pivot++){
        if(vec[s_pivot]==(end+1)) updateVec(vec, start, s_pivot);
    }
    return vec;
}
int boong(vector<int> vec, int size) {
    vector<int> tmp1(vec), tmp2;

    tmp1 = form1(tmp1, size);
    if (checkSort(tmp1, size))
        return 1;
    else {
        tmp1 = vec;
        tmp1 = form1(tmp1, size);
        if (checkSort(tmp1, size))
            return 2;
        else {
            tmp2 = form2(tmp1, size);
            if(checkSort(tmp2, size))
                return 2;
        }
    }
    tmp1 = vec;
    tmp1 = form2(tmp1, size);
    if (checkSort(tmp1, size))
        return 1;
    else {
        tmp1 = vec;
        tmp1 = form2(tmp1, size);
        if (checkSort(tmp1, size))
            return 2;
        else {
            tmp2 = form2(tmp1, size);
            if(checkSort(tmp2, size))
                return 2;
        }
    }
    tmp1 = vec;
    tmp1 = form3(tmp1, size);
    tmp2 = form1(tmp1, size);
    if (checkSort(tmp2, size))
        return 2;
    tmp1 = vec;
    tmp1 = form4(tmp1, size);
    tmp2 = form2(tmp1, size);
    if (checkSort(tmp2, size))
        return 2;
    else
        return 3;
}
int main() {
    int size;
    cin >> size;    
    for(int test = 0; test < 5; test++){
        vector<int> vec;
        int cnt = 0;
        for(int i = 0; i < size; i++){
            int tmp;
            cin >> tmp;
            vec.push_back(tmp);
        }
        cnt = boong(vec, size);
        if (cnt == 1)
            cout << "one\n";
        else if (cnt == 2)
            cout << "two\n";
        else
            cout << "over\n";
    }
    return 0;
}