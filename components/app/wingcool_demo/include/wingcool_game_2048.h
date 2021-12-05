#ifndef LV_WINGCOOL_2048_GAME_H
#define LV_WINGCOOL_2048_GAME_H

#ifdef __cplusplus
extern "C" {
#endif


/*********************
 *      INCLUDES
 *********************/
#include "lv_wingcool_demo_theme.h"

/*********************
 *      DEFINES
 *********************/
#define SIZE 4

#define LV_WINGCOOL_2048_GAME_BOX_W			(160)
#define LV_WINGCOOL_2048_GAME_BOX_H			(160)
#define LV_WINGCOOL_2048_NUMBER_BOX_W			(30)
#define LV_WINGCOOL_2048_NUMBER_BOX_H			(30)
#define LV_WINGCOOL_2048_CURRENT_SCORE_W		(65)
#define LV_WINGCOOL_2048_CURRENT_SCORE_H		(35)
#define LV_WINGCOOL_2048_BEST_SCORE_W			(65)
#define LV_WINGCOOL_2048_BEST_SCORE_H			(35)

#define LV_WINGCOOL_2048_GAME_BG_COLOR 		lv_color_hex(0xe8e5db) //LV_COLOR_MAKE(0xCD, 0xC1, 0xB4)
#define LV_WINGCOOL_2048_GAME_BOX_COLOR 		lv_color_hex(0xBBADA0)
#define LV_WINGCOOL_2048_NUMBER_BOX_COLOR 	lv_color_hex(0xCDC1B4)
#define LV_WINGCOOL_2048_NUMBER_2_COLOR 		lv_color_hex(0xeee4da)
#define LV_WINGCOOL_2048_NUMBER_4_COLOR 		lv_color_hex(0xeee1c9)
#define LV_WINGCOOL_2048_NUMBER_8_COLOR 		lv_color_hex(0xf3b27a)
#define LV_WINGCOOL_2048_NUMBER_16_COLOR 		lv_color_hex(0xf69664)
#define LV_WINGCOOL_2048_NUMBER_32_COLOR 		lv_color_hex(0xf77c5f)
#define LV_WINGCOOL_2048_NUMBER_64_COLOR 		lv_color_hex(0xf75f3b)
#define LV_WINGCOOL_2048_NUMBER_128_COLOR 	lv_color_hex(0xedd073)
#define LV_WINGCOOL_2048_NUMBER_256_COLOR 	lv_color_hex(0xEDCC61)
#define LV_WINGCOOL_2048_NUMBER_512_COLOR 	lv_color_hex(0xEDCC61)
#define LV_WINGCOOL_2048_NUMBER_1024_COLOR 	lv_color_hex(0xEDCC61)
#define LV_WINGCOOL_2048_NUMBER_2048_COLOR 	lv_color_hex(0xEDC22E)

/**********************
 *      TYPEDEFS
 **********************/

typedef struct _lv_wingcool_2048_game {
	lv_obj_t * bg;					
	lv_obj_t * canvas_stage;		
	lv_obj_t * label_best_score;	
	lv_obj_t * label_current_score;	
	lv_task_t * task_handle;		
									 
	uint8_t game_board[SIZE][SIZE];	
	uint32_t current_score_value;	
	bool play_game;					
} T_lv_wingcool_2048_game, *PT_lv_wingcool_2048_game;


/**********************
 * GLOBAL PROTOTYPES
 **********************/
void lv_wingcool_game_2048(lv_indev_t * indev);




/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* LV_WINGCOOL_2048_GAME_H */





