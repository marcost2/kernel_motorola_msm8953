/*
 * Copyright (c) 2012-2013, 2017 The Linux Foundation. All rights reserved.
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

/** ------------------------------------------------------------------------- *
    ------------------------------------------------------------------------- *


    \file halTypes.h

    \brief This header captures types that must be shared in common with individual
            module headers before inclusion into halCommonApi.h.

    $Id$


   ========================================================================== */

#ifndef HALTYPES_H
#define HALTYPES_H
#ifndef WINXP_APPS_BUILD    //TODO: this header dependency does not belong in this file

#endif /* WINXP_APPS_BUILD */

#include "palTypes.h"
#include "wlan_nv.h"

#define OFFSET_OF(structType,fldName)   (&((structType*)0)->fldName)

/** ------------------------------------------------------------------------- *

    \typedef tHalHandle

    \brief Handle to the HAL.  The HAL handle is returned by the HAL after it
    is opened (by calling halOpen).

    -------------------------------------------------------------------------- */
typedef void *tHalHandle;

// define a value for an invalid HAL handle.....
#define HAL_INVALID_HAL_HANDLE ( NULL )


/** ------------------------------------------------------------------------- *

    \enum VOS_STATUS

    \brief Enumeration of all status codes returned by the higher level
    HAL interface functions.

    -------------------------------------------------------------------------- */
/*typedef enum
{
    eHAL_STATUS_SUCCESS,

    // general failure.  This status applies to all failure that are not covered
    // by more specific return codes.
    eHAL_STATUS_FAILURE,
    eHAL_STATUS_RESOURCES,

    // a parameter on the PAL function call is not valid.
    eHAL_STATUS_NOT_INITIALIZED,

    // status codes added for the ImageValidate library
    eHAL_STATUS_E_NULL_VALUE,

    // PMC return codes.
    eHAL_STATUS_PMC_PENDING,
    eHAL_STATUS_PMC_DISABLED,
    eHAL_STATUS_PMC_NOT_NOW,
    eHAL_STATUS_PMC_AC_POWER, // 3 uses (port to VOSS?)
    eHAL_STATUS_PMC_SYS_ERROR, // 3 uses (port to VOSS?)
    eHAL_STATUS_PMC_ALREADY_IN_IMPS, // 4 uses (port to VOSS?)

    eHAL_STATUS_HEARTBEAT_TMOUT, // 2 uses (port to VOSS?)
    eHAL_STATUS_NTH_BEACON_DELIVERY, // 2 uses (port to VOSS?)

    //CSR
    eHAL_STATUS_CSR_WRONG_STATE,

#ifdef WLAN_FEATURE_VOWIFI_11R
    eHAL_STATUS_FT_PREAUTH_KEY_SUCCESS, // 4 uses (port to VOSS?)
    eHAL_STATUS_FT_PREAUTH_KEY_FAILED, // 4 uses (port to VOSS?)
#endif
    //CMD not Queued in SME
    eHAL_STATUS_CMD_NOT_QUEUED,

#ifdef WLAN_FEATURE_LFR_MBB
#endif

} VOS_STATUS;*/

typedef enum
{
    HAL_STOP_TYPE_SYS_RESET,
    HAL_STOP_TYPE_SYS_DEEP_SLEEP,
    HAL_STOP_TYPE_RF_KILL,
}tHalStopType;

// macro to check for SUCCESS value of the halStatus
#define HAL_STATUS_SUCCESS( variable ) ( VOS_STATUS_SUCCESS == ( variable ) )

/// Bit value data structure
typedef enum sHalBitVal  // For Bit operations
{
    eHAL_CLEAR,
    eHAL_SET
}tHalBitVal;

// -------------------------------------------------------------
/// MMH APIs
enum {
   eHI_PRI,
   ePROT,
   eDBG
};

/// System role definition on a per BSS
typedef enum eBssSystemRole
{
    eSYSTEM_UNKNOWN_ROLE,
    eSYSTEM_AP_ROLE,
    eSYSTEM_STA_IN_IBSS_ROLE,
    eSYSTEM_STA_ROLE,
    eSYSTEM_BTAMP_STA_ROLE,
    eSYSTEM_BTAMP_AP_ROLE,

    eSYSTEM_LAST_ROLE,
    eSYSTEM_MULTI_BSS_ROLE = eSYSTEM_LAST_ROLE
} tBssSystemRole;


// ---------------------------------------
// Channel Bonding Sideband configuration
// ---------------------------------------
typedef enum sHalCBsidebandType
{
    eHAL_SIDEBAND_CENTER=0,
    eHAL_SIDEBAND_LOWER,
    eHAL_SIDEBAND_UPPER,
    eHAL_SIDEBAND_COPY
}tHalCBsidebandType;


/// HAL states
typedef enum {
    eHAL_IDLE,
    eHAL_INIT,
    eHAL_CFG, //CFG download completed.
    eHAL_STARTED, //halProcessStartEvent compelted.
    eHAL_SYS_READY, //Sys_ready msg received from HDD.
    eHAL_NORMAL, //Sys_ready msg received from HDD and halProcessStartEvent completed.
} tHAL_STATE;




// Type to define softmac mode (also system mode)
typedef enum
{
    //3- Promisc, 2 - Scan, 1 - Learn  0 - Normal
    eHAL_SYS_MODE_NORMAL = 0,
    eHAL_SYS_MODE_LEARN,
    eHAL_SYS_MODE_SCAN,
    eHAL_SYS_MODE_PROMISC,
    eHAL_SYS_MODE_SUSPEND_LINK,
    eHAL_SYS_MODE_ROAM_SCAN,
    eHAL_SYS_MODE_ROAM_SUSPEND_LINK,
} eHalSysMode;




// HAL frame types.  Used on the TxRx APIs and the
// corresponding PAL routines.
typedef enum {

    HAL_TXRX_FRM_RAW,
    HAL_TXRX_FRM_ETH2,
    HAL_TXRX_FRM_802_3,
    HAL_TXRX_FRM_802_11_MGMT,
    HAL_TXRX_FRM_802_11_CTRL,
    HAL_TXRX_FRM_802_11_DATA,
    HAL_TXRX_FRM_IGNORED,   //This frame will be dropped
    HAL_TXRX_FRM_MAX

} eFrameType;


typedef enum
{
    ANI_TXDIR_IBSS = 0,
    ANI_TXDIR_TODS,
    ANI_TXDIR_FROMDS,
    ANI_TXDIR_WDS

} eFrameTxDir;

typedef enum
{
    eRF_BAND_UNKNOWN = 0,
    eRF_BAND_2_4_GHZ = 1,
    eRF_BAND_5_GHZ = 2
} eRfBandMode;


#ifndef __offsetof
#define __offsetof(type, field) ((tANI_U32)(&((type *)0)->field))
#endif

#ifndef offsetof
#define offsetof(type, field) __offsetof(type, field)
#endif

#define HAL_MAX_TXPOWER_INVALID       127

/* These are the min/max tx power (non virtual rates) range
 * supported by rome/prima hardware
 */
#define MIN_TX_PWR_CAP    8
#define MAX_TX_PWR_CAP    22

/* Moving the miscellaneous defination required by UMAC are moved here from 
 * volansdefs.h */
/* --------------------------------------------------------------------
 * Support definitions for taurus
 * --------------------------------------------------------------------
 */

/*
 * Volans supports 8 stations in hardware
 *
 * Volans without Virtual STA feature can only support 8 stations:
 *    1 Broadcast STA (hard)
 *    1 "Self" STA (hard)
 *    6 Soft AP Stations (hard)
 *
 * Volans with Virtual STA feature supports 14 stations:
 *    1 Broadcast STA (hard)
 *    1 "Self" STA (hard)
 *    2 General Purpose Stations to support Virtual STAs (hard)
 *   10 Soft AP Stations (4 hard/6 virtual)
 */

#define HAL_INVALID_BSSIDX          (HAL_NUM_BSSID + 1)
#define HAL_NUM_UMA_DESC_ENTRIES    8
#define MAX_NUM_OF_BACKOFFS         8

#define IS_VALID_BSSIDX(__x) \
                        ((__x) < HAL_NUM_BSSID)

#ifdef WLAN_SOFTAP_VSTA_FEATURE
#define HAL_NUM_ASSOC_STA           32
#define HAL_NUM_STA                 41
#define HAL_NUM_HW_STA              16
#define HAL_NUM_GPSTA               4
#define HAL_NUM_VSTA                (HAL_NUM_STA - HAL_NUM_HW_STA)

#define QWLANFW_MAX_NUM_VSTA        HAL_NUM_VSTA
#define QWLANFW_VSTA_INVALID_IDX    (HAL_NUM_STA + 1)
#define QWLAN_VSTA_MIN_IDX          HAL_NUM_HW_STA
#define QWLANFW_NUM_GPSTA           HAL_NUM_GPSTA


#define IS_VSTA_VALID_IDX(__x) \
                          ((__x) != QWLANFW_VSTA_INVALID_IDX)

#define IS_VSTA_IDX(__x) \
                   (((__x) >= QWLAN_VSTA_MIN_IDX) && ((__x) < HAL_NUM_STA))

                 
// is the STA a General Purpose STA?
#define IS_GPSTA_IDX(__x) \
    (((__x) >= (HAL_NUM_HW_STA-HAL_NUM_GPSTA)) && \
     ((__x) < HAL_NUM_HW_STA))

// is the STA a HW STA (excluding GP STAs)
#define IS_HWSTA_IDX(__x) \
    ((__x) < (HAL_NUM_HW_STA-HAL_NUM_GPSTA))

#else
/*In prima 12 HW stations are supported including BCAST STA(staId 0)
 and SELF STA(staId 1) so total ASSOC stations which can connect to Prima
 SoftAP = 12 - 1(Self STa) - 1(Bcast Sta) = 10 Stations. */
#define HAL_NUM_STA                 12
#define HAL_NUM_ASSOC_STA           10
#define HAL_NUM_HW_STA              12
#endif

/*
 * From NOVA Mac Arch document
 *  Encryp. mode    The encryption mode
 *  000: Encryption functionality is not enabled
 *  001: Encryption is set to WEP
 *  010: Encryption is set to WEP 104
 *  011: Encryption is set to TKIP
 *  100: Encryption is set to AES
 *  101 - 111: Reserved for future
 */

#define HAL_ENC_POLICY_NULL        0
#define HAL_ENC_POLICY_WEP40       1
#define HAL_ENC_POLICY_WEP104      2
#define HAL_ENC_POLICY_TKIP        3
#define HAL_ENC_POLICY_AES_CCM     4

#define STACFG_MAX_TC   8


#endif

