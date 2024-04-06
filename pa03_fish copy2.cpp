#include <bits/stdc++.h>
using namespace std;
void flip(vector<int> &v,int s,int e){reverse(v.begin()+s, v.begin()+e+1);for (int i=s; i<e+1; i++) v[i]*= -1;}
void makeArr(vector<int> &a,int n){a.resize(n);for (int i=0; i<n; i++) cin >> a[i];}
void makeOriginVec(vector<int> &o, int n){for (int i=0; i<n; i++) o[i] =i+1;}
void SSE(vector<int> a,vector<int> o,int *sP,int *eP){
  int n=a.size();
  int s=-1, e=-1;
  for (int i=0; i<n;i++){
    if (a[i] != o[i]){
      if (s== -1)  s=i;
      e=i;
    }} if (s != -1){
    *sP=s;
    *eP=e;}}
void isSF(vector<int> a, vector<int> o, bool &isS){
  int n=a.size();
  int s= -1, e= -1;
  isS=false;
  for(int i = 0; i < n; i++){
    if(a[i] != o[i]){
      if (s == -1) s=i;
      e=i;
    }
  } if (s==-1)  isS=true;
}
void F1(vector<int> &a,vector<int> o,int sP,int eP,bool &isS){
  isSF(a,o,isS);
  if (!isS){int pivot=eP;while (pivot>=sP){if (a[pivot]==-(sP+1))  flip(a,sP,pivot);pivot--;}}}
void F2(vector<int> &a,vector<int> o,int sP,int eP,bool &isS){
  isSF(a,o,isS);
  if (!isS){int pivot=sP;while (pivot<=eP){if (a[pivot]==-(eP + 1))  flip(a,pivot,eP);pivot++;}}}
void F3(vector<int> &a,vector<int> o,int sP,int eP,bool &isS){
  isSF(a,o,isS);
  if (!isS){int pivot=eP;while (pivot>=sP){if (a[pivot]==(sP+1)) flip(a,sP,pivot);pivot--;}}}
void F4(vector<int> &a, vector<int> o,int sP,int eP,bool &isS){
  isSF(a,o,isS);
  if (!isS){int pivot=sP;while (pivot<=eP){if (a[pivot]==(eP+1)) flip(a,pivot,eP);pivot++;}}}
int S1(vector<int> a, vector<int> o, int sP, int eP, bool &isS){
  int s=-1, e=-1;F1(a,o,sP,eP,isS);isSF(a,o,isS);if (isS) return 1;vector<int> tmp;
  for (int i=0; i<a.size();i++)  tmp.push_back(a[i]);
  if (!isS){SSE(a,o,&s,&e);F1(a,o,s,e,isS);isSF(a,o,isS);if (isS) return 2;
  } if (!isS){F2(tmp,o,s,e,isS);isSF(tmp,o,isS);if (isS) return 2;} return 0;
}

int S2(vector<int> a, vector<int> o, int sP, int eP, bool &isS){
  int s=-1, e=-1;F2(a,o,sP,eP,isS);isSF(a,o,isS);if (isS) return 1;vector<int> tmp;
  for (int i=0; i<a.size();i++) tmp.push_back(a[i]);
  if (!isS){SSE(a,o,&s,&e);F1(a,o,s,e,isS);isSF(a,o,isS);if (isS) return 2;}
  if (!isS){F2(tmp,o,s,e,isS);isSF(tmp,o,isS);if (isS) return 2;} return 0;}
int S3(vector<int> a,vector<int> o,int sP,int eP,bool &isS){int s = -1, e = -1;F3(a,o,sP,eP,isS);isSF(a,o,isS);
  if (!isS){SSE(a,o,&s,&e);F1(a,o,s,e,isS);isSF(a,o,isS);if (isS) return 2;} return 0;}
int S4(vector<int> a,vector<int> o,int sP,int eP,bool &isS){
  int s=-1, e=-1;F4(a,o,sP,eP,isS);isSF(a,o,isS);
  if (!isS){SSE(a,o,&s,&e);F2(a,o,s,e,isS);isSF(a,o,isS);
    if (isS) return 2;
  } return 0;}
int main(){int n;cin>>n;vector<int> a(n);vector<int> o(n);
  for (int i=0;i<5;i++){
    int s=-1, e=-1;bool isS=false;
    makeArr(a,n);makeOriginVec(o,n);SSE(a,o,&s,&e);
    if (S1(a,o,s,e,isS)==1 || S2(a,o,s,e,isS)==1) cout<<"one"<<"\n";
    else if(S1(a,o,s,e,isS)==2 || S2(a,o,s,e,isS)==2 || S3(a,o,s,e,isS)==2 || S4(a,o,s,e,isS)==2)  cout<<"two"<<"\n";
    else  cout<<"over"<<"\n";
  } return 0;
}