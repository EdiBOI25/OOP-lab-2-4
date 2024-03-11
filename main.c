#include <stdio.h>
#include <stdlib.h>
#include "expense.h"
#include "repository.h"
#include "service.h"
#include "UI.h"
#include "./tests.h"


int main() {
	test_all();
	Repository* repo = repository_construct();
	Service* serv = service_construct(repo);
	UI* ui = ui_construct(serv);
	ui_run(ui);

	ui_destruct(ui);
	service_destruct(serv);
	repository_destruct(repo);
	
	return 0;
}