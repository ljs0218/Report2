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

	const char deptName[NUM_DEPTS][DEPT_NAME_LENGTH] = { "������Ű�", "����", "�����", "�ڵ�����", "��ǻ�Ͱ��а�" };
	const char SUBJECT_NAMES[NUM_SUBJECTS][SUBJECT_NAME_LENGTH] = { "����", "����", "����" };

	int len = 0;

	while (1) {
		printf("--------------------------------------------------------------------------\n");
		printf("����ó�� ���α׷��� ���� ���� ȯ���մϴ�.\n���Ͻô� �޴��� �Է��ϼ���.\n");
		printf("--------------------------------------------------------------------------\n");
		printf(" 1. ��ü�л��������\n 2. �а��� ��� ��ȸ\n 3. ���� ��� ��ȸ\n 4. �л� ������ �߰�\n");
		printf(">> ");

		int num;
		scanf("%d", &num);

		switch (num) {
		case 1:
			if (len > 0) {
				printf("��ü�л��������\n");
				printf("�л���ȣ �л��̴ϼ�       �а��� �������� �������� ��������   ����    ���\n");
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
					printf("Q�� �Է��Ͽ� ���� >> ");
					char input;
					scanf(" %c", &input);
					if (input == 'Q' || input == 'q') break;
				}
			}
			else {
				printf("����� �����Ͱ� �����ϴ�.\n");
			}
			break;

		case 2:
			if (len > 0) {
				printf("�а��� ��� ��ȸ\n");
				char code;
				scanf(" %c", &code);
				if (code >= 'a' && code <= 'z') {
					code -= 32;  // �빮�ڷ� ��ȯ
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
					printf("%s �� %d���� ����� %.2f�Դϴ�.\n", deptName[idx], cnt, average);
				}
				else {
					printf("�߸��� �а��ڵ��Դϴ�.\n");
				}
			}
			else {
				printf("����� �����Ͱ� �����ϴ�.\n");
			}
			break;

		case 3:
			printf("���� ��� ��ȸ\n");
			printf("��ȸ�ϰ��� �ϴ� �����ȣ�� �Է��ϼ��� ���� : 1, ���� : 2, ���� : 3 >> ");
			int input;
			scanf("%d", &input);
			if (input >= 1 && input <= NUM_SUBJECTS) {
				printf("%s ���� ��� ��ȸ\n", SUBJECT_NAMES[input - 1]);
				int total = 0;
				for (int i = 0; i < len; i++) {
					total += scores[input][i];
				}
				double average = (double)total / len;
				printf("--------------------------------------------------------------------------\n");
				printf("%s ���� ����� %.2f�Դϴ�.\n", SUBJECT_NAMES[input - 1], average);
			}
			else {
				printf("�߸��� �����ȣ�Դϴ�.\n");
			}
			break;

		case 4:
			printf("�л���ȣ �̸� �а��ڵ� �������� �������� ���������� �Է��ϼ���.\n����: 107 I A 93 55 55\n>> ");
			scanf("%d %c %c %d %d %d", &stuNum[len], &stuName[len], &deptCode[len], &scores[KOR_NUM][len], &scores[ENG_NUM][len], &scores[MATH_NUM][len]);
			if (stuName[len] >= 'a' && stuName[len] <= 'z') {
				stuName[len] -= 32;  // �빮�ڷ� ��ȯ
			}
			
			if (deptCode[len] >= 'a' && deptCode[len] <= 'z') {
				deptCode[len] -= 32;  // �빮�ڷ� ��ȯ
			}
			len++;
			break;

		default:
			break;
		}
	}

	return 0;
}
