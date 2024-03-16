#include <stdio.h>
#include <stdlib.h>
#include "expense.h"
#include "dynamic_array.h"
#include "service.h"
#include "UI.h"
#include "./tests.h"
// TODO: void* pointer to functions + repository print all pt dyn array
// TODO 2: refa sort astfel incat sa returneze lista noua (deep copy, free la lista dupa)

int main() {
	test_all();
	//Repository* repo = repository_construct();
	DynamicArray* list = array_construct(10);
	Service* serv = service_construct(list);
	UI* ui = ui_construct(serv);
	ui_run(ui);

	ui_destruct(ui);
	service_destruct(serv);
	//repository_destruct(repo);
	array_destruct(list);
	
	return 0;
}