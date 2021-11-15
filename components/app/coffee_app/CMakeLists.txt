set(COMPONENT_SRCS 
    src/coffee_app.c
#    src/coffee_bean.c
#    src/coffee_cup.c
#    src/coffee_flower.c
#    src/sky.c
    src/coffee.c
    src/cup.c
    src/tree.c
    )
set(COMPONENT_ADD_INCLUDEDIRS
    include
)
set(COMPONENT_PRIV_REQUIRES
    "lvgl"
)

register_component()
