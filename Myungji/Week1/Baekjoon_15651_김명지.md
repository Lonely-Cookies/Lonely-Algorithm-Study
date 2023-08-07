# N과 M 문제 (3)
중복된 수가 존재하는 길이 m 수열
```cpp
#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[10];
bool visited[10], check[10][10];

void dfs(int cnt){
    if(cnt==m){
        for(int i=0;i<m;i++){
            cout << arr[i]<< " ";
        }
        cout << "\n";
        return;
    }
    for(int i=1;i<=n;i++){ //n개의 노드
        // if(!visited[i]){
            // visited[i]=true;
            arr[cnt]=i;
            dfs(cnt+1);
            // visited[i]=false; //초기화
        // }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //1. 입력받기
    cin >> n >> m;
    //2.dfs
    dfs(0); //0부터 시작
    return 0;
}
```

