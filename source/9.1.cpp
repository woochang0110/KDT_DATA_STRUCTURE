#if 1
#include<stdio.h>
int main(void)
{
	int kor=70, eng=80,mat=90;
	
	int tot =kor+eng+mat;
	printf("����: %d, ����: %d, ����: %d",kor,eng,mat);
	printf("����:%d",tot); 
	
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
		scanf("%c %lf %s",&grade,&score,name); // �迭�� �ּ�����& �Ⱥٿ�����
		
		if(grade=='F')
		{
			break;
		}
		else
		{
			printf("����: %c\n",grade);
			printf("����: %.1f\n",score);
			printf("�̸�: %s\n",name); 
	
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
		scanf("%c %lf %s",&grade,&score,name); // �迭�� �ּ�����& �Ⱥٿ�����
		
		if(grade=='F')
		{
			break;
		}
		else
		{
			printf("����: %c\n",grade);
			printf("����: %.1f\n",score);
			printf("�̸�: %s\n",name); 
	
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
	printf("%100s\n","ASCII CODE TABLE\n"); // �� 30Byte ����ϰ� �������� space�� ä���
	printf("%100s\n","================\n"); // �� 30Byte ����ϰ� �������� space�� ä���
	
	for(k=0;k<4;k++)
	{
			printf("%10s%10s%10s%10s","DEC","HEX","OCT","CHAR"); // ���ʺ��� 10ĭ�� �� ��� 
	}		
	for(k=0;k<4;k++)
	{
			printf("%10s%10s%10s%10s","===","===","===","===="); // ���ʺ��� 10ĭ�� �� ��� 
	}
	for(i=0; i < 32; i++)
	{	
		for(j=0;j<4; j++)
		{
			
			if(i+32*j<33){
				printf("%10d%10.2x%10o%10s",i+32*j,i+32*j,i+32*j,ascii[i+32*j]);
			}
			else{
				printf("%10d%10.2x%10o%10c",i+32*j,i+32*j,i+32*j,i+32*j); //10ĭ 10����,10ĭ 16����, 10ĭ 8����, 10ĭ ����
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
	//10�� decimal�� ���
	printf("i: %d\n",i);
	
	//10�� octal �� ���
	printf("octal 10: %o\n",i);
	
	//10�� hexa �� ���
	printf("hexa 10: %x\n",i);
	 
	//floating ó�� 
	printf("%lf\n",3.4); //�Ҽ��� 6�ڸ� ��� 
	printf("%.1lf\n",3.4); //�Ҽ��� 1�ڸ� ���
	printf("%.10lf\n",3.444444); //�Ҽ��� 10�ڸ� ���
	
	//ASCII �ڵ�
	
	char c;
	int ch[2];
	
	c= 'A'; //�빮�� A�� 0x41 (65)  1Byte
//	c= "A" // A \0�� �ؼ� NULL ���� 2Byte 
	ch[0]='A'; //ch[0]= 0x41; //ch[0]=0b01000001;
	ch[1]='\0';
	
	//�� ���ڸ� �������� %c
	printf("c: %c\n",c);
	printf("ch: %s\n",ch);
	
	const double tax_rate=0.12; //const �� read only�� write�� �ȵ� 
	
	return 0;
}

#endif








#if 0
#include<stdio.h> // printf scanf gets fgets ���� �Լ� 
#include<string.h> // strcat strlen strlen  ���� �Լ� 
int main (void)
{
	char c[6] ="abcd"; // abcd= 4Byte, compiler null�� 1Byte
					  // �迭 ���� ¦���� ��ƶ� 
					  
	printf("sizeof c:%d \n",sizeof(c)) ; //6Byte
	
	
	unsigned char uc[] ="abcde"; // abcde= 5Byte compiler NULL�� 1Byte  
	//compiler�� �ʱⰪ ������ŭ �޸� Ȯ�� 
					  
	printf("sizeof uc:%d \n",sizeof(uc)) ; //6Byte
	
	int i[10]={0,1,2,3,4,5,6,7,8,9}; // abcde= 5Byte
	 				  
	printf("sizeof i:%d \n",sizeof(i)) ; //40Byte
	
	long l[6];
	
	printf("sizeof l:%d \n",sizeof(l)); //24Byte
	
	//������ ����ִ� ���ڿ��� ���� Ȯ��:strlen �Լ� = NULL�������� ���ڰ���Ȯ�� 
	printf("c�� ���ڼ�: %d\n",strlen(c)); //4Byte 
//	printf("uc�� ���ڼ�: %d\n",strlen(uc)); //5Byte 
	c[0]='A';
	c[1]='B';
	c[2]='C';
	c[3]='\0'; //String�� �������� NULL�� ������� 
	printf("c�� ���ڼ�: %d\n",strlen(c)); //3Byte 


}




#endif















#if 0

#include <stdio.h>

int main(void)
{
	//����(variable) : �ڷ�(data)�� �����ϴ� �޸�(RAM,ROM) ���� 
	char c; // 1Byte ���� -127~c~127���� ���尡�� 
	
	unsigned char uc = 0xff; //1Byte ���� 0~255(0x00~0xff)���� ���� ����//hexa
//	unsigned char uc = 0377; //octa�� 8���� �տ� 0���̸��
//	unsigned char uc = 0b11111111; //2���� ǥ�� binary
//	unsigned char uc = 255; //decimal
	
	short s; //short�� 2Byte�� 4Byte (CPU�� ���� �ٸ� intel i5�� 2Byte)  RAM 2Byte �Ҵ� 
	unsigned short us; // 2Byte  0~us~65535  (0x0000~us~0xffff)
	
	int i; //���� 4Byte  -(2^31+1)~ i~ +(2^31-1) 
	unsigned int ui; // ����� ���� 4Byte 0~ 2^32-1 
	
	long l; //4Byte 
	
	printf("uc: %d\n",uc);// decimal
	printf("uc: %0x\n",uc);// hexa
	// 2������ ���� ����ؾߵ� 
	
	uc++; //overflow �Ǽ� 0�� �� 
	//������++�� ����ϴ� ������  �������Ϳ��� ���� �����ؼ� uc=uc+1�� ���� ����ӵ��� �� ������ ����  
	printf("uc: %0x\n",uc);  
	printf("char: \t%d\n",sizeof(i)); // sizeof() ������ �ڷ�ũ��(Byte)�� ����ϴ� �Լ� 
	return 0;	
}



#endif 













#if 0 //���Ǻ� compile  #if 1�̸� �������� ����  #if 0�̸� ������ ���� 
/*
 1.PROGRAM NAME: TEST.C 
 2. Ver 1.0
 3. �ۼ���: ChangMin
 4. ���: C��� �⺻ test program 
*/
#include <stdio.h>

int main(void)//void �ƹ��� ���� ����(�������� ���� �ۼ��ϴ°�)
{
	printf("Hello \n")// Hello 5����Ʈ, \n 1����Ʈ, printf ���ڿ� ���Ḧ ���� NULL 1����Ʈ �� 7����Ʈ ����
	 
	
	
	return 0;	//Error Code:0  =  main �Լ��� ���������� �����ϰ� �����Ѵٴ� �� 
}



#endif //���Ǻ� ������ ���� 


 



