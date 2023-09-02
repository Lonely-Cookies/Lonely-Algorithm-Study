#include <bits/stdc++.h>
using namespace std;
int a,b,c, f, l, ret;
int t[104];
vector<int> v;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //1. 압력받기
    cin >> a >> b >> c;
    for(int i=0;i<3;i++){
        cin >> f >> l;
        for(int i=f;i<l;i++) t[i]++;
    }
    //3. 요금 계산
    for(int i=0;i<100;i++){
        if(t[i]==0) continue;
        if(t[i]==1) ret+=a;
        else if(t[i]==2) ret += b*2;
        else if(t[i]==3) ret += c*3;
    }
    //4. 요금 출력
    cout << ret;

    return 0;
}