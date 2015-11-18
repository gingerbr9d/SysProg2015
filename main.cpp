/*
 * main.cpp
 *
 *  Created on: Nov 11, 2015
 *      Author: arty
 */
#include "Scanner/includes/Scanner.h"
#include "Symboltable/includes/Symboltable.h"
#include <sys/time.h>
#include <iostream>
#include <unistd.h> /* for WRITE */
#include <fcntl.h>

/* copypasted piece of code for running-time measurements */
typedef unsigned long long timestamp_t;
static timestamp_t
get_timestamp ()
{
   struct timeval now;
   gettimeofday (&now, NULL);
   return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}

/* main test method */
int main(int argc, char* argv[]) {
    timestamp_t t0 = get_timestamp();

    /* open output file */
    /*
    char* filename = "out.txt";
    int fd = open(filename, O_WRONLY|O_CREAT|O_TRUNC, O_DIRECT);
    char* buffer = new char[50];
    int count = 50;
    int wrote = write(fd, buffer, count);
     */

    /* this code is taken from the Script*/
    /*   (c) Prof. Dr. Thomas FuchB      */
	if (argc < 1) return EXIT_FAILURE;
	Symboltable* stab = new Symboltable();
	Scanner* s = new Scanner(argv[1], stab);
	Token* t;
	while ((t = s->nextToken())) {
		//memcpy(buffer, t->)
		t->toString();
	}

	std::cout << "Time: " << (get_timestamp() - t0) / 1000000.0L << "secs"  << std::endl;
	return EXIT_SUCCESS;
}


