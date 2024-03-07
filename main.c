#include <stdio.h>


#include "expense.h"
#include "tests.h"


int main() {
	TestAll();
	Expense* e1 = ConstructExpense(12, 300, "mancare");

	return 0;
}