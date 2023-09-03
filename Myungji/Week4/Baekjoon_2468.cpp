#include <bits/stdc++.h>
using namespace std;
int n, a[104][104], visited[104][104], mx, h, ret, ans;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

void dfs(int y, int x){
    visited[y][x]=1;
    // cout << y << ":" << x << " 방문\n";
    for(int i=0;i<4;i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny<0||nx<0||ny>=n||nx>=n) continue;
        if(visited[ny][nx]) continue;
        if(a[ny][nx]>h) dfs(ny, nx);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //1. 압력받기
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
            mx = max(a[i][j], mx); //높이 최대값 저장
        }
    }
    //2. dfs 수행
    for(h=0;h<=mx;h++){ //k : 높이
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]>h && visited[i][j]==0){
                    dfs(i, j);
                    ret++;
                    // cout << "한곳 끝\n";
                }
            }
        }
        ans = max(ret, ans);
        ret=0;
        memset(visited,0,sizeof(visited));
    }
    //3. 정답 출력
    cout << ans;
    return 0;
}