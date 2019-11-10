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
	find_package(SDL2 CONFIG REQUIRED)
	target_link_libraries(breakoutc
		OpenGL::GL
		SDL2::SDL2 SDL2::SDL2main
	)
elseif(UNIX)
	find_package(OpenGL REQUIRED)
	find_package(GLEW REQUIRED)
	find_package(SDL2 CONFIG REQUIRED)
	target_link_libraries(breakoutc
		m
		${OPENGL_LIBRARIES}
		${GLEW_LIBRARIES}
		${SDL2_LIBRARIES}
	)
endif()
