#include<iostream>
#include<bits/stdc++.h>
//#include"Selection_in_expected_linear_time.cpp"
using namespace std;
int mintemp, cmintemp;
const int INF = 0x3f3f3f3f;
class huffmantree
{
	public:
		int parent, lc, rc, weight;
		string code;
};

int search_first_element(huffmantree* a)//寻找第一个不是叶节点的元素位置
{
	int i = 1;
	while (a[i].parent != 0)i++;
	return i;
}

void min_cmin(huffmantree* a, int end,int &s1, int &s2,int first_element)
{
	int mintemp = INF - 1;
	int cmintemp = INF;
	s1 = first_element;
	s2 = first_element;
	for (int i = first_element ; i <= end; i++)
	{
		if (a[i].parent == 0)
		{
			if (a[i].weight < mintemp)
			{
				mintemp = a[i].weight;
				s2 = s1;
				s1 = i;
				
			}
			else if (a[i].weight < cmintemp)
			{
				cmintemp = a[i].weight;
				s2 = i;
			}
		}
	}
}
void tree_building(huffmantree* tree,int n)
{
	for (int i = 1; i <= n; i++)
	{
		cin >> tree[i].weight;
		tree[i].lc = 0;
		tree[i].rc = 0;
		tree[i].parent = 0;
	}
	for (int i = n + 1; i <= 2 * n-1; i++)
	{
		//表格的最后一项就是根节点
		int min1, min2;
		int first_element = search_first_element(tree);//第一个非叶节点的位置
		min_cmin(tree, i - 1, min1, min2, first_element);
		tree[min1].parent = i;
		tree[min2].parent = i;
		tree[i].lc = min1;
		tree[i].rc = min2;
		tree[i].parent = 0;
		tree[i].weight = tree[min1].weight + tree[min2].weight;
	}

}

void createhuffmancode(huffmantree *a,int num)
{
	//vector<string> huffmancode;
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

void test(huffmantree* a, int num)
{
	for (int i = 1; i <= num * 2-1; i++)
	{
		cout << a[i].weight << ' ' << a[i].lc << ' ' << a[i].rc<<' ' << a[i].parent << endl;
	}
}

int main()
{
	int t;
	cin >> t;
	for(int r = 1; r <=t;r++)
	{
		int n;
		cin >> n;
		huffmantree* tree = new huffmantree[2 * n];//n个数对应哈夫曼树2n-1个节点，从1开始编码故2n
		tree_building(tree,n);
		test(tree,n);
		createhuffmancode(tree, n);
		cout << "case " << r << endl;
		for (int i = 1; i <= n; i++)
		{
			cout << tree[i].weight << ' ' << tree[i].code << endl;
		}
	}
}