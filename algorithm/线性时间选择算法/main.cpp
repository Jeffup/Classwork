# include <iostream>
# include <vector>
using namespace std;
int select(vector<int>, long);
int main()
{
	cout << "请输入数组长度：" << endl;
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)

	{
		cout << "输入第" << i << "个元素" << endl;
		cin >> v[i];
	}
	cout << "请输入要找的第几小的元素：";
	long k; cin >> k;
	cout << select(v, k);
	system("pause");
}

int select(vector<int> vec, long k)
// 寻找数组v第k大的数
{
	if (vec.size() == 1)
		return vec[0];
	int r = rand() % vec.size();

	vector<int> vec_left, vec_right;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] <= vec[r])
			vec_left.push_back(vec[i]);
		else
			vec_right.push_back(vec[i]);
	}
	if (vec_left.size() > k)
		return select(vec_left, k);
	else if (vec_left.size() == k)
		return vec[r];
	else
		return select(vec_right, k - vec_left.size());
}
