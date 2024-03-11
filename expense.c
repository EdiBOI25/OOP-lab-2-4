#include "expense.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Expense* expense_construct(int day, int amount, char* type) {
	Expense* e = malloc(sizeof(Expense));
	e->day = day;
	e->amount = amount;
	e->type = malloc((strlen(type) + 1) * sizeof(char));
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
	if (e->type == NULL) {
		return 0;
	}
	if (strlen(e->type) < 3) {
		return 0;
	}
	return 1;
}
