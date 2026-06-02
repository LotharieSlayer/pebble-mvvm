#include "click_service.h"

void click_config_provider(void *context, ClickHandler select_handler, ClickHandler up_handler, ClickHandler down_handler) {
  window_single_click_subscribe(BUTTON_ID_SELECT, select_handler);
  window_single_click_subscribe(BUTTON_ID_UP, up_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_handler);
}