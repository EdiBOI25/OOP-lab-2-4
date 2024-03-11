#include "repository.h" 
#include <stdlib.h>
#include <stdio.h>

Repository* repository_construct() {
    Repository* repo = malloc(sizeof(Repository));
    repo->expenses = malloc(2 * sizeof(Expense));
    repo->length = 0;
    repo->capacity = 1;
    return repo;
}

void repository_destruct(Repository* repo) {
    if (repo == NULL) {
        return;
    }
	for (int i = repo->length - 1; i >= 0; i--) {
        expense_destruct(repo->expenses[i]);
    }
    free(repo->expenses);
    free(repo);
}

void repository_add_expense(Repository* repo, Expense* e) {
    if (repo->length == repo->capacity) {
		repository_resize(repo);
	}
    repo->expenses[repo->length] = e;
    repo->length++;
}

void repository_resize(Repository* repo) {
    int new_capacity = 2 * repo->capacity;
    Expense** new_expenses = malloc(new_capacity * sizeof(Expense)); // allocate new memory for expenses
    for (int i = 0; i < repo->length; ++i) {
        // copy the old expenses to the new array
	    new_expenses[i] = repo->expenses[i];
    }
    free(repo->expenses); // free the old memory
    repo->capacity = new_capacity;
    repo->expenses = new_expenses;
}

Expense* repository_get_expense(Repository* repo, int position) {
	return (repo->expenses[position]);
}

Expense** repository_get_all(Repository* repo) {
    return repo->expenses;
}

void repository_print_all(Repository* repo) {
	for (int i = 0; i < repo->length; ++i) {
        print_expense(repo->expenses[i]);
	}
}
