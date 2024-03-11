#include "UI.h"

#include <stdlib.h>
#include <stdio.h>

UI* ui_construct(Service* service) {
	UI* ui = malloc(sizeof(UI));
	ui->service = service;
	return ui;
}

void ui_destruct(UI* ui) {
	if (ui == NULL) {
		return;
	}
	free(ui);
}

void ui_run(UI* ui) {
	char main_menu[] = "EXPENSES MENU\n"
		"1. Add expense\n"
		"2. Edit expense\n"
		"3. Delete expense\n"
		"4. Filter expenses\n"
		"5. Sort expenses\n"
		"9. Print all expenses\n"
		"0. Exit app\n";

	while(1) {
		printf("%s\n", main_menu);
		int option;
		printf("Choose an option: ");
		scanf("%d", &option);

		switch (option) {
		case 0:
			printf("Bye bye!\n");
			return;
		case 1:
			ui_add_expense(ui);
			break;
		case 9:
			ui_print_all_expenses(ui);
			break;
		default:
			printf("Invalid option.\n");
		}
	}
}


void ui_add_expense(UI* ui) {
	int day, amount;
	char type[30];
	printf("Enter day: ");
	scanf("%d", &day);
	printf("Enter amount: ");
	scanf("%d", &amount);
	printf("Enter type: ");
	scanf("%s", type);
	service_add_expense(ui->service, day, amount, type);
	printf("Expense added successfully!\n");
}

void ui_print_all_expenses(UI* ui) {
	repository_print_all(ui->service->repository);
}
