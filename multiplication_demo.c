/*Please use -std=c99 to compile...*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	FILE *fp;
	fp = fopen("file.txt","w+");
	
	for(int i=1;i<10;i++){
		for(int j=1;j<10;j++){
			fprintf(fp,"%d %s %d %s %d\t",i,"*",j,"=",i*j);
		}
		fprintf(fp,"\n");
	}

}
