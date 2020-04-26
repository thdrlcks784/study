#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
struct Person{
	int regi_num;
	char name[10];
	char memo[90];
};
int main(int argc, char *argv[]){
	struct Person p;
	int fd ,number;
	int count = 0;

	if((fd=open(argv[1], O_RDONLY))==-1){
		perror(argv[1]);
		exit(2);
	
	}
	while(1){
		printf("Please enter the registration number to search : ");
		scanf("%d", &number);	
		lseek(fd, (number-1)*sizeof(p), SEEK_SET);
		if(read(fd, &p, sizeof(p)) > 0)
                      printf("registration number : %d | name : %s | memo : %s\n",p.regi_num, p.name, p.memo);
		else printf("wrong registration number\n");
	}
}
