#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>

#define FILENAME "test_records.txt"
#define  MAX_QUESTIONS 30 //�̶���Ŀģʽ
#define MAX_MINUTE 900 //�̶���Ŀģʽ���ʱ��
#define LIMIT_MINUTE 180 //�̶�ʱ��ģʽ�޶�ʱ��

#define u32 uint32_t
#define i32 int32_t

////������������
/**
* �Ӽ�
*
* Prameters:
* -number1:�����1
* -number2:�����2
* -operators[]:�������
* -operator:���������
* 
* Returns:
* - -1:��Ч
* - ����������ȷ��
*/
i32 add_sub(void) {

	//������������������
	u32 number1 = rand() % (100 - 0 + 1) + 0;
	u32 number2 = rand() % (100 - 0 + 1) + 0;
	char operators[] = { '+', '-' };//�������������
	char operator = operators[rand() % 2];//������������

	switch (operator) {
	case '+':
		if (number1 + number2 <= 100) {
			printf("����������%d + %d = ", number1, number2);//��ʾ��
			return number1 + number2;
			break;
		}
		else {
			return -1;//��Ч//�����õ�
			break;
		}
	case '-':
		if (number1 < number2) {
			return -1;
		}
		else {
			printf("����������%d - %d = ", number1, number2);//��ʾ��
			return number1 - number2;
		}
	default:
		return -1;//��Ч
		break;
	}
}
/**
* �˳�
*
* Prameters:
* -number1:�����1
* -number2:�����2
* -operators[]:�������
* -operator:���������
*
* Returns:
* - -1:��Ч
* - ����������ȷ��
*/
i32 mul_div(void) {

	//������������������
	u32 number2 = rand() % 10 + 1;//1-10
	u32 number1 = rand() % ((10 - 0 + 1) + 0) * number2;

	char operators[] = { '*', '/' };//�������������
	char operator = operators[rand() % 2];//������������


	switch (operator) {
	case '*':
		if (number1 <= 100) {
			printf("����������%d x %d = ", number1 / number2, number2);//��ʾ��
			return number1;
			break;
		}
		else {
			return -1;//��Ч
			break;
		}
	case '/':
		if (number1 <= 100) {
			printf("����������%d / %d = ", number1, number2);//��ʾ��
			return number1 / number2;
			break;
		}
		else {
			return -1;//��Ч
			break;
		}
	default:
		return -1;//��Ч
		break;
	}
}