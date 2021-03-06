/*
 * Copyright (c) 2010 by Cristian Maglie <c.maglie@bug.st>
 * SPI Master library for arduino.
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 */

#ifndef _SPI_H_
#define _SPI_H_

#include <stdio.h>
#include <stdint.h>
//#include <Arduino.h>
//#include <avr/pgmspace.h>
#include "armcmx.h"

#include "spi_core.h"

class SPIBus {
	SPIDef * SPIx;
	GPIOPin sck, miso, mosi, nss;
	
public:
	SPIBus(SPIDef * port, 
		GPIOPin sckpin, GPIOPin misopin, GPIOPin mosipin, GPIOPin nsspin) : 
    SPIx(port), sck(sckpin), miso(misopin), mosi(mosipin), nss(nsspin)  {}

  // SPI Configuration methods

//  inline static void attachInterrupt();
//  inline static void detachInterrupt(); // Default

  void begin(); // Default
  void begin(GPIOPin pinsck, GPIOPin pinmiso, GPIOPin pinmosi, GPIOPin pinnss);
  void end();

	
  uint32 transfer(uint32 _data) {
    return SPI_transfer(SPIx, _data);
    //return SPI_receive(SPIPort, _data);
	}
  
  /*
  inline uint16 send(uint16 _data) {
    return SPI_send(SPIPort, _data);
  }
  
  inline uint16 receive(uint16 _data) {
    return SPI_receive(SPIPort, _data);
  }
  */
  
  inline void setDataSize(uint32 dss) {
    SPI_datasize(SPIx, dss);
  }
  
	inline void setBitOrder(uint32 bitOrder) {
		//SPI_setBitOrder(port, bitOrder);
	}

	inline void setDataMode(uint32 mode) {
		SPI_mode(SPIx, mode);
	}

	inline void setClockDivider(uint32 rate) {
		SPI_clock(SPIx, rate);
	}
	
	inline void setMode(uint32 clkdiv, uint32 cpol, uint32 cpha, uint32 msbfirst) {
		//SPI_setMode(port, clkdiv, cpol, cpha, msbfirst);
	}
	
};

extern SPIBus SPI0, SPI1; // sck, miso, mosi, cs


/*
void SPIClass::attachInterrupt() {
  SPCR |= _BV(SPIE);
}

void SPIClass::detachInterrupt() {
  SPCR &= ~_BV(SPIE);
}
*/

#endif
