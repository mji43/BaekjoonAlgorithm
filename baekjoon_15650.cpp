//조합 - 중복 허용 X - visited배열 사용
#include <iostream>
#define MAX 9
using namespace std;

int n, m;
int arr[MAX] = { 0, };
bool visited[MAX] = { 0, };
//num-시작점, cnt-뽑는 개수
void dfs(int num, int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = num; i <= n; i++) 	
	{
		if (!visited[i]) //i번째 값 방문 X-> 방문표시, 재귀호출 -> 방문X 표시 
		{
			visited[i] = true;
			arr[cnt] = i;
			dfs(i + 1, cnt + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	dfs(1, 0);
}
