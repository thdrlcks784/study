/*
===========================================================================
Name        : exam.c
Author      : SONG KI-SU
Version     : v1.0
Copyright   : SONG KI_SU
Description : 환경변수 설정

구분    날짜        내용
----   ---------- -----------------------------------------------------------
생성    2020/05/07 환경변수 설정 프로그램 구현
-----------------------------------------------------------------------------
코딩구분 설명
생성 : 처음으로 프로그램 개발했을 때
추가 : 기존의 프로그램에서 알고리즘(로직)을 추가했을 때, 함수 추가
수정 : 기존의 프로그램의 알고리즘(로직)을 수정했을 때
삭제 : 기존의 프로그램 알고리즘 일부를 삭제했을 때
===========================================================================
*/
/*---------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>				/*헤더파일 정의*/
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
/*---------------------------------------------------------------------------------------------------*/
void title();
void fileopen();
void read_parameter();
void front();
void back();					/*함수 원형 정의*/
int return_vseq();
void modify();
void remove_parameter();
void error_check();
/*---------------------------------------------------------------------------------------------------*/
char filename[10];
int count;
int fd;					/*전역변수 선언*/
int page = 0;
int err_ch = 0;
char work;
/*---------------------------------------------------------------------------------------------------*/
struct vparameter {
	int vseq;
	char vkey[10];			/*환경변수 구조체 선언*/
	char vpvalue[30];
};
/*---------------------------------------------------------------------------------------------------*/
void title() {
	printf("\t환경 변수 설정 v1.0\tFile name : %s \n", filename);
	printf("========================================================================\n");
	printf("\t\t환경 변수 설정 화면\n");
	printf("Seq\tParameter\tParameter value\n");
	printf("---\t---------\t---------------\n");	/*메인 title 출력 함수*/
	read_parameter();
	printf("---------------------------------------\n");
	printf("1. 입력 2. 수정 4. 삭제 7. 앞으로 8. 뒤로 9. 종료\n");
	printf("========================================================================\n");
	error_check(err_ch);
	err_ch = 0;
	printf("원하는 작업을 선택하세요 : ");
}
/*---------------------------------------------------------------------------------------------------*/
int return_vseq() {		/*파일의 마지막 vseq번호를 리턴하기 위한 함수*/
	int i = 0;
	struct vparameter v;
	fileopen();
	while (1) {
		lseek(fd, i * sizeof(v), SEEK_SET);
		if (read(fd, &v, sizeof(v)) == 0) { break; }
		i++;
	}
	close(fd);
	return i;
}
/*---------------------------------------------------------------------------------------------------*/
void fileopen() {		/*fileopen 함수*/
	if ((fd = open(filename, O_RDWR | O_CREAT | O_APPEND, 0640)) == -1) {
		printf("File open Error\n");
		exit(1);
	}
}
/*---------------------------------------------------------------------------------------------------*/
void insert() {			/*환경변수 입력 함수*/
	struct vparameter v;
	fileopen();
	lseek(fd, count * sizeof(v), SEEK_SET);
	v.vseq = count + 1;
	printf("Parameter Key : ");
	scanf("%s", v.vkey);
	printf("\nParameter value : ");
	scanf("%s", v.vpvalue);
	write(fd, &v, sizeof(v));
	count++;
	close(fd);
}
/*---------------------------------------------------------------------------------------------------*/
void read_parameter() {		/*환경변수 출력 함수*/
	int line = page * 5;	/*이 함수는 title에서 5개씩 환경변수를 출력하기 위해 사용*/
	fileopen();
	struct vparameter v;
	for (int i = 0; i < 5; i++) {
		lseek(fd, line * sizeof(v), SEEK_SET);
		if (read(fd, &v, sizeof(v)) > 0) {
			printf("%d\t%s\t\t%s\n", v.vseq, v.vkey, v.vpvalue);
		}
		else {
			printf("\n");
		}
		line++;

	}
	close(fd);
}
/*---------------------------------------------------------------------------------------------------*/
void modify() {				/*환경변수 수정을 위한 함수*/
	struct vparameter v;
	int modify;
	printf("수정을 진행할 seq_num 을 입력하시오. : ");
	scanf("%d", &modify);
	if (modify > count || modify < 1) {
		err_ch = 1;
	}
	else {
		if ((fd = open(filename, O_RDWR, 0640)) == -1) {
			printf("File open Error\n");
			exit(1);
		}
		lseek(fd, (modify - 1) * sizeof(v), SEEK_SET);
		v.vseq = modify;
		printf("Parameter Key : ");
		scanf("%s", v.vkey);
		printf("\nParameter value : ");
		scanf("%s", v.vpvalue);
		write(fd, &v, sizeof(v));
		close(fd);
	}

}
/*---------------------------------------------------------------------------------------------------*/
void remove_parameter() {		/*환경변수 삭제함수*/
	if (count == 0) { err_ch = 1; return; }
	struct vparameter v1;
	struct vparameter v2;
	if ((fd = open(filename, O_RDWR, 0640)) == -1) {
		printf("File open Error\n");
		exit(1);
	}
	int seq_num, last_num = count;
	char vkey[11], vpvalue[31];
	printf("삭제할 seq_num을 입력하시오. : ");
	scanf("%d", &seq_num);
	if (seq_num > count) { err_ch = 1; return; }
	for (int i = seq_num; i < last_num; i++) {
		lseek(fd, i * sizeof(v1), SEEK_SET);
		read(fd, &v1, sizeof(v1));
		v1.vseq = i;
		memcpy(&v2, &v1, sizeof(struct vparameter));
		lseek(fd, (i - 1) * sizeof(v1), SEEK_SET);
		write(fd, &v2, sizeof(struct vparameter));

	}
	lseek(fd, 0, SEEK_SET);
	ftruncate(fd, sizeof(struct vparameter) * (count - 1));
	close(fd);
	count--;
	if (count % 5 == 0 && page > 0) { front(); }

}
/*---------------------------------------------------------------------------------------------------*/
void front() {		/*page변경 함수*/
	page--;
}
void back() {
	page++;
}
/*---------------------------------------------------------------------------------------------------*/
void error_check(int check) {		/*오류메세지 출력 함수*/
	switch (check) {
	case 1:
		printf("입력하신 seq_num은 존재하지 않거나 파일이 비어있습니다.\n");
		break;
	case 2:
		printf("맨 앞 페이지 입니다.\n");
		break;
	case 3:
		printf("맨 뒷 페이지 입니다.\n");
		break;
	case 4:
		printf("잘못된 입력입니다.\n");
		break;
	}
}
/*---------------------------------------------------------------------------------------------------*/
int main() {		/*main 함수*/
	struct vparameter v;
	printf("\t환경 변수 설정 v1.0\tFile name : ");
	scanf("%s", filename);
	v.vseq = return_vseq();
	count = v.vseq;
	while (1) {
		system("clear");
		title();
		scanf("%s", &work);
		switch (work) {
		case '1':
			insert();
			break;
		case '2':
			modify();
			break;
		case '3':
			printf("%d : %d : %d\n", v.vseq, count, page);
			break;
		case '4':
			remove_parameter();
			break;
		case '7':
			if (page == 0) { err_ch = 2; }
			else { front(); }
			break;
		case '8':
			if (((count - 1) / 5) == page) { err_ch = 3; }
			else { back(); }
			break;
		case '9':
			exit(1);
		default:
			err_ch = 4;
			break;
		}
	}
}
