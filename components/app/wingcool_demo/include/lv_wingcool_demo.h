/**
 * @file lv_wingcool_demo.h
 *
 */

#ifndef LV_WINGCOOL_DEMO_H
#define LV_WINGCOOL_DEMO_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "lvgl.h"


/*********************
 *      DEFINES
 *********************/
/*Bg positions*/
#define LV_WINGCOOL_DEMO_BG_NONE 					(-LV_VER_RES)
#define LV_WINGCOOL_DEMO_BG_FULL 					(0)
#define LV_WINGCOOL_DEMO_BG_NORMAL 				(-2 * (LV_VER_RES / 3))
#define LV_WINGCOOL_DEMO_BG_SMALL 				(-5 * (LV_VER_RES / 6))

/*Animations*/
#define LV_WINGCOOL_DEMO_ANIM_X 					(LV_HOR_RES / 40)
#define LV_WINGCOOL_DEMO_ANIM_Y 					(LV_VER_RES / 40)
#define LV_WINGCOOL_DEMO_ANIM_DELAY 				(40)
#define LV_WINGCOOL_DEMO_ANIM_TIME  				(150)
#define LV_WINGCOOL_DEMO_ANIM_TIME_HOME  			(500)
#define LV_WINGCOOL_DEMO_ANIM_TIME_BG  			(150)



/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void home_open(uint32_t delay);

void lv_wingcool_demo_printer(lv_indev_t * indev);

void lv_wingcool_demo_anim_out_all(lv_obj_t * obj, uint32_t delay);
void lv_wingcool_demo_anim_bg(uint32_t delay, lv_color_t color, int32_t y_new);

void lv_wingcool_demo_anim_top_to_bottom(lv_obj_t * obj, uint32_t delay);

lv_obj_t * add_title(const char * txt);
lv_obj_t * add_back(lv_event_cb_t event_cb);


/**********************
 *      MACROS
 **********************/
LV_IMG_DECLARE(sky_320x240);   // assets\星空320x240.png
LV_IMG_DECLARE(img_1);   // assets\1.png
LV_IMG_DECLARE(img_4);   // assets\4.png
LV_IMG_DECLARE(img_6);   // assets\6.png
LV_IMG_DECLARE(img_5);   // assets\5.png
LV_IMG_DECLARE(img_9);   // assets\9.png
LV_IMG_DECLARE(img_8);   // assets\8.png
LV_IMG_DECLARE(img_2);   // assets\2.png
LV_IMG_DECLARE(img_3);   // assets\3.png
LV_IMG_DECLARE(img_7);   // assets\7.png
LV_IMG_DECLARE(yg_logo);
LV_IMG_DECLARE(wingcool_logo);



#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_WINGCOOL_DEMO_H*/
