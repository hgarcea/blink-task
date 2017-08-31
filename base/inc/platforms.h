/* Copyright 2014, ACSE & CADIEEL
 *    ACSE   : http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/
 *    CADIEEL: http://www.cadieel.org.ar
 * Copyright 2014, 2015 Mariano Cerdeiro
 * All rights reserved.
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef CIAAPLATFORMS_H
#define CIAAPLATFORMS_H
/** \brief Platform file
 **
 ** Platform header file
 **
 **/

/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */
/** \addtogroup Platform
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 * MaCe         Mariano Cerdeiro
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20140910 v0.0.1 MaCe add support for k60_120
 * 20140530 v0.0.1 initials initial version
 */

/*==================[inclusions]=============================================*/

/*==================[cplusplus]==============================================*/
#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/
/** \brief check for ARCH/CPUTYPE and CPU */
#ifndef ARCH
#error ARCH is not defined, this define shall be included in the compile \
   command
#endif

#ifndef CPUTYPE
#error CPUTYPE is not defined, this define shall be included in the compile \
   command
#endif

#ifndef CPU
#error CPU is not defined, this define shall be included in the compile \
   command
#endif

/****** ARCH macro definitions ******/
/** \brief ARCH cortexM4 */
#define cortexM4             1

/****** CPUTYPE macro definitions ******/
/*** CPUTYPES for ARCH=cortexM4 ***/
#define lpc43xx               1

/****** CPU macro definitions ******/
/*** CPU for ARCH=x86 CPUTYPE=ia32 ***/

/*** CPU for ARCH=x86 CPUTYPE=ia64 ***/

/*** CPU for ARCH=cortexM4 CPUTYPE=lpc43xx ***/
#define lpc4337               1

/****** BOARDS macro definitions ******/

/*** BOARD for ARCH=cortexM4 CPUTYPE=lpc43xx ***/
#define edu_ciaa_nxp          1

/*** BOARD for ARCH=cortexM4 CPUTYPE=lpc43xx ***/
#define i3d_ciaa_nxp          2

/****** CIAAPLATFORM_REGLENGTH ******/

/****** CIAAPLATFORM_ENDIANESS ******/
#define CIAAPLATFORM_BIGENDIAN      0
#define CIAAPLATFORM_LITTLEENDIAN   1
#if (ARCH == posix)
#define CIAAPLATFORM_ENDIANESS CIAAPLATFORM_LITTLEENDIAN
#endif

#if ( (ARCH == cortexM4) && (CPUTPYE == lpc43xx) )

#endif

#if ( ( ARCH == cortexM4 ) && \
        ( CPUTYPE == lpc43xx ) && \
        ( CPU == lpc4337 ) )
#else
#error the entered architecture is not supported... :(
#endif

/*==================[typedef]================================================*/

/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/

/*==================[cplusplus]==============================================*/
#ifdef __cplusplus
}
#endif
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
#endif /* #ifndef CIAAPLATFORMS_H */

