#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <time.h>
#include <stdlib.h>

#define  MAX_QUESTIONS 30 //�̶���Ŀģʽ
#define MAX_MINUTE 900 //�̶���Ŀģʽ���ʱ��

#define u32 uint32_t
#define i32 int32_t

i32 add_sub(void);
i32 mul_div(void);
void save_test_result(char* mode, u32 problem, double score);

/**
* �̶���Ŀ
*
* Prameters:
* -problem:����
* -right:��ȷ��
* -metering:ͳ����Ч����
* -input:�û�����
* -right_answer:�ش���ȷ����
* -score:����ͳ��
*/
void fixed_problem(void) {
	//ģʽ
	static const char mode[] = "fixed problem";
	u32 problem = MAX_QUESTIONS;

	u32 right;
	u32 input;
	u32 metering = 1;
	double right_answer = 0.0;
	double score;

	//���������
	i32(*func_array[])() = { add_sub , mul_div };
	srand(time(NULL));

	//��ʱ
	clock_t start, end;
	double time_spent;

	start = clock();
	while (metering <= MAX_QUESTIONS) {

		//��ȷ��
		right = func_array[rand() % 2]();

		//����䣬��Ч�������
		if (right == -1) {
			continue;
		}

		//����
		scanf_s("%"SCNd32 , &input);
		if (right == input) {
			right_answer++;
			printf("��ȷ\n");
		}
		else {
			printf("����\n");
		}

		metering++;//�ƴ�

		//��ʱ
		if ((clock() - start) / CLOCKS_PER_SEC >= MAX_MINUTE) {
			printf("ʱ�䵽��");
			break;
		}
	}
	end = clock();
	time_spent = (end - start) / CLOCKS_PER_SEC;

	score = right_answer * 100.0 / MAX_QUESTIONS + (MAX_MINUTE - time_spent);
	printf("\n�ɼ���%.1f\n", score);

	save_test_result(mode, problem, score);
	system("pause");
}