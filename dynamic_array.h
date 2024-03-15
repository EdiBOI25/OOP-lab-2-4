#pragma once
#include "expense.h"

/**
 * \brief Dynamic array of expenses
 */
typedef struct {
	Expense** expenses;
	int length;
	int capacity;
} DyanimcArray;

/**
 * \brief Initializes an empty dynamic array
 * \return empty dynamic array
 */
DyanimcArray* array_construct();

/**
 * \brief Frees the allocated memory of given dynamic array
 * \param array the array to be deconstructed
 */
void array_destruct(DyanimcArray* array);
