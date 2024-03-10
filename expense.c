#include "expense.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Expense* construct_expense(int day, int amount, char* type) {
	Expense* e = malloc(sizeof(Expense));
	e->day = day;
	e->amount = amount;
	e->type = malloc((strlen(type) + 1) * sizeof(char));
	strcpy(e->type, type);
	return e;
}

void destruct_expense(Expense *e) {
	//print_expense(e);
	//printf("expense.c: destructing expense with amount %d\n", e->amount);
	if (e == NULL) {
		return;
	}
	free(e->type);
	//e->type = NULL;
	//printf("expense.c: destructed type for amount %d\n", e->amount);
	free(e);
	printf("expense.c: destructed expense\n");
}

void print_expense(Expense* e) {
	printf("Day: %d, Amount: %d, Type: %s\n",
		e->day, e->amount, e->type);
}
