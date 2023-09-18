#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int n = 9;
int a[n];
//给定数组a[0:n-1]。设计一个算法在最坏情况下用3n/2-2次比较找出a[0:n-1]中的元素最大最小值
//最坏2(n-1)次
//最好n-1次
//平均(3n-3)/2
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

//给定数组a[0:n - 1]。设计一个算法在最坏情况下用n + logn - 2次比较找出a[0:n - 1]中的元素最大值和次大值
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