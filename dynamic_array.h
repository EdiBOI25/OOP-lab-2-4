#pragma once
#include "expense.h"

/**
 * \brief Dynamic array of expenses
 */
typedef struct {
	Expense** expenses;
	int length;
	int capacity;
} DynamicArray;

/**
 * \brief Initializes an empty dynamic array
 * \param capacity the capacity of the array to be initialised with
 * \return empty dynamic array
 */
DynamicArray* array_construct(int capacity);

/**
 * \brief Frees the allocated memory of given dynamic array
 * \param array the array to be deconstructed
 */
void array_destruct(DynamicArray* array);

/**
 * \brief Adds an expense to the array
 * \param array the dynamic array to which the expense will be added
 * \param e the expense to add
 */
void array_add_expense(DynamicArray* array, Expense* e);

/**
 * \brief Allocates more memory for an array
 * \param array the array to be resized
 * \return resized array
 */
void array_resize(DynamicArray* array);

/**
 * \brief Returns the expense found at given position
 * \param array the array in which to search for expense
 * \param position the position to search for
 * \return expense at given position | NULL if not found
 */
Expense* array_get_expense(DynamicArray* array, int position);

/**
 * \brief Returns the list of expenses
 * \param array the array to get expenses from
 * \return list of expenses
 */
Expense** array_get_all(DynamicArray* array);

/**
 * \brief Deletes the expense found at a given position
 * \param array the array to delete the expense from
 * \param position the position of the expense to delete
 */
void array_delete_expense(DynamicArray* array, int position);

/**
 * \brief Returns a deep copy of given array
 * \param source_array the array whose contents will be copied
 * \return deep copy of source_array
 */
DynamicArray* array_deep_copy(DynamicArray* source_array);
