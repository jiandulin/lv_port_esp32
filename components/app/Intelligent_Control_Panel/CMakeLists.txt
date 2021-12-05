set(COMPONENT_SRCS src/control_pannel_app.c)
set(COMPONENT_ADD_INCLUDEDIRS
    include
)
list(APPEND COMPONENT_SRCS "assets/img_1.c"
    "assets/img_4.c"
    "assets/img_5.c"
    "assets/img_6.c"
    "assets/img_8.c"
    "assets/img_9.c"
    "assets/sky_320x240.c"
    )
set(COMPONENT_PRIV_REQUIRES
    "lvgl"
    "lv_lib_png"
)

register_component()
