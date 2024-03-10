#pragma once
#include "repository.h"
#include "expense.h"

typedef struct {
	Repository* repository;
} Service;

/**
 * \brief Creates a service
 * \param repository: the repository that the service will use
 * \return the service
 */
Service* service_construct(Repository* repository);

/**
 * \brief Distructs a service
 * \param service: the service that will be destructed
 */
void service_destruct(Service* service);

/**
 * \brief Adds an expense to the repository
 * \param service: the service that contains the repository
 * \param day: the day of the expense
 * \param amount: the amount of the expense
 * \param type: the type of the expense
 */
void service_add_expense(Service* service, int day, int amount, char* type);
