#include <iostream>
#include <string>
using namespace std;

#define MAX 8+1

//�������� 
int N, M;//�ڿ���, ����
int arr[MAX] = { 0, };//������ ���� �迭 
bool visited[MAX] = { 0, };//���� �湮�ߴٸ� true

void dfs(int num) {
	//base case
	if (num == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
		
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			arr[num] = i;
			visited[i] = true;
			dfs(num + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> N >> M ;
	dfs(0);
}