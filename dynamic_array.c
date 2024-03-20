#include "dynamic_array.h"

#include <stdio.h>
#include <stdlib.h>


DynamicArray* array_construct(int capacity) {
	DynamicArray* array = malloc(sizeof(DynamicArray));
	if(array == NULL) {
		return NULL;
	}

	array->expenses = malloc(capacity * sizeof(Expense));
	if (array->expenses == NULL) {
		free(array);
		return NULL;
	}
	array->length = 0;
	array->capacity = capacity;

	return array;
}

void array_destruct(DynamicArray* array) {
	if (array == NULL) {
		return;
	}
	for (int i = array->length - 1; i >= 0; i--) {
		expense_destruct(array->expenses[i]);
	}
	free(array->expenses);
	free(array);
}

void array_add_expense(DynamicArray* array, Expense* e) {
	if(array == NULL) {
		return;
	}
	if(e == NULL) {
		return;
	}
	if (array->length == array->capacity) {
		array_resize(array);
	}
	array->expenses[array->length] = e;
	array->length++;
}

void array_resize(DynamicArray* array) {
	int new_capacity = array->capacity * 2;
	Expense** new_expenses = malloc(new_capacity * sizeof(Expense));
	if (new_expenses == NULL) {
		return;
	}
	for (int i = 0; i < array->length; ++i) {
		new_expenses[i] = array->expenses[i];
	}
	free(array->expenses);
	array->capacity = new_capacity;
	array->expenses = new_expenses;
}

DynamicArray* array_deep_copy(DynamicArray* source_array) {
	DynamicArray* destination_array = array_construct(source_array->capacity);

	if (destination_array == NULL || source_array == NULL) {
		return NULL;
	}
	for(int i = 0; i < source_array->length; ++i) {
		destination_array->expenses[i] = expense_deep_copy(source_array->expenses[i]);
	}
	destination_array->length = source_array->length;

	return destination_array;
}

Expense* array_get_expense(DynamicArray* array, int position) {
	if (position < 0 || position > array->length) {
		return NULL;
	}
	return array->expenses[position];
}

Expense** array_get_all(DynamicArray* array) {
	return array->expenses;
}

void array_delete_expense(DynamicArray* array, int position) {
	if (array == NULL) {
		return;
	}
	if (position < 0 || position >= array->length) {
		return;
	}
	expense_destruct(array->expenses[position]);
	for (int i = position; i < array->length - 1; ++i) {
		array->expenses[i] = array->expenses[i + 1];
	}
	array->length--;
}

void array_print(DynamicArray* array) {
	if (array == NULL) {
		return;
	}
	for(int i = 0; i < array->length; ++i) {
		printf("%d: ", i);
		print_expense(array->expenses[i]);
	}
}
