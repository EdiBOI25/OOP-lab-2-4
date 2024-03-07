#include <stdio.h>
#include <stdlib.h>
#include "expense.h"
#include "tests.h"


int main() {
	test_all();
	Expense* e1 = construct_expense(12, 300, "mancare");
	printf("%s\n", e1->type);
	free(e1->type);
	free(e1);
	

	return 0;
}