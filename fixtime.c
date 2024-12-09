#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define LIMIT_MINUTE 180 //�̶�ʱ��ģʽ�޶�ʱ��

#define u32 uint32_t
#define i32 int32_t

i32 add_sub(void);
i32 mul_div(void);
void save_test_result(char* mode, u32 problem, double score);

/**
* �̶�ʱ��
* 
* Prameters:
* -problem:����
* -right:��ȷ��
* -metering:ͳ����Ч����
* -input:�û�����
* -right_answer:�ش���ȷ����
* -score:����ͳ��
*/
void fixed_time(void) {

	//ģʽ
	static const char mode[] = "fixed time";
	u32 problem = 0;

	u32 right;
	u32 input;
	u32 metering = 0;
	double right_answer = 0.0;
	double score;

	//���������
	i32(*func_array[])() = { add_sub , mul_div };
	srand(time(NULL));

	//��ʱ
	clock_t start;

	start = clock();
	while (true) {

		//��ȷ��
		right = func_array[rand() % 2]();

		//�����
		if (right == -1) {
			continue;
		}

		//����
		problem++;
		scanf_s("%"SCNd32, &input);
		if (right == input) {
			right_answer++;
			printf("��ȷ\n");
		}
		else {
			printf("����\n");
		}

		//��ʱ
		if ((clock() - start) / CLOCKS_PER_SEC >= LIMIT_MINUTE) {
			printf("ʱ�䵽��");
			break;
		}

	}

	score = right_answer * 100.0 / problem * right_answer;
	printf("\n�ɼ���%.1f\n", score);

	save_test_result(mode, problem, score);
	system("pause");
}