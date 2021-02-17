#include "./shell/console.h"
#include "./io/io.h"

void kernel_early(void) {
}

// Driver to test functionality
int main(void) {

	unsigned char byte;
	int check;
	while(1){

		while( byte = scan()){

			putchar(charmap[byte]);

		};
		
		// exit condition check
		check = check_exit();
		if (check == TERM_NUM){
			shift_line(1);
			terminal_print_line(EXIT_MSG);
			break;
		}
	};

		
	return 0;
}

