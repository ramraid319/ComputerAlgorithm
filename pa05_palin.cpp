#include <iostream>
#include <string>
using namespace std;
bool is_pal(string s, int l, int r) {
    while(l<=r) if(s[l++]!=s[r--]) return false;
    return true;
}
int pal(string s) {
    if(s[0] != s[s.length()-1]) return 0;
    if(is_pal(s, 0, s.length()-1)) return s.length();
    int bias = 0;
    for(int i=0; i<s.length(); i++) {
        int j=s.length()-i-1;
        if(s[i]!=s[j]) {
            int l=i, r=j;
            while(!is_pal(s, l, --r));
            bias = j-r;
            l=i; r=j;
            while(!is_pal(s, ++l, r));
            if(bias > l-i) bias=l-i;
            break;
        }
    }
    return s.length()-bias;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cout << pal(s) << endl;
    }
    return 0;
}
