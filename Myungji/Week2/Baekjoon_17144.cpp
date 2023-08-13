#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
vector<vector<int>> v(2004);
bool ret;

void dfs(int depth, int here, vector<bool> visited){
    //깊이 4 : 종료 조건
    if(depth==4){
        ret = true; return;
    }
    for(int j=0;j<v[here].size();j++){
        int node = v[here][j]; //다음 노드
        if(visited[node]) continue;
        visited[node]=true;
        dfs(depth+1, node, visited); //다음 노드로 이동
        visited[node]=0;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //1. 입력받기
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    //2. 깊이가 4인 노드 구하기
    for(int i=0;i<n;i++){
        vector<bool> visited(2004);
        visited[i]=1;
        dfs(0, i, visited);
        if(ret) break;    }
    //3. 정답 출력
    cout << ret << "\n";

    return 0;
}