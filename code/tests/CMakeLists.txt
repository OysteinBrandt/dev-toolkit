project( Tests CXX )

add_executable( tests main.cpp )

# TEST API
target_sources( tests
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/test-api/catch.hpp
)

# HEADER_FILES
target_sources( tests
	PRIVATE
		${ROOT_DIR}/algorithm/combination.hpp
		${ROOT_DIR}/algorithm/remove_leading.hpp
)

# SOURCE_FILES
target_sources( tests
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/algorithm/combination_test.cpp
		${CMAKE_CURRENT_LIST_DIR}/algorithm/remove_leading_test.cpp
)

target_include_directories( tests PRIVATE ${ROOT_DIR} )
target_include_directories( tests PRIVATE ${CMAKE_CURRENT_LIST_DIR}/test-api/ )

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
		cxx_std_17
)
