#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int x[8] = { 1,1,2,2,-1,-1,-2,-2 };
int y[8] = { 2,-2,1,-1,2,-2,1,-1 };
//右1上2 右1下2 右2上1 右二下1 左1 上2 左1下2 左2上1 左1下2 
int dist[9][9];
bool state[9][9];
int bfs(int sx,int sy,int ex,int ey )
{
	queue<pair<int, int>> p;
	dist[sx][sy] = 0;
	state[sx][sy] = 1;
	p.push({ sx,sy });
	while (!p.empty())
	{
		int x2 = p.front().first;
		int y2 = p.front().second;
		p.pop();
		for (int i = 0; i < 8; i++)
		{
			int tx = x2 + x[i];
			int ty = y2 + y[i];
			//如果越界或者被访问过则跳过
			if (tx < 1 || ty < 1 || tx >8 || ty>8 || state[tx][ty])
			{
				continue;
			}
			state[tx][ty] = true;
			p.push({ tx,ty });
			dist[tx][ty] = dist[x2][y2] + 1;
		}
	}
	return dist[ex][ey];
}
int minstep = inf;
void dfs(int sx, int sy, int ex, int ey,int step)
{
	if (sx == ex && sy == ey)
	{
		if (step < minstep)
		{
			minstep = step;
			//cout << minstep << endl;
			return;
		}
		return;
	}
	for (int i = 0; i < 8; i++)
	{
		int tx = sx + x[i];
		int ty = sy + y[i];
		//如果越界或者被访问过则跳过
		if (tx < 1 || ty < 1 || tx >8 || ty>8 || state[tx][ty])
			continue;
		if (step < minstep)
		{
			state[tx][ty] = true;
			dfs(tx, ty, ex, ey, step + 1);
			state[tx][ty] = false;
		}
	}
	return ;
}
int main()
{
	string st, ed;
	while (cin >> st)
	{
		minstep = inf;
		memset(dist, -1, sizeof(dist));
		memset(state, 0, sizeof(state));
		cin >> ed;
		int sx, sy, ex, ey;
		sx = st[1] - '0';
		sy = st[0] - 'a' + 1;
		ex = ed[1] - '0';
		ey = ed[0] - 'a' + 1;
		state[sx][sy] = 1;//设置原点走过
		//int b_ans = bfs(sx, sy, ex, ey);
		dfs(sx, sy, ex, ey, 0);
		int d_ans = minstep;
		cout << st << " ==> " << ed << ": " << d_ans << " moves" << endl;
	}
}