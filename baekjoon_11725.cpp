#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100001;

int N;
bool visited[MAX]; //방문처리
int parent[MAX]; //부모 기록 
vector<int> tree[MAX];


//DFS
void findParent(int from)
{
	visited[from] = true; // 방문 처리 

	for (int i = 0; i < tree[from].size(); i++) //from노드와 붙어있는 인접노드 하나씩 방문  
	{
		int next = tree[from][i];   
		if (visited[next] == false) // 방문 안했다면 
		{
			parent[next] = from; // next의 부모노드 = from
			findParent(next); // 재귀함수
		}
	}
}

int main()
{
	cin >> N; //노드의 개수 

	for (int i = 0; i < N - 1; i++) //양방향 노드 연결 
	{
		int node1, node2;
		cin >> node1 >> node2;
		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}
	findParent(1);

	for (int i = 2; i <= N; i++)
	{
		cout << parent[i] << "\n";
	}
	return 0;
}



