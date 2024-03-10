#include <stdlib.h>
#include "service.h"
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
