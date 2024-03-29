/**************************************************
*    Author: Frank Dockhorn
*    Copyright 2001 - 2006
*    Application: Four wins
***************************************************/


/*
	File:			Array.h

	Function:		Defines an array type that manages its own storage space,
					and can be used as a stack or a list.
					
	Author(s):		Andrew Willmott

	Copyright:		(c) 1995-2000, Andrew Willmott
 */
#include "Basics.h"


#ifndef __ARRAY__
#define __ARRAY__


#define TMPLArray	template<class T>
#define TArray		Array<T>


const Int kFirstAllocation = 6;//16; // Default number of items to initially 
								 // allocate to the array
const Int THRESHOLD = 127;

TMPLArray class Array
{
public:
					Array();
					Array(UInt32 size, Int alloc = kFirstAllocation);		
					Array(const TArray &array);
				   ~Array();
	
//	Array operators
	
	inline T		&operator [] (Int i);		///< Indexing operator
	inline const T	&operator [] (Int i) const; ///< Indexing operator
	inline Int		NumItems() const;			///< Number of items in the array
	
	TArray			&operator = (const TArray &array);	///< Assignment!
//	Useful for stack implementations

	inline T		&Top();						///< Return top of stack
	inline Void		Pop();						///< Delete top of stack
	inline Void		Push(const T &t);			///< Push item onto stack  
	
// List Operations

	inline Void		Append(const T &t);			///< Append single item to array

	inline T		&Last();					///< Return last item in array
	Void			Clear();					///< Delete all items
    Void			Reset();	
	Void			ResetItemCount();

	Void			PreAllocate(UInt32 numItems);///< Preallocate space for array
	Void			SetSize(Int newSize);		///< Set array size directly.
	Void			Add(Int n = 1);				///< Add n items to the array
	Void			Shrink(Int n = 1);			///< shrink the array by n items
	Void 			Insert(Int i, Int n = 1);	///< Insert n items at i
	Void			Delete(Int i, Int n = 1);	///< Delete n items at i
	Void			ShrinkWrap();				/**< Ensure allocated space =
													 space being used */
	Void			ClearTo(const T &t);		///< Clear the array using t

	Void			Append(const TArray &a);	///< Append array to array
	Void			SwapWith(TArray &a);		///< Swaps this array with a
	Void			Replace(TArray &a);			/**< Replace this array with a
													 & clear a. */

	const T			&Item(Int i) const
					{ return(SELF[i]); };
	T				&Item(Int i)
					{ return(SELF[i]); };
	
// Low level access

	inline T		*Ref() const;				///< Return pointer to array
	inline T		*Detach();					/**< As above, but the array 
													 no longer owns the data. */

	Void			Attach(T *itemsPtr, Int numItems, Bool shared);
					/**< Attach the array to the given chunk of memory.
						 If shared is true, the memory won't be deleted 
						 when the array is destroyed. */

	Void 			WriteFile(const Char *filename);
	Void 			ReadFile(const Char *filename);


//	Private...

protected:
	T*				itemArray;		///< pointer to array
	Byte 			items;		///< items in the array
	Byte			allocated;	///< number of items we have space allocated for. 
	
	Void 			Grow();
};	



// --- Inlines ----------------------------------------------------------------


TMPLArray inline TArray::Array() : itemArray(0), items(0), allocated(0)
{
}

TMPLArray inline Int TArray::NumItems() const
{
	return(items);
}

TMPLArray inline T &TArray::operator [] (Int i)
{	
	return(itemArray[i]);
}

TMPLArray inline const T &TArray::operator [] (Int i) const
{	
	return(itemArray[i]);
}


TMPLArray inline T &TArray::Top()
{
	return(itemArray[items - 1]);
}

TMPLArray inline T &TArray::Last()
{
	return(itemArray[items - 1]);
}

TMPLArray inline Void TArray::Push(const T &t)
{
	if (items >= allocated)
	{
		if (allocated > THRESHOLD)
		{
			return;
		}
		Grow();
	}
	
	itemArray[items++] = t;
}

TMPLArray inline Void TArray::Append(const T &t)
{
	if (items >= allocated)
	{
		if (allocated > THRESHOLD)
		{
			return;
		}
		Grow();
	}
	
	itemArray[items++] = t;
}




TMPLArray inline Void TArray::Pop()
{	
	items--;
}

TMPLArray inline Void TArray::Clear()
{	
	items = 0;
	allocated = 0;
	delete[] itemArray;
	itemArray = 0;
}

TMPLArray inline Void TArray::ResetItemCount()
{	
	items = 0;
}

TMPLArray inline Void TArray::Reset()
{
   items = 0;
   allocated = 0;
   itemArray = 0;
}

TMPLArray inline T *TArray::Ref() const
{
	return(itemArray);
}

TMPLArray inline T *TArray::Detach()
{
	T* result = itemArray;

	items = 0;
	allocated = 0;
	itemArray = 0;

	return(result);
}

TMPLArray inline Void TArray::ClearTo(const T &t)
{
	for (Int i = 0; i < items; i++)
		itemArray[i] = t;
}



#ifndef __Array
#define __Array
  #include "Array.cpp"
#endif

#endif


