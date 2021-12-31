
#include "lvgl.h"
#include "style_app.h"
#include "touch_app.h"
#include "astronaut.h"
#include "coffee_app.h"
#include "arc_app.h"

//#include "control_pannel_app.h"
#include "lv_wingcool_demo.h"

#include "lv_examples/src/lv_ex_style/lv_ex_style.h"
#include "lv_examples/src/lv_ex_get_started/lv_ex_get_started.h"
#include "lv_examples/src/lv_ex_widgets/lv_ex_widgets.h"

static lv_indev_t * my_indev;


void user_app(lv_indev_t * indev)
{
	my_indev = indev;

	//lv_style_cogwheel_img_app();
//	ks_esp_cam_init();
//	astronaut_start();
	//touch_app_init();
	//	  lvgl_coffee_init();
	//arc_app();
	// lv_ex_get_started_4();
	// lv_ex_get_started_1();
	// lv_ex_get_started_2();
	// lv_ex_get_started_3();
	// lv_ex_style_1();
	// lv_ex_style_2();
	// lv_ex_style_3();
	// lv_ex_style_4();
	// lv_ex_style_5();
	// lv_ex_style_6();
	// lv_ex_style_7();
	// lv_ex_style_8();
	// lv_ex_style_9();
	// lv_ex_style_10();
	// lv_ex_style_11();
	// lv_ex_arc_1();
	// lv_ex_arc_2();
	//	  lv_ex_bar_1();
	//	  lv_ex_btn_1();
	//	  lv_ex_btn_2();
	//	  lv_ex_btnmatrix_1();
	// lv_ex_calendar_1();
	// lv_ex_canvas_1();
	// lv_ex_canvas_2();
	// lv_ex_checkbox_1();
	// lv_ex_chart_1();
	// lv_ex_chart_2();
	// lv_ex_cont_1();
	// lv_ex_cpicker_1();
	//	  lv_ex_cpicker_2();
	//	  lv_ex_dropdown_1();
	//	  lv_ex_dropdown_2();
	//	  lv_ex_gauge_1();
	//	  lv_ex_gauge_2();
	//	  lv_ex_img_1();
	//	  lv_ex_img_2();
	//	  lv_ex_img_3();
	//	  lv_ex_imgbtn_1();
	//	  lv_ex_keyboard_1();
	//	  lv_ex_label_1();
	//	  lv_ex_label_2();
	//	  lv_ex_label_3();
	//	  lv_ex_led_1();
	//	  lv_ex_line_1();
	//	  lv_ex_list_1();
	//	  lv_ex_linemeter_1();
	//	  lv_ex_msgbox_1();
	//	  lv_ex_msgbox_2();
	//	  lv_ex_obj_1();
	//	  lv_ex_page_1();
	//	  lv_ex_spinner_1();
	//	  lv_ex_roller_1();
	//	  lv_ex_slider_1();
	//	  lv_ex_slider_2();
	//	  lv_ex_spinbox_1();
	//	  lv_ex_switch_1();
	//	  lv_ex_textarea_1();
	//	  lv_ex_textarea_2();
	//	  lv_ex_textarea_3();
	//	  lv_ex_objmask_1();
	//	  lv_ex_objmask_2();
	//	  lv_ex_table_1();
	//	  lv_ex_tabview_1();
	//	  lv_ex_tileview_1();
	//	  lv_ex_win_1();
	//	  BuildPages();
	lv_wingcool_demo_printer(my_indev);

}

