cmake_minimum_required(VERSION 3.8)

project(QM)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory("extern/SFML")

set(SFML_STATIC_LIBRARIES TRUE)

set(Includes
	"extern/SFML/include"
)

set(LibrariesRelease
	sfml-system
	sfml-window
    sfml-graphics
)
set(LibrariesDebug
	sfml-system
	sfml-window
    sfml-graphics
)

file(GLOB_RECURSE src
	src/*.cpp
	src/*.h)

include_directories(${Includes})

add_executable(QM ${src})

foreach(lib ${LibrariesDebug})
	target_link_libraries(QM debug ${lib})
endforeach()
foreach(lib ${LibrariesRelease})
	target_link_libraries(QM optimized ${lib})
endforeach()
