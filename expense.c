#include "expense.h"
#include <string.h>

struct Expense Expense(int day, int amount, char type[20]) {
	struct Expense e;
	e.day = day;
	e.amount = amount;
	strcpy(e.type, type);
	return e;
}
