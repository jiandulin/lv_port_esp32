cmake_minimum_required(VERSION 3.5)

set(EXTRA_COMPONENT_DIRS 
    "components/app/style_app"
    "components/app/led_strip"
    "components/app/touch_app"
    "components/app/astronaut_app"
    "components/app/coffee_app"
    "components/app/arc_app"
#    "components/app/Intelligent_Control_Panel"
    "components/app/wingcool_demo"
    )

if (NOT DEFINED PROJECT_NAME)
    include($ENV{IDF_PATH}/tools/cmake/project.cmake)
    project(lvgl-demo)
else()
    message(FATAL_ERROR "LV PORT ESP32: This must be a project's main CMakeLists.txt.")
endif()
