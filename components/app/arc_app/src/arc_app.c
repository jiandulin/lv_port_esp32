/*** 
 * @Descripttion :  
 * @version      : 0.0.1
 * @Author       : jiandulin
 * @Date         : 2021-11-08 15:08:20
 * @LastEditors  : jiandulin
 * @LastEditTime : 
 * @FilePath     : 
 */
#include <stdio.h>
//#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
//#else
//#include "lvgl/lvgl.h"
//#endif

/* ESP32 includes */
#include "esp_log.h"

#include "arc_app.h"

#define TAG "arc_app"


static void arc_event_cb(lv_obj_t * arc, lv_event_t event)
{
    ESP_LOGI(TAG, "event： %d", event);
    if(event == LV_EVENT_VALUE_CHANGED) {
        /*Refresh the arc*/
        // lv_arc_ext_t *angle_end = lv_arc_get_angle_end(arc);
        // lv_arc_set_end_angle(arc, angle_end->arc_angle_end);
        ESP_LOGI(TAG, "touch...");
        lv_arc_set_angles(arc, 0, 0);
        lv_arc_set_start_angle(arc, 0);
    }
}

void arc_app(void)
{
    static lv_style_t arc_style;
    lv_style_init(&arc_style);
    lv_style_set_bg_opa(&arc_style, LV_STATE_DEFAULT, LV_OPA_TRANSP);
    lv_style_set_border_opa(&arc_style, LV_STATE_DEFAULT, LV_OPA_TRANSP);
    

    /*Create an Arc*/
    lv_obj_t * arc = lv_arc_create(lv_scr_act(), NULL);
    // lv_arc_set_type(arc, LV_ARC_TYPE_REVERSE);
    lv_arc_set_bg_angles(arc, 0, 360);
    // lv_arc_set_type(arc, LV_ARC_TYPE_SYMMETRIC);
    // lv_arc_set_angles(arc, 0, 360);
    // lv_arc_set_type(arc, LV_ARC_TYPE_NORMAL);
    // lv_arc_set_start_angle(arc, 0);
    // lv_arc_set_end_angle(arc, 180);
    lv_obj_set_size(arc, 150, 150);
    //lv_arc_set_range(arc, 0, 180);
    //lv_arc_set_value(arc, 90);
    //lv_arc_set_rotation(arc, 200);
    lv_obj_add_style(arc, LV_ARC_PART_BG, &arc_style);
    lv_obj_align(arc, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_event_cb(arc, arc_event_cb);         /*Assign an event function*/

}

static lv_obj_t * label;

static void slider_event_cb(lv_obj_t * slider, lv_event_t event)
{
    ESP_LOGI(TAG, "event1： %d", event);
    if(event == LV_EVENT_VALUE_CHANGED) {
        /*Refresh the text*/
        ESP_LOGI(TAG, "event： %d", event);
        lv_label_set_text_fmt(label, "%d", lv_slider_get_value(slider));
    }
}

/**
 * Create a slider and write its value on a label.
 */
void lv_ex_get_started_4(void)
{
    /* Create a slider in the center of the display */
    lv_obj_t * slider = lv_slider_create(lv_scr_act(), NULL);
    lv_obj_set_width(slider, 200);                        /*Set the width*/
    lv_obj_align(slider, NULL, LV_ALIGN_CENTER, 0, 0);    /*Align to the center of the parent (screen)*/
    lv_obj_set_event_cb(slider, slider_event_cb);         /*Assign an event function*/

    /* Create a label below the slider */
    label = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_text(label, "0");
    lv_obj_set_auto_realign(slider, true);                          /*To keep center alignment when the width of the text changes*/
    lv_obj_align(label, slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);    /*Align below the slider*/
}