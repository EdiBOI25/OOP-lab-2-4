#pragma once
#include "expense.h"

// Dynamic array of expenses
typedef struct {
	Expense* expenses[50];
	int length;
	int capacity;
} Repository;


/**
 * \brief Initializes an empty repository
 * \return empty repository
 */
Repository* repository_construct();

/**
 * \brief Frees the memory allocated for the repository
 * \param repo: Repository* - the repository to be freed
 */
void repository_destruct(Repository* repo);

/**
 * \brief Adds an expense to the repository
 * \param repo: Repository* - the repository to which the expense will be added
 * \param e: Expense* - the expense to be added
 */
void repository_add_expense(Repository* repo, Expense* e);

/**
 * \brief Allocates more memory for the repository
 * \param repo: Repository* - the repository for which more memory will be allocated
 */
void repository_resize(Repository* repo);

/**
 * \brief Returns the expense found at given position
 * \param repo: Repository* - the repository in which we search
 * \param position: int >= 0 - the position of the expense in repository
 * \return expense at given position
 */
Expense* repository_get_expense(Repository* repo, int position);

/**
 * \brief Returns the list of expenses
 * \param repo: the repository which has the list of expenses
 * \return list of expenses
 */
Expense** repository_get_all(Repository* repo);

/**
 * \brief Prints all expenses stored in the repository
 * \param repo the repository that contains all the expenses
 */
void repository_print_all(Repository* repo);

/**
 * \brief Sets a new value for day for an expense
 * \param repo the repository which has the expenses
 * \param position the position of the expense to edit
 * \param new_day new value of day
 */
void repository_set_day(Repository* repo, int position, int new_day);

/**
 * \brief Sets a new value for amount for an expense
 * \param repo the repository which has the expenses
 * \param position the position of the expense to edit
 * \param new_amount new value of amount
 */
void repository_set_amount(Repository* repo, int position, int new_amount);

/**
 * \brief Sets a new value for type for an expense
 * \param repo the repository which has the expenses
 * \param position the position of the expense to edit
 * \param new_type new value of type
 */
void repository_set_type(Repository* repo, int position, char* new_type);

/**
 * \brief Deletes the expense at a given position
 * \param repo the repository which has the expenses
 * \param position the position of the expense to remove
 */
void repository_delete_expense(Repository* repo, int position);
