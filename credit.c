#include <stdio.h>



int checksum(long long cardnum){
	
	long long data = cardnum;
	int len = 0;

	while (data != 0){
		len++;
		data = data/10;
	}

	long long data2 = cardnum;
	int total = 0;
	for(int i = 0; i < len; i++){
		if (i %2 != 0){
			total += (data2%10)*2;
		}

		data2 = data2/10;
	}

	return total;
}

int main()
{
	long long cardnumber = 4003600000000014;
	printf("%lli\n", cardnumber);
	printf("%d", checksum(cardnumber));
	
}