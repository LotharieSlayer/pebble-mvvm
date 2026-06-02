#include <pebble.h>
#include "main.h"
#include "./windows/feat1/feat1_view.h"
#include "./windows/feat1/feat1_viewmodel.h"

Window *s_window;

static void init(void) {
  s_window = window_create();

  window_set_window_handlers(s_window, (WindowHandlers) {
    .load = feat1_load,
    .unload = feat1_unload,
  });

  feat1_viewmodel_init(s_window);

  const bool animated = true;
  window_stack_push(s_window, animated);
}

static void deinit(void) {
  window_destroy(s_window);
}

int main(void) {
  init();
  APP_LOG(APP_LOG_LEVEL_DEBUG, "Done initializing, pushed window: %p", s_window);
  app_event_loop();
  deinit();
}