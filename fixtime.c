#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define LIMIT_MINUTE 180 //固定时间模式限定时间

#define u32 uint32_t
#define i32 int32_t

i32 add_sub(void);
i32 mul_div(void);
void save_test_result(char* mode, u32 problem, double score);

/**
* 固定时间
* 
* Prameters:
* -problem:题数
* -right:正确答案
* -metering:统计有效题数
* -input:用户输入
* -right_answer:回答正确题数
* -score:分数统计
*/
void fixed_time(void) {

	//模式
	static const char mode[] = "fixed time";
	u32 problem = 0;

	u32 right;
	u32 input;
	u32 metering = 0;
	double right_answer = 0.0;
	double score;

	//随机数生成
	i32(*func_array[])() = { add_sub , mul_div };
	srand(time(NULL));

	//计时
	clock_t start;

	start = clock();
	while (true) {

		//正确答案
		right = func_array[rand() % 2]();

		//卫语句
		if (right == -1) {
			continue;
		}

		//输入
		problem++;
		scanf_s("%"SCNd32, &input);
		if (right == input) {
			right_answer++;
			printf("正确\n");
		}
		else {
			printf("错误\n");
		}

		//限时
		if ((clock() - start) / CLOCKS_PER_SEC >= LIMIT_MINUTE) {
			printf("时间到！");
			break;
		}

	}

	score = right_answer * 100.0 / problem * right_answer;
	printf("\n成绩：%.1f\n", score);

	save_test_result(mode, problem, score);
	system("pause");
}