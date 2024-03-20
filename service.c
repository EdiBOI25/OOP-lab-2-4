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
	if (service == NULL) {
		return NULL;
	}
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
		expense_destruct(expense);
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

int compare_int(int* a, int* b) {
	if (a == b) {
		return 0;
	}
	if (a > b) {
		return 1;
	}
	return -1;
}

int compare_string(char* a, char* b) {
	return strcmp(a, b);
}

int compare_type(const Expense* e1, const Expense* e2) {
	if (e1 == NULL || e2 == NULL) {
		return 0;
	}

	return strcmp(e1->type, e2->type);
}

int compare_amount(const Expense* e1, const Expense* e2) {
	if (e1 == NULL || e2 == NULL) {
		return 0;
	}

	if (e1->amount == e2->amount) {
		return 0;
	}
	if (e1->amount > e2->amount) {
		return 1;
	}
	return -1;
}

DynamicArray* filter_by_day(DynamicArray* source_array, int day) {
	DynamicArray* filtered_array = array_construct(source_array->capacity);

	for (int i = 0; i < source_array->length; ++i) {
		if (source_array->expenses[i]->day == day) {
			array_add_expense(filtered_array, expense_deep_copy(source_array->expenses[i]));
		}
	}

	return filtered_array;
}

DynamicArray* filter_by_amount(DynamicArray* source_array, int amount) {
	DynamicArray* filtered_array = array_construct(source_array->capacity);

	for (int i = 0; i < source_array->length; ++i) {
		if (source_array->expenses[i]->amount == amount) {
			array_add_expense(filtered_array, expense_deep_copy(source_array->expenses[i]));
		}
	}

	return filtered_array;
}

DynamicArray* filter_by_type(DynamicArray* source_array, char* type) {
	DynamicArray* filtered_array = array_construct(source_array->capacity);

	for (int i = 0; i < source_array->length; ++i) {
		if ((source_array->expenses[i]->type, type) == 0) {
			array_add_expense(filtered_array, expense_deep_copy(source_array->expenses[i]));
		}
	}

	return filtered_array;
}

//DynamicArray* service_filter(Service* serv, char* parameter, void* key) {
//	if (serv == NULL || parameter == NULL || key == NULL) {
//		return NULL;
//	}
//
//	if (strcmp(parameter, "day") == 0) {
//		return filter_by_day(serv->list, (int)key);
//	}
//	else if (strcmp(parameter, "amount") == 0) {
//		return filter_by_amount(serv->list, (int)key);
//	}
//	else if (strcmp(parameter, "type") == 0) {
//		return filter_by_type(serv->list, key);
//	}
//	else {
//		return NULL;
//	}
//
//	
//}

DynamicArray* service_sort(Service* serv, char* parameter, int reverse) {
	if (serv == NULL || parameter == NULL) {
		return NULL;
	}
	//void* (*getter)(void* to_get); // pointers to functions

	/*if (strcmp(parameter, "day") == 0) {
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
	}*/

	DynamicArray* sorted_array = array_construct(serv->list->capacity);
	sorted_array = array_deep_copy(serv->list);
	if (strcmp(parameter, "amount") == 0) {
		sort(sorted_array, compare_amount, reverse);
	}
	else if (strcmp(parameter, "type") == 0) {
		sort(sorted_array, compare_type, reverse);
	}
	else {
		return NULL;
	}	

	return sorted_array;
}
void sort(DynamicArray* da, compare_method cmp, int reverse) {
	for (int i = 0; i < da->length - 1; ++i) {
		for (int j = i + 1; j < da->length; ++j) {
			if (reverse == 0) {
				if (cmp(da->expenses[i], da->expenses[j])>0) {
					printf("BEFORE SWAP:\n");
					print_expense(da->expenses[i]);
					print_expense(da->expenses[j]);
					Expense* aux = da->expenses[i];
					da->expenses[i] = da->expenses[j];
					da->expenses[j] = aux;
					printf("AFTER SWAP:\n");
					print_expense(da->expenses[i]);
					print_expense(da->expenses[j]);
				}
			}
			else {
				if (cmp(da->expenses[i], da->expenses[j]) < 0) {
					printf("BEFORE SWAP:\n");
					print_expense(da->expenses[i]);
					print_expense(da->expenses[j]);
					Expense* aux = da->expenses[i];
					da->expenses[i] = da->expenses[j];
					da->expenses[j] = aux;
					printf("AFTER SWAP:\n");
					print_expense(da->expenses[i]);
					print_expense(da->expenses[j]);
				}
			}
		}
	}
	
}
void service_sort_by_amount(Service* serv, int reverse) {
	int len = serv->list->length;
	Expense** sorted_list = (Expense**)malloc(len * sizeof(Expense*));
	if (sorted_list == NULL) {
		return;
	}
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
	if (sorted_list == NULL) {
		return;
	}
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
