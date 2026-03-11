cmake_minimum_required(VERSION 3.10)
project(komplikator)

# Wymuszenie standardu C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Znalezienie pakietu LLVM
find_package(LLVM REQUIRED CONFIG)

# Dodanie nagłówków LLVM do ścieżek wyszukiwania
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# Informacja dla kompilatora, gdzie szukać Twoich plików .h
include_directories(include)

# Definicja pliku wykonywalnego (pliki .cpp z katalogu lib)
add_executable(komplikator 
    src/lib/main.cpp 
    src/lib/Lexer.cpp
    src/lib/TokenTypes.cpp
)

# Linkowanie bibliotek LLVM (tutaj przykładowo Support i Core)
# Możesz dodać więcej komponentów w find_package, jeśli ich potrzebujesz
llvm_map_components_to_libnames(llvm_libs support core native)
target_link_libraries(komplikator ${llvm_libs})
