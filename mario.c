#include <stdio.h>

int main()
{
	int height = 0;
	do {
		printf("Height\n");
		scanf("%d", &height);
		
	}

	while (!(height >= 1 && height <= 8));
	


	for (int i = 0; i < height; i++) {
		
		int leftsidestart = ((height * 2 + 2) / 2 - i -1);
		int leftsideend = ((height * 2 + 2) / 2 - 1);
		int rightsideend = ((height * 2 + 2) / 2 + i + 2);
		int rightsidestart = ((height * 2 + 2) / 2 + 2);
		int draw = 0;

		for (int x = 0; x < (height +3 +i); x++) {
			
			draw += 1;
			if ((draw >= leftsidestart && draw <= leftsideend) || (draw >= rightsidestart && draw <= rightsideend)) {
				printf("#");
			}
			else {
				printf(" ");
			}

			
			
			
		}
		printf("\n");
	}
}