#include "feat1_viewmodel.h"
#include "feat1_view.h"
#include "../../service/click_service.h"

static Feat1ViewUIState s_state;

static void prv_update_view(void) {
  feat1_view_update(&s_state);
}

static void prv_select_handler(ClickRecognizerRef recognizer, void *context) {
  s_state.label_text = "Select";
  prv_update_view();
}

static void prv_up_handler(ClickRecognizerRef recognizer, void *context) {
  s_state.label_text = "Up";
  prv_update_view();
}

static void prv_down_handler(ClickRecognizerRef recognizer, void *context) {
  s_state.label_text = "Down";
  prv_update_view();
}

static void prv_click_config(void *context) {
  click_config_provider(context, prv_select_handler, prv_up_handler, prv_down_handler);
}

void feat1_viewmodel_init(Window *window) {
  s_state = (Feat1ViewUIState) {
    .label_text = "Press a button",
  };
  window_set_click_config_provider(window, prv_click_config);
}

void feat1_viewmodel_notify(void) {
  prv_update_view();
}

void feat1_viewmodel_deinit(void) {}