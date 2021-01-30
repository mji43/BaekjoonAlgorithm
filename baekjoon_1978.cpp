#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	long long N, M, res;
	scanf("%lld", &N);
	scanf("%lld", &M);

	res = llabs(N - M);
	
	printf("%lld", res);

	return 0;
}


