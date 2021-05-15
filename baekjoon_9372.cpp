//백준9372 상근이의 여행
//MST - 모든 정점(국가)을 가장 적은 수의 간선(비행기 종류)으로 연결
//간선의 수 = 정점의 수 -1

#include <iostream>

using namespace std;

int T, n, m; //케이스, 국가, 비행기 종류 수 

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T ; //케이스 수

	while (T--) {
		cin >> n >> m;//노드(국가), 간선(비행기) 수 

	
		for (int i = 0; i < m; i++) { //간선 수 만큼 노드 연결 
			int node1, node2;
			cin >> node1 >> node2;
		}
		cout << n - 1 << '\n';//최소 간선 수 = 노드 -1
	}

	return 0;


}
