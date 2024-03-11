#pragma once
#include <assert.h> // pt teste
// assert(expresie); | ex: assert(cmmdc(3, 7) == 1);
#include <string.h>
#include <stdlib.h> // pt alocare dinamica
#include <stdio.h>

#include "expense.h"
#include "repository.h"
#include "service.h"

void test_all() {
	//// test expense
	Expense* e1 = expense_construct(12, 300, "mancare");
	assert(e1->day == 12);
	assert(e1->amount == 300);
	assert(strcmp(e1->type, "mancare") == 0);
	assert(expense_is_valid(e1));
	assert(expense_is_valid(expense_construct(32, 10, "asd")) == 0);
	assert(expense_is_valid(expense_construct(15, -100, "asdasd")) == 0);
	assert(expense_is_valid(expense_construct(15, 100, "as")) == 0);

	expense_set_day(e1, 20);
	assert(e1->day = 20);
	expense_set_amount(e1, 200000);
	assert(e1->amount = 200000);
	expense_set_type(e1, "qwerty");
	assert(strcmp(e1->type, "qwerty") == 0);

	expense_destruct(e1);

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

	repository_set_day(repo, 3, 20);
	assert(repository_get_expense(repo, 3)->day == 20);
	repository_set_amount(repo, 7, 200000);
	assert(repository_get_expense(repo, 7)->amount == 200000);

	repository_destruct(repo);

	// test service
	repo = repository_construct();
	Service* serv = service_construct(repo);
	for (int i = 0; i < 10; ++i) {
		service_add_expense(serv, i+1, 100 * i, "altele");
	}
	Expense** list = repository_get_all(serv->repository);
	assert(list[2]->day == 3);
	assert(list[5]->amount == 500);
	assert(strcmp(list[7]->type, "altele") == 0);

	service_set_day(serv, 2, 20);
	assert(list[2]->day == 20);
	service_set_amount(serv, 5, 2000);
	assert(list[5]->amount == 2000);
	service_set_type(serv, 7, "qwerty");
	assert(strcmp(list[7]->type, "qwerty") == 0);

	printf("Tests passed\n");
}
