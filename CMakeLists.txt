cmake_minimum_required(VERSION 3.8)
project(breakoutc)

add_executable(breakoutc
	game.c
	main.c
	math_mat2d.c
	mix_transform2d.c
	sys_draw2d.c
	sys_framerate.c
	sys_transform2d.c
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
