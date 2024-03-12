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

/**
 * \brief Sets a new value for day for an expense
 * \param serv the service which has the expenses
 * \param position the position of the expense to edit
 * \param new_day new value of day
 */
void service_set_day(Service* serv, int position, int new_day);

/**
 * \brief Sets a new value for amount for an expense
 * \param serv the service which has the expenses
 * \param position the position of the expense to edit
 * \param new_amount new value of amount
 */
void service_set_amount(Service* serv, int position, int new_amount);

/**
 * \brief Sets a new value for type for an expense
 * \param serv the service which has the expenses
 * \param position the position of the expense to edit
 * \param new_type new value of type
 */
void service_set_type(Service* serv, int position, char* new_type);

/**
 * \brief Deletes the expense at a given position
 * \param serv the service which has the expenses
 * \param position the position of the expense to delete
 */
void service_delete_expense(Service* serv, int position);

/**
 * \brief Filters and prints expenses which match the given type
 * \param serv the service in use
 * \param type the type to filter expenses by
 */
void service_filter_by_type(Service* serv, char* type);
