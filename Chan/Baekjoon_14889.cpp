// 플랫폼: 백준
// 문제: 스타트와 링크 - 실버 2
// 링크: https://www.acmicpc.net/problem/14889
// 언어: C++17
// 효율성: 2024 KB / 68 ms

#include <iostream>
#define MAX_DEPTH 20

int stats[MAX_DEPTH + 1][MAX_DEPTH + 1];
bool check[MAX_DEPTH + 1];
int min_diff = -1;

void dfs(int depth, int num, int n)
{
	if (depth == n / 2)
	{
		int temp = 0;
		for (int i = 1; i <= n - 1; i++)
			for (int j = i + 1; j <= n; j++)
			{
				if (check[i] && check[j])
					temp += (stats[i][j] + stats[j][i]);
				else if (!check[i] && !check[j])
					temp -= (stats[i][j] + stats[j][i]);
			}
		temp = temp >= 0 ? temp : -temp;
		if (min_diff == -1 || temp < min_diff)
			min_diff = temp;
		return;
	}

	for (int i = num; i <= n - 1; i++)
	{
		check[i] = true;
		dfs(depth + 1, i + 1, n);
		check[i] = false;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			std::cin >> stats[i][j];
	dfs(0, 1, N);
	std::cout << min_diff;
}