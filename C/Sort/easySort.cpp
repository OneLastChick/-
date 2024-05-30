#include "iostream"
#include "cstdlib"
#include "ctime"

//������򵥵����򷽷�
using namespace std;

//�����ʼ������
void setArray(int *data, int size)
{
    cout << "�����ʼ��" << size << "����" << endl;
    for (int i = 0; i < size; i++)
    {
        data[i] = rand() % 100 + 1;
    }
}

//��ӡ����
void Print(int *data, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

//�������������Ԫ��
void Swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

//ð������
void bubbleSort(int *data, int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (data[j + 1] < data[j])
            {
                Swap(data[j + 1], data[j]);
            }
        }
    }
}

//ֱ�Ӳ�������
void insertionSort(int *data, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = data[i]; //��������Ԫ��
        int j = i - 1;
        //��data[i]���뵽�������data[0...i-1]
        while (j >= 0 && data[j] > key)
        {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;
    }
}

//��ѡ������
void choiceSort(int *data,int size)
{
    for(int i=0;i<size-1;i++)
    {
        int min=data[i];
        for(int j=i+1;j<size;j++)
        {
            if(data[j]<min)
            {
                min=data[j];
            }
        }
        Swap(data[i],min);
    }
}
int main()
{
    srand((unsigned)time(NULL)); //�������������

    const int size = 10;
    int data[size];

    // ��ʼ������
    setArray(data, size);

    // ��ӡԭʼ����
    cout << "ԭʼ����: ";
    Print(data, size);

    // ʹ��ð������
    bubbleSort(data, size);
    cout << "ð������������: ";
    Print(data, size);

    // ���³�ʼ������
    setArray(data, size);

    // ��ӡ���³�ʼ���������
    cout << "���³�ʼ���������: ";
    Print(data, size);

    // ʹ�ò�������
    insertionSort(data, size);
    cout << "��������������: ";
    Print(data, size);


    //ʹ��ֱ��ѡ������
    choiceSort(data,size);
    cout<<"ֱ��ѡ������������:";
    Print(data,size);


    system("pause");
    return 0;
}
