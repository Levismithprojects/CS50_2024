#include <stdio.h>


int numberlen(long long number){
	int len = 0;

	while (number != 0){
		len++;
		number = number/10;
	}

	return len;
}
int checksum(long long cardnum){
	
	long long data = cardnum;
	int length = numberlen(cardnum);

	long long data2 = cardnum;
	int oddtotal = 0;
	int eventotal = 0;

	for(int i = 0; i < length; i++){
		if (i %2 != 0){
			int oddresult = (data2%10)*2;
			

			if ((data2%10*2)/10 != 0){
				
				oddtotal += oddresult%10;
				oddresult /= 10;
				oddtotal += oddresult;
				
			}

			else{
				oddtotal += oddresult;
				
			}
			
		}

		else{
			
			eventotal += data2%10;

		}

		data2 = data2/10;
	}

	if((oddtotal + eventotal)%10 == 0){
		return 0;
	}
	else{
		return 1;
	}
}

int main()
{
	const int mincardlength = 13;
	const int maxcardlength = 16;
	long long cardnumber;
	
	printf("Input number: \n");
	scanf("%lld", &cardnumber);

	
	if(numberlen(cardnumber) >= mincardlength && numberlen(cardnumber) <= maxcardlength)
		if(checksum(cardnumber) == 0){

			switch(numberlen(cardnumber)){
			case 15:
				printf("American Express");
				break;

			case 13:
				printf("Visa");
				break;

			case 16:
				if(cardnumber%10000000000000000 == 4){
					printf("Visa");
				}

				else{
					printf("Mastercard");
				}
				break;
		}
		printf("\n");
		printf("Valid");

		}

		else{
			printf("Invalid");
		}

	else{
		printf("Invalid");
	}
	
	
}