Project (voronoi)
CMake_Minimum_Required (VERSION 3.1)

include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2_GFX REQUIRED SDL2_gfx)

add_compile_options(-Wall -Wempty-body -Werror -Wstrict-prototypes -Werror=maybe-uninitialized -Warray-bounds -g)

#Add the include directories of the (found) libraries.
Include_Directories(
 	${SDL2_INCLUDE_DIRS}
  ${SDL2_GFX_INCLUDE_DIRS}
)

file(GLOB SOURCES  src/*.c src/*/*.c src/*.h src/*/*.h)

SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

Add_Executable (${CMAKE_PROJECT_NAME} ${SOURCES})
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 20)

Target_Link_Libraries (
 	${CMAKE_PROJECT_NAME}
 	${SDL2_LIBRARIES}
  ${SDL2_GFX_LIBRARIES}
 	m
)
