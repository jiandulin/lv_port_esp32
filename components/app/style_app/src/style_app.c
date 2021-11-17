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

#include "style_app.h"


void lv_style_cogwheel_img_app(void)
{
    /* Now create the actual image */
    lv_obj_t * img = lv_img_create(lv_scr_act(), NULL);
    LV_IMG_DECLARE(img_cogwheel_argb);
    lv_img_set_src(img, &img_cogwheel_argb);
    lv_obj_align(img, NULL, LV_ALIGN_CENTER, 50, 50);
    lv_img_set_pivot(img, 0, 0);    /*Rotate around the top left corner*/

    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, img);
    lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)lv_img_set_angle);
    lv_anim_set_values(&a, 0, 3600);
    lv_anim_set_time(&a, 5000);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
    lv_anim_start(&a);

    //lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)lv_img_set_zoom);
    //lv_anim_set_values(&a, 128, 400);
    //lv_anim_set_playback_time(&a, 1000);
    //lv_anim_start(&a);

}