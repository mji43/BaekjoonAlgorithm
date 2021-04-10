#define _CRT_NO_WARNINGS_SECURE
#include <iostream>
#include <algorithm>
#include<cstring>
using namespace std;

char arr[10];
int main(void) {

	cin >> arr;

	sort(arr, arr + strlen(arr), greater<int>()); //내림차순
	for (int i = 0; i < strlen(arr); i++) {
		cout << arr[i];
	}

	return 0;
}

