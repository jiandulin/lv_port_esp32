#idf_component_register(SRCS main.c)
set(COMPONENT_SRCS
	src/style_app.c
	)

set(COMPONENT_ADD_INCLUDEDIRS  
	include 
	)

set(COMPONENT_PRIV_REQUIRES  "lvgl" )

register_component()