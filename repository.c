#include "repository.h" 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Repository* repository_construct() {
    Repository* repo = malloc(sizeof(Repository));
    if (repo == NULL) {
        return NULL;
    }
    /*repo->expenses = malloc(2 * sizeof(Expense));
    if (repo->expenses == NULL) {
        return NULL;
    }*/
    repo->length = 0;
    //repo->capacity = 1;
    repo->capacity = 50;
    return repo;
}

void repository_destruct(Repository* repo) {
    if (repo == NULL) {
        return;
    }
	for (int i = repo->length - 1; i >= 0; i--) {
        expense_destruct(repo->expenses[i]);
    }
    /*free(repo->expenses);*/
    free(repo);
}

void repository_add_expense(Repository* repo, Expense* e) {
    /*if (repo->length == repo->capacity) {
		repository_resize(repo);
	}*/
    repo->expenses[repo->length] = e;
    repo->length++;
}

//void repository_resize(Repository* repo) {
//    int new_capacity = 2 * repo->capacity;
//    Expense** new_expenses = malloc(new_capacity * sizeof(Expense)); // allocate new memory for expenses
//    for (int i = 0; i < repo->length; ++i) {
//        // copy the old expenses to the new array
//	    new_expenses[i] = repo->expenses[i];
//    }
//    free(repo->expenses); // free the old memory
//    repo->capacity = new_capacity;
//    repo->expenses = new_expenses;
//}

Expense* repository_get_expense(Repository* repo, int position) {
    if (position < 0 || position >= repo->length) {
        return NULL;
    }
	return (repo->expenses[position]);
}

Expense** repository_get_all(Repository* repo) {
    return repo->expenses;
}

void repository_print_all(Repository* repo) {
	for (int i = 0; i < repo->length; ++i) {
        printf("%d: ", i);
        print_expense(repo->expenses[i]);
	}
    printf("\n");
}

void repository_set_day(Repository* repo, int position, int new_day) {
    if (repo == NULL) {
        return;
    }
    if (position < 0 || position >= repo->length) {
        return;
    }
    expense_set_day(repo->expenses[position], new_day);
}

void repository_set_amount(Repository* repo, int position, int new_amount) {
    if (repo == NULL) {
        return;
    }
    if (position < 0 || position >= repo->length) {
        return;
    }
    expense_set_amount(repo->expenses[position], new_amount);
}

void repository_set_type(Repository* repo, int position, char* new_type) {
	if (repo == NULL) {
        return;
	}
    if (position < 0 || position >= repo->length) {
        return;
    }
    expense_set_type(repo->expenses[position], new_type);
}

void repository_delete_expense(Repository* repo, int position) {
    if (repo == NULL) {
        return;
    }
    if (position < 0 || position >= repo->length) {
        return;
    }
    expense_destruct(repo->expenses[position]);
    for(int i = position; i < repo->length - 1; ++i) {
        repo->expenses[i] = repo->expenses[i + 1];
    }
    repo->length--;
}
