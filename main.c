#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

#define u32 uint32_t

//�ⲿ��������
void register_login(void);//���û�
void process_bar(void);//������
void fixed_problem(void);//�̶���Ŀ
void fixed_time(void);//�̶�ʱ��

int main(void)
{
	register_login();
	system("cls");
	u32 choice;

	do
	{
		//��ʾ�˵�
		puts("****���˵�****");
		puts("1���̶���Ŀ����������ʱ������1000�֣�");
		puts("2���̶�ʱ������������������������ޣ�");
		puts("3���˳�");
		puts("��ѡ��һ��ѡ��:");
		scanf_s("%"SCNu32, &choice);

		//�����û���ѡ��
		switch (choice) {
		case 1:
			process_bar();
			fixed_problem();
			system("cls");
			puts("��Ϸ�Ѿ����꣬�������˵�����ѡ��");
			break;
		case 2:
			process_bar();
			fixed_time();
			system("cls");
			puts("��Ϸ�Ѿ����꣬�������˵�����ѡ��");
			break;
		case 3:
			puts("��л���棬�ټ���");
			break;
		default:
			puts("��Чѡ��������ѡ��");
			break;
		}

	} while (choice != 3);

	system("pause");
	return 0;
}