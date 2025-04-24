/*
 * avr.h
 *
 * Created: 4/20/2025 9:49:30 PM
 *  Author: Phil & Ami 
 */ 
#ifndef _AVR_H_
#define _AVR_H_

#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/io.h>

#define XTAL_FRQ 8000000lu

#define SET_BIT(p,i) ((p) |= (1 << (i)))
#define CLR_BIT(p,i) ((p) &=~(1 << (i)))
#define GET_BIT(p,i) ((p) & (1 << (i)))

#define NOP() asm volatile ("nop"::)
void avr_wait(unsigned short msec);

#endif /*_AVR_H_*/