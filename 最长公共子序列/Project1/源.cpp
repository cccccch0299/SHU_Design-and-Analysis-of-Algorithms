#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[51][51];
int path[51][51];//0是斜上，2是左，1是上
set<string> a;
void display(int m,int n,char* s1,char*s2,string ans)
{
	//cout << ans << endl;
	if (m < 1 || n < 1)
	{
		reverse(ans.begin(), ans.end());
		a.emplace(ans);
		//错误点cout << ans << endl;
		return;
	}
	if (s1[m] == s2[n])
	{
		//ans += s1[m];
		display(m - 1, n - 1, s1, s2, ans + s1[m]+' ');
	}
	else
	{
		if (dp[m - 1][n] >= dp[m][n - 1])display(m - 1, n, s1, s2,ans);
		if (dp[m - 1][n] <= dp[m][n - 1])display(m , n - 1, s1, s2,ans);
		
	}
}

int main()
{
	int T;
	cin >> T;
	for(int count = 1;count <=T;count++)
	{
		int m, n;
		char s1[50], s2[50];
		memset(dp, 0, sizeof(dp));//初始化dp数组
		memset(path, 0, sizeof(path));
		cin >> m >> n;
		for (int i = 1; i <= m; i++)
		{
			cin >> s1[i];
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> s2[i];
		}
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (s1[i] == s2[j])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
					path[i][j] = 0;
				}
				else if (dp[i - 1][j] >= dp[i][j - 1])
				{
					dp[i][j] = dp[i - 1][j];
					path[i][j] = 1;

				}
				else if (dp[i - 1][j] < dp[i][j - 1])
				{
					dp[i][j] = dp[i ][j - 1];
					path[i][j] = 2;
				}
					//dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		cout << "Case " << count << endl;
		cout << "最长公共子序列的长度为：";
		cout << dp[m][n] << endl << " LCS(X,Y): " << endl;
		string ans;
		display(m, n, s1, s2,ans);
		for (set<string>::iterator it = a.begin(); it != a.end(); it++)
		{
			cout << *it << endl;
		}
		a.clear();
		cout << endl ;
		cout << "c表（长度表）" << endl;
		for (int i = 0; i <= m; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				cout << dp[i][j] << ' ';
			}
			cout << endl;
		}
		cout << "b表(回溯表)" << endl;
		for (int i = 0; i <= m; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				cout << path[i][j] << ' ';
			}
			cout << endl;
		}
	}
}