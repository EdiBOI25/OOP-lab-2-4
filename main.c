#include <stdio.h>
#include <stdlib.h> // pt alocare dinamica
#include <assert.h> // pt teste
// assert(expresie); | ex: assert(cmmdc(3, 7) == 1);

#include "expense.h"


int main() {
	struct Expense e = Expense(30, 20, "mancare");
	printf("amount: %d, day: %d, type: %s", e.amount, e.day, e.type);

	return 0;
}