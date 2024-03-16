#pragma once
#include "dynamic_array.h"
#include "expense.h"

typedef struct {
	DynamicArray* list;
} Service;

/**
 * \brief Creates a service
 * \param list the list of expenses that the service will use
 * \return the service
 */
Service* service_construct(DynamicArray* list);

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
 * \brief Filters and prints expenses which match the given parameters
 * \param serv the service in use
 * \param parameter the parameter to filter by (must be day, amount or type)
 * \param key the key to filter by (ex: 30, 2000, food)
 * \return list with filtered expenses
 */
DynamicArray* service_filter(Service* serv, char* parameter, void* key);

/**
 * \brief Sorts and prints the expenses by amount
 * \param serv the service in use
 * \param reverse 1 if sorting should be in reverse order, 0 if contrary
 */
void service_sort_by_amount(Service* serv, int reverse);

/**
 * \brief Sorts and prints the expenses by type
 * \param serv the service in use
 * \param reverse 1 if sorting should be in reverse order, 0 if contrary
 */
void service_sort_by_type(Service* serv, int reverse);
