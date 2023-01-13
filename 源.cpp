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
//һά�������±����ά�����±�֮��Ĺ�ϵ��
//��һά�����±�Ϊidx
//��idx/���������У�idx%�е����У�eg idx=8�� ���蹲��������8/3=2�����ǵڶ��У�8%3=2�����ǵڶ��У�����Ĭ�ϵĶ�ά���������±궼��0��ʼ
//ͬ��ɵ�������Ϊ  idx= ��֪������*����+��֪������ ��eg idx=8��8=2*3+2��

