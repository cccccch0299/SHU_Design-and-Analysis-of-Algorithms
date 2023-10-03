#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node {
public:
	int parent, lc, rc, weight, idx;
	string code;

	bool operator<(const node& p) const {
		if (this->weight < p.weight)
			return true;
		else if (this->weight == p.weight)
		{
			if (this->idx > p.idx)
				return true;
			else return false;
		}
		else return false;
	}
}huffmantree[100];

void createhuffmancode(node* a, int num);
void test(node* a, int num);
multiset<node> s;

void creathuffmantree(int n)
{
	int temp = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> huffmantree[i].weight;
		huffmantree[i].idx = i;
		huffmantree[i].parent = 0;
		s.insert(huffmantree[i]);
		temp++;
	}
	while (s.size() != 1)
	{
		auto it = s.begin();
		huffmantree[temp].weight = (*it).weight;
		huffmantree[temp].rc = (*it).idx;
		huffmantree[(*it).idx].parent = temp;
		it++;
		huffmantree[temp].weight += (*it).weight;
		huffmantree[temp].lc = (*it).idx;
		huffmantree[(*it).idx].parent = temp;
		huffmantree[temp].idx = temp;
		huffmantree[temp].parent = 0;
		s.erase(s.begin());
		s.erase(s.begin());
		s.insert(huffmantree[temp]);
		temp++;
	}
	createhuffmancode(huffmantree, n);
}
void test(node* a, int num)
{
	for (int i = 1; i <= num * 2 - 1; i++)
	{
		cout<< a[i].idx <<' ' << a[i].weight << ' ' << a[i].lc << ' ' << a[i].rc << ' ' << a[i].parent << endl;
	}
}

void createhuffmancode(node* a, int num)
{
	for (int i = 1; i <= num; i++)
	{
		int temp = i;//孩子的位置也要更新
		string code;
		code.clear();
		int f = a[i].parent;
		while (f != 0)
		{
			if (a[f].lc == temp)
			{
				code += '0';
			}
			else if (a[f].rc == temp)
			{
				code += '1';
			}
			temp = f;
			f = a[f].parent;
		}
		reverse(code.begin(), code.end());
		a[i].code = code;
	}
}
int main()
{
	int t;
	cin >> t;
	for(int i = 1;i <=t;i++)
	{
		s.clear();
		int n;
		cin >> n;
		creathuffmantree( n);
		cout << "case " << i << endl;
		for (int i = 1; i <= n; i++)
		{
			cout << huffmantree[i].weight << ' ' << huffmantree[i].code << endl;
		}
		cout << endl;
	}
}
