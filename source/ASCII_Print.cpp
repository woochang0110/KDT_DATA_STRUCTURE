#include<stdio.h>
#include<string.h>
int main(void)
{
	int i,j,k;
	char * ascii[500]={"NUL","SOH","STX","ETX","EOT","ENQ","ACK","BEL","BS","HT","LF","VT","FF","CR","SO","SI","DLE","DC1","DC2","DC3","DC4","NAK","SYN","ETB","CAN","EM","SUB","ESC","FS","GS","RS","US","SP"};
	printf("%30s\n","ASCII CODE TABLE\n"); // �� 30Byte ����ϰ� �������� space�� ä���
	printf("%30s\n","================\n"); // �� 30Byte ����ϰ� �������� space�� ä���
	
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

