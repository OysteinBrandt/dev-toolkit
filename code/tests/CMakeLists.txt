project( Tests CXX )

include_directories( "${PROJECT_SOURCE_DIR}/../" )

add_executable( tests main.cpp algorithm/remove_leading_test.cpp test-api/catch.hpp )

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
