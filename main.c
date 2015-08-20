#include <stdio.h>
#include <unistd.h>
#include <string.h>

int
main(){
	FILE *fp;
	char returnData[64];
	fp = popen("/sbin/ifconfig eth0", "r");

	int i=1;
	char *token;

	while (fgets(returnData, 64, fp) != NULL)
	{
		if(i == 2){
			token = strtok (returnData, ":");
			break;
		}
		i++;
	}

	while (token != NULL)
	{
		token = strtok (NULL, "  Bcast");
		printf("inet : %s\n", token);
		break;
	}

	pclose(fp);
}
