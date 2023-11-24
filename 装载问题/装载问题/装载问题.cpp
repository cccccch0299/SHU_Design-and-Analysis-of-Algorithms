#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
int w[21];
int c1, c2;
string assign, best;//当前分配方案 和 最佳分配方案
int cargo1max;//第一艘船最大装载量
int r;//剩余重量
void dfs(int count,int cargos1)//cargos1第一艘船装在重量
{
	if (count == n + 1)
	{
		if (cargos1 > cargo1max)
		{
			cargo1max = cargos1;
			//cout << cargo1max << endl;
			best = assign;
		}
		if (cargos1 == cargo1max && assign > best)//选择字典序大的
		{
			best = assign;
		}
		return ;
	}
	r -= w[count];
	if (w[count] + cargos1 <= c1)
	{
		assign[count] = '1';
		dfs(count + 1, w[count] + cargos1);
		assign[count] = '0';//回溯
	}
	if (cargos1 + r > cargo1max)
	{
		dfs(count + 1, cargos1);//不选第count件货物
		r += w[count];
	}
}

int main()
{
	int cas = 1;
	while (cin >> n)
	{
		assign.resize(n + 1, '0');
		best.resize(n + 1, '0');
		int sum = 0;
		cargo1max = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> w[i];
			sum += w[i];
		}
		r = sum;
		cin >> c1 >> c2;
		cout << "Case " << cas << endl;
		cas++;
		dfs(1, 0);
		if (cargo1max + c2 < sum)
		{
			cout << cargo1max << " " << c2<<endl;
			cout << "No" << endl;
		}
		else
		{
			cout << cargo1max << " " << best.substr(1,n) << endl;
		}
	}
}