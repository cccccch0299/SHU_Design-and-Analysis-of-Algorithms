#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N = 101;
int n;
int m[N][N], pos[N][N],p[N];//m���i,j֮����С�ĳ˵Ĵ�����pos��¼�ϵ�λ��

void chain(int l, int r)
{
	for (int i = 0; i < r; i++)
	{
		m[i][i] = 0;//i��i֮��0�γ˷�
	}
	for (int iv = 2; iv <= r; iv++)//iv��ʾ��� �����С���� ��С�����㵽������
	{
		for (int i = 1; i <= r - iv +1; i++)
		{
			int j = i + iv - 1;
			m[i][j] = m[i + 1][j] + p[i-1]*p[i]*p[j];//��ʼ�� ֱ�Ӵ�����һ���ָ�
			pos[i][j] = i;
			for (int k = i + 1; k < j; k++)
			{
				int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t < m[i][j])
				{
					m[i][j] = t;
					pos[i][j] = k;
					//cout << t << endl;
				}
			}
		}
	}
}

void display(int l,int r)
{
	if (l == r)
	{
		cout << "A" << l;
		return;
	}
	if (l != 1 || r != n)
		cout << "(";
	display(l, pos[l][r]);
	display(pos[l][r] + 1, r);
	if (l != 1 || r != n)
		cout << ")";
}
int main()
{
	//int n;
	int case_num = 0;
	while (cin >> n)
	{
		memset(m, 0, sizeof(m));
		case_num++;
		for (int i = 0; i <= n; i++)
			cin >> p[i];
		chain(1, n);
		cout << "Case " << case_num << endl;
		cout << m[1][n] << ' ';
		display(1, n);
		cout << endl;

	}
}
