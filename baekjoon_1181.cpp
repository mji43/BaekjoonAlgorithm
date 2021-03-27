#include<iostream>
#include<algorithm>
#include <vector>
#include<string>

using namespace std;

bool cmp(string a, string b)
{
	if (a.size() == b.size())
		return a < b;
	else
		return a.size() < b.size();
}

int main()
{


	int n;
	cin >> n;
	vector<string> vec(n);
	for (int i = 0; i < n; i++)
	{

		cin >> vec[i];
	}

	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < n; i++)
	{
		if (i != 0 && vec[i] == vec[i - 1]) continue;
		cout << vec[i] << '\n';
	}

	return 0;

}