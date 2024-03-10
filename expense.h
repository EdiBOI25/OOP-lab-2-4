#pragma once
// Expense "class"
//	day: int
//	amount: int
//	type: string (char[20])
typedef struct{
	int day;
	int amount;
	char* type;
} Expense;


// Expense "class" constructor
//	day: int
//	amount: int
//	type: string (char[])
//	returns struct Expense
Expense* expense_construct(int day, int amount, char* type);

/**
 * \brief Frees the memory allocated for the expense
 * \param e: Expense* - the expense to be freed
 */
void expense_destruct(Expense* e);

/**
 * \brief Prints an expense
 * \param e: Expense* - the expense to be printed
 */
void print_expense(Expense* e);

/**
 * \brief Checks if the given expense has valid parameters
 * \param e the expense that needs to be validated
 * \return true if the expense is valid, false if contrary
 */
int expense_is_valid(Expense* e);
