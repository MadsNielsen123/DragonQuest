cmake_minimum_required(VERSION 3.14)

project(DragonQuest LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)
find_package(Qt5 REQUIRED COMPONENTS Core Quick Sql)

add_executable(DragonQuest
  main.cpp
  terminal.h terminal.cpp
  backgroundcolor.h backgroundcolor.cpp
  textcolor.h textcolor.cpp
  format.h format.cpp
  character.h character.cpp
  hero.h hero.cpp
  monster.h monster.cpp
  battle.h battle.cpp
  databasehandler.h databasehandler.cpp
  bigtext.h bigtext.cpp
  cave.h cave.cpp
  magic.h magic.cpp
)
target_link_libraries(DragonQuest PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt5::Core Qt5::Quick Qt5::Sql)
