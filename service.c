#include <stdlib.h>
#include "service.h"

#include <stdio.h>
#include <string.h>

#include "dynamic_array.h"
#include "expense.h"

Service* service_construct(DynamicArray* list) {
	if (list == NULL) {
		return NULL;
	}
	Service* service = malloc(sizeof(Service));
	service->list = list;
	return service;
}

void service_destruct(Service* service) {
	if (service == NULL) {
		return;
	}
	free(service);
}

void service_add_expense(Service* service, int day, int amount, char* type) {
	Expense* expense = expense_construct(day, amount, type);
	if (expense_is_valid(expense) == 0) {
		return;
	}
	array_add_expense(service->list, expense);
}

void service_set_day(Service* serv, int position, int new_day) {
	if (serv == NULL) {
		return;
	}
	if (position < 0 || position >= serv->list->length) {
		return;
	}
	if (new_day < 1 || new_day > 31) {
		return;
	}
	//repository_set_day(serv->repository, position, new_day);
	serv->list->expenses[position]->day = new_day;
}

void service_set_amount(Service* serv, int position, int new_amount) {
	if (serv == NULL) {
		return;
	}
	if (position < 0 || position >= serv->list->length) {
		return;
	}
	if (new_amount < 0) {
		return;
	}
	//repository_set_amount(serv->repository, position, new_amount);
	serv->list->expenses[position]->amount = new_amount;
}

void service_set_type(Service* serv, int position, char* new_type) {
	if (serv == NULL) {
		return;
	}
	if (position < 0 || position >= serv->list->length) {
		return;
	}
	if (new_type == NULL) {
		return;
	}
	if (strlen(new_type) < 3) {
		return;
	}
	strcpy(serv->list->expenses[position]->type, new_type);
}

void service_delete_expense(Service* serv, int position) {
	if (serv == NULL) {
		return;
	}
	array_delete_expense(serv->list, position);
}

int compare_int(const void* a, const void* b) {
	return a == b;
}

int compare_string(const void* a, const void* b) {
	return strcmp(a, b) == 0;
}

int compare(const void* el1, const void* el2, int (*method)(const void* a, const void* b)) {
	return method(el1, el2);
}

DynamicArray* service_filter(Service* serv, char* parameter, void* key) {
	if (serv == NULL || parameter == NULL || key == NULL) {
		return NULL;
	}
	void* (*getter)(void* to_get); // pointers to functions
	int (*compare_method)(const void* a, const void* b);

	if (strcmp(parameter, "day") == 0) {
		getter = expense_get_day;
		compare_method = compare_int;
	}
	else if (strcmp(parameter, "amount") == 0) {
		getter = expense_get_amount;
		compare_method = compare_int;
	}
	else if (strcmp(parameter, "type") == 0) {
		getter = expense_get_type;
		compare_method = compare_string;
	}
	else {
		return NULL;
	}

	DynamicArray* filtered_array = array_construct(serv->list->capacity);

	for(int i = 0; i < serv->list->length; ++i) {
		if((*compare_method)((*getter)(serv->list->expenses[i]), key)) {
			array_add_expense(filtered_array, expense_deep_copy(serv->list->expenses[i]));
		}
	}

	return filtered_array;
}

void service_sort_by_amount(Service* serv, int reverse) {
	int len = serv->list->length;
	Expense** sorted_list = (Expense**)malloc(len * sizeof(Expense*));
	for (int i = 0; i < len; ++i) {
		sorted_list[i] = serv->list->expenses[i];
	}

	for (int i = 0; i < len - 1; ++i) {
		for (int j = i + 1; j < len; ++j) {
			if (reverse) {
				if(sorted_list[i]->amount < sorted_list[j]->amount) {
					Expense* aux = sorted_list[i];
					sorted_list[i] = sorted_list[j];
					sorted_list[j] = aux;
				}
			}
			else {
				if (sorted_list[i]->amount > sorted_list[j]->amount) {
					Expense* aux = sorted_list[i];
					sorted_list[i] = sorted_list[j];
					sorted_list[j] = aux;
				}
			}
		}
	}

	for (int i = 0; i < len; ++i) {
		print_expense(sorted_list[i]);
	}

	free(sorted_list);
}

void service_sort_by_type(Service* serv, int reverse) {
	int len = serv->list->length;
	Expense** sorted_list = (Expense**)malloc(len * sizeof(Expense*));
	for (int i = 0; i < len; ++i) {
		sorted_list[i] = serv->list->expenses[i];
	}

	for (int i = 0; i < len - 1; ++i) {
		for (int j = i + 1; j < len; ++j) {
			if (reverse) {
				if (strcmp(sorted_list[i]->type, sorted_list[j]->type) < 0) {
					Expense* aux = sorted_list[i];
					sorted_list[i] = sorted_list[j];
					sorted_list[j] = aux;
				}
			}
			else {
				if (strcmp(sorted_list[i]->type, sorted_list[j]->type) > 0) {
					Expense* aux = sorted_list[i];
					sorted_list[i] = sorted_list[j];
					sorted_list[j] = aux;
				}
			}
		}
	}

	for (int i = 0; i < len; ++i) {
		print_expense(sorted_list[i]);
	}

	free(sorted_list);
}
