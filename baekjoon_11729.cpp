#include <iostream>

using namespace std;


#include <iostream>
#include <algorithm>
using namespace std;


void hanoi(int N, int start, int mid, int end)
{
	if (N == 1)
		cout << start <<" "<< end << '\n';
	else
	{
		hanoi(N - 1, start, end, mid);
		cout << start << " " << end << '\n';
		hanoi(N - 1, mid, start,end);
	}
}

int main()
{
	int N; //원판 수 

	cin >> N;

	int cnt = 1;
	for (int i = 0; i < N; i++)
	{
		cnt *= 2;
	}
	cout << cnt - 1 << '\n'; // cout<< (1<<n)-1<<'\n'; // 2^n-1
	hanoi(N, 1, 2, 3);


	return 0;
}
