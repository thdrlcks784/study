#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

struct Person{
	int regi_num;
	char name[10];
	char memo[90];
};
int main(int argc, char *argv[]){
	struct Person p;
	int fd;
	int count = 0;

	if((fd = open(argv[1], O_RDWR|O_CREAT|O_APPEND,0640))==-1){
		printf("File open Error\n");
		exit(1);
	}
	

	printf("input data format\nregistration number | name | memo\n");
	while(1){
		memset(p.name, 0, sizeof(p.name));
		memset(p.memo, 0, sizeof(p.memo));
		lseek(fd, count*sizeof(p), SEEK_SET);
		printf("registration number : ");
		scanf("%d",&p.regi_num);	
		printf("name : ");
		scanf("%s", p.name);
		p.name[strlen(p.name)]='|';
		printf("memo : ");
		scanf("%s", p.memo);
		p.memo[strlen(p.memo)+1]='\n';
		printf("intput date : %d | %s %s \n",p.regi_num, p.name, p.memo);
	
		write(fd, &p, sizeof(p));	
		count += 1;
	}
	close(fd);
	exit(0);
}
