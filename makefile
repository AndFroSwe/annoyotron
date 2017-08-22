# Makefile for annoyotron project

# Compiler options
CC = avr-gcc
MCU_TARGET = atmega328p
OPTIMIZE = -O2
CFLAGS = -Wall -pedantic -mmcu=$(MCU_TARGET) -g $(OPTIMIZE)
OBJCOPY = avr-objcopy
# AVRDUDE options
PART = m328p
PROGRAMMER = atmelice_isp

# Compilations
all: annoyotron.elf annoyotron.hex flash

build: annoyotron.elf annoyotron.hex flash

clean:
	rm -f *.o *.elf *.hex

flash:
	avrdude -p $(PART) -c $(PROGRAMMER) -U flash:w:annoyotron.hex

annoyotron.o: annoyotron.c annoyotron.h
	$(CC) $(CFLAGS) -c -o $@ $<

annoyotron.elf: annoyotron.o
	$(CC) $(CFLAGS) -o $@ $<

annoyotron.hex: annoyotron.elf
	$(OBJCOPY) -j .text -j .data -O ihex $< $@

.PHONY: all clean flash
