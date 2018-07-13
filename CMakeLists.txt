cmake_minimum_required(VERSION 2.8)
project( test_opencv )

find_package( OpenCV REQUIRED )

SET( SRCS )
aux_source_directory( "." SRCS )
add_executable( ${CMAKE_PROJECT_NAME} ${SRCS} )

target_link_libraries( ${CMAKE_PROJECT_NAME} ${OpenCV_LIBS} )
