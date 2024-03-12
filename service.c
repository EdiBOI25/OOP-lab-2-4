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
	repository_filter_by_type(serv->repository, type);
}
