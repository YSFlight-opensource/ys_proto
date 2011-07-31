cmake_minimum_required(VERSION 2.8)
		
#Configuration du projet
project(ys_proto)
#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BUILD_TYPE})

#find_package (Threads)


set(LIBRARY_OUTPUT_PATH lib/${CMAKE_BUILD_TYPE})


include_directories(include)

#Génération de la liste des fichiers sources
#file(
#	GLOB_RECURSE
#	source_files
#	src/*
#	include/*
#)

file(
	GLOB_RECURSE
	lib_files
	src/debug.cpp
    src/stringarray.cpp
    src/serialization/*
    src/sockets/*
    src/types/*
	include/*
)


#Déclaration de l'exécutable
#add_executable(
#	ys_proto
#	${source_files}
#)

#TARGET_LINK_LIBRARIES(ys_proto pthread)
message(${CMAKE_HOST_SYSTEM_PROCESSOR})
add_library(
    _ys_proto 
    SHARED
    ${lib_files} 
)

if (FORCE_CPU STREQUAL "32bits")
    message("Compiling on 32bits")
    add_definitions(                        -m32)
    set(CMAKE_EXE_LINKER_FLAGS                "${CMAKE_EXE_LINKER_FLAGS} -m32")
    set(CMAKE_SHARED_LIBRARY_C_FLAGS        "${CMAKE_SHARED_LIBRARY_C_FLAGS} -m32")
    set(CMAKE_SHARED_LIBRARY_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_CXX_FLAGS} -m32")
    SET_TARGET_PROPERTIES(_ys_proto PROPERTIES OUTPUT_NAME "_ys_proto32")
endif (FORCE_CPU STREQUAL "32bits") 

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
   message("Doing the Windows version!") 
   set (LIBS ${LIBS}wsock32)
   target_link_libraries(_ys_proto wsock32)
endif (CMAKE_SYSTEM_NAME STREQUAL "Windows")

