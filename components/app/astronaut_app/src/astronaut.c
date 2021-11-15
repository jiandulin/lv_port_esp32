/*** 
 * @Descripttion :  
 * @version      : 0.0.1
 * @Author       : jiandulin
 * @Date         : 2021-11-11 18:15:50
 * @LastEditors  : jiandulin
 * @LastEditTime : 
 * @FilePath     : 
 */
#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
//#include "esp_freertos_hooks.h"
//#include "freertos/semphr.h"

#include "lvgl.h"

#include "esp_log.h"
#include "esp_err.h"

#include "astronaut.h"

typedef struct _compment_t
{
    int16_t start;
    int16_t end;
    lv_obj_t * obj;
    uint16_t start_t;
    uint16_t end_t;
    lv_anim_path_cb_t cb;
    lv_anim_exec_xcb_t funcb;
    lv_anim_path_t path;
    lv_anim_t a;
    struct _compment_t *next;

}compment_t;

compment_t panim;

LV_IMG_DECLARE(taikong001);
LV_IMG_DECLARE(taikong002);
LV_IMG_DECLARE(taikong003);
LV_IMG_DECLARE(taikong004);
LV_IMG_DECLARE(taikong005);
LV_IMG_DECLARE(taikong006);
LV_IMG_DECLARE(taikong007);
LV_IMG_DECLARE(taikong008);
LV_IMG_DECLARE(taikong009);
LV_IMG_DECLARE(taikong010);

#define TAG "astronaut"
#define ANIEND                      \
    while (lv_anim_count_running()) \
        lv_task_handler();
lv_style_t style1;
/*****主体****/
lv_obj_t *scr,*scr_body,*img_anim;
lv_task_t *task_anim;



void ks_esp_cam_init(void)
{
	//lv_png_init();
	scr = lv_scr_act(); //获取当前活跃的屏幕对象

	static lv_style_t style1;
	lv_style_set_bg_color(&style1, LV_STATE_DEFAULT, LV_COLOR_BLACK); //设置屏幕背景
	lv_style_set_bg_opa(&style1, LV_STATE_DEFAULT,255);
	lv_obj_add_style(scr, LV_BTN_PART_MAIN, &style1); /*Default button style*/

	scr_body = lv_cont_create(scr, NULL); //屏幕主体
	lv_cont_set_fit2(scr_body, LV_FIT_NONE, LV_FIT_NONE);
	//lv_obj_set_size(scr_body, 240, 240 - 25);
    //lv_obj_set_pos(scr_body, 0, 25);
    lv_obj_set_size(scr_body, 150, 150);
    lv_obj_set_pos(scr_body, -70, 90);
	lv_style_set_border_color(&style1, LV_STATE_DEFAULT, LV_COLOR_BLACK); //边框背景色
	lv_style_set_border_width(&style1, LV_STATE_DEFAULT, 0);			  //边框宽度
	lv_style_set_border_opa(&style1, LV_STATE_DEFAULT, 0);				  //边框透明度
	lv_obj_add_style(scr_body, LV_BTN_PART_MAIN, &style1);				  /*Default button style*/
}

void page_home_anim(compment_t *comp)
{

    img_anim = lv_img_create(scr_body, NULL);
    //Write style LV_IMG_PART_MAIN for WIN_img0
    static lv_style_t style_img;
    lv_style_init(&style_img);

    //Write style state: LV_STATE_DEFAULT for style_img
    lv_style_set_image_recolor(&style_img, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_image_recolor_opa(&style_img, LV_STATE_DEFAULT, 0);
    lv_style_set_image_opa(&style_img, LV_STATE_DEFAULT, 255);
    lv_obj_add_style(img_anim, LV_IMG_PART_MAIN, &style_img);
    lv_obj_set_pos(img_anim, 70, 60);
    lv_img_set_src(img_anim, &taikong001);


    // img_anim = lv_gif_create_from_data(scr_body, taikongren_map);
	// lv_obj_set_size(img_anim, 100, 100);
	// lv_obj_set_pos(img_anim, 70, 50);
    
    //动画
    comp->start = 240;
    comp->end = 70;
    comp->obj = img_anim;
    comp->start_t = 500;
    comp->end_t = 500;
    comp->cb = lv_anim_path_ease_out;
    comp->funcb = (void *)lv_obj_set_y;
    comp->next = NULL;
}

void page_home_load()
{

    lv_style_set_bg_color(&style1, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_border_color(&style1, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_border_width(&style1, LV_STATE_DEFAULT, 0);
    lv_style_set_border_opa(&style1, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_opa(&style1, LV_STATE_DEFAULT, 0);
    //page_home_ksdiy();
    //page_home_temp(&pcth);
    //page_home_fensi(&pcf);
    //page_home_time(&pct);
    page_home_anim(&panim);

    /*lv_add_compment(&c22, &c33);
    lv_add_compment(&c33, &c44);
    lv_add_compment(&c44, &pcf);
    lv_add_compment(&pcf, &pct);
    lv_add_compment(&pct, &pcth);
    lv_add_compment(&pcth, &panim);

    obj_move(&c22, 1);*/
    ANIEND
}


void astronaut_anim_time(lv_task_t *task)
{
    static uint8_t i = 1;
    switch (i)
    {
    case 1:
        lv_img_set_src(img_anim, &taikong001);
        break;
    case 2:
        lv_img_set_src(img_anim, &taikong002);
        break;
    case 3:
        lv_img_set_src(img_anim, &taikong003);
        break;
    case 4:
        lv_img_set_src(img_anim, &taikong004);
        break;
    case 5:
        lv_img_set_src(img_anim, &taikong005);
        break;
    case 6:
        lv_img_set_src(img_anim, &taikong006);
        break;
    case 7:
        lv_img_set_src(img_anim, &taikong007);
        break;
    case 8:
        lv_img_set_src(img_anim, &taikong008);
        break;
    case 9:
        lv_img_set_src(img_anim, &taikong009);
        break;
    case 10:
        lv_img_set_src(img_anim, &taikong010);
        break;
    default:
        break;
    }

    if (i == 10)
        i = 1;
    i++;
}

void astronaut_start(void)
{
	page_home_load();
    task_anim = lv_task_create(astronaut_anim_time, 100, LV_TASK_PRIO_MID, NULL);

    ESP_LOGI("SYSTEM", "esp_get_free_heap_size : %d ", esp_get_free_heap_size());
}