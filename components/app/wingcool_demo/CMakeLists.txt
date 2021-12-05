set(COMPONENT_SRCS 
    "src/lv_wingcool_demo.c"
    "src/lv_wingcool_demo_theme.c"
    "src/wingcool_game_2048.c"
    "src/wingcool_general_calc.c"
    )
set(COMPONENT_ADD_INCLUDEDIRS
    include
    )
list(APPEND COMPONENT_SRCS "assets/img_1.c"
    "assets/img_2.c"
    "assets/img_3.c"
    "assets/img_4.c"
    "assets/img_5.c"
    "assets/img_6.c"
    "assets/img_7.c"
    "assets/img_8.c"
    "assets/img_9.c"
    "assets/sky_320x240.c"
    "assets/yg_logo.c"
    "assets/wingcool_logo.c"
    )
set(COMPONENT_PRIV_REQUIRES
    "lvgl"
    "lv_lib_png"
)

register_component()
