#pragma once
#include "expense.h"

// Dynamic array of expenses
typedef struct {
	Expense* expenses;
	int length;
	int capacity;
} Repository;


/**
 * \brief Initializes an empty repository
 * \return empty repository
 */
Repository* construct_repository();

/**
 * \brief Frees the memory allocated for the repository
 * \param repo: Repository* - the repository to be freed
 */
void destruct_repository(Repository* repo);

/**
 * \brief Adds an expense to the repository
 * \param repo: Repository* - the repository to which the expense will be added
 * \param e: Expense* - the expense to be added
 */
void add_expense(Repository* repo, Expense* e);

/**
 * \brief Allocates more memory for the repository
 * \param repo: Repository* - the repository for which more memory will be allocated
 */
void resize(Repository* repo);

/**
 * \brief Returns the expense found at given position
 * \param repo: Repository* - the repository in which we search
 * \param position: int >= 0 - the position of the expense in repository
 * \return expense at given position
 */
Expense* get_expense(Repository* repo, int position);

