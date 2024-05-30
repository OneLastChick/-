//
// Created by Npc on 2024/5/28.
//
#include "stdio.h"
#include "stdlib.h"
//˳�����
//��ıȽϴ���Ϊn+1
//ʱ�临�Ӷ�O(n),ASL=(n+1)/2
int sequenceSearch(int a[],int value,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==value)
        {
            return i;
        }
    }
    return -1;
}

//���ֲ���1
//��ıȽϴ���Ϊlog2(n+1)
//ʱ�临�Ӷ�O(log2n),
int binarySearch1(int a[],int value,int n)//n��˳���Ԫ�صĸ���
{
    //a[]���Ѿ����������
    int low,high,mid;
    low=0;
    high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==value)
        {
            return mid;
        }
        if(a[mid]>value)
        {
            high=mid-1;
        }
        if(a[mid]<value)
        {
            low=mid+1;
        }
    }
    return -1;
}

//���ֲ��ҵĵݹ�汾
int binarySearch2(int a[],int value,int low,int high)
{
    int mid=low+(high-low)/2;
    if(a[mid]==value)
        return mid;
    if(a[mid]>value)
        return binarySearch2(a,value,low,mid-1);
    if(a[mid]<value)
        return binarySearch2(a,value,mid+1,high);
}

//��ֵ���ң����ڶ��ֲ��ң������ҵ��ѡ��ĳ�����Ӧѡ��
/*�����ҵĵ�Ľ�Ϊ���£�
mid=low+(key-a[low])/(a[high]-a[low])*(high-low)��*/
int insertionSearch(int a[],int value,int low,int high)
{
    int mid=low+(value-a[low])/(a[high]-a[low])*(high-low);
    if(a[mid]==value)
        return mid;
    if(a[mid]>value)
        return insertionSearch(a,value,low,mid-1);
    if(a[mid]<value)
        return insertionSearch(a,value,mid+1,high);
}
/*ע�����ڱ��ϴ󣬶��ؼ��ֲַ��ֱȽϾ��ȵĲ��ұ���˵����ֵ�����㷨��ƽ�����ܱ��۰����Ҫ�õĶࡣ
 * ��֮������������ֲ��ǳ������ȣ���ô��ֵ����δ���Ǻܺ��ʵ�ѡ��*/

//쳲���������
#define Max_SIZE 20
#define MAX 100
//--------����쳲���������
void Fibonacci(int *F)
{
    F[0]=0;
    F[1]=1;
    for(int i=2;i<Max_SIZE;++i)
    {
        F[i]=F[i-1]+F[i-2];
    }
}
//---------쳲����������㷨
int fibonacciSearch(int *a,int n,int key)
{
    int F[Max_SIZE];
    Fibonacci(F);
    int u=0;
    while(n>F[u])  //����nλ��쳲��������е�λ��
    {
        u++;
    }

    for(int i=n-1;i<F[u]-1;++i) //���������һ��Ԫ�ز�ȫ쳲�����
    {
        a[i+1]=a[i];
    }

    int low=0;
    int high=n-1;

    while(low<=high)
    {
        int mid=low+F[u-1]-1;  //mid�����м�ֵ���ǻƽ�ָ��
        //������չ���
        if(mid>n&&a[n]==key)//��mid>n��˵������չ����ֵ������n
        {
            return n;
        }
        else if(mid>n)
        {
            return -2; //���ҵ����ݲ�����
        }

        //���۰����
        if(key==a[mid])
        {
            return mid;
        }//�ҵ���
        else if(key>a[mid])
        {
            low=mid+1;
            u-=2;
        }
        else if(key<a[mid])
        {
            high=mid-1;
            u-=1;
        }
    }
    return -2;
}

// ��������
int sequenceSearch(int a[], int value, int n);
int binarySearch1(int a[], int value, int n);
int binarySearch2(int a[], int value, int low, int high);
int insertionSearch(int a[], int value, int low, int high);
void Fibonacci(int *F);
int fibonacciSearch(int *a, int n, int key);

int main() {
    int a[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
    int n = sizeof(a) / sizeof(a[0]);
    int value = 7;

    // ˳����Ҳ���
    int seqIndex = sequenceSearch(a, value, n);
    printf("˳�����: ����ֵ %d ������Ϊ %d\n", value, seqIndex);

    // ���ֲ��Ҳ���
    int binIndex1 = binarySearch1(a, value, n);
    printf("���ֲ���: ����ֵ %d ������Ϊ %d\n", value, binIndex1);

    int binIndex2 = binarySearch2(a, value, 0, n-1);
    printf("���ֲ��ң��ݹ�棩: ����ֵ %d ������Ϊ %d\n", value, binIndex2);

    // ��ֵ���Ҳ���
    int insIndex = insertionSearch(a, value, 0, n-1);
    printf("��ֵ����: ����ֵ %d ������Ϊ %d\n", value, insIndex);

    // 쳲��������Ҳ���
    int fibIndex = fibonacciSearch(a, n, value);
    printf("쳲���������: ����ֵ %d ������Ϊ %d\n", value, fibIndex);

    system("pause");

    return 0;
}