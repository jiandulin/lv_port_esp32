#include <stdio.h>
#include "control_pannel_app.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * Screen1;
lv_obj_t * Object1;
lv_obj_t * Image6;
lv_obj_t * Button11;
lv_obj_t * Label2;
lv_obj_t * Object2;
lv_obj_t * Button4;
lv_obj_t * Image4;
lv_obj_t * Button5;
lv_obj_t * Image5;
lv_obj_t * Button7;
lv_obj_t * Image7;
lv_obj_t * Button8;
lv_obj_t * Image8;
lv_obj_t * Button9;
lv_obj_t * Image9;
lv_obj_t * Button10;
lv_obj_t * Image10;
lv_obj_t * Roller2;
lv_obj_t * Screen2;
lv_obj_t * Label3;




///////////////////// IMAGES ////////////////////
LV_IMG_DECLARE(sky_320x240);   // assets\星空320x240.png
LV_IMG_DECLARE(img_1);   // assets\1.png
LV_IMG_DECLARE(img_4);   // assets\4.png
LV_IMG_DECLARE(img_6);   // assets\6.png
LV_IMG_DECLARE(img_5);   // assets\5.png
LV_IMG_DECLARE(img_9);   // assets\9.png
LV_IMG_DECLARE(img_8);   // assets\8.png

///////////////////// FUNCTIONS ////////////////////
#define BAR_PROPERTY_VALUE 0
#define BAR_PROPERTY_VALUE_WITH_ANIM 1

void SetBarProperty(lv_obj_t * target, int id, int val)
{
    if(id == BAR_PROPERTY_VALUE_WITH_ANIM) lv_bar_set_value(target, val, LV_ANIM_ON);
    if(id == BAR_PROPERTY_VALUE) lv_bar_set_value(target, val, LV_ANIM_OFF);
}

#define BASIC_PROPERTY_POSITION_X 0
#define BASIC_PROPERTY_POSITION_Y 1
#define BASIC_PROPERTY_WIDTH 2
#define BASIC_PROPERTY_HEIGHT 3
#define BASIC_PROPERTY_CLICKABLE 4
#define BASIC_PROPERTY_HIDDEN 5
#define BASIC_PROPERTY_DRAGABLE 6
#define BASIC_PROPERTY_DISABLED 7

void SetBasicProperty(lv_obj_t * target, int id, int val)
{
    if(id == BASIC_PROPERTY_POSITION_X) lv_obj_set_x(target, val);
    if(id == BASIC_PROPERTY_POSITION_Y) lv_obj_set_y(target, val);
    if(id == BASIC_PROPERTY_WIDTH) lv_obj_set_width(target, val);
    if(id == BASIC_PROPERTY_HEIGHT) lv_obj_set_height(target, val);
}

void SetBasicPropertyB(lv_obj_t * target, int id, bool val)
{
    if(id == BASIC_PROPERTY_CLICKABLE) lv_obj_set_click(target, val);
    if(id == BASIC_PROPERTY_HIDDEN) lv_obj_set_hidden(target, val);
    if(id == BASIC_PROPERTY_DRAGABLE) lv_obj_set_drag(target, val);
    if(id == BASIC_PROPERTY_DISABLED) {
        if(val) lv_obj_add_state(target, LV_STATE_DISABLED);
        else lv_obj_clear_state(target, LV_STATE_DISABLED);
    }
}

#define BUTTON_PROPERTY_TOGGLE 0
#define BUTTON_PROPERTY_CHECKED 1

void SetButtonProperty(lv_obj_t * target, int id, bool val)
{
    if(id == BUTTON_PROPERTY_TOGGLE) lv_btn_toggle(target);
    if(id == BUTTON_PROPERTY_CHECKED) lv_btn_set_state(target, val ? LV_BTN_STATE_CHECKED_RELEASED : LV_BTN_STATE_RELEASED);
}

#define DROPDOWN_PROPERTY_SELECTED 0

void SetDropdownProperty(lv_obj_t * target, int id, int val)
{
    if(id == DROPDOWN_PROPERTY_SELECTED) lv_dropdown_set_selected(target, val);
}

#define IMAGE_PROPERTY_IMAGE 0

void SetImageProperty(lv_obj_t * target, int id, uint8_t * val)
{
    if(id == IMAGE_PROPERTY_IMAGE) lv_img_set_src(target, val);
}

#define LABEL_PROPERTY_TEXT 0

void SetLabelProperty(lv_obj_t * target, int id, char * val)
{
    if(id == LABEL_PROPERTY_TEXT) lv_label_set_text(target, val);
}

#define ROLLER_PROPERTY_SELECTED 0
#define ROLLER_PROPERTY_SELECTED_WITH_ANIM 1

void SetRollerProperty(lv_obj_t * target, int id, int val)
{
    if(id == ROLLER_PROPERTY_SELECTED_WITH_ANIM) lv_roller_set_selected(target, val, LV_ANIM_ON);
    if(id == ROLLER_PROPERTY_SELECTED) lv_roller_set_selected(target, val, LV_ANIM_OFF);
}

#define SLIDER_PROPERTY_VALUE 0
#define SLIDER_PROPERTY_VALUE_WITH_ANIM 1

void SetSliderProperty(lv_obj_t * target, int id, int val)
{
    if(id == SLIDER_PROPERTY_VALUE_WITH_ANIM) lv_slider_set_value(target, val, LV_ANIM_ON);
    if(id == SLIDER_PROPERTY_VALUE) lv_slider_set_value(target, val, LV_ANIM_OFF);
}

void ChangeScreen(lv_obj_t * target, int fademode, int spd, int delay)
{
    lv_scr_load_anim(target, fademode, spd, delay, false);
}

void SetOpacity(lv_obj_t * target, int val)
{
    lv_obj_set_style_local_opa_scale(target, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, val);
}


///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS2 ////////////////////
static void Object1_eventhandler(lv_obj_t * obj, lv_event_t event)
{
	printf("Object1_eventhandler event value = %d\n", event);
	if(event == LV_EVENT_DRAG_END) {
        ChangeScreen(Screen2, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
    }
}
//static void Object2_eventhandler(lv_obj_t * obj, lv_event_t event)
//{
//}
static void Button11_eventhandler(lv_obj_t * obj, lv_event_t event)
{
	printf("Button11_eventhandler event value = %d\n", event);
}
static void Button4_eventhandler(lv_obj_t * obj, lv_event_t event)
{
	printf("Button4_eventhandler event value = %d\n", event);
}
static void Button5_eventhandler(lv_obj_t * obj, lv_event_t event)
{
	printf("Button5_eventhandler event value = %d\n", event);
}
static void Button7_eventhandler(lv_obj_t * obj, lv_event_t event)
{
	printf("Button7_eventhandler event value = %d\n", event);
}
static void Button8_eventhandler(lv_obj_t * obj, lv_event_t event)
{
	printf("Button8_eventhandler event value = %d\n", event);
}
static void Button9_eventhandler(lv_obj_t * obj, lv_event_t event)
{
	printf("Button9_eventhandler event value = %d\n", event);
}
static void Button10_eventhandler(lv_obj_t * obj, lv_event_t event)
{
	printf("Button10_eventhandler event value = %d\n", event);
    if(event == LV_EVENT_CLICKED) {
        ChangeScreen(Object2, LV_SCR_LOAD_ANIM_OVER_RIGHT, 500, 0);
    }
}
static void Object2_eventhandler(lv_obj_t * obj, lv_event_t event)
{
	printf("Object2_eventhandler event value = %d\n", event);
	if(event == LV_EVENT_DRAG_END) {
        ChangeScreen(Screen1, LV_SCR_LOAD_ANIM_OVER_RIGHT, 500, 0);
    }
}


///////////////////// SCREENS ////////////////////
void BuildPages(void)
{
//	Screen1 = lv_obj_create(NULL, NULL);

//    Object1 = lv_obj_create(lv_scr_act(), NULL);
//	lv_obj_set_pos(Object1, 0, 0);
//    lv_obj_set_click(Object1, false);
//    lv_obj_set_hidden(Object1, false);
//    lv_obj_clear_state(Object1, LV_STATE_DISABLED);
//    lv_obj_set_size(Object1, 320, 240);  // force: 0
//    lv_obj_align(Object1, Screen1, LV_ALIGN_CENTER, 0, 0); // force: 320
//    lv_obj_set_drag(Object1, true);
//	lv_obj_set_drag_dir(Object1, LV_DRAG_DIR_ONE);
//	lv_obj_set_drag_throw(Object1, false);
//	lv_obj_set_drag_parent(Object1, true);
//    lv_obj_set_event_cb(Object1, Object1_eventhandler);
	Object1 = lv_cont_create(lv_scr_act(), NULL);
	lv_obj_set_pos(Object1, 0, 0);
	lv_obj_set_click(Object1, false);
	lv_obj_set_hidden(Object1, false);
	lv_obj_clear_state(Object1, LV_STATE_DISABLED);
	lv_obj_set_size(Object1, 320, 240);  // force: 0
	lv_obj_align(Object1, NULL, LV_ALIGN_CENTER, 0, 0); // force: 320
	lv_obj_set_drag(Object1, true);
	lv_obj_set_drag_dir(Object1, LV_DRAG_DIR_ONE);
	lv_obj_set_drag_throw(Object1, false);
	lv_obj_set_event_cb(Object1, Object1_eventhandler);

	
	Image6 = lv_img_create(Object1, NULL);
    lv_img_set_src(Image6, &sky_320x240);
    lv_obj_set_click(Image6, false);
    lv_obj_set_hidden(Image6, false);
    lv_obj_set_size(Image6, 320, 240);
    lv_obj_align(Image6, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_drag(Image6, false);

    lv_obj_clear_state(Image6, LV_STATE_DISABLED);

    Button11 = lv_btn_create(lv_scr_act(), NULL);
    lv_btn_set_checkable(Button11, true);
    if(false) lv_btn_set_state(Button11, false ? LV_STATE_CHECKED : LV_STATE_DEFAULT);
    lv_btn_set_layout(Button11, LV_LAYOUT_OFF);
    lv_obj_set_click(Button11, true);
    lv_obj_set_hidden(Button11, false);
    lv_obj_clear_state(Button11, LV_STATE_DISABLED);
    lv_obj_set_size(Button11, 310, 50);  // force: 0
    lv_obj_align(Button11, NULL, LV_ALIGN_CENTER, 0, -90); // force: 310
    lv_obj_set_drag(Button11, false);
    lv_obj_set_event_cb(Button11, Button11_eventhandler);
    lv_obj_set_style_local_bg_color(Button11, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,
                                    lv_color_hex(255 * 256 * 256 + 12 * 256 + 12));
	lv_obj_set_style_local_bg_color(Button11, LV_BTN_PART_MAIN, LV_STATE_PRESSED, LV_COLOR_BLUE);
    lv_obj_set_style_local_bg_opa(Button11, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 50);
    lv_obj_set_style_local_bg_main_stop(Button11, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_bg_grad_stop(Button11, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 255);
    lv_obj_set_style_local_radius(Button11, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_border_side(Button11, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_BORDER_SIDE_NONE);

	Label2 = lv_label_create(Button11, NULL);
    lv_label_set_long_mode(Label2, LV_LABEL_LONG_EXPAND);
    lv_label_set_align(Label2, LV_LABEL_ALIGN_CENTER);
    lv_label_set_text(Label2, "Mode selection");
    lv_obj_set_size(Label2, 111, 16);  // force: 0
    lv_obj_set_click(Label2, false);
    lv_obj_set_hidden(Label2, false);
    lv_obj_add_state(Label2, LV_STATE_DISABLED);
    lv_obj_set_drag(Label2, false);
    lv_obj_set_style_local_text_color(Label2, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,
                                      lv_color_hex(255 * 256 * 256 + 255 * 256 + 255));
    lv_obj_set_style_local_text_opa(Label2, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 255);

    lv_obj_align(Label2, Button11, LV_ALIGN_CENTER, 0, 0); // force: 111

    Button4 = lv_btn_create(lv_scr_act(), NULL);
    lv_btn_set_checkable(Button4, false);
    if(false) lv_btn_set_state(Button4, false ? LV_STATE_CHECKED : LV_STATE_DEFAULT);
    lv_btn_set_layout(Button4, LV_LAYOUT_OFF);
    lv_obj_set_click(Button4, true);
    lv_obj_set_hidden(Button4, false);
    lv_obj_clear_state(Button4, LV_STATE_DISABLED);
    lv_obj_set_size(Button4, 150, 50);  // force: -80
    lv_obj_align(Button4, NULL, LV_ALIGN_CENTER, -80, -30); // force: 150
    lv_obj_set_drag(Button4, false);
    lv_obj_set_event_cb(Button4, Button4_eventhandler);
    lv_obj_set_style_local_bg_color(Button4, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,
                                    lv_color_hex(255 * 256 * 256 + 12 * 256 + 12));
	lv_obj_set_style_local_bg_color(Button4, LV_BTN_PART_MAIN, LV_STATE_PRESSED, LV_COLOR_BLUE);
    lv_obj_set_style_local_bg_opa(Button4, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 50);
    lv_obj_set_style_local_bg_main_stop(Button4, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 255);
    lv_obj_set_style_local_bg_grad_stop(Button4, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 255);
    lv_obj_set_style_local_radius(Button4, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_border_side(Button4, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_BORDER_SIDE_NONE);

	Image4 = lv_img_create(Button4, NULL);
    lv_img_set_src(Image4, &img_1);
    lv_obj_set_click(Image4, false);
    lv_obj_set_hidden(Image4, false);
    lv_obj_set_size(Image4, 150, 50);
    lv_obj_align(Image4, Button4, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_drag(Image4, false);

    lv_obj_clear_state(Image4, LV_STATE_DISABLED);

    Button5 = lv_btn_create(lv_scr_act(), NULL);
    lv_btn_set_checkable(Button5, false);
    if(false) lv_btn_set_state(Button5, false ? LV_STATE_CHECKED : LV_STATE_DEFAULT);
    lv_btn_set_layout(Button5, LV_LAYOUT_OFF);
    lv_obj_set_click(Button5, true);
    lv_obj_set_hidden(Button5, false);
    lv_obj_clear_state(Button5, LV_STATE_DISABLED);
    lv_obj_set_size(Button5, 150, 50);  // force: 80
    lv_obj_align(Button5, NULL, LV_ALIGN_CENTER, 80, -30); // force: 150
    lv_obj_set_drag(Button5, false);
    lv_obj_set_event_cb(Button5, Button5_eventhandler);
    lv_obj_set_style_local_bg_color(Button5, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,
                                    lv_color_hex(255 * 256 * 256 + 12 * 256 + 12));
	lv_obj_set_style_local_bg_color(Button5, LV_BTN_PART_MAIN, LV_STATE_PRESSED, LV_COLOR_BLUE);
    lv_obj_set_style_local_bg_opa(Button5, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 50);
    lv_obj_set_style_local_bg_main_stop(Button5, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_bg_grad_stop(Button5, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 255);
    lv_obj_set_style_local_radius(Button5, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_border_side(Button5, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_BORDER_SIDE_NONE);

	Image5 = lv_img_create(Button5, NULL);
    lv_img_set_src(Image5, &img_4);
    lv_obj_set_click(Image5, false);
    lv_obj_set_hidden(Image5, false);
    lv_obj_set_size(Image5, 150, 50);
    lv_obj_align(Image5, Button5, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_drag(Image5, false);

    lv_obj_clear_state(Image5, LV_STATE_DISABLED);

    Button7 = lv_btn_create(lv_scr_act(), NULL);
    lv_btn_set_checkable(Button7, false);
    if(false) lv_btn_set_state(Button7, false ? LV_STATE_CHECKED : LV_STATE_DEFAULT);
    lv_btn_set_layout(Button7, LV_LAYOUT_OFF);
    lv_obj_set_click(Button7, true);
    lv_obj_set_hidden(Button7, false);
    lv_obj_clear_state(Button7, LV_STATE_DISABLED);
    lv_obj_set_size(Button7, 150, 50);  // force: -80
    lv_obj_align(Button7, NULL, LV_ALIGN_CENTER, -80, 30); // force: 150
    lv_obj_set_drag(Button7, false);
    lv_obj_set_event_cb(Button7, Button7_eventhandler);
    lv_obj_set_style_local_bg_color(Button7, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,
                                    lv_color_hex(255 * 256 * 256 + 12 * 256 + 12));
	lv_obj_set_style_local_bg_color(Button7, LV_BTN_PART_MAIN, LV_STATE_PRESSED, LV_COLOR_BLUE);
    lv_obj_set_style_local_bg_opa(Button7, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 50);
    lv_obj_set_style_local_bg_main_stop(Button7, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_bg_grad_stop(Button7, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 255);
    lv_obj_set_style_local_radius(Button7, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_border_side(Button7, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_BORDER_SIDE_NONE);

	Image7 = lv_img_create(Button7, NULL);
    lv_img_set_src(Image7, &img_6);
    lv_obj_set_click(Image7, false);
    lv_obj_set_hidden(Image7, false);
    lv_obj_set_size(Image7, 150, 50);
    lv_obj_align(Image7, Button7, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_drag(Image7, false);

    lv_obj_clear_state(Image7, LV_STATE_DISABLED);

    Button8 = lv_btn_create(lv_scr_act(), NULL);
    lv_btn_set_checkable(Button8, false);
    if(false) lv_btn_set_state(Button8, false ? LV_STATE_CHECKED : LV_STATE_DEFAULT);
    lv_btn_set_layout(Button8, LV_LAYOUT_OFF);
    lv_obj_set_click(Button8, true);
    lv_obj_set_hidden(Button8, false);
    lv_obj_clear_state(Button8, LV_STATE_DISABLED);
    lv_obj_set_size(Button8, 150, 50);  // force: 80
    lv_obj_align(Button8, NULL, LV_ALIGN_CENTER, 80, 30); // force: 150
    lv_obj_set_drag(Button8, false);
    lv_obj_set_event_cb(Button8, Button8_eventhandler);
    lv_obj_set_style_local_bg_color(Button8, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,
                                    lv_color_hex(255 * 256 * 256 + 12 * 256 + 12));
	lv_obj_set_style_local_bg_color(Button8, LV_BTN_PART_MAIN, LV_STATE_PRESSED, LV_COLOR_BLUE);
    lv_obj_set_style_local_bg_opa(Button8, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 50);
    lv_obj_set_style_local_bg_main_stop(Button8, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_bg_grad_stop(Button8, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 255);
    lv_obj_set_style_local_radius(Button8, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_border_side(Button8, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_BORDER_SIDE_NONE);

	Image8 = lv_img_create(Button8, NULL);
    lv_img_set_src(Image8, &img_5);
    lv_obj_set_click(Image8, false);
    lv_obj_set_hidden(Image8, false);
    lv_obj_set_size(Image8, 150, 50);
    lv_obj_align(Image8, Button8, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_drag(Image8, false);

    lv_obj_clear_state(Image8, LV_STATE_DISABLED);

    Button9 = lv_btn_create(lv_scr_act(), NULL);
    lv_btn_set_checkable(Button9, false);
    if(false) lv_btn_set_state(Button9, false ? LV_STATE_CHECKED : LV_STATE_DEFAULT);
    lv_btn_set_layout(Button9, LV_LAYOUT_OFF);
    lv_obj_set_click(Button9, true);
    lv_obj_set_hidden(Button9, false);
    lv_obj_clear_state(Button9, LV_STATE_DISABLED);
    lv_obj_set_size(Button9, 150, 50);  // force: -80
    lv_obj_align(Button9, NULL, LV_ALIGN_CENTER, -80, 90); // force: 150
    lv_obj_set_drag(Button9, false);
    lv_obj_set_event_cb(Button9, Button9_eventhandler);
    lv_obj_set_style_local_bg_color(Button9, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,
                                    lv_color_hex(255 * 256 * 256 + 12 * 256 + 12));
	lv_obj_set_style_local_bg_color(Button9, LV_BTN_PART_MAIN, LV_STATE_PRESSED, LV_COLOR_BLUE);
    lv_obj_set_style_local_bg_opa(Button9, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 50);
    lv_obj_set_style_local_bg_main_stop(Button9, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_bg_grad_stop(Button9, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 255);
    lv_obj_set_style_local_radius(Button9, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_border_side(Button9, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_BORDER_SIDE_NONE);

	Image9 = lv_img_create(Button9, NULL);
    lv_img_set_src(Image9, &img_9);
    lv_obj_set_click(Image9, false);
    lv_obj_set_hidden(Image9, false);
    lv_obj_set_size(Image9, 150, 50);
    lv_obj_align(Image9, Button9, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_drag(Image9, false);

    lv_obj_clear_state(Image9, LV_STATE_DISABLED);

    Button10 = lv_btn_create(lv_scr_act(), NULL);
    lv_btn_set_checkable(Button10, false);
    if(false) lv_btn_set_state(Button10, false ? LV_STATE_CHECKED : LV_STATE_DEFAULT);
    lv_btn_set_layout(Button10, LV_LAYOUT_OFF);
    lv_obj_set_click(Button10, true);
    lv_obj_set_hidden(Button10, false);
    lv_obj_clear_state(Button10, LV_STATE_DISABLED);
    lv_obj_set_size(Button10, 150, 50);  // force: 80
    lv_obj_align(Button10, NULL, LV_ALIGN_CENTER, 80, 90); // force: 150
    lv_obj_set_drag(Button10, false);
    lv_obj_set_event_cb(Button10, Button10_eventhandler);
    lv_obj_set_style_local_bg_color(Button10, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,
                                    lv_color_hex(255 * 256 * 256 + 12 * 256 + 12));
	lv_obj_set_style_local_bg_color(Button10, LV_BTN_PART_MAIN, LV_STATE_PRESSED, LV_COLOR_BLUE);
//	lv_obj_set_style_local_pattern_recolor(Button10, LV_BTN_PART_MAIN, LV_STATE_PRESSED, LV_COLOR_PURPLE);
    lv_obj_set_style_local_bg_opa(Button10, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 50);
    lv_obj_set_style_local_bg_main_stop(Button10, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_bg_grad_stop(Button10, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 255);
    lv_obj_set_style_local_radius(Button10, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_border_side(Button10, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_BORDER_SIDE_NONE);

	Image10 = lv_img_create(Button10, NULL);
    lv_img_set_src(Image10, &img_8);
    lv_obj_set_click(Image10, false);
    lv_obj_set_hidden(Image10, false);
    lv_obj_set_size(Image10, 150, 50);
    lv_obj_align(Image10, Button10, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_drag(Image10, false);

    lv_obj_clear_state(Image10, LV_STATE_DISABLED);

//	Screen2 = lv_obj_create(NULL, NULL);

//    Object2 = lv_obj_create(lv_scr_act(), NULL);
//	lv_obj_set_pos(Object2, 0, 0);
//    lv_obj_set_click(Object2, false);
//    lv_obj_set_hidden(Object2, false);
//    lv_obj_clear_state(Object2, LV_STATE_DISABLED);
//    lv_obj_set_size(Object2, 320, 240);  // force: 0
//    lv_obj_align(Object2, Screen2, LV_ALIGN_CENTER, 0, 0); // force: 320
//    lv_obj_set_drag(Object2, true);
//	lv_obj_set_drag_dir(Object2, LV_DRAG_DIR_ONE);
//	lv_obj_set_drag_throw(Object2, false);
//	lv_obj_set_drag_parent(Object2, true);
//    lv_obj_set_event_cb(Object2, Object2_eventhandler);
	Object2 = lv_cont_create(lv_scr_act(), NULL);
	lv_obj_set_pos(Object2, 0, 0);
	lv_obj_set_click(Object2, false);
	lv_obj_set_hidden(Object2, false);
	lv_obj_clear_state(Object2, LV_STATE_DISABLED);
	lv_obj_set_size(Object2, 320, 240);  // force: 0
	lv_obj_align(Object2, NULL, LV_ALIGN_CENTER, 0, 0); // force: 320
	lv_obj_set_drag(Object2, true);
	lv_obj_set_drag_dir(Object2, LV_DRAG_DIR_ONE);
	lv_obj_set_drag_throw(Object2, false);
	lv_obj_set_event_cb(Object2, Object2_eventhandler);



    Label3 = lv_label_create(Object2, NULL);
    lv_label_set_long_mode(Label3, LV_LABEL_LONG_EXPAND);
    lv_label_set_align(Label3, LV_LABEL_ALIGN_CENTER);
    lv_label_set_text(Label3, "Text");
    lv_obj_set_size(Label3, 29, 16);  // force: 0
    lv_obj_set_click(Label3, false);
    lv_obj_set_hidden(Label3, false);
    lv_obj_clear_state(Label3, LV_STATE_DISABLED);
    lv_obj_set_drag(Label3, false);

    lv_obj_align(Label3, Object2, LV_ALIGN_CENTER, 0, 0); // force: 29

}

