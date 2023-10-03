#include<iostream>
//#include<cstdio>
#include<bits/stdc++.h>

using namespace std;

int n, k, len;
//ע�ⶼ�������÷���û�иı�ԭ�����ֵ
// ��swap�����÷��أ���Ϊ�����������㷨��
void Swap(int& a, int& b);
//��������
void quicksort(int a[], int p, int r);
//��x��Ϊ��׼��������ָ����x��λ��
int Partition(int a[], int p, int r, int x);

//��ÿ�����λ��,������λ����λ��i
int SearchMid(int a[], int p, int r);
//���Ի���
int Select(int a[], int p, int r, int k);

int main()
{
    //�������鳤��n
    cin >> n;
    //��������
    int* a = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    //�����kС
    cin >> k;
    //�ҵ�kС������
    int res = Select(a, 0, n - 1, k);
    cout << res << endl;
    delete[]a;
    return 0;
}

void quicksort(int arr[], int left, int right)
{
    int pivote = arr[left];
    int L, R;
    L = left;//����ʼ������˺����Ҷ˵�λ����Ź̶�����������ĵݹ�
    R = right;
    if (L >= R)
    {
        return;
    }
    while (left < right)
    {
        while (left < right && arr[right] > pivote)//����ע������ǰ���left<right�ܱ�Ҫ����
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
    quicksort(arr, L, right - 1);//�ݹ�ʱ����������
    quicksort(arr, left + 1, R);
}

int Partition(int a[], int p, int r, int x)
{
    //iָ����Ԫ�ص�ǰһ��λ�ã�jָ��βԪ�صĺ�һ��λ��
    int i = p - 1, j = r + 1;
    while (1)
    {
        //i�ӻ�׼���ұߵ�Ԫ�ؿ�ʼ�ң�ֱ���ҵ���һ�����ڵ��ڻ�׼����Ԫ��
        while (a[++i] < x && i < r);
        //j��βԪ�ؿ�ʼ�ң�ֱ���ҵ���һ��С�ڵ��ڻ�׼����Ԫ��
        while (a[--j] > x && j > p);
        //��i>=j��˵����׼����λ�����ҵ���Ϊj
        if (i >= j)
        {
            break;
        }
        //��������Ԫ�أ�ʹ�û�׼����ߵ����������������ұߵ�������С����
        Swap(a[i], a[j]);
    }
    //���ػ�׼����λ��
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
    //����������aͬ�ȴ�С������b
    int* b = new int[r - p + 1];
    //������b�������a��ע���ʱb���׵�ַΪ0����a���׵�ַΪp��
    for (int i = p; i <= r; ++i)
    {
        b[i - p] = a[i];
    }
    //������b����b[(r-p+1)/2]Ϊ��λ��
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
    //�ȿɵ��������һ�飨����5�������Ļ��֣��������ݹ飩��Ҳ�ɿ�������һ��ʼ��û5����ֱ����
    if (r - p < 5)
    {
        quicksort(a, p, r);
        return a[p + k - 1];
    }
    //�ֳ�n/5�飬ÿ��5�����ҵ�ÿ�����λ���������ŵ�������Ԫ�ص�λ��
    for (int i = 0; i <= (r - p - 4) / 5; ++i)
    {
        int mid = SearchMid(a, p + 5 * i, p + 5 * i + 4);
        Swap(a[mid], a[p + i]);
    }
    //�ҵ�������λ������λ��
    int x = Select(a, p, p + (r - p - 4) / 5, (r - p - 4) / 10 + 1);
    //������λ������
    int i = Partition(a, p, r, x);
    //���С������ĳ���
    len = i - p + 1;
    //����С������ĳ���С�ڵ���k��˵����kС��Ԫ������������ڣ�����ݹ�
    if (k <= len)
    {
        return Select(a, p, i, k);
    }
    //����˵����kС��Ԫ���ڽϴ������飬����ݹ�
    else
    {
        return Select(a, i + 1, r, k - len);
    }
}
