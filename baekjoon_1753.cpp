//����1753 �ִܰ�� 
//���ͽ�Ʈ��_�˰��� 
//�������� �������� ������ ������ �湮�ϸ� ���������� �ش� �������� �ּ� �Ÿ��� ã�� �˰���
#include <iostream>
#include <vector>
#include <queue>
#define MAX 20000+1
#define INF 98765421

using namespace std;

int V,E,start; //���, ���� ����, �������� ��ȣ   
//������ �����Ͱ� 2�� �̻��̸� pair�� ���´�.
vector<pair<int, int>>graph[MAX];//cost(�Ÿ�), vertex

vector<int> dijkstra(int start, int vertex) {

	//INF�� �ʱ�ȭ�� vertex���� ���Ҹ� ������ vector distance ����  
	vector<int> distance(vertex, INF); //start ���� �Ÿ� 
	distance[start] = 0; //�ڱ� �ڽ����� ���� ��� = 0 	//[star]��° ���Ҹ� �����Ѵ� 


	//�ּ��� ���� //priority_queue -> MAX_HEAP, ������ �ٲ� �ּҰ����������Ѵ�
	//cost(�Ÿ�), vertex
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		pair<int, int> cur = pq.top();
		pq.pop();

		int cost = -cur.first; //- ����ġ ���� ū�� 
		int vertex = cur.second;

		//�ּҰŸ�
		if (distance[vertex] < cost) {
			continue;
		}

		//vertex�� neighbor ���� Ȯ�� 
		for (int i = 0; i < graph[vertex].size(); i++) {
			pair<int, int> next = graph[vertex][i];
			int ncost = next.first;
			int nvertex = next.second;

			if (distance[nvertex] > cost + ncost) {
				distance[nvertex] = cost + ncost;
				//�Ÿ���ȣ ����ȭ, �Ÿ��� ���� ������ ���������� �Ѵ� 
				pq.push(make_pair(-distance[nvertex], nvertex));
			}
		}
	}
	return distance;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> E; //���, ���� ���� 
	cin >> start;//���� ���� ��ȣ 

	for (int i = 0; i < E; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;

		graph[u].push_back(make_pair(cost,v)); //����׷���
	}
	
	vector<int> result = dijkstra(start, V+1);

	for (int i = 1; i <= V; i++) {

		if (result[i] == INF)
			cout << "INF\n";

		else
			cout << result[i] << "\n";
	}
	return 0;
}