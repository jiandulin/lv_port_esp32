set(COMPONENT_SRCS src/astronaut.c)
set(COMPONENT_ADD_INCLUDEDIRS
    include
)
list(APPEND COMPONENT_SRCS "taikong/taikong001.c"
    "taikong/taikong002.c"
    "taikong/taikong003.c"
    "taikong/taikong004.c"
    "taikong/taikong005.c"
    "taikong/taikong006.c"
    "taikong/taikong007.c"
    "taikong/taikong008.c"
    "taikong/taikong009.c"
    "taikong/taikong010.c"
#    "taikong/myeye.c"
#	"taikong/example.c"
#	"taikong/example_gif.c"
	"taikong/50.c"
	"taikong/haqian.c"
#	"taikong/so.c"
    )
set(COMPONENT_PRIV_REQUIRES
    "lvgl"
#    "lv_lib_png"
    "lv_lib_gif"
)

register_component()
