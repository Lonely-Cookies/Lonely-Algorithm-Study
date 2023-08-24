#include <bits/stdc++.h>
using namespace std;

int n,m, a[300004], mx, ret=987654321;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	//1. 입력하기
	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> a[i];
		mx=max(mx, a[i]);
	}
	//2. 이분탐색
	int l=1; int r=mx;
	int mid=0;
	while(l<=r){
		mid=(l+r)/2;
		int cnt=0;
		for(int i=0;i<m;i++){
			//묶음 개수 구하기
			cnt += a[i]/mid; 
			if(a[i]%mid) cnt++; //마지막 묶음
		}
		//묶음이 n 이하이면
		if(cnt<=n){
			r=mid-1;
			ret=min(mid, ret);
		}
		//n 초과이면
		else l=mid+1;
	}
	//3. 정답 출력
	cout <<ret;
	return 0;
}