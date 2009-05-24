#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <fcntl.h>
#include <memory.h>
#include <regex.h>
#include <getopt.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <linux/soundcard.h>

#define	LENGTH		1		/* how many seconds of speech to store */
#define	RATE			8000		/* the sampling rate */
#define	SIZE			8		/* sample size: 8 or 16 bits */
#define	CHANNELS		1		/* 1 = mono 2 = stereo */

#define	BUF_SIZE		2
#define	SAMPLE_SIZE	(int) (LENGTH*RATE*SIZE*CHANNELS/8)

#ifndef	M_PI
#define	M_PI		3.14159265358979323846
#endif

#define D_M_PI  6.28318530717958623199592693708837032318115234375

typedef unsigned char u8;
typedef unsigned int u32;

int init_dsp();
char* getline (FILE *fp);
char** preg_match (char *regex, char* s, int *size);
double fourier (int u, u8* buf, int N);
double ABS (double x);
char *strdup (__const char *__s);
int snprintf (char *__restrict __s, size_t __maxlen,
		     __const char *__restrict __format, ...)
     __THROW __attribute__ ((__format__ (__printf__, 3, 4)));
