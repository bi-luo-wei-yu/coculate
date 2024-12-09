#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>

#define FILENAME "test_records.txt"

#define u32 uint32_t

//// ������Խ�����ļ�
void save_test_result(char* mode, u32 problem, double score) {

	//��ȡ��ǰʱ���
	time_t now = time(NULL);

	//ת���ɱ���ʱ��
	struct tm local_time;
	localtime_s(&local_time, &now);

	char local_time_str[80];
	strftime(local_time_str, sizeof(local_time_str), "%Y-%m-%d %H:%M:%S", &local_time);

	//�洢����
	FILE* file = fopen(FILENAME, "a");
	if (file) {
		fprintf(file, "date: %s", local_time_str);
		fprintf(file, "\tmode: %s", mode);
		fprintf(file, "\tproblem number: %u", problem);
		fprintf(file, "\tscore: %.1lf\n", score);
		fclose(file);
	}
	else {
		printf("�޷����ļ���������\n");
	}
}