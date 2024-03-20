#include <stdio.h>
#include <stdlib.h>
#include "expense.h"
#include "dynamic_array.h"
#include "service.h"
#include "UI.h"
#include "./tests.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main() {
	test_all();
	//Repository* repo = repository_construct();
	DynamicArray* list = array_construct(10);
	Service* serv = service_construct(list);
	UI* ui = ui_construct(serv);
	ui_run(ui);

	ui_destruct(ui);
	service_destruct(serv);
	array_destruct(list);
	//repository_destruct(repo);

	_CrtDumpMemoryLeaks();
	
	return 0;
}