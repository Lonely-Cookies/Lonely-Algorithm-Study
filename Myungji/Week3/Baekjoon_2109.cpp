#include <bits/stdc++.h>
using namespace std;

int p,f,s,v,c, ret;
int n, mp, mf, ms, mv, ret_price=987654321;
vector<int> info[15];
map<int, vector<vector<int>>> ret_v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	//1. 입력하기
	cin >> n;
	pair<int, int> l[n];
	for(int i=0;i<n;i++){
		cin >> l[i].second >> l[i].first; //강연기간 - 강연료
	}
	sort(l, l+n, greater<>()); //강연기간으로 내림차순 정렬
	//2. 일자별로 고비용 강의 pop
	priority_queue<int> pq;
	int j=0;
	for(int i=l[0].first;i>=1;i--){
		while(j<n && i<=l[j].first) pq.push(l[j++].second);
		if(pq.size()){
			ret += pq.top();
			pq.pop();
		}
	}
	//3. 정답 출력
	cout << ret;
	return 0;
}