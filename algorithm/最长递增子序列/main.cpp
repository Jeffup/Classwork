# include <iostream>
# include <vector>
using namespace std;
int select(vector<int>, long);
int maxlen(vector<int> vec);
int main()
{
	cout << "���������鳤�ȣ�" << endl;
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)

	{
		cout << "�����" << i << "��Ԫ��" << endl;
		cin >> v[i];
	}
	cout << "�����������" << maxlen(v) << endl;;
	system("pause");
}
int maxlen(vector<int> vec)
{
	int maxlen = 1;
	vector<int> tempmax(vec.size());
	tempmax[0] = 1;
	int maxindex = 1;
	for (int i = 1; i < vec.size(); i++)
	{
		if (vec[i - 1] < vec[i])
		{
			tempmax[i] = tempmax[i - 1] + 1;
			maxlen = tempmax[i] > maxlen ? tempmax[i] : maxlen;
			maxindex = tempmax[i] > maxlen ? i : maxlen;
		}
		else {
			tempmax[i] = 1;
		}
	}
	return maxlen;
}
