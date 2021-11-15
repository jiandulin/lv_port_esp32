#include "style_app.h"
#include "touch_app.h"
//#include "astronaut.h"
#include "coffee_app.h"


void user_app(void)
{
	touch_app_init();
    //ks_esp_cam_init();
    //astronaut_start();
    lvgl_coffee_init();
}