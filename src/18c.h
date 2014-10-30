/* 
 * File:   18c.h
 * Author: D300-01
 *
 * Created on January 1, 2005, 7:56 PM
 */

#ifndef _18C_H
#define	_18C_H

#if defined(__XC)
	#include <xc.h>
#elif defined(__18CXX)
	#include <P18F4520.h>
#else
    #include "p18f4520.h"
#endif

#endif	/* 18C_H */

