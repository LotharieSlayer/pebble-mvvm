#include "feat1_window.h"
#include "feat1_view.h"
#include "feat1_viewmodel.h"

static Window *s_window;

static void prv_window_load(Window *window) {
  feat1_view_create(window);
  feat1_viewmodel_notify();
}

static void prv_window_unload(Window *window) {
  feat1_view_destroy(window);
}

void feat1_window_push(void) {
  if (!s_window) {
    s_window = window_create();
    window_set_window_handlers(s_window, (WindowHandlers) {
      .load = prv_window_load,
      .unload = prv_window_unload,
    });
    feat1_viewmodel_init(s_window);
  }
  window_stack_push(s_window, true);
}

void feat1_window_pop(void) {
  window_stack_remove(s_window, true);
}