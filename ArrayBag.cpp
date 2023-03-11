/*
ArrayBag implementation for term project
CSCI 235 Spring 2023
*/

#include "Book.hpp"
#include "ArrayBag.hpp"


/** default constructor**/
template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): item_count_{0}
{
}  // end default constructor

/**
 @return item_count_ : the current size of the bag
 **/
template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return item_count_;
}  // end getCurrentSize

/**
 @return true if item_count_ == 0, false otherwise
 **/
template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return item_count_ == 0;
}  // end isEmpty

/**
 @return true if new_etry was successfully added to items_, false otherwise
 **/
template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& new_entry)
{
	bool has_room = (item_count_ < DEFAULT_CAPACITY);
	if (has_room)
	{
		items_[item_count_] = new_entry;
		item_count_++;
        return true;
	}  // end if

	return false;
}  // end add

/**
 @return true if an_etry was successfully removed from items_, false otherwise
 **/
template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& an_entry)
{
   int found_index = getIndexOf(an_entry);
	bool can_remove = !isEmpty() && (found_index > -1);
	if (can_remove)
	{
		item_count_--;
		items_[found_index] = items_[item_count_];
	}  // end if

	return can_remove;
}  // end remove

/**
 @post item_count_ == 0
 **/
template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	item_count_ = 0;
}  // end clear

/**
 @return the number of times an_entry is found in items_
 **/
template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& an_entry) const
{
   int frequency = 0;
   int cun_index = 0;       // Current array index
   while (cun_index < item_count_)
   {
      if (items_[cun_index] == an_entry)
      {
         frequency++;
      }  // end if

      cun_index++;          // Increment to next entry
   }  // end while

   return frequency;
}  // end getFrequencyOf

/**
 @return true if an_etry is found in items_, false otherwise
 **/
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& an_entry) const
{
	return getIndexOf(an_entry) > -1;
}  // end contains

// ********* PRIVATE METHODS **************//

/**
	@param target to be found in items_
 	@return either the index target in the array items_ or -1,
 	if the array does not containthe target.
 **/
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{  
	bool found = false;
  int result = -1;
  int search_index = 0;
   // If the bag is empty, item_count_ is zero, so loop is skipped
   while (!found && (search_index < item_count_))
   {

      if (items_[search_index] == target)
      {
         found = true;
         result = search_index;
      }
      else
      {
         search_index++;
      }  // end if
   }  // end while

   return result;
}  // end getIndexOf

template<class ItemType>
ArrayBag<ItemType>& ArrayBag<ItemType>::operator+=(const ItemType & rightParam)
{
    add(rightParam);
    return *this;
}

template<class ItemType>
ArrayBag<ItemType>& ArrayBag<ItemType>::operator+=(const ArrayBag<ItemType>& rightParam)
{
  for (int i = 0;i <rightParam.getCurrentSize(); i++ ){
      add(rightParam.items_[i]);
      
  }
    return *this;
}


template<class ItemType>
ArrayBag<ItemType>& ArrayBag<ItemType>::operator/=(const ItemType & rightParam)
{ 
    if (contains(rightParam)) {

    
    }
    else{
     add(rightParam);
    }
    return *this;
}
template<class ItemType>
ArrayBag<ItemType>& ArrayBag<ItemType>::operator/=(const ArrayBag<ItemType>& rightParam)
{

    for (int i = 0; i < rightParam.getCurrentSize();i++)
    {
        *this /= rightParam.items_[i];
        
    }
        return *this;
}

//explicitly instantiate the template for Book
template class ArrayBag<Book>;
