cmake_minimum_required(VERSION 3.11.3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_GENERATOR_PLATFORM x64)

project(Main)

add_library(
    Main SHARED
    src/dll/dll.cpp
    src/dll/hook/opengl32.cpp
    src/main/main.cpp
    src/main/jni.cpp
    src/menu/menu.cpp
    
    
    src/classes/minecraft/entity/entity.cpp
    src/classes/minecraft/world/world.cpp
    src/classes/minecraft/render/render.cpp
    src/classes/minecraft/render/matrixstack.cpp
    src/classes/minecraft/local/local.cpp
    
    src/system/system.cpp
    src/utils/crypt/crypt.cpp

    #min hook 
    src/complement/minhook/buffer.c
    src/complement/minhook/trampoline.c
    src/complement/minhook/hook.c
    src/complement/minhook/hde/hde64.c

    src/utils/Vector/Vector.cpp

    #cheat 
    src/cheat/cheat.cpp

    #imgui
    src/complement/imgui/imgui_impl_opengl3.cpp
    src/complement/imgui/imgui_impl_win32.cpp
    src/complement/imgui/imgui_custom.cpp
)

# import lib
target_link_directories(Main PUBLIC ${PROJECT_SOURCE_DIR}/src/complement/java/jdk/lib)
target_link_directories(Main PUBLIC ${PROJECT_SOURCE_DIR}/src/complement/minhook)
target_link_directories(Main PUBLIC ${PROJECT_SOURCE_DIR}/src/complement/imgui)
target_link_libraries(Main jvm.lib libMinHook-x64.lib imgui.lib)

