#idf_component_register(SRCS main.c)
set(COMPONENT_SRCS
	"style_app.c"
	)
set(COMPONENT_ADD_INCLUDEDIRS  "." )
set(COMPONENT_PRIV_REQUIRES  "lvgl" )

register_component()