cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(bZero C CXX ASM)

add_executable(prod test.c)

pico_sdk_init()

pico_generate_pio_header(prod ${CMAKE_CURRENT_LIST_DIR}/blink.pio)

pico_enable_stdio_usb(prod 1)
pico_enable_stdio_uart(prod 1)
pico_add_extra_outputs(prod)

target_link_libraries(prod pico_stdlib hardware_pio)