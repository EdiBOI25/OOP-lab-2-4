#pragma once
#include "service.h"

typedef struct {
	Service* service;
} UI;

/**
 * \brief Constructs a UI (menu)
 * \param service: the service used by the UI
 * \return the constructed UI
 */
UI* ui_construct(Service* service);

/**
 * \brief Deconstructs UI
 * \param ui: the UI that gets deconstructed
 */
void ui_destruct(UI* ui);

/**
 * \brief Runs the main menu of the app
 * \param ui: the ui whose menu will run
 */
void ui_run(UI* ui);

/**
 * \brief Adds an expense to the list
 * \param ui: the ui which runs
 */
void ui_add_expense(UI* ui);

/**
 * \brief Prints all stored expenses
 * \param ui the ui currently running
 */
void ui_print_all_expenses(UI* ui);

/**
 * \brief Edits data of an expense
 * \param ui the ui currently running
 */
void ui_edit_expense(UI* ui);
