#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	char input[] = "";
	
	printf("Please Use hello,bye to use !\n");

	while(1){
	
		printf(">_");
		scanf("%s",&input);
		
		if(strcmp(input,"hello") == 0){
			printf("HelloWord ! \n");
		}else if(strcmp(input,"bye") == 0){
			printf("Bye ! \n");
		}else{
			printf("InputError\n");
		}
				
	}	

	return 0;
}