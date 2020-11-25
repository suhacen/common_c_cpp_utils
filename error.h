/** 
* @file        error.h
* @brief       error code definition 
* @author      cencong
* @date        2020/11/11
* @version     0.2046.1
* @par Copyright (c):  hey@cencongs.com 
*/

#ifndef ERROR_H_
#define ERROR_H_

/**
 * Generic error codes
 */
typedef enum {
    ERROR_Ok                  = 0,      /**< No error */
    ERROR_Fail                = 1,      /**< Error, not specified */
    ERROR_Count,
}ERROR_CODE_t;

#endif /* ERROR_H_ */
