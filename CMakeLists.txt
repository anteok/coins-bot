cmake_minimum_required(VERSION 3.28)
project(Qt-CMake-Coins-Bot)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/usr/lib/cmake/Qt6")

find_package(Qt6 COMPONENTS
        Core
        Sql
        REQUIRED)

add_executable(coins-bot main.cpp
        db/tables/user.cpp
        db/tables/user.h
        db/connector.cpp
        db/connector.h
        db/tables/balance.cpp
        db/tables/balance.h
)
target_link_libraries(coins-bot
        Qt::Core
        Qt6::Sql
)

