#include <iostream>
#include <vector>
using namespace std;

const int MAX = 101;

int num; //컴퓨터의 수 
int set; //컴퓨터 쌍의 수
bool visited[MAX]; //방문처리
vector<int> tree[MAX];
int cnt = 0;

void dfs(int start)
{	//감염체크 
	visited[start] = true;

	for (int i = 0; i < tree[start].size(); i++) //start노드와 연결된 인접노드 방문
	{
		int next = tree[start][i];
		if (!visited[next])
		{
			cnt++;
			dfs(next);

		}
	}
}

int main()
{

	cin >> num; //컴퓨터 수 받기 
	cin >> set; //컴퓨터 쌍의 수 받기 

	for (int i = 0; i < set; i++)
	{
		int node1, node2;
		cin >> node1 >> node2;

		tree[node1].push_back(node2);
		tree[node2].push_back(node1); // 양방향 연결 
	}

	dfs(1);

	cout << cnt;

	return 0;
}