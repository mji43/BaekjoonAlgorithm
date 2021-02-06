#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int min(int a, int b)
{
	return a > b ? b : a;
}

int main()
{
	int arr[1000001] = { 0 , };
	int a;

	scanf("%d", &a);
	
	arr[1] = 0;
	for (int i = 2; i <= a; i++)
	{
		arr[i] = arr[i - 1] + 1; //규칙 3번  : 1을 빼기
		if (i % 2 == 0)
		{
			arr[i] = min(arr[i], arr[i / 2] + 1); //규칙 2번: 2로 떨어지는 경우
		}
		if (i % 3 == 0)
		{
			arr[i] = min(arr[i], arr[i / 3] + 1);//규칙 1번: 3으로 떨어지는 경우 
		}
	}
	
	printf("%d", arr[a]);

	return 0;
}
