#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int n = 9;
int a[n];
//��������a[0:n-1]�����һ���㷨����������3n/2-2�αȽ��ҳ�a[0:n-1]�е�Ԫ�������Сֵ
//�2(n-1)��
//���n-1��
//ƽ��(3n-3)/2
void max_min()
{
	int max, min;
	max = min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)max = a[i];
		else if (a[i] < min)min = a[i];
	}
	cout << max << " " << min<<endl;
}

//��������a[0:n - 1]�����һ���㷨����������n + logn - 2�αȽ��ҳ�a[0:n - 1]�е�Ԫ�����ֵ�ʹδ�ֵ
void max_cmax(int i,int j,int &max2,int &cmax)
{
	int lmax, lcmax, rmax, rcmax;
	if (i == j)
	{
		max2 = a[i];
		cmax = a[i];
	}
	else if (i == j - 1)
	{
		if (a[i] < a[j])
		{
			max2 = a[j];
			cmax = a[i];
		}
		else
		{
			max2 = a[i];
			cmax = a[j];
		}
	}
	else
	{
		int mid = (i + j) / 2;
		max_cmax(i, mid, lmax, lcmax);
		max_cmax(mid + 1, j, rmax, rcmax);
		if (lmax > rmax)
		{
			if(lcmax>rmax)
			{
				max2 = lmax;
				cmax = lcmax;
			}
			else
			{
				max2 = lmax;
				cmax = rmax;
			}
		}
		else
		{
			if (rcmax > lmax)
			{
				max2 = rmax;
				cmax = rcmax;
			}
			else
			{
				max2 = rmax;
				cmax = lmax;
			}
		}
	}
}

int main()
{

}