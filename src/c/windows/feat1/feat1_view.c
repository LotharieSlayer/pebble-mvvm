#include "feat1_view.h"

static TextLayer *s_text_layer;

void feat1_view_create(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  s_text_layer = text_layer_create(GRect(0, 72, bounds.size.w, 20));
  text_layer_set_background_color(s_text_layer, GColorCyan);
  text_layer_set_text_alignment(s_text_layer, GTextAlignmentCenter);
  layer_add_child(window_layer, text_layer_get_layer(s_text_layer));
}

void feat1_view_destroy(Window *window) {
  text_layer_destroy(s_text_layer);
  s_text_layer = NULL;
}

void feat1_view_update(const Feat1ViewUIState *state) {
  if (s_text_layer && state->label_text) {
    text_layer_set_text(s_text_layer, state->label_text);
  }
}