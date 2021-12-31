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
#include "lv_gif.h"

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

/*此页面窗口*/
static lv_obj_t *appWindow;
/*标题栏*/
static lv_obj_t *labelTitle;

/*标题栏分隔线*/
static lv_obj_t *lineTitle;
/*图标显示容器，用于裁剪显示*/
static lv_obj_t *contDisp;

lv_style_t style1;
/*****主体****/
lv_obj_t *scr,*scr_body,*img_anim;
lv_task_t *task_anim;
lv_obj_t *img_gif;

extern const uint8_t taikongren_map[];
extern const uint8_t myeye_map[]; /*Use the example gif*/
extern const uint8_t example_map[];
extern const uint8_t example_gif_map[];
extern const uint8_t l_50_map[];
extern const uint8_t haqian_map[];
extern const uint8_t so_map[];

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
//	printf("astronaut_anim_time 1\n");
//    static uint8_t i = 1;
//    switch (i)
//    {
//    case 1:
//        lv_img_set_src(img_anim, &taikong001);
//        break;
//    case 2:
//        lv_img_set_src(img_anim, &taikong002);
//        break;
//    case 3:
//        lv_img_set_src(img_anim, &taikong003);
//        break;
//    case 4:
//        lv_img_set_src(img_anim, &taikong004);
//        break;
//    case 5:
//        lv_img_set_src(img_anim, &taikong005);
//        break;
//    case 6:
//        lv_img_set_src(img_anim, &taikong006);
//        break;
//    case 7:
//        lv_img_set_src(img_anim, &taikong007);
//        break;
//    case 8:
//        lv_img_set_src(img_anim, &taikong008);
//        break;
//    case 9:
//        lv_img_set_src(img_anim, &taikong009);
//        break;
//    case 10:
//        lv_img_set_src(img_anim, &taikong010);
//        break;
//    default:
//        break;
//    }

//    if (i == 10)
//        i = 1;
//    i++;

    lv_gif_restart(img_gif);
//    img_gif = lv_gif_create_from_data(contDisp, l_50_map);
//	lv_obj_set_size(img_gif, 150, 150);
//	lv_obj_set_pos(img_gif, 85, 0);
//	printf("astronaut_anim_time\n");
}

#if 0
void cont_create(void)
{
	static lv_obj_t *contdisp;
	contdisp = lv_cont_create(lv_scr_act(), NULL);
	static lv_style_t style_cont;
	lv_style_set_pad_left(&style_cont, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_opa(&style_cont, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_top(&style_cont, LV_STATE_DEFAULT, 0);
	lv_style_set_border_color(&style_cont, LV_STATE_DEFAULT, LV_COLOR_BLACK);
	lv_style_set_border_width(&style_cont, LV_STATE_DEFAULT, 0);
	lv_style_set_border_opa(&style_cont, LV_STATE_DEFAULT, 255);
	lv_style_set_bg_color(&style_cont, LV_STATE_DEFAULT, LV_COLOR_BLACK); //设置屏幕背景
	lv_obj_add_style(contdisp, LV_BTN_PART_MAIN, &style_cont);			  /*Default button style*/
	lv_obj_set_size(contdisp, 320, 240);
	lv_obj_set_pos(contdisp, 0, 0);

	lv_obj_t *img_gif = lv_gif_create_from_data(contdisp, taikongren_90_map);
//	lv_obj_t *img_gif = lv_gif_create_from_data(contdisp, myeye_map);
//	lv_obj_t *img_gif = lv_img_create(contdisp, NULL);
//	lv_img_set_src(img_gif, &taikong001);
	lv_obj_set_size(img_gif, 150, 150);
	lv_obj_set_pos(img_gif, 85, 45);
}
#endif

static void Title_Create()
{
//	LV_FONT_DECLARE(number);
	appWindow = lv_cont_create(lv_scr_act(), NULL);
	static lv_style_t style_cont;
	lv_style_set_pad_left(&style_cont, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_opa(&style_cont, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_top(&style_cont, LV_STATE_DEFAULT, 0);
	lv_style_set_border_color(&style_cont, LV_STATE_DEFAULT, LV_COLOR_BLACK);
	lv_style_set_border_width(&style_cont, LV_STATE_DEFAULT, 0);
	lv_style_set_border_opa(&style_cont, LV_STATE_DEFAULT, 255);
	lv_style_set_bg_color(&style_cont, LV_STATE_DEFAULT, LV_COLOR_BLACK); //设置屏幕背景
	lv_obj_add_style(appWindow, LV_BTN_PART_MAIN, &style_cont);			  /*Default button style*/
	lv_obj_set_pos(appWindow, 0, 0);
	lv_obj_set_size(appWindow, 320, 240);

	labelTitle = lv_label_create(appWindow, NULL);

	static lv_style_t style_label;
	lv_style_init(&style_label);

	//Write style state: LV_STATE_DEFAULT for style_label
	lv_style_set_radius(&style_label, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_label, LV_STATE_DEFAULT, LV_COLOR_BLACK);
	lv_style_set_bg_grad_color(&style_label, LV_STATE_DEFAULT, LV_COLOR_BLACK);
	lv_style_set_bg_grad_dir(&style_label, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_label, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_label, LV_STATE_DEFAULT, LV_COLOR_WHITE);
	lv_obj_set_style_local_text_font(labelTitle, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_22);
	lv_style_set_text_letter_space(&style_label, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_label, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_label, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_label, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_label, LV_STATE_DEFAULT, 0);

	lv_obj_add_style(labelTitle, LV_LABEL_PART_MAIN, &style_label);
	lv_label_set_long_mode(labelTitle, LV_LABEL_LONG_BREAK);
	lv_label_set_align(labelTitle, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_pos(labelTitle, 0, 0);
	lv_obj_set_size(labelTitle, 320, 60);
	lv_label_set_recolor(labelTitle, true);

	/*默认选中的是第二个图标*/
	lv_label_set_static_text(labelTitle, "About");
	lv_obj_align(labelTitle, NULL, LV_ALIGN_IN_TOP_MID, 0, 10);
	lv_obj_set_auto_realign(labelTitle, true);

	lineTitle = lv_line_create(appWindow, NULL);
	static lv_style_t style_line;
	lv_style_init(&style_line);
	lv_style_set_line_color(&style_line, LV_STATE_DEFAULT, lv_color_make(0xFa, 0x05, 0x05));
	lv_style_set_line_width(&style_line, LV_STATE_DEFAULT, 5);
	lv_obj_add_style(lineTitle, LV_LINE_PART_MAIN, &style_line);
	lv_obj_set_pos(lineTitle, 0, 55);
	lv_obj_set_size(lineTitle, 320, 5);
	static lv_point_t screen_line3[] = {{0, 0}, {320, 0}};
	lv_line_set_points(lineTitle, screen_line3, 2);
}

static void Cont_create(void)
{
//	LV_FONT_DECLARE(myFont);
	uint8_t i;
	contDisp = lv_cont_create(appWindow, NULL);
	static lv_style_t style_cont;
	lv_style_set_pad_left(&style_cont, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_opa(&style_cont, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_top(&style_cont, LV_STATE_DEFAULT, 0);
	lv_style_set_border_color(&style_cont, LV_STATE_DEFAULT, LV_COLOR_BLACK);
	lv_style_set_border_width(&style_cont, LV_STATE_DEFAULT, 0);
	lv_style_set_border_opa(&style_cont, LV_STATE_DEFAULT, 255);
	lv_style_set_bg_color(&style_cont, LV_STATE_DEFAULT, LV_COLOR_BLACK); //设置屏幕背景
	lv_obj_add_style(contDisp, LV_BTN_PART_MAIN, &style_cont);			  /*Default button style*/
	lv_obj_set_size(contDisp, 320, 180);
	lv_obj_set_pos(contDisp, 0, 60);
//	lv_obj_t *img_gif = lv_gif_create_from_data(contDisp, taikongren_map);
//	lv_obj_set_size(img_gif, 150, 150);
//	lv_obj_set_pos(img_gif, 85, 0);
	img_gif = lv_gif_create_from_data(contDisp, l_50_map);
	lv_obj_set_size(img_gif, 150, 150);
	lv_obj_set_pos(img_gif, 85, 0);
	// lv_obj_align(img_gif, contDisp, LV_ALIGN_IN_TOP_MID, 0, 40); //设置图片显示顶端

	lv_obj_t *label_version = lv_label_create(contDisp, NULL);

	static lv_style_t style_label;
	lv_style_init(&style_label);

	//Write style state: LV_STATE_DEFAULT for style_label
	lv_style_set_radius(&style_label, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_label, LV_STATE_DEFAULT, LV_COLOR_BLACK);
	lv_style_set_bg_grad_color(&style_label, LV_STATE_DEFAULT, LV_COLOR_BLACK);
	lv_style_set_bg_grad_dir(&style_label, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_label, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_label, LV_STATE_DEFAULT, LV_COLOR_WHITE);
	lv_obj_set_style_local_text_font(label_version, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_12);
	lv_style_set_text_letter_space(&style_label, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_label, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_label, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_label, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_label, LV_STATE_DEFAULT, 0);

	lv_obj_add_style(label_version, LV_LABEL_PART_MAIN, &style_label);
	lv_label_set_long_mode(label_version, LV_LABEL_LONG_BREAK);
	lv_label_set_align(label_version, LV_LABEL_ALIGN_CENTER);
	// lv_obj_set_pos(label_version, 0, 0);
	lv_obj_set_size(label_version, 320, 20);
	// lv_label_set_recolor(label_version, true);

	/*默认选中的是第二个图标*/
	lv_label_set_static_text(label_version, "KS-ESP32-MASTER\nwingcool\n");
	lv_obj_align(label_version, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, 0);
	lv_obj_set_auto_realign(label_version, true);


}

void obj_add_anim(lv_obj_t *obj, lv_anim_exec_xcb_t exec_cb, uint16_t time, lv_coord_t start, lv_coord_t end, lv_anim_path_cb_t path_cb)
{
	lv_anim_t a;

	lv_anim_init(&a);
	lv_anim_set_var(&a, obj); //动画对象

	lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)exec_cb); //动画函数
	lv_anim_set_time(&a, time);

	a.start = start;		  //起始值
	a.end = end; //结束值
	a.path.cb = path_cb;	  //动画计算方法
	a.playback_time = 0;				  //回放时间设为0不执行动画回放

	lv_anim_start(&a); //开启动画
}

void page_about_load()
{
	Title_Create();
	Cont_create();
	obj_add_anim(
		appWindow,								  //动画对象
		(lv_anim_exec_xcb_t)lv_obj_set_x,		  //动画函数
		lv_anim_speed_to_time(300, 0, 50), //动画速度
		240,					  //起始值
		0,  //结束值
		lv_anim_path_ease_out						  //动画特效:模拟弹性物体下落
	);

	ANIEND
}

void page_about_end(void)
{

	obj_add_anim(
		appWindow,								  //动画对象
		(lv_anim_exec_xcb_t)lv_obj_set_x,		  //动画函数
		lv_anim_speed_to_time(300, 0, 50), //动画速度
		0,					  //起始值
		240,  //结束值
		lv_anim_path_ease_out						  //动画特效:模拟弹性物体下落
	);
	ANIEND
	lv_obj_del(appWindow);
//	printf("%s !Dram: %d bytes\r\n", __func__, heap_caps_get_free_size(MALLOC_CAP_INTERNAL | MALLOC_CAP_8BIT));
}
void astronaut_start(void)
{
//	page_home_load();
//    task_anim = lv_task_create(astronaut_anim_time, 100, LV_TASK_PRIO_MID, NULL);

//    ESP_LOGI("SYSTEM", "esp_get_free_heap_size : %d ", esp_get_free_heap_size());
//	cont_create();
	page_about_load();
	task_anim = lv_task_create(astronaut_anim_time, 5000, LV_TASK_PRIO_MID, NULL);
}