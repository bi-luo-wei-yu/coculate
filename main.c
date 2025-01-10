#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

#define u32 uint32_t

//外部函数声明
void register_login(void);//多用户
void process_bar(void);//进度条
void fixed_problem(void);//固定题目
void fixed_time(void);//固定时间

int main(void)
{
	register_login();
	system("cls");
	u32 choice;

	do
	{
		//显示菜单
		puts("****主菜单****");
		puts("1、固定题目数量计算用时（满分1000分）");
		puts("2、固定时间计算做题数量（满分无上限）");
		puts("3、退出");
		puts("请选择一个选项:");
		scanf_s("%"SCNu32, &choice);

		//处理用户的选择
		switch (choice) {
		case 1:
			process_bar();
			fixed_problem();
			system("cls");
			puts("游戏已经玩完，返回主菜单重新选择");
			break;
		case 2:
			process_bar();
			fixed_time();
			system("cls");
			puts("游戏已经玩完，返回主菜单重新选择");
			break;
		case 3:
			puts("感谢游玩，再见！");
			break;
		default:
			puts("无效选择，请重新选择！");
			break;
		}

	} while (choice != 3);

	system("pause");
	return 0;
}