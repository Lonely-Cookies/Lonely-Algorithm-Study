#include <bits/stdc++.h>
using namespace std;

int p,f,s,v,c;
int n, mp, mf, ms, mv, ret_price=987654321;
vector<int> info[15];
map<int, vector<vector<int>>> ret_v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	//1. 입력하기
	cin >> n;
	cin >> mp >> mf >> ms >> mv;
	for(int i=0;i<n;i++){
		cin >> p >> f >> s >> v >> c;
		info[i].push_back(p);
		info[i].push_back(f);
		info[i].push_back(s);
		info[i].push_back(v);
		info[i].push_back(c);
	}
	//2. 비트마스킹 수행
	for(int i=1;i<(1<<n);i++){ //모든 경우의 수
		p=f=s=v=c=0;
		vector<int> tmp;
		for(int j=0;j<n;j++){ //자리
			if(i & (1<<j)){
				p += info[j][0];
				f += info[j][1];
				s += info[j][2];
				v += info[j][3];
				c += info[j][4];
				tmp.push_back(j+1); //재료번호 저장
			}
		}

		if(p>=mp && f>=mf && s>=ms && v>=mv){
			if(ret_price >= c){
				ret_price = c;
				ret_v[ret_price].push_back(tmp); //재료번호 벡터 저장
			}
		}
	}
	//3. 정답 출력
	if(ret_price==987654321) cout << -1 << "\n";
	else{
		sort(ret_v[ret_price].begin(), ret_v[ret_price].end());
		cout << ret_price << "\n";
		for(int a:ret_v[ret_price][0])
			cout << a << " ";
	}
	return 0;
}