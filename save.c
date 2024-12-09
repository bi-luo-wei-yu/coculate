#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>

#define FILENAME "test_records.txt"

#define u32 uint32_t

//// 保存测试结果到文件
void save_test_result(char* mode, u32 problem, double score) {

	//获取当前时间戳
	time_t now = time(NULL);

	//转换成本地时间
	struct tm local_time;
	localtime_s(&local_time, &now);

	char local_time_str[80];
	strftime(local_time_str, sizeof(local_time_str), "%Y-%m-%d %H:%M:%S", &local_time);

	//存储数据
	FILE* file = fopen(FILENAME, "a");
	if (file) {
		fprintf(file, "date: %s", local_time_str);
		fprintf(file, "\tmode: %s", mode);
		fprintf(file, "\tproblem number: %u", problem);
		fprintf(file, "\tscore: %.1lf\n", score);
		fclose(file);
	}
	else {
		printf("无法打开文件保存结果。\n");
	}
}