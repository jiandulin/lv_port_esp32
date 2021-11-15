set(COMPONENT_SRCS src/touch_app.c)
set(COMPONENT_ADD_INCLUDEDIRS
    include
)
set(COMPONENT_PRIV_REQUIRES
    led_strip
#    board
)

register_component()
