//
// Created by Npc on 2024/4/21.
//
/*Target:
 * 1.����һ��opcode
 * 2.ʵ��opcode�Ľ�����*/
#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"

#define OPCODE_N 7  //����opcode�ĳ���
#define F_LEN 12

char *vm_stack; //�������ջ
char enc_flag[] = {0x23, 0x76, 0x61, 0x2a, 0x7b, 0x22, 0x38, 0x63, 0x53, 0x22, 0x3f,0x22};
//flag=1ds8i0*qA0-0
//Ҫ����Ҫʵ�ֹ��ܵ�α����ת���Զ����opcode
unsigned char vm_code[] = {
	0xf5,
    0xf1,0xe1,0x0,0x00,0x00,0x00,0xf2,0xf1,0xe4,0x20,0x00,0x00,0x00,
    0xf1,0xe1,0x1,0x00,0x00,0x00,0xf2,0xf1,0xe4,0x21,0x00,0x00,0x00,
    0xf1,0xe1,0x2,0x00,0x00,0x00,0xf2,0xf1,0xe4,0x22,0x00,0x00,0x00,
    0xf1,0xe1,0x3,0x00,0x00,0x00,0xf2,0xf1,0xe4,0x23,0x00,0x00,0x00,
    0xf1,0xe1,0x4,0x00,0x00,0x00,0xf2,0xf1,0xe4,0x24,0x00,0x00,0x00,
    0xf1,0xe1,0x5,0x00,0x00,0x00,0xf2,0xf1,0xe4,0x25,0x00,0x00,0x00,
    0xf1,0xe1,0x6,0x00,0x00,0x00,0xf2,0xf1,0xe4,0x26,0x00,0x00,0x00,
    0xf1,0xe1,0x7,0x00,0x00,0x00,0xf2,0xf1,0xe4,0x27,0x00,0x00,0x00,
    0xf1,0xe1,0x8,0x00,0x00,0x00,0xf2,0xf1,0xe4,0x28,0x00,0x00,0x00,
    0xf1,0xe1,0x9,0x00,0x00,0x00,0xf2,0xf1,0xe4,0x29,0x00,0x00,0x00,
    0xf1,0xe1,0xa,0x00,0x00,0x00,0xf2,0xf1,0xe4,0x2a,0x00,0x00,0x00,
    0xf1,0xe1,0xb,0x00,0x00,0x00,0xf2,0xf1,0xe4,0x2b,0x00,0x00,0x00,
    0xf1,0xe1,0xc,0x00,0x00,0x00,0xf2,0xf1,0xe4,0x2c,0x00,0x00,0x00,
    0xf4
};
enum opcodes{
    MOV=0xf1,
    XOR=0xf2,
    RET=0xf4,
    READ=0xf5,
};

enum regist{
    R1=0xe1,
    R2=0xe2,
    R3=0xe3,
};
//vm_opcode����
typedef struct
{
    unsigned char opcode;
    void (*handle)(void *);
    /*������һ������ָ�� handle����ָ��ָ��һ��������
     * �ú�������һ�� void* ���͵Ĳ��������Ҳ������κ�ֵ��*/
}vm_opcode;

//vm_cpu�ṹ��
/*����R1-3�Ƕ����ͨ�üĴ������������λ��ߴ�ŷ���ֵ,eipָ�����ڽ��͵�opcode��ַ*/
typedef struct vm_cpus
{
   int r1; //����Ĵ���R1
   int r2; //����Ĵ���R2
   int r3; //����Ĵ���R3
   unsigned char *eip; //ָ�����ڽ��͵�opcode��ַ

   vm_opcode op_list[OPCODE_N];//opcode�б�������е�opcode�Լ���Ӧ�Ĵ�����
}vm_cpu;



void mov_(vm_cpu *cpu);      //change flag position
void xor_(vm_cpu *cpu);      //xor flag , 0x1-0x9
void read_(vm_cpu *cpu);    //call read ,read the flag
void vm_init(vm_cpu *cpu);
void vm_start(vm_cpu *cpu);
void vm_dispatcher(vm_cpu *cpu);
void check();
//handles����ʵ��
void mov_(vm_cpu *cpu)
{
    /*//movָ��Ĳ������������ֽ����У�ָ���ʾ���һ���ֽ��ǼĴ�����ʶ��
     * �ڶ���������Ҫmov��������vm_stack�ϵ�ƫ��
    //������ֻ��ʵ���˴�vm_stack��ȡ���ݺʹ����ݵ�vm_stack��*/
    unsigned char *res=cpu->eip+1; //�Ĵ�����ʶ,��ָ��ĵ�һ���ֽ�
    int *offset=(int *)(cpu->eip+2); //������vm_stack�ϵ�ƫ��,��ָ��ĵڶ�����5�ֽ�
    char *dest=0;
    dest=vm_stack;

    switch (*res) {
        case 0xe1:
            cpu->r1=*(dest+*offset);// ��vm_stack��ȡ���ݣ��洢��cpu�ṹ���r1�Ĵ�����
            break;
        case 0xe2:
            cpu->r2=*(dest+*offset);// ��vm_stack��ȡ���ݣ��洢��cpu�ṹ���r2�Ĵ�����
            break;
        case 0xe3:
            cpu->r3=*(dest+*offset);  // ��vm_stack��ȡ���ݣ��洢��cpu�ṹ���r3�Ĵ�����
            break;
        case 0xe4:
        {
            int x=cpu->r1; // ��cpu�ṹ���r1�Ĵ�����ȡ����
            *(dest+*offset)=x; // �����ݴ洢��vm_stack��ָ��ƫ��λ����
            break;
        }
    }


    cpu->eip+=6; //movָ��ռ6���ֽڣ�eip���ƫ��6λ
}

void xor_(vm_cpu *cpu)
{
    int temp;
    temp=cpu->r1^cpu->r2;
    temp ^=0x12;
    cpu->r1=temp;
    cpu->eip+=1;  //xorָ��ռһ���ֽ�
}

void read_(vm_cpu *cpu)
{
    char *dest=vm_stack;
    read(0,dest,12); //����������ջ�ж�������
    cpu->eip+=1;
}



//vm_init����
void vm_init(vm_cpu *cpu)
{
    cpu->r1=0;
    cpu->r2=0;
    cpu->r3=0;
    cpu->eip=(unsigned char *)vm_code; //��eipָ��opcode�ĵ�ַ

    cpu->op_list[0].opcode=0xf1;
    cpu->op_list[0].handle=(void (*)(void *))mov_;
   /*   mov������һ������������ʾ�����ĵ�ַ��
        (*)�����ʾһ��ָ�룬ָ��һ��������
        (void *)����� ʾ��������һ�� void* ���͵Ĳ�����
         void�����ʾ�����������κ�ֵ��*/
   //�����Ϳ��Խ�0xF1�Ĳ��������Ӧ��handle����������һ����

   //����ͬ��
   cpu->op_list[1].opcode=0xf2;
   cpu->op_list[1].handle=(void (*)(void *))xor_;

   cpu->op_list[2].opcode=0xf5;
   cpu->op_list[2].handle=(void (*)(void *))read_;

   vm_stack=(char *)malloc(0x512);
   memset(vm_stack,0,0x512);
}

//�ַ���
void vm_dispatcher(vm_cpu *cpu)
{
    int i;
    for(i=0;i<OPCODE_N;i++)
    {
        if(*cpu->eip==cpu->op_list[i].opcode)
        {
            cpu->op_list[i].handle(cpu);
            break;
        }
    }
}

void vm_start(vm_cpu *cpu)
{
    cpu->eip=(unsigned char*)vm_code;
    while((*cpu->eip)!=RET)
    {
        vm_dispatcher(cpu);  //ִ�ж�Ӧ����
    }
}



void check()
{
    int i;
    char *target=vm_stack;
    for(i=0;i<F_LEN;i++)
    {
        int offset=i+0x20;
        if((char)target[offset]!=enc_flag[i])
        {
            puts("error");
        }
        else{
            continue;
        }
    }
     puts("right");
}
