#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n,m,temp, a[11], comp[11], visited[11], ret=INF;
vector<int> adj[11];

pair<int, int> dfs(int here, int value){
    visited[here]=1;
    pair<int, int> ret = {1, a[here]}; //구역수, 인구수
    for(int there: adj[here]){
        if(comp[there] != value) continue; //같은 팀이 아니면
        if(visited[there]) continue;
        pair<int, int> _temp = dfs(there, value);
        ret.first += _temp.first;
        ret.second += _temp.second;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //1. 입력받기
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++){
        cin >> m;
        for(int j=0;j<m;j++){
            cin >> temp;
            //양방향 간선
            adj[i].push_back(temp);
            adj[temp].push_back(i);
        }
    }
    //2. 모든 경우의 수에 대해 팀 잘 나누어졌는지 확인
    for(int i=1;i<(1<<n)-1;i++){ //000001 ~ 111111
        fill(comp, comp+11, 0); //팀표시
        fill(visited, visited+11, 0); //방문표시
        int idx1=-1, idx2=-1;
        for(int j=0;j<n;j++){ //자리수 별로(0부터 시작)
            if(i & (1<<j)){ //1 존재하면 팀 표시
                comp[j+1]=1; idx1=j+1;
            } else idx2=j+1;
        }
        //dfs 수행하여 모든 구역에 대해 팀이 나누어졌는지 확인
        pair<int, int> comp1 = dfs(idx1, 1); //위치, 값
        pair<int, int> comp2 = dfs(idx2, 0); //위치, 값
        if(comp1.first + comp2.first ==n) //모두 방문했으면
            ret=min(ret, abs(comp1.second-comp2.second)); //인구수차이
    }
    cout << (ret==INF ? -1 : ret) << "\n";
}