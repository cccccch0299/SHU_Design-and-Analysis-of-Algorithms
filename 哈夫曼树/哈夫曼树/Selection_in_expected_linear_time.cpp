#include<iostream>
//#include<cstdio>
#include<bits/stdc++.h>

using namespace std;

int n, k, len;
//注意都不是引用返回没有改变原数组的值
// 而swap是引用返回，是为了其中排序算法中
void Swap(int& a, int& b);
//快速排序
void quicksort(int a[], int p, int r);
//将x作为基准数将数组分割，返回x的位置
int Partition(int a[], int p, int r, int x);

//找每组的中位数,返回中位数的位置i
int SearchMid(int a[], int p, int r);
//线性划分
int Select(int a[], int p, int r, int k);

int main()
{
    //输入数组长度n
    cin >> n;
    //输入数组
    int* a = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    //输入第k小
    cin >> k;
    //找第k小并返回
    int res = Select(a, 0, n - 1, k);
    cout << res << endl;
    delete[]a;
    return 0;
}

void quicksort(int arr[], int left, int right)
{
    int pivote = arr[left];
    int L, R;
    L = left;//将初始的最左端和最右端的位置序号固定，方便后续的递归
    R = right;
    if (L >= R)
    {
        return;
    }
    while (left < right)
    {
        while (left < right && arr[right] > pivote)//！！注意这里前面的left<right很必要！！
        {
            right--;
        }
        if (arr[right] <= pivote)
        {
            arr[left] = arr[right];
        }
        while (left < right && arr[left] <= pivote)
        {
            left++;
        }
        if (arr[left] > pivote)
        {
            arr[right] = arr[left];
        }
        if (left >= right)
        {
            arr[left] = pivote;
        }
    }
    quicksort(arr, L, right - 1);//递归时分两个部分
    quicksort(arr, left + 1, R);
}

int Partition(int a[], int p, int r, int x)
{
    //i指向首元素的前一个位置，j指向尾元素的后一个位置
    int i = p - 1, j = r + 1;
    while (1)
    {
        //i从基准数右边的元素开始找，直到找到第一个大于等于基准数的元素
        while (a[++i] < x && i < r);
        //j从尾元素开始找，直到找到第一个小于等于基准数的元素
        while (a[--j] > x && j > p);
        //若i>=j，说明基准数的位置已找到，为j
        if (i >= j)
        {
            break;
        }
        //交换两个元素，使得基准数左边的数均不大于它，右边的数均不小于它
        Swap(a[i], a[j]);
    }
    //返回基准数的位置
    return j;
}

void Swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int SearchMid(int a[], int p, int r)
{
    //建立与数组a同等大小的数组b
    int* b = new int[r - p + 1];
    //用数组b存放数组a（注意此时b的首地址为0，而a的首地址为p）
    for (int i = p; i <= r; ++i)
    {
        b[i - p] = a[i];
    }
    //将数组b排序，b[(r-p+1)/2]为中位数
    quicksort(b, 0, r - p);
    for (int i = p; i <= r; ++i)
    {
        if (a[i] == b[(r - p + 1) / 2])
        {
            return i;
        }
    }
    delete[]b;
    return 0;
}

int Select(int a[], int p, int r, int k)
{
    //既可当作是最后一组（不满5个数）的划分（即结束递归），也可看作假如一开始就没5个数直接求
    if (r - p < 5)
    {
        quicksort(a, p, r);
        return a[p + k - 1];
    }
    //分成n/5组，每组5个，找到每组的中位数并将它放到数组首元素的位置
    for (int i = 0; i <= (r - p - 4) / 5; ++i)
    {
        int mid = SearchMid(a, p + 5 * i, p + 5 * i + 4);
        Swap(a[mid], a[p + i]);
    }
    //找到各组中位数的中位数
    int x = Select(a, p, p + (r - p - 4) / 5, (r - p - 4) / 10 + 1);
    //按照中位数划分
    int i = Partition(a, p, r, x);
    //求较小数数组的长度
    len = i - p + 1;
    //若较小数数组的长度小于等于k，说明第k小的元素在这个数组内，将其递归
    if (k <= len)
    {
        return Select(a, p, i, k);
    }
    //否则，说明第k小的元素在较大数数组，将其递归
    else
    {
        return Select(a, i + 1, r, k - len);
    }
}
