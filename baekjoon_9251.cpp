#include <iostream>
#include <algorithm>
#include<string>

using namespace std;
#define MAX 1001
int DP[MAX][MAX];

int main()
{
	string A, B;
	cin >> A >> B;

	for (int i = 1; i <= A.size(); i++)
	{
		for (int j = 1; j <= B.size(); j++)
		{
			if (A[i - 1] == B[j - 1]) //case 1: Ai = Bj
				DP[i][j] = DP[i - 1][j - 1] + 1; // lcs(Ai-1, Bj-1)+1
			else //case 2: Ai !=Bj
				DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]); //max(lcs(Ai-1, Bj),lcs(Ai,Bj-1)
		}
	}
	cout << DP[A.size()][B.size()] << '\n';

	return 0;
}
