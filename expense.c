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

void destruct_expense(Expense *e) {
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
