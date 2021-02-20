#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100001;

int N;
bool visited[MAX]; //�湮ó��
int parent[MAX]; 
vector<int> tree[MAX];

void findParent(int from)
{
	visited[from] = true; // �湮 ó�� 

	for (int i = 0; i < tree[from].size(); i++) //from���� �پ��ִ� ������� �ϳ��� �湮  
	{
		int next = tree[from][i];   
		if (visited[next] == false) // �湮 ���ߴٸ� 
		{
			parent[next] = from; // next�� �θ��� = from
			findParent(next); // ����Լ�
		}
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N - 1; i++)
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



