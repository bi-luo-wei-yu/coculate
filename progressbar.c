#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <Windows.h>

#define u32 uint32_t

/**
* progressbar
* 
* Parameters:
* -total_steps:进度条长度
*/
void process_bar(void) {
	system("cls");
	const u32 total_steps = 100;

	puts("游戏加载中，请稍后：");

	for (u32 i = 0; i <= total_steps; i++) {
		printf("\r[");

		//打印进度条的完整部分
		for (u32 j = 0; j < i; j++) {
			printf("#");
		}
		for (u32 j = i; j < total_steps; j++) {
			printf(" ");
		}

		printf("]%"PRIu32"%%", (i * 100) / total_steps);
		//实际：（已经传输的数据量/文件总大小）* %100

		fflush(stdout);//确保进度条即时显示
		Sleep(100);//模拟
	}

	system("cls");
	puts("加载完成,游戏开始！");
}