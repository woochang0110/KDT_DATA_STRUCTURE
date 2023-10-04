#if 1

/*
	계산식 입력(1+1=, exit로 종료)
	결과: 1+1=2 3-1=2 2*3=6 9/3=3 9%2=1
	1. 조건: ASCII코드의 숫자입력 필드에는 0~9까지 밖에 없음 그 외의 값이 입력되면 잘못입력되었다고 알려주고 다시 입력한다.
			printf("invalid input data");   
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	char input_buffer[6];
	int a,b;
	while(1)
	{
		printf("Enter (1+1, 종료:exit): ");
		fgets(input_buffer,100,stdin); 
//		strncpy(a,input_buffer,1);
//		strncpy(b,+2,1);
		a = atoi(input_buffer[0]);
		b = atoi(input_buffer[2]);
		printf("\n");
		if(strncmp(input_buffer,"exit",4)==NULL)//input_buffer의 4글자가 exit일 경우 NULL값 부여 //4Byte 내용 비교하여 exit 
		{
			break;
		}
		else if(a*b>=0&&a*b<82)
		{
			switch(input_buffer[1])
			{
				case '+': printf("%d%c%d=%d\n",a,input_buffer[1],b,a+b); break;
				case '-': printf("%d%c%d=%d\n",a,input_buffer[1],b,a-b); break;
				case '*': printf("%d%c%d=%d\n",a,input_buffer[1],b,a*b); break;
				case '/': printf("%d%c%d=%d\n",a,input_buffer[1],b,a/b); break;
				case '%': pprintf("%d%c%d=%d\n",a,input_buffer[1],b,a%b); break;
				default : printf("invalid operator data\n"); break;
			}
			printf("\n");
		}
		
		else
		{
			printf("invalid input data"); 
		}
	}
	return 0;
}

#endif







#if 0

#include <stdio.h>
#include <stdlib.h>
#include<string.h>	//strncmp
int main(void)
{
	char input_buffer[6];
	
	while(1)
	{
		printf("Enter Score(A~F) exit: ");
		fgets(input_buffer,100,stdin); 
		printf("\n");
		if(strncmp(input_buffer,"exit",4)==NULL)//input_buffer의 4글자가 exit일 경우 NULL값 부여 //4Byte 내용 비교하여 exit 
		{
			break;
		}
		else
		{
			switch(input_buffer[0])
			{
				case 'A': printf("Your Score is A\n"); break;
				case 'B': printf("Your Score is B\n"); break;
				case 'C': printf("Your Score is C\n"); break;
				case 'D': printf("Your Score is D\n"); break;
				case 'F': printf("Your Score is F\n"); break;
				default : printf("Enter Again\n"); break;
			}
			printf("\n");
		}
	}
	return 0;
}
#else
		if(input_buffer[0]=='e'&&input_buffer[1]=='x'&&input_buffer[2]=='i'&&input_buffer[3]=='t')
		{
			break;		
		}

#endif





#if 0
/*
 입력조건: 학점 평점 영어 수학 이름(A 4.1 100 100 wcm)
 1. 만약 학점 F면 프로그램 종료
 2. 평점 4.4 이상 영어 95이상 수학 95이상은 Excellent!와 입력값 출력 
 3. 평점 4.0 이상 영어 90이상 수학 90이상은 Good!와 입력값 출력
 4. 평점 3.0 이상 영어 85이상 수학 85이상은 Normal!과 입력값 출력


*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main(void)
{
	char input_buffer[34];
	char grade;
	char score[4]; //3.4\0 Ascii 값으로 들어있음 
	char name[20];
	char eng[4];	//99까지니까 ASCII 숫자 2개=2Byte랑 \0 NULL값 1Byte해서 3바이트 필요한데 짝수 맞춰야되니까 4Byte  
	char math[4];	//3바이트 필요한데 짝수 맞춰야되니까 4 
	double d_score;
	int i_eng,i_math;
	
	while(1)
	{
		printf("학점 평점 영어 수학 이름: (A 4.1 99 99 wcm)");
		fgets(input_buffer,100,stdin);
		printf("\n");
		if(input_buffer[0]=='F')
		{
			return 0;		
		}
		
		else
		{
			grade = input_buffer[0]; //input_buffer내용을 grade에 복사
			
			strncpy(score,input_buffer+2,3);
			d_score=atof(score);
			
			strncpy(eng,input_buffer+6,2);
			i_eng=atoi(eng);
			
			strncpy(math,input_buffer+9,2);
			i_math=atoi(math);
			
			strcpy(name,input_buffer+12);
			
			if(d_score>=4.4&&i_math>94&&i_eng>94)
			{
				printf("Excellent! ");
			}
			else if(d_score>=4.0&&i_math>89&&i_eng>89)
			{
				printf("Good~ ");
			}
			else if(d_score>=3.0&&i_math>84&&i_eng>84)
			{
				printf("Normal... ");
			}			
			else 
			{
				return 0;
			}
			printf("학점: %c 평점: %.1lf 영어: %d 수학: %d 이름:%s \n",grade,d_score,i_eng,i_math,name);

		}
	}
	return 0;
}


#endif


#if 0
#include <stdio.h>
#include <stdlib.h> //rand, atoi(Ascii->int), atof(Ascii-float), atol(Ascii->long) itoa(int->Ascii)함수 등 포함 
					//atoi 변환과정을 보면 keyboard의 ASCII입력을 메모리 상에 int로 입력하고 다시 ASCII로 출력 
#include<string.h>  // strncpy, strcpy,strcat 등의 함수가 들어있음 
int main(void)
{
	char grade;
	char score[4]; //3.4\0 Ascii 값으로 들어있음 
	char name[20];
	char input_buffer[100];
	int i=0;
	char eng[]="900"; 
	int i_eng=0;
	char math[]="100"; // 1의 ASCII 코드값: 0x31  0의 ASCII 코드값: 0x30 
	//즉, math[0]=0011 0001, math[1]=0011 0000, math[2]=0011 0000
	int i_math=0;
	int sum=0;
	char opt[100];
	while(1)
	{
		printf("학점 평점 영어 수학 이름: (A 4.1 100 100 wcm)");
		fgets(input_buffer,100,stdin);
		if(input_buffer[0]=='F')
		{
			return 0;		
		}
		
		else
		{
			grade = input_buffer[0]; //input_buffer내용을 grade에 복사
//			score[0] = input_buffer[2];
//			score[1] = input_buffer[3];
//			score[2] = input_buffer[4];
//			score[3] = '\0';

			strncpy(score,input_buffer+2,3); //많이쓰임 
			//strncpy(입력받을시작주소,입력넣을 시작주소,시작주소부터 입력넣을 사이즈)
			
			strncpy(eng,input_buffer+6,3); //많이쓰임 
			//strncpy(입력받을시작주소,입력넣을 시작주소,시작주소부터 입력넣을 사이즈)
			i_eng=atoi(eng);
			
			strncpy(math,input_buffer+10,3); //많이쓰임 
			//strncpy(입력받을시작주소,입력넣을 시작주소,시작주소부터 입력넣을 사이즈)
			i_math=atoi(math);
			sum=i_eng+i_math;
			itoa(sum,opt,10);
			
			strcpy(name,input_buffer+14);
			//strncpy(입력받을시작주소,입력넣을 시작주소)  NULL 만날 때까지 복사됨 
			
			
			printf("학점: %c\n",grade);
			//printf("평점: %s\n",score);
			printf("평점: %lf\n",atof(score));
			printf("영어: %d\n",i_eng);
			printf("수학: %d\n",i_math);

			printf("수학영어 합 ASCII값: %s\n",opt);
			printf("이름: %s\n",name);
			
		
		}
	
	}
	return 0;
}



#endif


#if 0
#include<stdio.h>
#define SQ(x) ((x)*(x))  //거듭제곱 SQUARE에 대한 매크로임. 
#define CUBE(x) (SQ(x)*(x)) //3제곱 
enum{
	SUN=7,MON=1,TUE=2,WED=3,THU=4,FRI=5,SAT=6
};

int sq(int n)
{
	return n*n;
}

int main(void)
{
	int n=2;
	printf("Macro 실행:%d의 제곱은 %d \n",n,SQ(n) ); //SQ가 매크로이기 때문에 컴파일 시에 SQ(n)을 ((n)*(n))으로 바뀜 
	printf("Macro 실행:%d의 세제곱은 %d \n",n,CUBE(n) ); //SQ가 매크로이기 때문에 컴파일 시에 SQ(n)을 ((n)*(n))으로 바뀜 
	printf("함수 실행:%d의 제곱은 %d \n",n,sq(n) ); //SQ가 매크로이기 때문에 컴파일 시에 SQ(n)을 ((n)*(n))으로 바뀜 
	printf("ENUM 출력:%d,%d,%d \n",SUN,MON,THU ); 
	
	return 0;
}



#endif
