#ifndef CONTROL_PANNEL_APP_H
#define CONTROL_PANNEL_APP_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

extern lv_obj_t * Screen1;
extern lv_obj_t * Object1;
extern lv_obj_t * Image6;
extern lv_obj_t * Label2;
extern lv_obj_t * Object2;
extern lv_obj_t * Image4;
extern lv_obj_t * Image5;
extern lv_obj_t * Image7;
extern lv_obj_t * Image8;
extern lv_obj_t * Image9;
extern lv_obj_t * Image10;


LV_IMG_DECLARE(sky_320x240);   // assets\星空320x240.png
LV_IMG_DECLARE(img_1);   // assets\1.png
LV_IMG_DECLARE(img_4);   // assets\4.png
LV_IMG_DECLARE(img_6);   // assets\6.png
LV_IMG_DECLARE(img_5);   // assets\5.png
LV_IMG_DECLARE(img_9);   // assets\9.png
LV_IMG_DECLARE(img_8);   // assets\8.png

void BuildPages(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
