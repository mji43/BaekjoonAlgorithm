//����9372 ������� ����
//MST - ��� ����(����)�� ���� ���� ���� ����(����� ����)���� ����
//������ �� = ������ �� -1

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, n, m; //���̽�, ����, ����� ���� �� 

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T ; //���̽� ��

	while (T--) {
		cin >> n >> m;//���(����), ����(�����) �� 

	
		for (int i = 0; i < m; i++) { //���� �� ��ŭ ��� ���� 
			int node1, node2;
			cin >> node1 >> node2;
		}
		cout << n - 1 << '\n';//�ּ� ���� �� = ��� -1
	}

	return 0;


}