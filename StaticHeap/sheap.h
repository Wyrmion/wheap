/**
  ******************************************************************************
  * @file     SHeap.h
  * @author   Kukushkin A.V.
  * @brief    Header file for static memory realization
  * @version  V1.0.1
  * @date     30. Jan. 2024
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __S_MEM_H__
#define __S_MEM_H__


#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>


/**
 * @addtogroup My_Heap
 * @{
 */

/**
 * @defgroup Sheap static memory
 * @{
 */

/* Public macro -------------------------------------------------------------*/
/* Public typedef -----------------------------------------------------------*/
/* Public constants ---------------------------------------------------------*/
/* Public function prototypes -----------------------------------------------*/
/* Public variables ---------------------------------------------------------*/


/* Public function prototypes -----------------------------------------------*/

/**
 * @defgroup sHeap_public_func SHeap public function
 * @{
 */
  
  /**
   * @defgroup SHeap_init SHeap initialization
   * @{
   */
  bool	SHeap_init(void* mem,size_t size);
  /** @}*/

  /**
   * @defgroup SHeap_public_basic SHeap basic function
   * @{
   */
  void* SHeap_malloc(size_t size);     
  void* SHeap_calloc(size_t num,size_t size);
  void  SHeap_free(void* ptr);
  /** @}*/
/** @}*/

/** @}*/  /* End of My_Heap group */
/** @}*/ /* End of My_memory group */


#ifdef __cplusplus
}
#endif

#endif

