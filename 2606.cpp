#include <iostream>
#include <vector>
using namespace std;

const int MAX = 101;

int num; //��ǻ���� �� 
int set; //��ǻ�� ���� ��
bool visited[MAX]; //�湮ó��
vector<int> tree[MAX];
int cnt = 0;

void dfs(int start)
{	//����üũ 
	visited[start] = true;

	for (int i = 0; i < tree[start].size(); i++) //start���� ����� ������� �湮
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

	cin >> num; //��ǻ�� �� �ޱ� 
	cin >> set; //��ǻ�� ���� �� �ޱ� 

	for (int i = 0; i < set; i++)
	{
		int node1, node2;
		cin >> node1 >> node2;

		tree[node1].push_back(node2);
		tree[node2].push_back(node1); // ����� ���� 
	}

	dfs(1);

	cout << cnt;

	return 0;
}