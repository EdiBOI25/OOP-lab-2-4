#pragma once
#include <assert.h> // pt teste
// assert(expresie); | ex: assert(cmmdc(3, 7) == 1);
#include <string.h>
#include <stdlib.h> // pt alocare dinamica
#include <stdio.h>

#include "expense.h"
#include "repository.h"
#include "dynamic_array.h"
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
	assert(expense_is_valid(expense_construct(-5, 100, "as")) == 0);

	expense_set_day(e1, 20);
	assert(e1->day = 20);
	expense_set_amount(e1, 200000);
	assert(e1->amount = 200000);
	expense_set_type(e1, "qwerty");
	assert(strcmp(e1->type, "qwerty") == 0);

	Expense* copy_exp = expense_deep_copy(e1);
	assert(e1->day == 20);
	assert(e1->amount == 200000);
	assert(strcmp(e1->type, "qwerty") == 0);

	print_expense(e1);
	expense_destruct(e1);

	// test dynamic array
	DynamicArray* dynamic_array = array_construct(2);
	assert(dynamic_array->capacity == 2);
	for (int i = 0; i < 10; i++) {
		Expense* e = expense_construct(i, i * 100, "mancare");
		array_add_expense(dynamic_array, e);
	}
	assert(dynamic_array->length == 10);
	assert(dynamic_array->capacity== 16);

	assert(array_get_expense(dynamic_array, 3)->day == 3);
	assert(array_get_expense(dynamic_array, 7)->amount == 700);

	array_delete_expense(dynamic_array, 3);
	array_delete_expense(dynamic_array, 100);
	assert(dynamic_array->length == 9);
	assert(array_get_expense(dynamic_array, 5)->day == 6);

	DynamicArray* copy_array = array_deep_copy(dynamic_array);
	assert(copy_array->length == 9);
	assert(copy_array->capacity == 16);
	assert(array_get_expense(copy_array, 5)->day == 6);

	array_destruct(dynamic_array);
	

	// test service
	dynamic_array = array_construct(10);
	Service* serv = service_construct(dynamic_array);
	for (int i = 0; i < 10; ++i) {
		service_add_expense(serv, i+1, 100 * i, "altele");
	}
	service_add_expense(serv, -10, 123, "ceva");
	Expense** list = array_get_all(serv->list);
	assert(list[2]->day == 3);
	assert(list[5]->amount == 500);
	assert(strcmp(list[7]->type, "altele") == 0);

	service_set_day(serv, 2, 20);
	assert(list[2]->day == 20);
	service_set_amount(serv, 5, 2000);
	assert(list[5]->amount == 2000);
	service_set_type(serv, 7, "qwerty");
	assert(strcmp(list[7]->type, "qwerty") == 0);

	service_set_day(serv, 3, 100);
	service_set_amount(serv, 3, -100);
	service_set_type(serv, 3, "a");

	service_delete_expense(serv, 5);
	assert(list[5]->day == 7);

	service_filter(serv, "day", 8);
	service_filter(serv, "amount", 200);
	service_filter(serv, "type", "altele");
	service_filter(serv, "random", "blabla");

	service_set_amount(serv, 1, 49572);
	service_set_amount(serv, 9, 49572);

	service_sort_by_amount(serv, 0);
	service_sort_by_amount(serv, 1);
	service_sort_by_type(serv, 1);
	service_sort_by_type(serv, 0);

	service_destruct(serv);
	array_destruct(dynamic_array);

	system("cls");
	printf("Tests passed\n");
}
