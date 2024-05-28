//
// Created by Npc on 2024/5/28.
//
#include "stdio.h"
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
    return -1
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