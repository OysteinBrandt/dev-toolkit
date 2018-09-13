# move project command to top level?
#project(Tests)

include_directories("${PROJECT_SOURCE_DIR}/algorithm")
#include_directories("${PROJECT_SOURCE_DIR}/tests/test-api")
find_package(Catch2 REQUIRED)

if (MSVC)
	add_compile_options(/W4)
else()
	add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_executable(tests main.cpp)
target_link_libraries(tests Catch2::Catch2)

target_compile_features(tests
	PRIVATE
		cxx_lambdas
		cxx_range_for
	)
