/* Library galileogpio, easy access to Intel Galileo GPIOs.
 * 
 * Copyright (c) 2015, Augusto Damasceno(@augustomatheuss), Carlos Bentzen(@cadubentzen), Sérgio Roza(@kalmik).
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 * 
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 */

#include "galileogpio.h"

// File manipulation

int writeString (char * f, char * t)
{
    FILE * rF;
    rF = fopen(f,"r+");
    if (rF == NULL)
    {
	return -1;
    }
    fprintf (rF,"%s",t);
    fclose (rF);
    return 0;
}

int writeInt (char * f, int t)
{
    FILE * rF;
    rF = fopen(f,"r+");
    if (rF == NULL)
    {
	return -1;
    }
    fprintf (rF,"%d",t);
    fclose (rF);
    return 0;
}


int readString (char * f, char * t)
{
    FILE * rF;
    rF = fopen (f,"r+");
    if (rF == NULL)
    {
        return -1;
    }
    fscanf (rF,"%s",t);
    fclose (rF);
    return 0;
}

int readInt (char * f)
{
    FILE * rF;
    int value;
    rF = fopen (f,"r+");
    if (rF == NULL)
    {
        return -1;
    }
    fscanf (rF,"%d",&value);
    fclose (rF);
    return value;
}

// Digital IOs

int exportIO(unsigned char n)
{
    int r;
    switch (n)
    {
        case (IO0):
            r = writeInt("/sys/class/gpio/export",IO0);
            r += writeInt("/sys/class/gpio/export",IO0A);
            r += direction(IO0A,OUT);
            r += setDigital(IO0A,HIGH);
            return r;
            break;
        case (IO1):
            r = writeInt("/sys/class/gpio/export",IO1);
            r += writeInt("/sys/class/gpio/export",IO1A);
            r += direction(IO1A,OUT);
            r += setDigital(IO1A,HIGH);
            return r;
            break;
        case (IO2):
            r = writeInt("/sys/class/gpio/export",IO2);
            r += writeInt("/sys/class/gpio/export",IO2A);
            r += direction(IO2A,OUT);
            r += setDigital(IO2A,HIGH);
            return r;
            break;
        case (IO3):
            r = writeInt("/sys/class/gpio/export",IO3);
            r += writeInt("/sys/class/gpio/export",IO3A);
            r += direction(IO3A,OUT);
            r += setDigital(IO3A,HIGH);
            return r;
            break;
        case (IO10):
            r = writeInt("/sys/class/gpio/export",IO10);
            r += writeInt("/sys/class/gpio/export",IO10A);
            r += direction(IO10A,OUT);
            r += setDigital(IO10A,HIGH);
            return r;
            break;
        case (IO11):
            r = writeInt("/sys/class/gpio/export",IO11);
            r += writeInt("/sys/class/gpio/export",IO11A);
            r += direction(IO11A,OUT);
            r += setDigital(IO11A,HIGH);
            return r;
            break;
        case (IO12):
            r = writeInt("/sys/class/gpio/export",IO12);
            r += writeInt("/sys/class/gpio/export",IO12A);
            r += direction(IO12A,OUT);
            r += setDigital(IO12A,HIGH);
            return r;
            break;
        case (IO13):
            r = writeInt("/sys/class/gpio/export",IO13);
            r += writeInt("/sys/class/gpio/export",IO13A);
            r += direction(IO13A,OUT);
            r += setDigital(IO13A,HIGH);
            return r;
            break;
        default:
            return writeInt("/sys/class/gpio/export",n);
    }
}

int unexportIO(unsigned char n)
{
    int r;
    switch (n)
    {
        case (IO0):
            r = writeInt("/sys/class/gpio/unexport",IO0);
            r += writeInt("/sys/class/gpio/unexport",IO0A);
            return r;
            break;
        case (IO1):
            r = writeInt("/sys/class/gpio/unexport",IO1);
            r += writeInt("/sys/class/gpio/unexport",IO1A);
            return r;
            break;
        case (IO2):
            r = writeInt("/sys/class/gpio/unexport",IO2);
            r += writeInt("/sys/class/gpio/unexport",IO2A);
            return r;
            break;
        case (IO3):
            r = writeInt("/sys/class/gpio/unexport",IO3);
            r += writeInt("/sys/class/gpio/unexport",IO3A);
            return r;
            break;
        case (IO10):
            r = writeInt("/sys/class/gpio/unexport",IO10);
            r += writeInt("/sys/class/gpio/unexport",IO10A);
            return r;
            break;
        case (IO11):
            r = writeInt("/sys/class/gpio/unexport",IO11);
            r += writeInt("/sys/class/gpio/unexport",IO11A);
            return r;
            break;
        case (IO12):
            r = writeInt("/sys/class/gpio/unexport",IO12);
            r += writeInt("/sys/class/gpio/unexport",IO12A);
            return r;
            break;
        case (IO13):
            r = writeInt("/sys/class/gpio/unexport",IO13);
            r += writeInt("/sys/class/gpio/unexport",IO13A);
            return r;
            break;
        default:
            return writeInt("/sys/class/gpio/unexport",n);
    }
}

int direction(unsigned char n, unsigned char * d)
{
    char f [34];
    sprintf(f,"/sys/class/gpio/gpio%d/direction",n);
    return writeString(f,d);
}

int drive(unsigned char n, unsigned char * d)
{
	char f [30];
    sprintf(f,"/sys/class/gpio/gpio%d/drive",n);
    return writeString(f,d);	
}

int setDigital(unsigned char n, unsigned char d)
{
    char f [30];
    sprintf(f,"/sys/class/gpio/gpio%d/value",n);
    return writeInt(f,d);
}

int getDigital(unsigned char n)
{
    char f [30];
    sprintf(f,"/sys/class/gpio/gpio%d/value",n);
    return readInt(f);
}

// Analog Inputs
/*
int exportAnalog (unsigned char n)
{
	switch(n)
	{
		case ANALOG0:
			return -!(!exportIO(ADMUX0) && !direction(OUT) && !setValue(LOW));
			break;
		case ANALOG1:
			return -!(!exportIO(ADMUX1) && !direction(OUT) && !setValue(LOW));
			break;
		case ANALOG2:
			return -!(!exportIO(ADMUX2) && !direction(OUT) && !setValue(LOW));
			break;
		case ANALOG3:
			return -!(!exportIO(ADMUX3) && !direction(OUT) && !setValue(LOW));
			break;
		case ANALOG4:
			return -!(!exportIO(ADMUX4A) && !direction(OUT) && !setValue(LOW) && !exportIO(ADMUX4B) && !direction(OUT) && !setValue(HIGH));
			break;
		case ANALOG5:
			return -!(!exportIO(ADMUX5A) && !direction(OUT) && !setValue(LOW) && !exportIO(ADMUX5B) && !direction(OUT) && !setValue(HIGH));
			break;
		default:
			return -1;
			break;
	}
}

int getAnalog(unsigned char n)
{
	char f[51];
	sprintf(f,"/sys/bus/iio/devices/iio:device0/in_voltage%d_raw",n);
	return readInt(f);
}
*/