// 플랫폼: 백준
// 문제: 베르트랑 공준 - 실버 2
// 링크: https://www.acmicpc.net/problem/4948
// 언어: C++17
// 효율성: 1232 KB / 16 ms

#include <cstdio>

int main()
{
    while (1)
    {
        int n;
        scanf("%d", &n);
        if (n == 0) break;
        
        bool not_prime[2 * n + 1] = { false, };
        
        not_prime[0] = true;
        not_prime[1] = true;
        
        for (int i = 2; i * i <= 2 * n; i++)
            if (not_prime[i] == false)
                for (int j = 2 * i; j <= 2 * n; j += i)
                    not_prime[j] = true;
        
        int count = 0;
        for (int i = n + 1; i <= 2 * n; i++)
            if (not_prime[i] == false) count++;
        printf("%d\n", count);
    }
}