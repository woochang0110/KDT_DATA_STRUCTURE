#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//    int sp_of_month[12] = {0,3,3,6,1,4,6,2,5,0,3,5 };//�޺��� ����Ҷ� ������ ������� 1������ �Ͽ��Ϻ��ʹ� 0 �Է� 
//	  �Լ����� int *sp�� �Ű������� �ް�   main���� int sp[12]; ����� ������ sp�� 
// 		i=0�϶� k=0;  

void cal_maker(int cal[12][8][8], int *day, int *sp)
{
    int i, j, k, n;

    //�����ͷ� �Ű����� �޾ƿͼ� ���ٲٰų� �Ұ� ��� ���� ���� �ȸ������

    for (i = 0; i < 12; i++)//��
    {
        n = 1; // �ش� ���� �Էµ� ��¥ �� ���� 
 //       printf("\n i :%d   %d�� ���ƾߵ�\n", i+1, *(day + i));
        for (j = 0; j < 7; j++)//��
        {
            if (j == 0)
            {
                k = *(sp + i);//�� ���� ù ����϶� �Է½��ۿ��� k�� ����
                
            }   
            else 
            { 
                k = 0; //�ƴϸ� �ٽ� �Ͽ���(k=0)���� �Է� 
            }
            for (k; k < 7; k++)//�ش� ���� ���ۿ��Ϻ��� ä������
            {
                if (*(day + i) == n - 1) { break;}//�ش� ���� �ϼ���ŭ ���Ҵٸ� 
                cal[i][j][k] = n;// �޺� �Է� �ϼ� ���� 
 //               printf("j:%d, k:%d, n:%d �Է°�:%d\n", j, k, n, cal[i][j][k]);
                n++;
                
            }
        }

    }

}


void cal_printer(int cal[12][8][8], int* day, int* sp)
{
    int i, j, k, l, n;

    for (i = 0; i < 12; i++)//��
    {
        n = 1;
        printf("\n%10s%d���޷�%10s\n", "",i+1,"");
        printf("%4s%4s%4s%4s%4s%4s%4s\n","��","��","ȭ","��","��","��","��");
        for (j = 0; j < 7; j++)//��
        {
            
            if (j == 0)   //�� ���� ù ����϶� 
            {
                k = *(sp + i);//k���ٰ� ��½��ۿ��� ����
                for (l = 0; l < k; l++)   //ù��� ���ϱ��� sp 
                {
                    printf("    ");//�� ���ϴ� 4ĭ��
                }

            }
            else// �� ���� ù ����� �ƴϸ�
            {
                k = 0;// �ٽ� �Ͽ���(k=0)���� ��� 
            }      

            for (k; k < 7; k++)//��
            {
                if (*(day + i) == n - 1)//�ش� ���� �ϼ���ŭ ���Ҵٸ� Ż��
                {
                    break;
                }
                printf("%4d", cal[i][j][k]);
                n++;   //������Ҵ��� ī��Ʈ 
            }
            printf("\n");         //�������� new line 
        }
    }

}


int main(void)
{                     //[�޺��� �ϼ� ����][1�޿� 5��][1���Ͽ� 7��]
    int calender[12][8][8];
    int day_of_month[12] = { 31,28,31,30,31,31,30,31,30,31,30,31 };   //2023�� �޷��� 3�����迭�� ��� 
    int sp_of_month[12] = { 0,3,3,6,1,4,6,2,5,0,3,5 };//�޺��� ����Ҷ� ������ ������� 1������ �Ͽ��Ϻ��ʹ� 0 �Է� 

    cal_maker(calender, day_of_month, sp_of_month);
    cal_printer(calender, day_of_month, sp_of_month);

    return 0;
}
