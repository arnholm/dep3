#############################################################################
# Name:        CMakeListst.txt
# Purpose:     CMake file to build dep3
# Author:      Carsten Arnholm
# Created:     2020-12-21
#############################################################################

# Minimum required CMake version
cmake_minimum_required(VERSION 2.8)

# Name the project
project(dep3)

# Request the required wxWidgets libs
find_package(wxWidgets 3.0 COMPONENTS core base aui REQUIRED)

# Include the wxWidgets use file to initialize various settings
include(${wxWidgets_USE_FILE})

# Source files  
set(SRC_FILES
    dep3App.h
	 dep3App.cpp  
	 dep3DropTarget.h  
	 dep3DropTarget.cpp  
	 dep3Main.h 
	 dep3Main.cpp  
	 dep3Panel.h
	 dep3Panel.cpp
    )

# Executable build target
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Link required libraries
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
 
