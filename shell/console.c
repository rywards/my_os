/*
* Function terminal_print_line appended from 
* code written by Professor McKee
* by Ryan Edwards
*/

#include "console.h"

// function to print characters to screen
void terminal_print_line(char* string){

	unsigned int i = 0;
	int remain = 160;
	while (string[i] != '\0') {

		VGA_MEMORY[CURR_LOC] = string[i];
		VGA_MEMORY[CURR_LOC + 1] = 0x02;
		i++;
		remain = remain - 2;
		CURR_LOC = CURR_LOC + 2;

	}
	
	//CURR_LOC = CURR_LOC + remain;
	return;
}

// Function to shift up one line in console
void shift_line(int number){

	int lines = 2 * number;

	// Just took what was in VGA_MEMORY and added 
	// the width to what's printed
	for (int i = 0; i < TOTAL_DISPLAY; i++){

		VGA_MEMORY[i] = VGA_MEMORY[i + lines*VGA_WIDTH];	
	}

	return;
}

void putchar(char string){

	int remain = 160;
	
	VGA_MEMORY[CURR_LOC] = string;
	VGA_MEMORY[CURR_LOC + 1] = 0x02;
	

	remain = remain - 2;
	CURR_LOC = CURR_LOC + 2;

	
	//CURR_LOC = CURR_LOC + remain;

	return;
}

int check_exit(){
	
	if ((VGA_MEMORY[CURR_LOC-2] == 't') && (VGA_MEMORY[CURR_LOC-4] == 'i') && 			
	    (VGA_MEMORY[CURR_LOC-6] == 'x') && (VGA_MEMORY[CURR_LOC-8] == 'e')){
		return TERM_NUM;
	}
}
