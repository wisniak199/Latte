CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

LIST( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )
# ...
SET (CMAKE_CXX_STANDARD 14)

# set variable pointing to the antlr tool that supports C++
set(ANTLR4CPP_JAR_LOCATION ${PROJECT_SOURCE_DIR}/thirdparty/antlr/antlr-4.7.1-complete.jar)

# add external build for antlrcpp
include( ExternalAntlr4Cpp )

# Include the runtime to compile against
include_directories( ${ANTLR4CPP_INCLUDE_DIRS} )
link_directories( ${ANTLR4CPP_LIBS} )
message(STATUS "Found antlr4cpp libs: ${ANTLR4CPP_LIBS} and includes: ${ANTLR4CPP_INCLUDE_DIRS} ")

# Find LLVM
SET (LLVM_DIR "/home/wisniak199/mrjp/llvm-3.7.0/share/llvm/cmake/")
find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
include_directories(${LLVM_INCLUDE_DIRS})
llvm_map_components_to_libnames(llvm_libs support core irreader)

# Call macro to add lexer and grammar to your build dependencies.
antlr4cpp_process_grammar(demo latte
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/Latte.g4)
# include generated files in project environment
include_directories(${antlr4cpp_include_dirs_latte})


# add generated grammar to demo binary target
add_executable(test_antlr main.cpp LatteLLVMVisitor.cpp ${antlr4cpp_src_files_latte})
add_dependencies(test_antlr antlr4cpp antlr4cpp_generation_latte)
target_link_libraries(test_antlr antlr4-runtime ${llvm_libs})
