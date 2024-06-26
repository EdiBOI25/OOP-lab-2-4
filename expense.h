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


// Expense constructor
//	day: int
//	amount: int
//	type: string (char[])
//	returns struct Expense
Expense* expense_construct(const int day, const int amount, const char* type);

/**
 * \brief Frees the memory allocated for the expense
 * \param e: Expense* - the expense to be freed
 */
void expense_destruct(Expense* e);

/**
 * \brief Prints an expense
 * \param e: Expense* - the expense to be printed
 */
void print_expense(const Expense* e);

/**
 * \brief Checks if the given expense has valid parameters
 * \param e the expense that needs to be validated
 * \return true if the expense is valid, false if contrary
 */
int expense_is_valid(const Expense* e);

/**
 * \brief Sets a new day for the expense
 * \param e the expense whose day will be modified
 * \param new_day the new day
 */
void expense_set_day(Expense* e, const int new_day);

/**
 * \brief Sets a new amount for the expense
 * \param e the expense whose amount will be modified
 * \param new_amount the new amount
 */
void expense_set_amount(Expense* e, const int new_amount);

/**
 * \brief Sets a new type for the expense
 * \param e the expense whose type will be modified
 * \param new_type the new type
 */
void expense_set_type(Expense* e, const char* new_type);

/**
 * \brief Creates and returns a deep copy of an expense
 * \param source_expense the expense whose contents will be copied
 * \return the deep copy of source expense
 */
Expense* expense_deep_copy(const Expense* source_expense);
