// 플랫폼: 백준
// 문제: 소트인사이드 - 실버 5
// 링크: https://www.acmicpc.net/problem/1427
// 언어: C++17
// 효율성: 2024 KB / 0 ms

#include <iostream>
#include <string>

int main()
{
    std::string num;
    std::cin >> num;

    int len = num.length();
    for (int i = 0; i < len - 1; i++)
        for (int j = 0; j < len - i - 1; j++)
            if (num[j] < num[j + 1])
            {
                int temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
    std::cout << num;
}