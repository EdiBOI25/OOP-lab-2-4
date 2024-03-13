#include "expense.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Expense* expense_construct(int day, int amount, char* type) {
	Expense* e = malloc(sizeof(Expense));
	if (e == NULL) {
		return NULL;
	}
	e->day = day;
	e->amount = amount;
	/*e->type = malloc((strlen(type) + 1));
	if (e->type == NULL) {
		free(e);
		return NULL;
	}*/
	strcpy(e->type, type);
	return e;
}

void expense_destruct(Expense *e) {
	if (e == NULL) {
		return;
	}
	//free(e->type);
	free(e);
}

void print_expense(Expense* e) {
	printf("Day: %d, Amount: %d, Type: %s\n",
		e->day, e->amount, e->type);
}

int expense_is_valid(Expense* e) {
	if (e->day < 1) {
		return 0;
	}
	if (e->day > 31) {
		return 0;
	}
	if (e->amount < 0) {
		return 0;
	}
	/*if (e->type == NULL) {
		return 0;
	}*/
	if (strlen(e->type) < 3) {
		return 0;
	}
	return 1;
}

void expense_set_day(Expense* e, int new_day) {
	e->day = new_day;
}

void expense_set_amount(Expense* e, int new_amount) {
	e->amount = new_amount;
}

void expense_set_type(Expense* e, char* new_type) {
	/*if (new_type == NULL) {
		return;
	}
	free(e->type);
	e->type = malloc((strlen(new_type) + 1));*/
	strcpy(e->type, new_type);
}
