#include <iostream>
#include <string>
using namespace std;

#define MAX 8+1

//전역변수 
int N, M;//자연수, 길이
int arr[MAX] = { 0, };//수열을 담을 배열 
bool visited[MAX] = { 0, };//수를 방문했다면 true

void dfs(int num) {
	//base case
	if (num == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
		
	}
	//방문하지 않은 수 찾기 
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			arr[num] = i;
			visited[i] = true;//방문
			dfs(num + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> N >> M ;
	dfs(0);
}
