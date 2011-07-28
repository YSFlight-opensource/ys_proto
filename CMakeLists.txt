cmake_minimum_required(VERSION 2.6)
		
#Configuration du projet
project(ys_proto)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BUILD_TYPE})

find_package (Threads)

include_directories(include)

#Génération de la liste des fichiers sources
file(
	GLOB_RECURSE
	source_files
	src/*
	include/*
)

#Déclaration de l'exécutable
add_executable(
	ys_proto
	${source_files}
)

TARGET_LINK_LIBRARIES(ys_proto pthread)
