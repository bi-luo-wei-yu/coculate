#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <Windows.h>

#define u32 uint32_t

/**
* progressbar
* 
* Parameters:
* -total_steps:����������
*/
void process_bar(void) {
	system("cls");
	const u32 total_steps = 100;

	puts("��Ϸ�����У����Ժ�");

	for (u32 i = 0; i <= total_steps; i++) {
		printf("\r[");

		//��ӡ����������������
		for (u32 j = 0; j < i; j++) {
			printf("#");
		}
		for (u32 j = i; j < total_steps; j++) {
			printf(" ");
		}

		printf("]%"PRIu32"%%", (i * 100) / total_steps);
		//ʵ�ʣ����Ѿ������������/�ļ��ܴ�С��* %100

		fflush(stdout);//ȷ����������ʱ��ʾ
		Sleep(100);//ģ��
	}

	system("cls");
	puts("�������,��Ϸ��ʼ��");
}