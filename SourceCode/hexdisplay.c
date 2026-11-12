#include <stdint.h>

/*consts_atthetop*/
#define HEX_BASE1 (*(volatile int *)0xff200020)
#define HEX_BASE2 (*(volatile int *)0xff200030)

// Bit codes for displaying hexadecimal digits on a 7-segment display
const int BIT_CODES[16] = {0b00111111, 0b00000110, 0b01011011, 0b01001111,
                           0b01100110, 0b01101101, 0b01111101, 0b00000111,
                           0b01111111, 0b01100111, 0b01110111, 0b01111100,
                           0b00111001, 0b01011110, 0b01111001, 0b01110001};

/*hexdisplay.c*/

// There are two functions here:
// clear_HEX_DISP takes in the hex display number that needs to be switched off.
// HEX_DISP takes two arguments: the digit to be displayed and the hex display
// which it corresponds to

void clear_HEX_DISP(int hex_display) {
  int bit_pattern;
  volatile int *hex_base;
  int mask;
  int current_value;

  // Get the bit pattern for the digit
  bit_pattern = 0x0;
  int shifted_pattern;
  int current_hexoutput;

  // Determine which HEX display to use
  hex_base = (hex_display < 4) ? &HEX_BASE1 : &HEX_BASE2;

  if (hex_display == 5) {
    current_hexoutput = *hex_base & ~(0x7f00);  // zeroes out the relevant bits
    shifted_pattern = bit_pattern << 8;
    *hex_base = current_hexoutput | shifted_pattern;
  }

  if (hex_display == 4) {
    current_hexoutput = *hex_base & ~(0x7f);  // zeroes out the relevant bits
    shifted_pattern = bit_pattern;
    *hex_base = current_hexoutput | shifted_pattern;
  }

  if (hex_display == 3) {
    current_hexoutput =
        *hex_base & ~(0x7f000000);  // zeroes out the relevant bits
    shifted_pattern = bit_pattern << 24;
    *hex_base = current_hexoutput | shifted_pattern;
  }

  if (hex_display == 2) {
    current_hexoutput = *hex_base & ~(0x7f0000);  // zeroes out the relevant
                                                  // bits
    shifted_pattern = bit_pattern << 16;
    *hex_base = current_hexoutput | shifted_pattern;
  }

  if (hex_display == 1) {
    current_hexoutput = *hex_base & ~(0x7f00);  // zeroes out the relevant bits
    shifted_pattern = bit_pattern << 8;
    *hex_base = current_hexoutput | shifted_pattern;
  }

  if (hex_display == 0) {
    current_hexoutput = *hex_base & ~(0x7f);  // zeroes out the relevant bits
    shifted_pattern = bit_pattern;
    *hex_base = current_hexoutput | shifted_pattern;
  }
}
void HEX_DISP(int digit, int hex_display) {
  int bit_pattern;
  volatile int *hex_base;
  int mask_shift;
  int mask;
  int current_value;

  // Check if the display should be blanked
  if (digit & 0x10) {
    return;
  }

  // Extract the low-order 4 bits
  digit &= 0x0F;

  // Get the bit pattern for the digit
  bit_pattern = BIT_CODES[digit];
  bit_pattern &= 0x7f;
  int shifted_pattern;
  int current_hexoutput;

  // Determine which HEX display to use
  hex_base = (hex_display < 4) ? &HEX_BASE1 : &HEX_BASE2;

  if (hex_display == 5) {
    current_hexoutput = *hex_base & ~(0x7f00);  // zeroes out the relevant bits
    shifted_pattern = bit_pattern << 8;
    *hex_base = current_hexoutput | shifted_pattern;
  }

  if (hex_display == 4) {
    current_hexoutput = *hex_base & ~(0x7f);  // zeroes out the relevant bits
    shifted_pattern = bit_pattern;
    *hex_base = current_hexoutput | shifted_pattern;
  }

  if (hex_display == 3) {
    current_hexoutput =
        *hex_base & ~(0x7f000000);  // zeroes out the relevant bits
    shifted_pattern = bit_pattern << 24;
    *hex_base = current_hexoutput | shifted_pattern;
  }

  if (hex_display == 2) {
    current_hexoutput = *hex_base & ~(0x7f0000);  // zeroes out the relevant
                                                  // bits
    shifted_pattern = bit_pattern << 16;
    *hex_base = current_hexoutput | shifted_pattern;
  }

  if (hex_display == 1) {
    current_hexoutput = *hex_base & ~(0x7f00);  // zeroes out the relevant bits
    shifted_pattern = bit_pattern << 8;
    *hex_base = current_hexoutput | shifted_pattern;
  }

  if (hex_display == 0) {
    current_hexoutput = *hex_base & ~(0x7f);  // zeroes out the relevant bits
    shifted_pattern = bit_pattern;
    *hex_base = current_hexoutput | shifted_pattern;
  }
}
