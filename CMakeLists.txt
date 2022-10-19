cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(bZero C CXX ASM)

add_executable(prod main.c)
add_executable(test test.c)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

# pio header files
pico_generate_pio_header(prod ${CMAKE_CURRENT_LIST_DIR}/libs/transmit/nec/nec_carrier_burst.pio)
pico_generate_pio_header(prod ${CMAKE_CURRENT_LIST_DIR}/libs/transmit/nec/nec_carrier_control.pio)

#prod
pico_enable_stdio_usb(prod 1)
pico_enable_stdio_uart(prod 1)
pico_add_extra_outputs(prod)

target_link_libraries(prod pico_stdlib hardware_pio)

#test
pico_enable_stdio_usb(test 1)
pico_enable_stdio_uart(test 1)
pico_add_extra_outputs(test)

target_link_libraries(test pico_stdlib)
