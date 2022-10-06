#define LED_PIN 13
#define BTN_PIN 12

#define NEC_FREQ 38000.0
#define NEC_START 9000.0
#define NEC_GAP 4500.0
#define NEC_PULSE 562.0
#define NEC_EXTENDED 1687.0

#define SAMSUNG_FREQ 37900.0
#define SAMSUNG_START 4500.0
#define SAMSUNG_PULSE 590.0
#define SAMSUNG_EXTENDED 1690.0

#define RC5_PULSE 889.0

#define SIRC_FREQ 40000.0
#define SIRC_START 2400.0
#define SIRC_PULSE 600.0
#define SIRC_EXTENDED 1200.0

int bit_len(unsigned int n)
void int_to_bin_digit(unsigned int in, int len_digitis, int *out_digit)
int invert_binary(int num, int bits)
void pulsate(int freq, int increment)
void control_led(int array[], int len, int led, int freq, int interval, int zDelay, int oDelay)
void control_led_SIRC(int array[], int len, int led, int zFreq, int oFreq, int interval, int delay)
// void LORENZMACHWAS()
void reverse_arr(int arr[], int n)
int check_len(int len, int bits)
