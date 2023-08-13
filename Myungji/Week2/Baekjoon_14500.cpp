#include <bits/stdc++.h>
using namespace std;
int n, m, mx;
int dy[] = {0,0,-1,1};
int dx[]={-1,1,0,0};
int mp[504][504], visited[504][504];

void uniShape(int y, int x){
    // ㅜ
    if (y + 1 < n && x + 2 < m)
        mx = max(mx, mp[y][x] + mp[y][x + 1] + mp[y][x + 2] + mp[y + 1][x + 1]);
    // ㅏ
    if (y + 2 < n && x + 1 < m)
        mx = max(mx, mp[y][x] + mp[y + 1][x] + mp[y + 1][x + 1] + mp[y + 2][x]);
    // ㅗ
    if (y - 1 >= 0 && x + 2 < m)
        mx = max(mx, mp[y][x] + mp[y][x + 1] + mp[y][x + 2] + mp[y - 1][x + 1]);
    // ㅓ
    if (y + 2 < n && x - 1 >= 0)
        mx = max(mx, mp[y][x] + mp[y + 1][x] + mp[y + 1][x - 1] + mp[y + 2][x]);
}

void norShape(int y, int x, int depth, int sum){
    //종료조건
    if(depth==3){
        mx = max(mx, sum); return;
    }
    for(int i=0;i<4;i++){
        int ny = y+dy[i];
        int nx = x + dx[i];
        if(ny<0||nx<0||ny>=n||nx>=m) continue;
        if(visited[ny][nx]) continue;
        visited[ny][nx]=1;
        norShape(ny, nx, depth+1, sum+mp[ny][nx]);
        visited[ny][nx]=0;
    }
    
}

void solve(int y, int x){
    uniShape(y, x); //ㅏ,ㅗ,ㅓ,ㅜ
    visited[y][x]=1;
    norShape(y,x, 0, mp[y][x]);
    visited[y][x]=0;
;}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //1. 입력받기
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> mp[i][j];
    //2. 합의 최댓값 구하기
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            solve(i, j);
    //3. 정답 출력
    cout << mx;

    return 0;
}