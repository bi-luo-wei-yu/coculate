/**
*前言:
*基本要求完成于11.24
*12.8完成了一个看起来可以用的多用户：）还没太学会存储
*这么晚提交的根本原因是提交github时由于不会操作导致项目被删，很多更改没了TAT
*曾经误打误撞提交上去过，但更新后不会了，新版本查到的攻略都不行TAT
* 
* Notes:
* -结构体没完全学完:0学长凑合看吧
* -有一两个项目没写完函数注释（没时间完全恢复了TAT)
* -多用户和进度条都是模拟的
* -关于整型变量：采用<stdint.h>
*/
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