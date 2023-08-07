//https://school.programmers.co.kr/learn/courses/30/lessons/60057
#include <bits/stdc++.h>

using namespace std;

void convert(const string &text, const int &group_count, vector<string> &out){
    if(!out.empty()) out.clear(); //저장할 벡터 초기화
    for(int index=0; index<text.size(); index+=group_count)
        out.push_back(text.substr(index, group_count)); //text 나누어서 저장
}

int solution(string s) {
    int answer = 0; 
    vector<int> len; //나눠진 토큰 개수 저장
    vector<string> token; //나눠진 토큰
    string before;
    for(int index=1;index<=s.size()/2;index++){ //절반까지 확인하면 됨
        convert(s, index, token); //token에 문자열 나누어서 저장
        string text="";
        before=token[0]; //비교할 문자열
        int cnt=1;
        for(int index=1;index<token.size();index++){
            if(token[index].compare(before)==0) //앞과 같으면
                cnt++;
            else{ //앞 문자와 다르면
                if (cnt!=1) //1개면 숫자 안붙임
                    text += to_string(cnt); //숫자 붙이기
                text += before; //문자 붙이기
                before=token[index]; //업데이트
                cnt =1;
            }
        }
        if(cnt != 1) //1개면 숫자 안붙임
            text += to_string(cnt); 
        text += before; //문자 붙이기
        len.push_back(text.size()); //나눠진 문자열 길이 저장
    }
    if(len.empty()) //비어있으면 전체 문자열 길이로 저장
        len.push_back(s.size());
    //정답 반환
    answer = *min_element(len.begin(), len.end());
    return answer;
}