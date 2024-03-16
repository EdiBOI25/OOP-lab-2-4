#include "UI.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

UI* ui_construct(Service* service) {
	UI* ui = malloc(sizeof(UI));
	if (ui == NULL) {
		return NULL;
	}
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
	for (int i = 0; i < 10; ++i) {
		service_add_expense(ui->service, i+1, i*100, "default");
	}

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
		case 2:
			ui_edit_expense(ui);
			break;
		case 3:
			ui_delete_expense(ui);
			break;
		case 4:
			ui_filter_expense(ui);
			break;
		case 5:
			ui_sort_expense(ui);
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
}

void ui_print_all_expenses(UI* ui) {
	//repository_print_all(ui->service->repository);
	for (int i = 0; i < ui->service->list->length; ++i) {
		printf("%d: ", i);
		print_expense(ui->service->list->expenses[i]);
	}
	printf("\n");
}

void ui_edit_expense(UI* ui) {
	ui_print_all_expenses(ui);
	printf("Choose the number of the expense you want to edit: ");
	int position;
	scanf("%d", &position);
	if (position >= ui->service->list->length || position < 0) {
		printf("Invalid position.");
		return;
	}
	printf("Choose the parameter you want to edit (day/amount/type): ");
	char param[10];
	scanf("%s", param);
	if (strcmp(param, "day") == 0) {
		int day;
		printf("Enter new value for day: ");
		scanf("%d", &day);
		service_set_day(ui->service, position, day);
	}
	else if (strcmp(param, "amount") == 0) {
		int amount;
		printf("Enter new value for amount: ");
		scanf("%d", &amount);
		service_set_amount(ui->service, position, amount);
	}
	else if (strcmp(param, "type") == 0) {
		char* type[50];
		printf("Enter new value for type: ");
		scanf("%s", type);
		service_set_type(ui->service, position, type);
	}
	else {
		printf("Invalid parameter name.\n");
	}
}

void ui_delete_expense(UI* ui) {
	ui_print_all_expenses(ui);
	printf("Choose the number of the expense you want to delete: ");
	int position;
	scanf("%d", &position);
	if (position >= ui->service->list->length || position < 0) {
		printf("Invalid position.");
		return;
	}
	service_delete_expense(ui->service, position);
}

void ui_filter_expense(UI* ui) {
	char* filter[50];
	printf("Choose the parameter you want to filter by (day/amount/type): ");
	scanf("%s", filter);
	if (strcmp(filter, "day") == 0) {
		int day;
		printf("Enter value for day: ");
		scanf("%d", &day);
		printf("Filtering by day...\n");
	}
	else if (strcmp(filter, "amount") == 0) {
		int amount;
		printf("Enter new for amount: ");
		scanf("%d", &amount);
		printf("Filtering by amount...\n");
	}
	else if (strcmp(filter, "type") == 0) {
		char* type[50];
		printf("Enter value for type: ");
		scanf("%s", type);
		service_filter(ui->service, filter, type);
	}
	else {
		printf("Invalid filter.\n");
	}
}

void ui_sort_expense(UI* ui) {
	printf("Choose parameter to sort by (amount/type): ");
	char* param[50];
	scanf("%s", param);
	printf("Choose if sorting should be in reverse order (1 or 0): ");
	int reverse;
	scanf("%d", &reverse);
	if (strcmp(param, "amount") == 0) {
		service_sort_by_amount(ui->service, reverse);
	}
	else if (strcmp(param, "type") == 0) {
		service_sort_by_type(ui->service, reverse);
	}
	else {
		printf("Invalid parameter.\n");
	}
}
