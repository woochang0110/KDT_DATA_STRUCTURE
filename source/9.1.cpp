#if 1
#include<stdio.h>
int main(void)
{
	int kor=70, eng=80,mat=90;
	
	int tot =kor+eng+mat;
	printf("국어: %d, 영어: %d, 수학: %d",kor,eng,mat);
	printf("총점:%d",tot); 
	
}



#endif





#if 0
#include<stdio.h>
#include<string.h>
int main(void)
{
	char grade;
	double score;
	char name[20];
	while(1)
	{
		printf("grade score name(A 3.4 wcm): \n");
		scanf("%c %lf %s",&grade,&score,name); // 배열은 주소지정& 안붙여도됨
		
		if(grade=='F')
		{
			break;
		}
		else
		{
			printf("학점: %c\n",grade);
			printf("평점: %.1f\n",score);
			printf("이름: %s\n",name); 
	
		}
	}
	printf("Finish\n");
	return 0;
}

#endif







#if 0
#include<stdio.h>
#include<string.h>
int main(void)
{
	char grade;
	double score;
	char name[20];
	while(1)
	{
		printf("grade score name(A 3.4 wcm): \n");
		scanf("%c %lf %s",&grade,&score,name); // 배열은 주소지정& 안붙여도됨
		
		if(grade=='F')
		{
			break;
		}
		else
		{
			printf("학점: %c\n",grade);
			printf("평점: %.1f\n",score);
			printf("이름: %s\n",name); 
	
		}
	}
	printf("Finish\n");
	return 0;
}

#endif



#if 0
#include<stdio.h>
#include<string.h>
int main(void)
{
	int i,j,k;
	char * ascii[500]={"NUL","SOH","STX","ETX","EOT","ENQ","ACK","BEL","BS","HT","LF","VT","FF","CR","SO","SI","DLE","DC1","DC2","DC3","DC4","NAK","SYN","ETB","CAN","EM","SUB","ESC","FS","GS","RS","US","SP"};
	printf("%100s\n","ASCII CODE TABLE\n"); // 총 30Byte 출력하고 나머지는 space로 채운다
	printf("%100s\n","================\n"); // 총 30Byte 출력하고 나머지는 space로 채운다
	
	for(k=0;k<4;k++)
	{
			printf("%10s%10s%10s%10s","DEC","HEX","OCT","CHAR"); // 왼쪽부터 10칸씩 값 출력 
	}		
	for(k=0;k<4;k++)
	{
			printf("%10s%10s%10s%10s","===","===","===","===="); // 왼쪽부터 10칸씩 값 출력 
	}
	for(i=0; i < 32; i++)
	{	
		for(j=0;j<4; j++)
		{
			
			if(i+32*j<33){
				printf("%10d%10.2x%10o%10s",i+32*j,i+32*j,i+32*j,ascii[i+32*j]);
			}
			else{
				printf("%10d%10.2x%10o%10c",i+32*j,i+32*j,i+32*j,i+32*j); //10칸 10진수,10칸 16진수, 10칸 8진수, 10칸 문자
			}
			
			
		}
		printf("\n");
	}
 

	
	return 0;
}



#endif






#if 0
#include<stdio.h>

int main(void)
{
	int i=10;
	//10을 decimal로 출력
	printf("i: %d\n",i);
	
	//10을 octal 로 출력
	printf("octal 10: %o\n",i);
	
	//10을 hexa 로 출력
	printf("hexa 10: %x\n",i);
	 
	//floating 처리 
	printf("%lf\n",3.4); //소수점 6자리 출력 
	printf("%.1lf\n",3.4); //소수점 1자리 출력
	printf("%.10lf\n",3.444444); //소수점 10자리 출력
	
	//ASCII 코드
	
	char c;
	int ch[2];
	
	c= 'A'; //대문자 A는 0x41 (65)  1Byte
//	c= "A" // A \0을 해서 NULL 포함 2Byte 
	ch[0]='A'; //ch[0]= 0x41; //ch[0]=0b01000001;
	ch[1]='\0';
	
	//한 글자만 찍을때는 %c
	printf("c: %c\n",c);
	printf("ch: %s\n",ch);
	
	const double tax_rate=0.12; //const 는 read only임 write는 안됨 
	
	return 0;
}

#endif








#if 0
#include<stdio.h> // printf scanf gets fgets 등의 함수 
#include<string.h> // strcat strlen strlen  등의 함수 
int main (void)
{
	char c[6] ="abcd"; // abcd= 4Byte, compiler null값 1Byte
					  // 배열 값은 짝수로 잡아라 
					  
	printf("sizeof c:%d \n",sizeof(c)) ; //6Byte
	
	
	unsigned char uc[] ="abcde"; // abcde= 5Byte compiler NULL값 1Byte  
	//compiler가 초기값 갯수만큼 메모리 확보 
					  
	printf("sizeof uc:%d \n",sizeof(uc)) ; //6Byte
	
	int i[10]={0,1,2,3,4,5,6,7,8,9}; // abcde= 5Byte
	 				  
	printf("sizeof i:%d \n",sizeof(i)) ; //40Byte
	
	long l[6];
	
	printf("sizeof l:%d \n",sizeof(l)); //24Byte
	
	//변수에 들어있는 문자열의 수를 확인:strlen 함수 = NULL전까지의 문자갯수확인 
	printf("c의 문자수: %d\n",strlen(c)); //4Byte 
//	printf("uc의 문자수: %d\n",strlen(uc)); //5Byte 
	c[0]='A';
	c[1]='B';
	c[2]='C';
	c[3]='\0'; //String의 마지막은 NULL로 만들어줌 
	printf("c의 문자수: %d\n",strlen(c)); //3Byte 


}




#endif















#if 0

#include <stdio.h>

int main(void)
{
	//변수(variable) : 자료(data)를 저장하는 메모리(RAM,ROM) 공간 
	char c; // 1Byte 문자 -127~c~127까지 저장가능 
	
	unsigned char uc = 0xff; //1Byte 문자 0~255(0x00~0xff)까지 저장 가능//hexa
//	unsigned char uc = 0377; //octa는 8진수 앞에 0붙이면됨
//	unsigned char uc = 0b11111111; //2진수 표현 binary
//	unsigned char uc = 255; //decimal
	
	short s; //short는 2Byte나 4Byte (CPU에 따라 다름 intel i5는 2Byte)  RAM 2Byte 할당 
	unsigned short us; // 2Byte  0~us~65535  (0x0000~us~0xffff)
	
	int i; //정수 4Byte  -(2^31+1)~ i~ +(2^31-1) 
	unsigned int ui; // 양수인 정수 4Byte 0~ 2^32-1 
	
	long l; //4Byte 
	
	printf("uc: %d\n",uc);// decimal
	printf("uc: %0x\n",uc);// hexa
	// 2진수는 직접 출력해야됨 
	
	uc++; //overflow 되서 0이 됨 
	//증감자++를 사용하는 이유는  레지스터에서 직접 동작해서 uc=uc+1에 비해 실행속도가 더 빠르기 때문  
	printf("uc: %0x\n",uc);  
	printf("char: \t%d\n",sizeof(i)); // sizeof() 변수의 자료크기(Byte)를 계산하는 함수 
	return 0;	
}



#endif 













#if 0 //조건부 compile  #if 1이면 컴파일을 실행  #if 0이면 컴파일 안함 
/*
 1.PROGRAM NAME: TEST.C 
 2. Ver 1.0
 3. 작성자: ChangMin
 4. 기능: C언어 기본 test program 
*/
#include <stdio.h>

int main(void)//void 아무런 것이 없다(가독성을 위해 작성하는것)
{
	printf("Hello \n")// Hello 5바이트, \n 1바이트, printf 문자열 종료를 위한 NULL 1바이트 총 7바이트 먹힘
	 
	
	
	return 0;	//Error Code:0  =  main 함수를 정상적으로 실행하고 리턴한다는 뜻 
}



#endif //조건부 컴파일 종료 


 



