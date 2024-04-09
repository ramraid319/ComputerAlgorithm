#include <iostream>
#include <vector>
using namespace std;
void printTower(const vector<int> tow) {
    for(auto it:tow) {cout << it << " ";}
    cout << endl;
}
void moveDisk(vector<int>& fromTow, vector<int>& toTow) {
    if(!fromTow.empty()) {
        int tmp = fromTow.back();
        if(!toTow.empty()) {
            if(tmp < toTow.back()) {
                fromTow.pop_back();
                toTow.push_back(tmp);
                
                printTower(fromTow);
                printTower(toTow);
            }
            else cout << "can't do that" << endl;
        } else {
            fromTow.pop_back();
            toTow.push_back(tmp);

            printTower(fromTow);
            printTower(toTow);
        }
    }
}
int main() {
    int n = 0;
    cin >> n;
    vector<int> tow1;
    vector<int> tow2;
    vector<int> tow3;
    for(int i=n;i>0;i--) {tow1.push_back(i);}
    printTower(tow1);
    moveDisk(tow1, tow2);
    moveDisk(tow1, tow2);
    moveDisk(tow1, tow2);
    moveDisk(tow1, tow2);
    moveDisk(tow1, tow2);

    return 0;
}