#include "expense.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Expense* expense_construct(const int day, const int amount, const char* type) {
	Expense* e = malloc(sizeof(Expense));
	if (e == NULL) {
		return NULL;
	}

	e->day = day;
	e->amount = amount;
	e->type = malloc((strlen(type) + 1));
	if (e->type == NULL) {
		free(e);
		return NULL;
	}

	strcpy(e->type, type);
	return e;
}

void expense_destruct(Expense *e) {
	if (e == NULL) {
		return;
	}
	free(e->type);
	free(e);
}

void print_expense(const Expense* e) {
	if(e == NULL) {
		return;
	}
	printf("Day: %d, Amount: %d, Type: %s\n",
		e->day, e->amount, e->type);
}

int expense_is_valid(const Expense* e) {
	if (e->day < 1 || e->day > 31) {
		printf("Invalid day: must be between 1 and 31.\n");
		return 0;
	}
	if (e->amount < 0) {
		printf("Invalid amount: must be positive integer.\n");
		return 0;
	}
	if (e->type == NULL) {
		return 0;
	}
	if (strlen(e->type) < 3) {
		printf("Invalid type: must have at least 3 characters.\n");
		return 0;
	}
	return 1;
}

void expense_set_day(Expense* e, const int new_day) {
	e->day = new_day;
}

void expense_set_amount(Expense* e, const int new_amount) {
	e->amount = new_amount;
}

void expense_set_type(Expense* e, const char* new_type) {
	if (new_type == NULL) {
		return;
	}
	free(e->type);
	e->type = malloc((strlen(new_type) + 1));
	if(e->type == NULL) {
		return;
	}
	strcpy(e->type, new_type);
}

Expense* expense_deep_copy(const Expense* source_expense) {
	return expense_construct(source_expense->day, source_expense->amount, source_expense->type);
}
