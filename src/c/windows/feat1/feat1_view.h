#pragma once
#include <pebble.h>

// Data model for the view (UI state)
typedef struct {
  const char *label_text;
} Feat1ViewUIState;

void feat1_view_create(Window *window);
void feat1_view_destroy(Window *window);
void feat1_view_update(const Feat1ViewUIState *state);