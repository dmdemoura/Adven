cmake_minimum_required(VERSION 3.5)
project(Adven VERSION 1.0.5 LANGUAGES CXX ASM)

set(CPACK_PACKAGE_NAME libadven)
set(CPACK_PACKAGE_VENDOR placeholder)
set(CPACK_PACKAGE_CONTACT placeholder)

include(CPack)
include(GNUInstallDirs)

#Downloads CmakeStuff if not already downloaded
if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/external/CmakeStuff/.git)
    execute_process(COMMAND git submodule update --init -- external/CmakeStuff
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endif()
#Where CMake searches for find package modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/external/CmakeStuff/)

find_package(advencore)
find_package(libgbfs)

add_library(adven
    source/Scene.cpp
    source/Sprite.cpp
    source/Camera.cpp
    source/CircleCollider.cpp
    source/Collider.cpp
    source/Debug.cpp
    source/Fixed.cpp
    source/GameObject.cpp
    source/Math.cpp
    source/Moveable.cpp
    source/ObjectRenderer.cpp
    source/RectCollider.cpp
    source/main.cpp
    source/LoggingBuffer.cpp
    source/Log.cpp
    source/Input.cpp
)

target_include_directories(adven
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/include/adven
)
target_link_libraries(adven advencore tonc libgbfs)

#For instalation of static library files.
install(TARGETS adven
    EXPORT adven-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
#For instalation of include files.
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
#For installation of CMake config files. For find_package().
install(EXPORT adven-config DESTINATION ${CMAKE_INSTALL_DATADIR}/adven)