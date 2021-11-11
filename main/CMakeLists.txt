#idf_component_register(SRCS main.c)
#set(COMPONENT_SRCS
#	main.c
#	"style_app/style_app.c"
#	)
#set(COMPONENT_ADD_INCLUDEDIRS  "." "style_app")
set(COMPONENT_SRCS main.c)
set(COMPONENT_ADD_INCLUDEDIRS  ".")


register_component()