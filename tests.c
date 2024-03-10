#pragma once
#include <assert.h> // pt teste
// assert(expresie); | ex: assert(cmmdc(3, 7) == 1);
#include <string.h>
#include <stdlib.h> // pt alocare dinamica
#include <stdio.h>

#include "expense.h"
#include "repository.h"

void test_all() {
	//// test expense
	Expense* e1 = expense_construct(12, 300, "mancare");
	assert(e1->day == 12);
	assert(e1->amount == 300);
	assert(strcmp(e1->type, "mancare") == 0);
	destruct_expense(e1);

	// test repository
	Repository* repo = repository_construct();
	for(int i = 0; i < 10; i++) {
		Expense* e = expense_construct(i, i * 100, "mancare");
		repository_add_expense(repo, e);
	}
	assert(repo->length == 10);
	assert(repo->capacity == 16);
	assert(repository_get_expense(repo, 3)->day == 3);
	assert(repository_get_expense(repo, 7)->amount == 700);

	repository_destruct(repo);

	printf("Tests passed\n");
}
