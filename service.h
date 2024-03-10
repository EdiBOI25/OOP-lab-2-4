#pragma once
#include "repository.h"
#include "expense.h"

typedef struct {
	int n;
	//Repository* repository = repository_construct();
} Service;

/**
 * \brief Adds an expense to the repository
 * \param service: the service that contains the repository
 * \param day: the day of the expense
 * \param amount: the amount of the expense
 * \param type: the type of the expense
 */
void add_expense(Service* service, int day, int amount, char* type);
