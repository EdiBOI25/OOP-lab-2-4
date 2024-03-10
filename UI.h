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
void ui_deconstruct(UI* ui);
