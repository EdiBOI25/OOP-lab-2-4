#include <stdio.h>
#include <stdlib.h>
#include "expense.h"
#include "tests.h"


int main() {
	test_all();
	Expense* e = construct_expense(12, 300, "mancare");
	destruct_expense(e);

	return 0;
}