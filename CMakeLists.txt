cmake_minimum_required(VERSION 3.16)
project(ProjetIA)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_DIR "/opt/homebrew/opt/sfml/lib/cmake/SFML")

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System Audio)

add_executable(ProjetIA
        ProjetIA/ProjetIA.cpp
        ProjetIA/Character.cpp
        ProjetIA/Batiment1.cpp
        ProjetIA/Batiment2.cpp
        ProjetIA/Batiment3.cpp
        ProjetIA/Batiment4.cpp
        ProjetIA/Bouton.cpp
        ProjetIA/Scene.cpp
        ProjetIA/Input.cpp
        ProjetIA/Play.cpp
        ProjetIA/Quit.cpp
        ProjetIA/Character2.cpp
        ProjetIA/Way.cpp
)

target_link_libraries(ProjetIA
        SFML::Graphics
        SFML::Window
        SFML::System
        SFML::Audio
)