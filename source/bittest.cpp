#include <stdio.h> 

int main (void)
{
	int i;
	
	union
	{
		unsigned int BYTE_4;
		
		struct
		{
			unsigned bit[32]: 32;
		}s;
	}u;
	u.BYTE_4 = 0xffffffff;
	for(i=0; i<32;i++ )
	{
		printf("%d",bit[i]);
	}
	
	
	
	return 0;
}
