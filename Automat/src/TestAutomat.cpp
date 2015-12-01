#include "../includes/Automat.h"
#include <iostream>

#define WSP_Z 12
#define CLSC_Z 16
int main (int argc, char* argv[]){
	Automat* automat = new Automat();
	char* input = "12ddf var koo 34  <:> d @";

	int i = 0;
	char c = input[i];
	while (c != '\0') {
		// process next symbol
		int back_steps = automat->read(c);
		// output current state only iff it's not dealing with so called 'look ahead'
		if (back_steps == 0) {
			std::cout << "char: " << c << "   state: " << automat->getFinalState() << std::endl;
		}
		// adjust out pointer position & read the next symbol from input
		i = i + 1 - back_steps;
		c = input[i];
		// reset automat iff a new lexem was found during processing
		if (automat->isLexemReady()) {
			automat->reset();
		}


	}



	std::cout << "===========================" << std::endl;
	Position* p = new Position();
	p->update('a'); p->update('a'); p->update('a'); p->update('a'); // 1,4
	p->update('\0'); p->update('\0'); p->update('\0'); 				// 4,4
	std::cout << "col> " << p->seekColumnWithOffset(0) << std::endl;
	std::cout << "line> " << p->seekLineWithOffset(0) << std::endl << std::endl;

		p->update(5);
		std::cout << "> " << p->seekLineWithOffset(0) << ":" <<p->seekColumnWithOffset(0) << std::endl;

	p->update('a');
	p->update('a'); p->update('\0');p->update('\0'); p->update('a'); p->update('a'); p->update('\0'); // 1,4
		p->update('\0');

}
