# N과 M 문제 (4)
중복된 수가 존재하는 길이 m 오름차순 수열(같은 수도 가능)
```cpp
#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[10];
vector<int> v;
bool visited[10];

void dfs(int num, int cnt){
    if(cnt==m){
        for(int i=0;i<m;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=num;i<=n;i++){ //시작점 항상 커지도록
        // if(!visited[i]){
            // visited[i]=true;
            arr[cnt]=i; 
            dfs(i, cnt+1); //동일한 수부터 시작
            // visited[i]=false; //초기화
        // }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //1. 입력받기
    cin >> n >> m;

    //2.dfs
    dfs(1, 0); //0부터 시작
    return 0;
}
```

