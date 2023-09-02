#include <bits/stdc++.h>
using namespace std;
int n, a[24][24], dp[24][24][3]; //y,x,direction

bool check(int y, int x, int d){ //새로운 파이프 현재 셀에 배치 가능 여부
    if(d==0 || d==2){ //수평, 수직 -> 2방향
        if(!a[y][x]) return true; //파이프가 존재하지 않으면 배치 가능
    }
    else if(d==1) //대각선 방향일때 -> 3방향
    //현재 셀, 현재셀의 바로 위 셀, 현재셀의 왼쪽 셀 점유되어있는지 확인
    if(a[y][x]==0 && a[y-1][x]==0 && a[y][x-1]==0) return true;

    return false;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //1. 압력받기
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }                      
    dp[1][2][0]=1; //파이프 초기 (1,2) 가로방향(0)
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            //경우의 수 : 더하기
            //가로형태 파이프였을때
            if(check(i, j+1, 0)) dp[i][j+1][0] += dp[i][j][0]; //가로
            if(check(i+1, j+1, 1)) dp[i+1][j+1][1] += dp[i][j][0]; //대각선
            //세로 형태 파이프였을때
            if(check(i+1, j, 2)) dp[i+1][j][2] += dp[i][j][2]; //세로
            if(check(i+1,j+1,1)) dp[i+1][j+1][1] += dp[i][j][2]; //대각선
            //대각선 형태의 파이프였을때
            if(check(i, j+1, 0)) dp[i][j+1][0] += dp[i][j][1]; //가로
            if(check(i+1, j, 2)) dp[i+1][j][2] += dp[i][j][1]; //세로
            if(check(i+1, j+1, 1)) dp[i+1][j+1][1] += dp[i][j][1]; //대각선
        }
    }
    //3. (n, n) 도착시 경우의 수                    
    int ret = dp[n][n][0]; //가로
    ret += dp[n][n][1]; //대각선
    ret += dp[n][n][2]; //세로 경우의 수 더하기
    //4. 정답 출력하기
    cout << ret << "\n";
    return 0;
}