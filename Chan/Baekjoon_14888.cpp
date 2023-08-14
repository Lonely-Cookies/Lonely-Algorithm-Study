// 플랫폼: 백준
// 문제: 연산자 끼워넣기 - 실버 1
// 링크: https://www.acmicpc.net/problem/14888
// 언어: C++17
// 효율성: 1112 KB / 0 ms

#include <cstdio>
#define MAX_DEPTH 11
#define MIN_RANGE -1000000000
#define MAX_RANGE 1000000000

int operands[MAX_DEPTH];
int operators[4];
int max = MIN_RANGE - 1;
int min = MAX_RANGE + 1;

void dfs(int depth, int n, int temp)
{
	if (depth == n - 1)
	{
		if (temp > max) max = temp;
		if (temp < min) min = temp;
		return;
	}

	for (int i = 0; i < 4; i++)
		if (operators[i] > 0)
		{
			operators[i]--;
			if      (i == 0) dfs(depth + 1, n, temp + operands[depth + 1]);
			else if (i == 1) dfs(depth + 1, n, temp - operands[depth + 1]);
			else if (i == 2) dfs(depth + 1, n, temp * operands[depth + 1]);
			else if (i == 3) dfs(depth + 1, n, temp / operands[depth + 1]);
			operators[i]++;
		}
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &operands[i]);
	for (int i = 0; i < 4; i++)
		scanf("%d", &operators[i]);
	dfs(0, N, operands[0]);
	printf("%d\n%d", max, min);
}