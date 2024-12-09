#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_USERS 100//最多用户数
#define MAX_LENGTH 50//最大长度

typedef struct {
	char username[MAX_LENGTH];
	char password[MAX_LENGTH];
} User;

User users[MAX_USERS];
int userCount = 0;

//清除缓冲区
void clearBuffer(void) {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void registerUser(void) {
	if (userCount >= MAX_USERS) {
		printf("User limit reached.\n");
		return;
	}

	char username[MAX_LENGTH];
	char password[MAX_LENGTH];

	printf("Enter username: ");
	fgets(username, MAX_LENGTH, stdin);
	// Remove newline character and ensure null terminator
	username[strcspn(username, "\n")] = 0;  

	if (findUserByUsername(username) != -1) {
		printf("Username already exists.\n");
		return;
	}

	printf("Enter password: ");
	fgets(password, MAX_LENGTH, stdin);
	// Remove newline character and ensure null terminator
	password[strcspn(password, "\n")] = 0;  

	strcpy_s(users[userCount].username, MAX_LENGTH, username);
	strcpy_s(users[userCount].password, MAX_LENGTH, password);
	userCount++;

	printf("User registered successfully.\n");
}

int32_t loginUser(void) {
	char username[MAX_LENGTH];
	char password[MAX_LENGTH];

	printf("Enter username: ");
	fgets(username, MAX_LENGTH, stdin);
	username[strcspn(username, "\n")] = 0;  // Remove newline character and ensure null terminator
	clearBuffer();  // Clear buffer to avoid input issues

	printf("Enter password: ");
	fgets(password, MAX_LENGTH, stdin);
	password[strcspn(password, "\n")] = 0;  // Remove newline character and ensure null terminator
	clearBuffer();  // Clear buffer to avoid input issues

	for (int i = 0; i < userCount; i++) {
		if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
			printf("Login successful.\n");
			return true;
		}
	}

	printf("Invalid username or password.\n");
	return false;
}

int32_t findUserByUsername(char* username) {
	for (int i = 0; i < userCount; i++) {
		if (strcmp(users[i].username, username) == 0) {
			return i;
		}
	}
	return -1;
}

//主程序
void register_login(void) {
	int32_t choice;

	printf("1. Register\n2. Login\n3. Exit\n");
	printf("Enter your choice: ");
	scanf_s("%d", &choice);
	clearBuffer();  // Clear buffer to avoid input issues

	switch (choice) {
	case 1:
		registerUser();
		break;
	case 2:
		if (loginUser()) {
			printf("Welcome!\n");
		}
		break;
	case 3:
		break;
	default:
		printf("Invalid choice.\n");
	}

}