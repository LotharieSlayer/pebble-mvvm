#include "feat1_viewmodel.h"
#include "feat1_view.h"
#include "../../service/click_service.h"

static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
  text_layer_set_text(s_text_layer, "Select");
}

static void up_click_handler(ClickRecognizerRef recognizer, void *context) {
  text_layer_set_text(s_text_layer, "Up");
}

static void down_click_handler(ClickRecognizerRef recognizer, void *context) {
  text_layer_set_text(s_text_layer, "Down");
}

static void click_config(void *context) {
  click_config_provider(context, select_click_handler, up_click_handler, down_click_handler);
}

void feat1_viewmodel_init(Window *window) {
  window_set_click_config_provider(window, click_config);
}