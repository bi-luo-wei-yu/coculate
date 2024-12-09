#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>

#define FILENAME "test_records.txt"
#define  MAX_QUESTIONS 30 //固定题目模式
#define MAX_MINUTE 900 //固定题目模式最大时间
#define LIMIT_MINUTE 180 //固定时间模式限定时间

#define u32 uint32_t
#define i32 int32_t

////计算器主程序
/**
* 加减
*
* Prameters:
* -number1:随机数1
* -number2:随机数2
* -operators[]:运算符们
* -operator:调用运算符
* 
* Returns:
* - -1:无效
* - 其他数：正确答案
*/
i32 add_sub(void) {

	//生成随机数和随机符号
	u32 number1 = rand() % (100 - 0 + 1) + 0;
	u32 number2 = rand() % (100 - 0 + 1) + 0;
	char operators[] = { '+', '-' };//四则运算符定义
	char operator = operators[rand() % 2];//随机调用运算符

	switch (operator) {
	case '+':
		if (number1 + number2 <= 100) {
			printf("请输入结果：%d + %d = ", number1, number2);//提示语
			return number1 + number2;
			break;
		}
		else {
			return -1;//无效//跳过用的
			break;
		}
	case '-':
		if (number1 < number2) {
			return -1;
		}
		else {
			printf("请输入结果：%d - %d = ", number1, number2);//提示语
			return number1 - number2;
		}
	default:
		return -1;//无效
		break;
	}
}
/**
* 乘除
*
* Prameters:
* -number1:随机数1
* -number2:随机数2
* -operators[]:运算符们
* -operator:调用运算符
*
* Returns:
* - -1:无效
* - 其他数：正确答案
*/
i32 mul_div(void) {

	//生成随机数和随机符号
	u32 number2 = rand() % 10 + 1;//1-10
	u32 number1 = rand() % ((10 - 0 + 1) + 0) * number2;

	char operators[] = { '*', '/' };//四则运算符定义
	char operator = operators[rand() % 2];//随机调用运算符


	switch (operator) {
	case '*':
		if (number1 <= 100) {
			printf("请输入结果：%d x %d = ", number1 / number2, number2);//提示语
			return number1;
			break;
		}
		else {
			return -1;//无效
			break;
		}
	case '/':
		if (number1 <= 100) {
			printf("请输入结果：%d / %d = ", number1, number2);//提示语
			return number1 / number2;
			break;
		}
		else {
			return -1;//无效
			break;
		}
	default:
		return -1;//无效
		break;
	}
}