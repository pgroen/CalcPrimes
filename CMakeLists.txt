#
# Copyright (c) 2022 Peter M. Groen
#
# This source code is licensed under the MIT license found in the 
# LICENSE file in the root directory of this source tree.
#
cmake_minimum_required(VERSION 3.16)
LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/submodules/cmake)

include(projectheader)
project_header(calcprimes)

find_package( Qt5Core       REQUIRED )
find_package( Qt5Gui        REQUIRED )
find_package( Qt5Widgets    REQUIRED )

include_directories( SYSTEM
    ${Qt5Core_INCLUDE_DIRS}
    ${Qt5Gui_INCLUDE_DIRS}
    ${Qt5Widgets_INCLUDE_DIRS}
)

include(compiler)

set(SRC_LIST
    ${CMAKE_SOURCE_DIR}/src/calcprime.cpp
    ${CMAKE_SOURCE_DIR}/src/calcprime_form.cpp
    ${CMAKE_SOURCE_DIR}/src/main.cpp
)

include(qtuic)
create_ui( SRC_LIST UIC_LIST
    ${CMAKE_SOURCE_DIR}/src/calcprime_form.ui
)

include(qtmoc)
create_mocs( SRC_LIST MOC_LIST
    ${CMAKE_SOURCE_DIR}/src/calcprime.h
    ${CMAKE_SOURCE_DIR}/src/calcprime_form.h
)

add_executable( ${PROJECT_NAME}
    ${SRC_LIST}
)

target_link_libraries(
    ${PROJECT_NAME}
    ${Qt5Core_LIBRARIES}
    ${Qt5Gui_LIBRARIES}
    ${Qt5Widgets_LIBRARIES}
)

set_target_properties( ${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/archive
)

include(installation)
install_application()
