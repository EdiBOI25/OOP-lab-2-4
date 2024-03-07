#include "expense.h"
#include <string.h>

Expense* ConstructExpense(int day, int amount, char* type) {
	Expense* e = malloc(sizeof(Expense));
	if (e == NULL) {
		return NULL;
	}
	e->day = day;
	e->amount = amount;
	e->type = malloc(strlen(type) + 1);
	if (e->type == NULL) {
		return NULL;
	}
	strcpy(e->type, type);
	return NULL;
}
