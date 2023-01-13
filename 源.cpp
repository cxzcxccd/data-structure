#include<iostream>
#include<queue>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
string res = "123804765";

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
string s;

int bfs(string s)
{
	queue<string> q;
	unordered_map<string, int> hash;

	q.push(s);
	while (!q.empty())
	{
		auto hh = q.front();
		q.pop();
		if (hh == res) return hash[hh];
	  int k=hh.find('0');
	  int i =k / 3, j =k % 3;
	  for (int ww = 0; ww < 4;ww++)
	  {
		  int x = i + dx[ww];
		  int y = j + dy[ww];
		  if (x < 0 || x >= 3 || y < 0 || y >= 3) continue;
		  int dir = hash[hh];
		  swap( hh[k], hh[x * 3 + y]);
		  if (!hash.count(hh))
		  {
			  q.push(hh);
			  hash[hh] = dir + 1;
		  }
		  swap(hh[k], hh[x * 3 + y]);
	  }
	}
}
int main()
{
	string s;
	cin >> s;
 cout << bfs(s);
	return 0;
}
//一维度数组下标与二维数组下标之间的关系：
//设一维数组下标为idx
//则idx/列数等于行，idx%列等于列，eg idx=8， 假设共有三列则，8/3=2，就是第二行，8%3=2，就是第二列，这里默认的二维数组行列下标都从0开始
//同理可得逆运算为  idx= 已知点行数*列数+已知点列数 ，eg idx=8，8=2*3+2；

