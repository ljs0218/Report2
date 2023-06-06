#include <stdio.h>

#define MAX_SIZE 50
#define NUM_SUBJECTS 3
#define NUM_DEPTS 5
#define SUBJECT_NAME_LENGTH 10
#define DEPT_NAME_LENGTH 20

#define KOR_NUM 1
#define ENG_NUM 2
#define MATH_NUM 3

int main() {
	int scores[NUM_SUBJECTS + 1][MAX_SIZE];
	int stuNum[MAX_SIZE];
	char stuName[MAX_SIZE];
	char deptCode[MAX_SIZE];

	const char deptName[NUM_DEPTS][DEPT_NAME_LENGTH] = { "정보통신과", "기계과", "전기과", "자동차과", "컴퓨터공학과" };
	const char SUBJECT_NAMES[NUM_SUBJECTS][SUBJECT_NAME_LENGTH] = { "국어", "영어", "수학" };

	int len = 0;

	while (1) {
		printf("--------------------------------------------------------------------------\n");
		printf("성적처리 프로그램에 오신 것을 환영합니다.\n원하시는 메뉴를 입력하세요.\n");
		printf("--------------------------------------------------------------------------\n");
		printf(" 1. 전체학생정보출력\n 2. 학과별 평균 조회\n 3. 과목별 평균 조회\n 4. 학생 데이터 추가\n");
		printf(">> ");

		int num;
		scanf("%d", &num);

		switch (num) {
		case 1:
			if (len > 0) {
				printf("전체학생정보출력\n");
				printf("학생번호 학생이니셜       학과명 국어점수 영어점수 수학점수   총점    평균\n");
				printf("--------------------------------------------------------------------------\n");
				for (int i = 0; i < len; i++) {
					int total = 0;
					for (int j = 1; j <= NUM_SUBJECTS; j++) {
						total += scores[j][i];
					}
					double average = (double)total / NUM_SUBJECTS;
					int idx = deptCode[i] - 65;
					printf("%8d %10c %12s %7d %8d %9d %6d %7.2f\n", stuNum[i], stuName[i], deptName[idx], scores[KOR_NUM][i], scores[ENG_NUM][i], scores[MATH_NUM][i], total, average);
				}
				printf("--------------------------------------------------------------------------\n");
				while (1) {
					printf("Q를 입력하여 종료 >> ");
					char input;
					scanf(" %c", &input);
					if (input == 'Q' || input == 'q') break;
				}
			}
			else {
				printf("출력할 데이터가 없습니다.\n");
			}
			break;

		case 2:
			if (len > 0) {
				printf("학과별 평균 조회\n");
				char code;
				scanf(" %c", &code);
				if (code >= 'a' && code <= 'z') {
					code -= 32;  // 대문자로 변환
				}

				int idx = code - 65;
				if (idx <= NUM_DEPTS - 1) {
					double total = 0;
					int cnt = 0;
					for (int i = 0; i < len; i++) {
						if (deptCode[i] == code) {
							int temp = 0;
							for (int j = 1; j <= NUM_SUBJECTS; j++) {
								temp += scores[j][i];
							}
							total += (double)temp / NUM_SUBJECTS;
							cnt++;
						}
					}
					double average = cnt > 0 ? (double)total / cnt : 0;
					printf("%s 총 %d명의 평균은 %.2f입니다.\n", deptName[idx], cnt, average);
				}
				else {
					printf("잘못된 학과코드입니다.\n");
				}
			}
			else {
				printf("출력할 데이터가 없습니다.\n");
			}
			break;

		case 3:
			printf("과목별 평균 조회\n");
			printf("조회하고자 하는 과목번호를 입력하세요 국어 : 1, 영어 : 2, 수학 : 3 >> ");
			int input;
			scanf("%d", &input);
			if (input >= 1 && input <= NUM_SUBJECTS) {
				printf("%s 점수 평균 조회\n", SUBJECT_NAMES[input - 1]);
				int total = 0;
				for (int i = 0; i < len; i++) {
					total += scores[input][i];
				}
				double average = (double)total / len;
				printf("--------------------------------------------------------------------------\n");
				printf("%s 점수 평균은 %.2f입니다.\n", SUBJECT_NAMES[input - 1], average);
			}
			else {
				printf("잘못된 과목번호입니다.\n");
			}
			break;

		case 4:
			printf("학생번호 이름 학과코드 국어점수 영어점수 수학점수를 입력하세요.\n예시: 107 I A 93 55 55\n>> ");
			scanf("%d %c %c %d %d %d", &stuNum[len], &stuName[len], &deptCode[len], &scores[KOR_NUM][len], &scores[ENG_NUM][len], &scores[MATH_NUM][len]);
			if (stuName[len] >= 'a' && stuName[len] <= 'z') {
				stuName[len] -= 32;  // 대문자로 변환
			}
			
			if (deptCode[len] >= 'a' && deptCode[len] <= 'z') {
				deptCode[len] -= 32;  // 대문자로 변환
			}
			len++;
			break;

		default:
			break;
		}
	}

	return 0;
}
