#include "repository.h"
#include <stdlib.h>
#include <stdio.h>

Repository* construct_repository() {
    Repository* repo = malloc(sizeof(Repository));
    repo->expenses = malloc(1 * sizeof(Expense));
    repo->length = 0;
    repo->capacity = 1;
    return repo;
}

void destruct_repository(Repository* repo) {
	for (int i = 10; i >= 0; i--) {
        printf("repository.c: destructing expense %d\n", i);
        destruct_expense(&repo->expenses[i]);
        printf("repository.c: destructed expense %d\n", i);
	}
    free(repo->expenses);
    free(repo);
}

void add_expense(Repository* repo, Expense* e) {
    if (repo->length == repo->capacity) {
		resize(repo);
	}
    repo->expenses[repo->length] = *e;
    repo->length++;
}

void resize(Repository* repo) {
    int new_capacity = 2 * repo->capacity;
    Expense* new_expenses = malloc(new_capacity * sizeof(Expense)); // allocate new memory for expenses
    for (int i = 0; i < repo->length; ++i) {
        // copy the old expenses to the new array
	    new_expenses[i] = repo->expenses[i];
    }
    free(repo->expenses); // free the old memory
    repo->capacity = new_capacity;
    repo->expenses = new_expenses;
}

Expense* get_expense(Repository* repo, int position) {
	return &repo->expenses[position];
}
