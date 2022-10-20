add_library(rc5_transmit rc5_transmit.c)

# invoke pio_asm to assemble state machine code
pico_generate_pio_header(rc5_transmit ${CMAKE_CURRENT_LIST_DIR}/rc5_carrier_burst.pio)
pico_generate_pio_header(rc5_transmit ${CMAKE_CURRENT_LIST_DIR}/rc5_carrier_control.pio)

target_link_libraries(rc5_transmit PRIVATE
        pico_stdlib
        hardware_pio
        )

target_include_directories (rc5_transmit PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_BINARY_DIR}
	)