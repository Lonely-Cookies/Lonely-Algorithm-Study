#include <bits/stdc++.h>
using namespace std;
int N, ret;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    pair<int, int> p[N];
    for(int i=0;i<N;i++){
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p+N);
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<N;i++){
        pq.push(p[i].second);
        while(pq.size()>p[i].first) pq.pop();
    }
    while(!pq.empty()){
        ret += pq.top();
        pq.pop();
    }
    cout << ret;
}