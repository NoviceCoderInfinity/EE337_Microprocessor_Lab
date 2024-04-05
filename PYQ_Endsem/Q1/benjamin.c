#include <stdio.h>
#include <at89c5131.h>
#include "serial.h"	
#include "mcp3008.h"

void update_samples(float samples[8], float to_add);
float calculate_output(float samples[8], float coefficients_array[8]);

void main(void) {
		float coefficients_array[8] = {0.02017993, 0.06489484, 0.16638971, 0.24853553, 0.24853553, 0.16638971, 0.06489484, 0.02017993};
		float samples[8] = {0};
		
		spi_init();	adc_init();
		
}

void update_samples(float samples[8], float to_add) {
		int i;
		for(i = 7; i > 0; --i) {
					samples[i] = samples[i-1]; }
		samples[0] = to_add;
}

float calculate_output(float samples[8], float coefficients_array[8]) {
		float output = 0; short iter;
		for (iter = 0; iter < 8; ++iter) {
				output += samples[iter] * coefficients_array[iter];
		}
		return output;
}