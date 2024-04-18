//
// Created by Npc on 2024/4/18.
//
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int *buildNext(char *P){
    int m = strlen(P) , j=0;
    int * N = new int[m];
    int t = N[0] = -1;
    while( j < m-1 ){
        if( 0 > t || P[j] == P[t] ){
            N[++j] = ++t;
        }
        else{
            t = N[t];
        }
    }
    return N;
}

int KMP(char T[],char P[]){ //T--����,P--ģʽ��
    int *next = buildNext(P);   //����NEXT��
    int n = strlen(T) , i=0;
    int m = strlen(P) , j=0;
    while( j<m && i<n ){
        if( j<0 || T[i]==P[j] ){
            i++;
            j++;
        }else{
            j = next[j];
        }

    }
    delete []next;
    return i-j;
}

int main(){

    char org[] = "ABABABABABD";
    char str[] = "ABABD";
    int ans = KMP(org,str);
    cout << ans <<endl;
    system("pause");
    return 0;
}