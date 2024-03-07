#include <stdio.h>
#include <stdlib.h>


#include "expense.h"
#include "tests.h"


int main() {
	TestAll();
	Expense* e1 = ConstructExpense(12, 300, "mancare");
	printf("%s\n", e1->type);
	free(e1->type);
	free(e1);
	

	return 0;
}