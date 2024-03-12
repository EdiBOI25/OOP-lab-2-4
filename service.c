#include <stdlib.h>
#include "service.h"

#include <stdio.h>
#include <string.h>

#include "repository.h"
#include "expense.h"

Service* service_construct(Repository* repository) {
	Service* service = malloc(sizeof(Service));
	service->repository = repository;
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
	repository_add_expense(service->repository, expense);
}

void service_set_day(Service* serv, int position, int new_day) {
	if (new_day < 1 || new_day > 31) {
		return;
	}
	repository_set_day(serv->repository, position, new_day);
}

void service_set_amount(Service* serv, int position, int new_amount) {
	if (new_amount < 0) {
		return;
	}
	repository_set_amount(serv->repository, position, new_amount);
}

void service_set_type(Service* serv, int position, char* new_type) {
	if (new_type == NULL) {
		return;
	}
	if (strlen(new_type) < 3) {
		return;
	}
	repository_set_type(serv->repository, position, new_type);
}

void service_delete_expense(Service* serv, int position) {
	if (serv == NULL) {
		return;
	}
	repository_delete_expense(serv->repository, position);
}

void service_filter_by_type(Service* serv, char* type) {
	if (serv == NULL || type == NULL) {
		return;
	}
	for (int i = 0; i < serv->repository->length; ++i) {
		if (strcmp(serv->repository->expenses[i]->type, type) == 0) {
			print_expense(serv->repository->expenses[i]);
		}
	}
}

void service_sort_by_amount(Service* serv, int reverse) {
	int len = serv->repository->length;
	Expense** sorted_list = (Expense**)malloc(len * sizeof(Expense*));
	for (int i = 0; i < len; ++i) {
		sorted_list[i] = serv->repository->expenses[i];
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
	int len = serv->repository->length;
	Expense** sorted_list = (Expense**)malloc(len * sizeof(Expense*));
	for (int i = 0; i < len; ++i) {
		sorted_list[i] = serv->repository->expenses[i];
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
