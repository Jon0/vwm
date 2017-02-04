
# executable names
set(VWM_NAME "vwm")


# executable files
file(GLOB VWM_FILES
	"main.c"
)


add_executable(
	${VWM_NAME}
	${VWM_FILES}
)


target_link_libraries(
	${VWM_NAME}
    	${DRM_LIBRARIES}
)
