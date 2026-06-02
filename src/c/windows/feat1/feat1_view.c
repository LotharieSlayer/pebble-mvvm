#include "feat1_view.h"

TextLayer *s_text_layer;

void feat1_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  s_text_layer = text_layer_create(GRect(0, 72, bounds.size.w, 20));
  text_layer_set_background_color(s_text_layer, GColorCyan);
  text_layer_set_text(s_text_layer, "Press a button");
  text_layer_set_text_alignment(s_text_layer, GTextAlignmentCenter);
  layer_add_child(window_layer, text_layer_get_layer(s_text_layer));
}

void feat1_unload(Window *window) {
  text_layer_destroy(s_text_layer);
}