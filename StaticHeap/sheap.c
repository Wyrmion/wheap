/**
 ****************************************************************************
 * @file     SHeap.C
 * @author   Kukushkin A.V.
 * @brief    This file provides code for work with static memory realization
 * @version  V1.0.2
 * @date     25. Apr. 2025
 * @note     If you need aligned memory block plz global #define SHEAP_ALIGN 2/4/8 
 *************************************************************************
 */
 

#include <stdlib.h>
#include <string.h>

#include "sheap.h"

/* Private macro -------------------------------------------------------------*/
/**
 * @addtogroup SHeap
 * @{
 */

#ifndef SHEAP_ALIGN
  #define SHEAP_ALIGN 4 
#endif 
 
/* Private typedef -----------------------------------------------------------*/
/**
 * @brief sStaticMem class 
 * 
 */
typedef struct 
{
  uint8_t*  memory;   /*!< pointer to static memory */
  size_t    size;     /*!< size of static memory*/
  
  uint8_t*  cur_mem;  /*!< cur memory pointer*/
  size_t    cur_size; /*!< cur memory allocated*/
}cStaticHeap_t;


/* Private constants ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Exported functions -------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static cStaticHeap_t SHeap;       /*!< Static @ref cStaticHeap_t SHeap class*/
static bool memory_init = false;  /*!< Static mem initialization flag.*/

/**
 * @brief Static heap memory initialization function
 * 
 * @param heap    pointer to heap
 * @param size    heap size 
 * @return true   static heap init complete  
 * @return false  static heap init fault
 */
bool	SHeap_init(void* heap,size_t size)
{
  if((heap == NULL)||(size == 0))
    return false;
  
  memset(&SHeap,0,sizeof(cStaticHeap_t));
  
  SHeap.memory    = heap;
  SHeap.cur_mem   = heap;
  SHeap.size      = size;
  
  memory_init = true;

  return true;
}

/**
 * @brief Allocates size bytes of uninitialized storage
 * @param size total bytes to allocate
 * 
 * @return pointer if memory allocate and NULL if fault
 */
void* SHeap_malloc(size_t size)
{
  if(!memory_init)
    return NULL;

  #ifdef SHEAP_ALIGN 
   if(size<SHEAP_ALIGN)
     size = SHEAP_ALIGN;
   else
   {
     uint32_t remainder = 0;
     if((remainder = size%SHEAP_ALIGN)!=0)
         size+=(SHEAP_ALIGN-remainder);
   }
  #endif       
  
  if((size+SHeap.cur_size)>SHeap.size)
    return NULL;
  
  SHeap.cur_size+=size;

  void* ptr = SHeap.cur_mem;
  SHeap.cur_mem+=size;

  return (void*)(ptr);
}   
/**
* @brief   Allocates memory for an array of num objects of size and initializes all bytes in the allocated storage to zero
* 
* @param   num    number of objects
* @param   size  	size of each object 
* 
* @return  pointer to the lowest(first) byte in the allocated memory
*/
void* SHeap_calloc(size_t num,size_t size)
{
  size*=num; /* get total size*/

  if(!memory_init)
    return NULL;
  
  #ifdef SHEAP_ALIGN 
   if(size<SHEAP_ALIGN)
     size = SHEAP_ALIGN;
   else
   {
     uint32_t remainder = 0;
     if((remainder = size%SHEAP_ALIGN)!=0)
         size+=(SHEAP_ALIGN-remainder);
   }
  #endif   
  
  if((size+SHeap.cur_size)>SHeap.size)
    return NULL;
 
  SHeap.cur_size+=size;

  void* ptr = SHeap.cur_mem;

  memset(ptr,0,size);

  SHeap.cur_mem+=size;

  return (void*)(ptr);
}

/**
 * @brief Deallocates the space previously allocated by malloc() (empty for this realization)
 * 
 * @param ptr pointer to memory
 */
void  SHeap_free(void* ptr)
{
  (void)ptr; /* UNUSED */
}
/** @}*/ /*End of SHeap group*/
