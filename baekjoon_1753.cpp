//백준1753 최단경로 
//다익스트라_알고리즘 
//시작점을 기준으로 인접한 노드들을 방문하며 시작점에서 해당 노드까지의 최소 거리를 찾는 알고리즘
#include <iostream>
#include <vector>
#include <queue>
#define MAX 20000+1
#define INF 98765421

using namespace std;

int V,E,start; //노드, 간선 개수, 시작정점 번호   
//전달할 데이터가 2개 이상이면 pair로 묶는다.
vector<pair<int, int>>graph[MAX];//cost(거리), vertex

vector<int> dijkstra(int start, int vertex) {

	//INF로 초기화된 vertex개의 원소를 가지는 vector distance 생성  
	vector<int> distance(vertex, INF); //start 기준 거리 
	distance[start] = 0; //자기 자신한테 가는 비용 = 0 	//[star]번째 원소를 참소한다 


	//최소힙 생성 //priority_queue -> MAX_HEAP, 음수로 바꿔 최소값나오도록한다
	//cost(거리), vertex
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		pair<int, int> cur = pq.top();
		pq.pop();

		int cost = -cur.first; // (-가중치 가장 큰거) = 가중치 가장 작은 거
		int vertex = cur.second;

		/*
		//최소거리
		if (distance[vertex] < cost) {
			continue;
		}
		*/

		//vertex의 neighbor 전부 확인 
		for (int i = 0; i < graph[vertex].size(); i++) {
			pair<int, int> next = graph[vertex][i];
			int ncost = next.first;
			int nvertex = next.second;

			if (distance[nvertex] > cost + ncost) {
				distance[nvertex] = cost + ncost;
				//거리부호 음수화, 거리가 작은 순으로 꺼내지도록 한다 
				pq.push(make_pair(-distance[nvertex], nvertex));
			}
		}
	}
	return distance;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> E; //노드, 간선 개수 
	cin >> start;//시작 정점 번호 

	for (int i = 0; i < E; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;

		graph[u].push_back(make_pair(cost,v)); //방향그래프
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
