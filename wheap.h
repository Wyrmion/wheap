/**
  ******************************************************************************
  * @file     wheap.h
  * @author   Wyrm
  * @brief    Header file for heap wrapper
  * @version  V1.0.3
  * @date     03. Feb. 2026
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MY_MEMORY_H__
#define __MY_MEMORY_H__


#ifdef __cplusplus
extern "C"{
#endif

#include <stdbool.h>
#include <stddef.h>


/**
 * @addtogroup Wyrm_Drivers Wyrm Drivers
 * @{
 */

/**
 * @defgroup My_Heap My Heap wrapper
 * @{
 */

/* Public macro -------------------------------------------------------------*/

/**
 * @defgroup my_heap_wrapper My heap wrapper macro
 * @{
 */
  #ifdef USE_MY_STATIC_MEMORY
    /**
     * @brief Heap memory initialization function
     * 
     * @param heap    pointer to heap
     * @param size    heap size 
     * @return true   static heap init complete  
     * @return false  static heap init fault
     */
    #include "StaticHeap/sheap.h"
    #define heap_init(heap,size) SHeap_init(heap,size)
    
  #else 
    #ifdef USE_FREERTOS_MEMORY 
    #include "FreeRTOS.h"
    #endif
  #endif


  /**
   * @brief Allocates size bytes of uninitialized storage. (malloc wrapper)
   * @param size total bytes to allocate
   * 
   * @return pointer if memory allocate and NULL if fault
   */
  #ifdef USE_STD_MALLOC   
    #define heap_malloc(size) malloc(size)
  #else 
    #ifdef USE_MY_STATIC_MEMORY
      #define heap_malloc(size) SHeap_malloc(size)
    #else 
      #ifdef USE_FREERTOS_MEMORY
        #define heap_malloc(size) pvPortMalloc(size)
      #endif
    #endif
  #endif      
  /**
   * @brief Allocates size bytes of uninitialized storage and Explicit Conversion . (malloc wrapper)
   * @param type what type to convert to
   * @return pointer if memory allocate and NULL if fault
   */
  #ifdef USE_STD_MALLOC   
    #define heap_malloc_cast(type) (type*)malloc(sizeof(type))
  #else 
    #ifdef USE_MY_STATIC_MEMORY
      #define heap_malloc_cast(type) (type*)SHeap_malloc(sizeof(type))  
    #else
      #ifdef USE_FREERTOS_MEMORY
        #define heap_malloc_cast(type) (type*)pvPortMalloc(sizeof(type))
      #endif
    #endif
  #endif      


  /**
   * @brief   Allocates memory for an array of num objects of size and initializes all bytes in the allocated storage to zero
   * 
   * @param  	number number of objects
   * @param   size  	size of each object 
   * 
   * @return  pointer to the lowest(first) byte in the allocated memory
   */
  #ifdef USE_STD_MALLOC
    #define heap_calloc(number,size) calloc(number,size)
  #else 
    #ifdef USE_MY_STATIC_MEMORY
      #define heap_calloc(num,size) SHeap_calloc(num,size)
    #else
      #ifdef USE_FREERTOS_MEMORY
        #define heap_calloc(num,size) pvPortCalloc(Num,Size)
      #endif
    #endif
  #endif   

  
    
  #ifdef USE_STD_MALLOC
  /**
   * @brief Reallocates the given area of memory
   * @param ptr   pointer to the memory area to be reallocated
   * @param size  new size of the array in bytes
   * 
   * @return pointer to the lowest(first) byte in the allocated memory
   */
  
    #define heap_realloc(ptr,size)   realloc(ptr,size)
  #endif /* Freertos and SHeap not support realloc*/  

  /**
   * @brief Deallocates the space previously allocated by malloc()
   * 
   * @param ptr pointer to memory
   */
  #ifdef USE_STD_MALLOC
    #define heap_free(ptr) free(ptr)
  #else 
    #ifdef USE_MY_STATIC_MEMORY
        #define heap_free(ptr) SHeap_free(ptr)
    #else 
      #ifdef USE_FREERTOS_MEMORY
        #define heap_free(ptr) vPortFree(ptr)
      #endif
    #endif
  #endif   
/** @}*/  /* End of My Heap wrapper group */
/** @}*/ /* End of Wyrm Drivers group */


#ifdef __cplusplus
}
#endif

#endif

