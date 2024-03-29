/*
	File:			CLConfig.h

	Function:		Contains configuration options for compiling the CL 
					library.
					
	Author(s):		Andrew Willmott

	Copyright:		Copyright (c) 1995-1996, Andrew Willmott
*/

//
//	Current options are as follows:
//
//	CL_CHECKING			- Do range checking on array accesses
//	CL_FLOAT			- Preferred math type is float, rather than double
//	CL_NO_BOOL			- Compiler has no bool type.
//	CL_NO_TF			- true and false are not predefined.
//  CL_TMPL_INST    	- use ANSI syntax to explicitly instantiate Array templates
//	CL_SGI_INST			- use sgi's weirdo instantiation syntax.
//	CL_NO_MEM_MAP		- no mmap call.
//	CL_HAS_VSNPRINTF	- has the vsnprintf call
//	CL_MACOS			- macos stuff (ancient)
//

// --- Configuration ----------------------------------------------------------
/*
#define CL_CONFIG sgi-n64
#define CL_SGI_INST
#define CL_64_BIT
*/
