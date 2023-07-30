cmake_minimum_required(VERSION 3.27.0)
set(CMAKE_C_REQUIRED 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # For the LSP

project(mstr VERSION 0.1)

add_library(
  mstr 
  mstr.h 
  mstr.c
)

# Will install the project to be able to be used as a CLI command
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
