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
Expense* construct_expense(int day, int amount, char* type);

/**
 * \brief Frees the memory allocated for the expense
 * \param e: Expense* - the expense to be freed
 */
void destruct_expense(Expense* e);

/**
 * \brief Prints an expense
 * \param e: Expense* - the expense to be printed
 */
void print_expense(Expense* e);
