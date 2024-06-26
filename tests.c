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

	expense_set_day(e1, 20);
	assert(e1->day == 20);
	expense_set_amount(e1, 200000);
	assert(e1->amount == 200000);
	expense_set_type(e1, "qwerty");
	assert(strcmp(e1->type, "qwerty") == 0);

	Expense* copy_exp = expense_deep_copy(e1);
	assert(copy_exp->day == 20);
	assert(copy_exp->amount == 200000);
	assert(strcmp(copy_exp->type, "qwerty") == 0);
	expense_destruct(copy_exp);

	print_expense(e1);
	expense_destruct(e1);

	Expense* ee = expense_construct(32, 10, "asd");
	assert(expense_is_valid(ee) == 0);
	expense_destruct(ee);
	ee = expense_construct(15, -100, "asdasd");
	assert(expense_is_valid(ee) == 0);
	expense_destruct(ee);
	ee = expense_construct(15, 100, "as");
	assert(expense_is_valid(ee) == 0);
	expense_destruct(ee);

	// test dynamic array
	DynamicArray* dynamic_array = array_construct(2);
	assert(dynamic_array->capacity == 2);
	assert(dynamic_array->length == 0);
	for (int i = 0; i < 10; i++) {
		Expense* e = expense_construct(i, i * 100, "mancare");
		array_add_expense(dynamic_array, e);
	}
	assert(dynamic_array->length == 10);
	assert(dynamic_array->capacity== 16);

	assert(array_get_expense(dynamic_array, 3)->day == 3);
	assert(array_get_expense(dynamic_array, 7)->amount == 700);
	assert(array_get_expense(dynamic_array, 300) == NULL);

	array_delete_expense(dynamic_array, 3);
	array_delete_expense(dynamic_array, 100);
	assert(dynamic_array->length == 9);
	assert(array_get_expense(dynamic_array, 5)->day == 6);

	DynamicArray* copy_array = array_deep_copy(dynamic_array);
	assert(copy_array->length == 9);
	assert(copy_array->capacity == 16);
	assert(array_get_expense(copy_array, 5)->day == 6);
	array_destruct(copy_array);

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
	service_set_type(serv, 300, "ahgjhghgjhg");

	service_delete_expense(serv, 5);
	assert(list[5]->day == 7);

	DynamicArray* filter_array = filter_by_day(serv->list, 8);
	array_print(filter_array);
	array_destruct(filter_array);
	
	filter_array = filter_by_amount(serv->list, 200);
	array_print(filter_array);
	array_destruct(filter_array);
	printf("FILTER BY TYPE:\n");
	filter_array = filter_by_type(serv->list, "altele");
	array_print(filter_array);
	array_destruct(filter_array);
	/*filter_array = service_filter(serv, "random", "blabla");
	array_print(filter_array);
	array_destruct(filter_array);*/

	service_set_amount(serv, 1, 49572);
	service_set_amount(serv, 9, 49572);


	printf("\n\nSORTS:\n");
	DynamicArray* sorted_array = service_sort(serv, "amount", 0);
	array_print(sorted_array);
	array_destruct(sorted_array);
	sorted_array = service_sort(serv, "amount", 1);
	array_print(sorted_array);
	array_destruct(sorted_array);
	sorted_array = service_sort(serv, "type", 0);
	array_print(sorted_array);
	array_destruct(sorted_array);
	sorted_array = service_sort(serv, "type", 1);
	array_print(sorted_array);
	array_destruct(sorted_array);
	printf("END SORTS\n");

	/*service_sort_by_amount(serv, 0);
	service_sort_by_amount(serv, 1);
	service_sort_by_type(serv, 1);
	service_sort_by_type(serv, 0);*/

	service_destruct(serv);
	array_destruct(dynamic_array);

	system("cls");
	printf("Tests passed\n");
}
