project( Tests CXX )

set( HEADER_FILES 
	${ROOT_DIR}/algorithm/remove_leading.hpp
)

set( SOURCE_FILES 
	algorithm/remove_leading_test.cpp
)

add_executable( tests main.cpp ${SOURCE_FILES} ${HEADER_FILES} test-api/catch.hpp )

target_include_directories( tests PRIVATE ${ROOT_DIR} )

if ( CMAKE_CXX_COMPILER_ID MATCHES "Clang|AppleClang|GNU" )
		target_compile_options( tests  PRIVATE -Wall -Wextra -Wunreachable-code )
endif()
if ( CMAKE_CXX_COMPILER_ID MATCHES "Clang" )
		target_compile_options( tests  PRIVATE -Wweak-vtables -Wexit-time-destructors -Wglobal-constructors -Wmissing-noreturn )
endif()
if ( CMAKE_CXX_COMPILER_ID MATCHES "MSVC" )
		target_compile_options( tests  PRIVATE /W4 /w44265 /WX )
endif()

target_compile_features( tests
	PRIVATE
		cxx_lambdas
		cxx_range_for
)
