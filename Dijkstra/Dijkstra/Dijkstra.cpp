#include<iostream>
#include<bits/stdc++.h>
const int INF = 0x3f3f3f3f;
using namespace std;
int e[51][51];//图
int point[51];//0违背更新 1被更新
int dist[51];//路径花费
int n;
int path[51];
stack<int> q;
void dijkstra(int s, int t)
{
	dist[s] = 0;
	int temps = s;
	for (int i = 1; i <= n; i++)//将所有点都遍历一遍，但是i的值不会起任何用处
	{
		int  u = INF, temp;
		for (int j = 1; j <= n; j++)
		{
			if (point[j] == 0 && dist[j] < u)//最开始是自己
			{
				u = dist[j];
				temp = j;
			}
		}
		/*path[temps] = temp;
		temps = temp;*/
		point[temp] = 1;
		for (int v = 1; v <= n; v++)
		{
			if (e[temp][v] > 0)
			{
				if (u + e[temp][v] < dist[v])//绕路
				{
					dist[v] = u + e[temp][v];
					path[v] = temp;
				}
			}
		}
	}
	cout << "The least distance from " << s << " -> " << t << " is " << dist[t] << endl;
	cout << "the path is " << s;
	//q.push(t);
	while (path[t] != -1)
	{
		q.push(t);
		t = path[t];
	}
	while (!q.empty())
	{
		cout << "->" << q.top();
		q.pop();
	}
	cout << endl;
}

int main()
{

	int temp = 1;
	while (cin >> n)
	{
		memset(e, INF, sizeof(e));
		memset(point, 0, sizeof(point));
		memset(dist, INF, sizeof(dist));
		memset(path, -1, sizeof(path));
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> e[i][j];
			}
		}
		int s, t;
		cin >> s >> t;
		cout << "Case " << temp << endl;
		dijkstra(s, t);
		temp++;
	}
}