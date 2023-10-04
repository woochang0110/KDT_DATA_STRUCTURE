#include<stdio.h>
#include<string.h>
int main(void)
{
	int i,j,k;
	char * ascii[500]={"NUL","SOH","STX","ETX","EOT","ENQ","ACK","BEL","BS","HT","LF","VT","FF","CR","SO","SI","DLE","DC1","DC2","DC3","DC4","NAK","SYN","ETB","CAN","EM","SUB","ESC","FS","GS","RS","US","SP"};
	printf("%30s\n","ASCII CODE TABLE\n"); // 총 30Byte 출력하고 나머지는 space로 채운다
	printf("%30s\n","================\n"); // 총 30Byte 출력하고 나머지는 space로 채운다
	
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

