cmake_minimum_required(VERSION 3.8)
project(breakoutc)

add_executable(breakoutc
	game.c
	main.c
	math/math_mat2d.c
	math/math_vec2.c
	mixins/mix_collide.c
	mixins/mix_control_ball.c
	mixins/mix_control_brick.c
	mixins/mix_control_paddle.c
	mixins/mix_draw2d.c
	mixins/mix_move.c
	mixins/mix_transform2d.c
	scenes/scn_main.c
	systems/sys_collide.c
	systems/sys_control_ball.c
	systems/sys_control_brick.c
	systems/sys_control_paddle.c
	systems/sys_draw2d.c
	systems/sys_framerate.c
	systems/sys_move.c
	systems/sys_transform2d.c
)


if(MSVC)
	find_package(OpenGL REQUIRED)
	find_package(GLEW REQUIRED)
	find_package(SDL2 CONFIG REQUIRED)
	target_link_libraries(breakoutc
		OpenGL::GL
		GLEW::GLEW
		SDL2::SDL2 SDL2::SDL2main
	)
elseif(APPLE)
	find_package(OpenGL REQUIRED)
	find_library(SDL2_LIBRARY SDL2 "/Library/Frameworks")
	find_library(SDL2_App PRIVATE ${SDL2_LIBRARY})
	target_include_directories(breakoutc PRIVATE ${SDL2_INCLUDE_DIR})
	target_link_libraries(breakoutc
		${OPENGL_LIBRARIES}
		${SDL2_LIBRARY}
	)
elseif(UNIX)
	find_package(SDL2 CONFIG REQUIRED)
	target_link_libraries(breakoutc m ${SDL2_LIBRARIES})
endif()
