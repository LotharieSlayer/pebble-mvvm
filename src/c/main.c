#include <pebble.h>
#include "./windows/feat1/feat1_window.h"
// #include "./windows/feat2/feat2_window.h" // future (need some kind of router ^^)

static void init(void) {
  feat1_window_push();
}

static void deinit(void) {
}

int main(void) {
  init();
  app_event_loop();
  deinit();
  return 0;
}