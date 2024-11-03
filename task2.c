#include <stdio.h>
#include <ctype.h>

	
	int main(){
	

	char *reading = "task2test.txt";		
	FILE *point;

	point = fopen(reading,"r");

	if(point==NULL)
	{
	printf("Could noy be opened for reading %s\n", reading);
	return 1;
	
		
	}
	
	int countLine =0;
	char ch;
	int character=0;
	int Words=0;
	int countW=0;
	while ((ch = fgetc(point)) !=EOF){
		
		
		character++;
		
		if (isspace(ch)) {
			Words = 0;
		} else if (!Words) {
			Words = 1;
			countW++;
		}

		// lines
		if (ch == '\n'){
		countLine++;
		}
				
	 
	

	// charat
	
	//	if ()
	}	
	printf(" the lines in the text is : %d\n",countLine);
	printf("the characters is : %d\n", character);
	printf("The words in the text is : %d\n", countW);
//	char string;
//	while ((string = fgetc(point)) != EOF)
//		putchar(string);
	fclose(point);

		return 0;
	}
