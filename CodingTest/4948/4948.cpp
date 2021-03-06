﻿#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, bool> numbers;

void PrimeNum(int max);

int main(void)
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, max;
	max = 0;
	vector<int> num;
	vector<int> answer;
	do
	{
		cin >> n;
		if (n == 0) break;
		if (max < n)
		{
			max = n;
		}
		num.push_back(n);
	} while (true);
	
	PrimeNum(2 * max);

	for (int i = 0; i < num.size(); i++)
	{
		int count = 0;
		for (int j = num[i] + 1; j <= 2 * num[i]; j++)
		{
			if (numbers[j])
			{
				count++;
			}
		}
		cout << count << "\n";
	}
}

//에라토스테네스의 체 (소수 찾기)
void PrimeNum(int max)
{
	// 만약 1보다 작거나 같으면 종료
	if (max <= 1) return;

	//2 ~ num 까지 n - 1개 저장
	//배열 인덱스와 num 이 같도록 2 부터 시작
	//처음엔 모두 소수로 보고 true 로 지정
	for (int i = 2; i <= max; i++) {
		numbers[i] = true;
	}

	//만약 numbers[i] 가 true 라면 소수이며 이후의 numbers[i]의 배수들은 모두 소수가 아니기 때문에 모두 false를 준다
	for (int i = 2; i <= max; i++)
	{
		if (numbers[i])//true 라면
		{
			for (int j = i * 2; j <= max; j += i)
			{
				numbers[j] = false;
			}
		}
	}
}