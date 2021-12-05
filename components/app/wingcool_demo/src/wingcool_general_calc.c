/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "wingcool_general_calc.h"


/**********************
 *  STATIC VARIABLES
 **********************/
static lv_obj_t * bg_calc;
static lv_obj_t * g_calc_ta;
static char *curr_char = NULL;
static char *next_char = NULL;

static token_t current_token = TOKENIZER_ERROR;
static error_t error_code = no_error;


static const char * btnm_map[] = {  "(", ")",  "C", "<-",  "\n",
									  "7", "8", "9", "/", "\n",
									  "4", "5", "6", "*",  "\n",
									  "1", "2", "3", "-",  "\n",
									  "0", ".", "=", "+",  ""};

static const error_table_t error_table[] = {
    {.error_code = no_error,            .message = "no error"},
    {.error_code = syntax_error,        .message = "syntax error!"}
};
	
/**********************
 *	STATIC PROTOTYPES
 **********************/
LV_EVENT_CB_DECLARE(back_to_home_event_cb_1);

static void lv_wingcool_calc_init(void);
static void lv_wingcool_calc_tokenizer_init(char *expr);
static token_t lv_wingcool_calc_get_next_token(void);
static token_t lv_wingcool_calc_siglechar(void);
static int lv_wingcool_calc_expr(void);
static int lv_wingcool_calc_term(void);
static token_t lv_wingcool_calc_tokenizer_token(void);
static void lv_wingcool_calc_tokenizer_next(void);
static int lv_wingcool_calc_factor(void);
static bool lv_wingcool_calc_tokenizer_finished(void);
static token_t lv_wingcool_calc_get_next_token(void);


static void event_handler_btnmatrix(lv_obj_t * obj, lv_event_t e);

void lv_wingcool_calc(void)
{
	/* menu item style */
//    static lv_style_t wingcool_bg_calc;
//    lv_style_init(&wingcool_bg_calc);
//    lv_style_set_bg_opa(&wingcool_bg_calc, LV_STATE_DEFAULT, LV_OPA_30); // 设置色彩透明度
//    lv_style_set_radius(&wingcool_bg_calc, LV_STATE_DEFAULT, 0); // 设置圆角
//    lv_style_set_bg_color(&wingcool_bg_calc, LV_STATE_DEFAULT, LV_COLOR_SILVER); //设置颜色
    
	bg_calc = lv_obj_create(lv_scr_act(), NULL);
//	lv_obj_add_style(bg_calc, LV_BTNMATRIX_PART_BG, &wingcool_bg_calc);
	lv_obj_set_size(bg_calc, LV_HOR_RES, LV_VER_RES);
	lv_obj_set_y(bg_calc, 0);

    lv_wingcool_calc_init();

//    add_title(bg_calc, "CALC");
//	add_title("CALC");
	lv_obj_t * back = add_back(back_to_home_event_cb_1);
}

static void lv_wingcool_calc_init(void)
{
    lv_obj_t * btnm = lv_btnmatrix_create(bg_calc, NULL);
//	lv_obj_t * btnm = lv_btnmatrix_create(lv_scr_act(), NULL);
	lv_obj_clean_style_list(btnm, LV_OBJ_PART_MAIN);
    lv_obj_set_width(btnm, LV_HOR_RES);
    lv_obj_set_height(btnm, LV_WINGCOOL_CALC_MAX_H);
    lv_btnmatrix_set_map(btnm, btnm_map);
	lv_obj_set_style_local_bg_color(btnm, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(0xf9f9f9));
    lv_obj_align(btnm, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, 0);
    lv_obj_set_event_cb(btnm, event_handler_btnmatrix);

	g_calc_ta = lv_textarea_create(bg_calc, NULL);
//	g_calc_ta = lv_textarea_create(lv_scr_act(), NULL);
    lv_obj_set_style_local_text_font(g_calc_ta, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_22);  // text font
    lv_obj_set_style_local_bg_color(g_calc_ta, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_obj_set_style_local_text_color(g_calc_ta, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_GREEN);
    lv_obj_set_style_local_radius(g_calc_ta, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_textarea_set_max_length(g_calc_ta, LV_WINGCOOL_CALC_HISTORY_MAX_LINE);
    lv_obj_set_size(g_calc_ta, LV_HOR_RES, LV_WINGCOOL_CALC_HISTORY_MAX_H);
    lv_textarea_set_text_align(g_calc_ta, LV_LABEL_ALIGN_RIGHT);
    lv_textarea_set_text(g_calc_ta, "");
    lv_textarea_set_placeholder_text(g_calc_ta, "CALC HISTORY");
//    lv_textarea_set_cursor_hidden(g_calc_ta, true);
    lv_obj_align(g_calc_ta, btnm, LV_ALIGN_OUT_TOP_MID, 0, 0);
}

static void event_handler_btnmatrix(lv_obj_t * obj, lv_event_t e)
{
    if(e == LV_EVENT_VALUE_CHANGED)
    {
        static char calc_exp[LV_WINGCOOL_CALC_EXPR_LEN];
        static  int count = 0;
        const char * txt = lv_btnmatrix_get_active_btn_text(obj);
        if (strcmp(txt, "=") == 0)
        {
            char tmp_buff[32];
            int calc_results;

            lv_wingcool_calc_tokenizer_init(calc_exp);

            calc_results = lv_wingcool_calc_expr();

            if (error_code != no_error)
            {
                for (int i = 0; i < sizeof(error_table); i++)
                {
                    if (error_table[i].error_code == error_code)
                    {
                        lv_textarea_add_text(g_calc_ta, "\n");
                        lv_textarea_add_text(g_calc_ta, error_table[i].message);
                        lv_textarea_add_text(g_calc_ta, "\n");
                        //printf("\n%s\n", error_table[i].message);
                    }
                }
                error_code = no_error;
            }
            else
            {
                sprintf(tmp_buff, "=\n%d\n", calc_results);
                lv_textarea_add_text(g_calc_ta, tmp_buff);
                memset(calc_exp, '\0',sizeof(calc_exp));
            }

        }
        else if (strcmp(txt, "C") == 0)
        {
            lv_textarea_set_text(g_calc_ta, "");
            memset(calc_exp, '\0',sizeof(calc_exp));
            count = 0;
        }

        else if (strcmp(txt, "<-") == 0)
        {
            lv_textarea_del_char(g_calc_ta);
            calc_exp[count-1] = '\0';
            count--;
        }

        else
        {
            lv_textarea_add_text(g_calc_ta, txt);
            strcat(&calc_exp[0], txt);
            count++;
        }
    }
}

static token_t lv_wingcool_calc_siglechar(void)
{
    switch (*curr_char)
    {
    case '+':
        return TOKENIZER_PLUS;
    case '-':
        return TOKENIZER_MINUS;
    case '*':
        return TOKENIZER_ASTR;
    case '/':
        return TOKENIZER_SLASH;
    case '(':
        return TOKENIZER_LPAREN;
    case ')':
        return TOKENIZER_RPAREN;
    default:
        break;
    }

    return TOKENIZER_ERROR;
}


static token_t lv_wingcool_calc_get_next_token(void)
{
    int i;

    if (curr_char == '\0')
        return TOKENIZER_ENDOFINPUT;

    if (isdigit(*curr_char))
    {
        for (i = 0; i <= LV_WINGCOOL_CALC_MAX_NUM_LEN; i++)
        {
            if (!isdigit(*(curr_char + i)))
            {
                next_char = curr_char + i;
                return TOKENIZER_NUMBER;
            }
        }
    }
    else if (lv_wingcool_calc_siglechar())
    {
        next_char++;
        return lv_wingcool_calc_siglechar();
    }

    return TOKENIZER_ERROR;
}

static bool lv_wingcool_calc_tokenizer_finished(void)
{
    return *curr_char == '\0' || current_token == TOKENIZER_ENDOFINPUT;
}

static void lv_wingcool_calc_error(error_t err)
{
    error_code = err;

    return;
}

static void lv_wingcool_calc_tokenizer_next(void)
{
    if (lv_wingcool_calc_tokenizer_finished())
        return;

    curr_char = next_char;
    current_token = lv_wingcool_calc_get_next_token();

    return;
}

static token_t lv_wingcool_calc_tokenizer_token(void)
{
    return current_token;
}

static int lv_wingcool_calc_tokenizer_num(void)
{
    return atoi(curr_char);
}

static void lv_wingcool_calc_accept(token_t token)
{
    if (token != lv_wingcool_calc_tokenizer_token())
        lv_wingcool_calc_error(syntax_error);

    lv_wingcool_calc_tokenizer_next();
}

static int lv_wingcool_calc_factor(void)
{
    int r = 999;	//这里由于编译器规则，没有赋值编译不过

    switch (lv_wingcool_calc_tokenizer_token())
    {
    case TOKENIZER_NUMBER:
        r = lv_wingcool_calc_tokenizer_num();
        lv_wingcool_calc_accept(TOKENIZER_NUMBER);
        break;
    case TOKENIZER_LPAREN:
        lv_wingcool_calc_accept(TOKENIZER_LPAREN);
        r = lv_wingcool_calc_expr();
        lv_wingcool_calc_accept(TOKENIZER_RPAREN);
        break;
    default:
        lv_wingcool_calc_error(syntax_error);
    }
    return r;
}

static int lv_wingcool_calc_term(void)
{
    int f1, f2;
    token_t op;

    f1 = lv_wingcool_calc_factor();
    op = lv_wingcool_calc_tokenizer_token();

    while (op == TOKENIZER_ASTR || op == TOKENIZER_SLASH)
    {
        lv_wingcool_calc_tokenizer_next();
        f2 = lv_wingcool_calc_factor();
        switch ((int)op)
        {
        case TOKENIZER_ASTR:
            f1 = f1 * f2;
            break;
        case TOKENIZER_SLASH:
            f1 = f1 / f2;
            break;
        }
        op = lv_wingcool_calc_tokenizer_token();
    }

    return f1;
}


static int lv_wingcool_calc_expr(void)
{
    int t1, t2 = 0;
    token_t op;

    t1 = lv_wingcool_calc_term();
    op = lv_wingcool_calc_tokenizer_token();

    while (op == TOKENIZER_PLUS || op == TOKENIZER_MINUS)
    {
        lv_wingcool_calc_tokenizer_next();
        t2 = lv_wingcool_calc_term();
        switch ((int)op)
        {
        case TOKENIZER_PLUS:
            t1 = t1 + t2;
            break;
        case TOKENIZER_MINUS:
            t1 = t1 - t2;
            break;
        }
        op = lv_wingcool_calc_tokenizer_token();
    }

    return t1;
}

static void lv_wingcool_calc_tokenizer_init(char *expr)
{
    curr_char = next_char = expr;
    current_token = lv_wingcool_calc_get_next_token();

    return;
}

LV_EVENT_CB_DECLARE(back_to_home_event_cb_1)
{
    if (e == LV_EVENT_CLICKED) {
        lv_wingcool_demo_anim_out_all(lv_scr_act(), 0);
        lv_wingcool_demo_anim_bg(0, LV_WINGCOOL_DEMO_WHITE, LV_WINGCOOL_DEMO_BG_FULL);
        home_open(0);
    }
}

