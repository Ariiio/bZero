add_library(samsung_transmit samsung_transmit.c)

# invoke pio_asm to assemble state machine code
pico_generate_pio_header(samsung_transmit ${CMAKE_CURRENT_LIST_DIR}/samsung_carrier_burst.pio)
pico_generate_pio_header(samsung_transmit ${CMAKE_CURRENT_LIST_DIR}/samsung_carrier_control.pio)

target_link_libraries(samsung_transmit PRIVATE
        pico_stdlib
        hardware_pio
        )

target_include_directories (samsung_transmit PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_BINARY_DIR}
	)