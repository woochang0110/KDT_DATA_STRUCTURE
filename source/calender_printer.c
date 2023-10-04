#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//    int sp_of_month[12] = {0,3,3,6,1,4,6,2,5,0,3,5 };//달별로 출력할때 어디부터 출력할지 1월달은 일요일부터니 0 입력 
//	  함수에서 int *sp를 매개변수로 받고   main에서 int sp[12]; 사용할 때에는 sp로 
// 		i=0일때 k=0;  

void cal_maker(int cal[12][8][8], int *day, int *sp)
{
    int i, j, k, n;

    //포인터로 매개변수 받아와서 값바꾸거나 할게 없어서 따로 변수 안만들어줌

    for (i = 0; i < 12; i++)//월
    {
        n = 1; // 해당 월에 입력된 날짜 수 저장 
 //       printf("\n i :%d   %d일 돌아야됨\n", i+1, *(day + i));
        for (j = 0; j < 7; j++)//주
        {
            if (j == 0)
            {
                k = *(sp + i);//그 달의 첫 출력일때 입력시작요일 k에 지정
                
            }   
            else 
            { 
                k = 0; //아니면 다시 일요일(k=0)부터 입력 
            }
            for (k; k < 7; k++)//해당 월의 시작요일부터 채워넣음
            {
                if (*(day + i) == n - 1) { break;}//해당 월의 일수만큼 돌았다면 
                cal[i][j][k] = n;// 달별 입력 일수 저장 
 //               printf("j:%d, k:%d, n:%d 입력값:%d\n", j, k, n, cal[i][j][k]);
                n++;
                
            }
        }

    }

}


void cal_printer(int cal[12][8][8], int* day, int* sp)
{
    int i, j, k, l, n;

    for (i = 0; i < 12; i++)//월
    {
        n = 1;
        printf("\n%10s%d월달력%10s\n", "",i+1,"");
        printf("%4s%4s%4s%4s%4s%4s%4s\n","일","월","화","수","목","금","토");
        for (j = 0; j < 7; j++)//주
        {
            
            if (j == 0)   //그 달의 첫 출력일때 
            {
                k = *(sp + i);//k에다가 출력시작요일 지정
                for (l = 0; l < k; l++)   //첫출력 요일까지 sp 
                {
                    printf("    ");//한 요일당 4칸씩
                }

            }
            else// 그 달의 첫 출력이 아니면
            {
                k = 0;// 다시 일요일(k=0)부터 출력 
            }      

            for (k; k < 7; k++)//일
            {
                if (*(day + i) == n - 1)//해당 월의 일수만큼 돌았다면 탈출
                {
                    break;
                }
                printf("%4d", cal[i][j][k]);
                n++;   //몇번돌았는지 카운트 
            }
            printf("\n");         //주차마다 new line 
        }
    }

}


int main(void)
{                     //[달별로 일수 저장][1달에 5주][1주일에 7일]
    int calender[12][8][8];
    int day_of_month[12] = { 31,28,31,30,31,31,30,31,30,31,30,31 };   //2023년 달력을 3차원배열로 출력 
    int sp_of_month[12] = { 0,3,3,6,1,4,6,2,5,0,3,5 };//달별로 출력할때 어디부터 출력할지 1월달은 일요일부터니 0 입력 

    cal_maker(calender, day_of_month, sp_of_month);
    cal_printer(calender, day_of_month, sp_of_month);

    return 0;
}
