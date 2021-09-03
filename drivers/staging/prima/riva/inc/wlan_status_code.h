/*
 * Copyright (c) 2012 The Linux Foundation. All rights reserved.
 *
 * Previously licensed under the ISC license by Qualcomm Atheros, Inc.
 *
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * This file was originally distributed by Qualcomm Atheros, Inc.
 * under proprietary terms before Copyright ownership was assigned
 * to the Linux Foundation.
 */

/*===========================================================================
 *
 *  @file:     wlan_status_code.h
 *
 *  @brief:    Common header file containing all the status codes
 *             All status codes have been consolidated into one enum
 *
 *  @author:   Kumar Anand
 *
 *=========================================================================*/

#ifndef __WLAN_STATUS_CODE_H__
#define __WLAN_STATUS_CODE_H__

/*-------------------------------------------------------------------------
  Include Files
-------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 *  Type Declarations
 * -------------------------------------------------------------------------*/

typedef enum
{
   /* PAL Request succeeded!*/
   PAL_STATUS_SUCCESS = 0,

   /* Request failed because there of an invalid request.  This is
      typically the result of invalid parameters on the request*/
   PAL_STATUS_INVAL,

   /* Request refused because a request is already in place and
      another cannot be handled currently */
   PAL_STATUS_ALREADY,

   /* Request failed because of an empty condition */
   PAL_STATUS_EMPTY,

   /* Request failed for some unknown reason. */
   PAL_STATUS_FAILURE,

} palStatus;

/* Helper Macros */
#define PAL_IS_STATUS_SUCCESS(status) (PAL_STATUS_SUCCESS  == (status))

#endif //__WLAN_STATUS_CODE_H__
