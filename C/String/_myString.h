//
// Created by Npc on 2024/4/18.
//

#ifndef C__MYSTRING_H
#define C__MYSTRING_H
/*ʵ���˸��ֶ��ַ����Ĳ���*/
#include "stdio.h"
#include<iostream>
#include<cstring>
using namespace std;
//��ȡ�ַ�������
/*ѭ������'\0'��ֹͣ*/
int _strlen(char str[])
{
    int i=0;
    for(i=0;str[i]!='\0';i++){}
    return i;
}

//��ȡ�ַ�λ��--��ȡĳ�ַ��״��ڸ��ַ������ֵ�λ��
/*C�����п���ʹ��strchr(str,c)��ʾ*/
int _charAt(char str[],char c){
    int i=0;
    for(i=0;str[i]!='\0'&&str[i]!=c;i++){}
    return i;
}

//����Ӵ�  ��ȡ�ַ����ĵ�i-j��
char *_substr(char str[],int i,int j){
    int pos=0;
    char *backup;
    while(i<j){
        backup[pos++] = str[i++];
    }
    backup[pos]='\0';
    return backup;
}

//����Ӵ� ��ȡ��m��
char *_suffix(char str[],int m){
    int len=0;
    for(;str[len]!='\0';len++){}
    //��ȡ�ַ����ܳ���(����ʹ��������װ�������������ʱ����ʹ��strlen���)

    printf("%d\n",len-m);

    int pos=0,i;
    char backup[500];
    for(i=len-m ;i<len ;i++){
        backup[pos++] = str[i];
    }
    backup[pos]='\0';
    return backup;
}

//����Ӵ�����ȡǰm��
char *_prefix(char str[],int m){
    int pos=0,i;
    char *backup;
    for(i=0 ;i<m ;i++){
        backup[pos++] = str[i];
    }
    backup[pos]='\0';
    return backup;
}

//�ַ������Ӳ���
char *_strcat(char dest[],char src[]){
    char * ret = dest;
    while(*dest!='\0'){dest++;}
    //��src���ݸ�����dest֮��
    while(*src){
        *dest++ = *src++;
    }
    //��dest����׷��\0
    *dest = '\0';
    return ret;
}

//�ַ����Ƚϲ���
int _strcmp (char  *  src, char  *  dst)   {
    int  ret  =  0  ;
    while(  !(ret  =  *(unsigned  char  *)src  -  *(unsigned  char  *)dst)  &&  *dst)   //���������������ȫ������õ�ֵ 0��ȡ����Ϊ���
        ++src,  ++dst;
    if  (  ret  <  0  )
        ret  =  -1  ;
    else  if  (  ret  >  0  )
        ret  =  1  ;
    return ret;
}

//�ַ���ƥ��--������
bool isBF(char str1[],char str2[]){
    bool flag=false;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    for(int i=0;i<len1;i++){
        for(int j=0;j<len2;j++){
            int pos=i;
            if( str1[pos++] != str2[j]){
                break;
            }else{
                if(j=len2-1)
                    flag=true;
            }
        }
    }
    return flag;
}
#endif //C__MYSTRING_H
