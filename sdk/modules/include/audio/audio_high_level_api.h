/****************************************************************************
 * modules/include/audio/audio_high_level_api.h
 *
 *   Copyright 2018 Sony Semiconductor Solutions Corporation
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name of Sony Semiconductor Solutions Corporation nor
 *    the names of its contributors may be used to endorse or promote
 *    products derived from this software without specific prior written
 *    permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#ifndef __MODULES_INCLUDE_AUDIO_AUDIO_HIGH_LEVEL_API_H
#define __MODULES_INCLUDE_AUDIO_AUDIO_HIGH_LEVEL_API_H

/**
 * @defgroup audioutils Audio Utility
 * @{
 */

/* API Documents creater with Doxgen */

/**
 * @defgroup audioutils_audio_high_level_api Audio High Level API
 * @{
 *
 * @file       audio_high_level_api.h
 * @brief      CXD5602 Audio High Level API
 * @author     CXD5602 Audio SW Team
 */

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <sdk/config.h>

#include "audio/audio_command_id.h"
#include "audio/audio_common_defs.h"
#ifdef CONFIG_AUDIOUTILS_PLAYER
#  include "audio/audio_player_api.h"
#  include "audio/audio_outputmix_api.h"
#  include "audio/audio_renderer_api.h"
#endif
#ifdef CONFIG_AUDIOUTILS_RECORDER
#  include "audio/audio_recorder_api.h"
#  include "audio/audio_capture_api.h"
#endif
#if defined(CONFIG_AUDIOUTILS_VOICE_CALL) || defined(CONFIG_AUDIOUTILS_VOICE_COMMAND)
#  include "audio/audio_effector_api.h"
#  include "audio/audio_renderer_api.h"
#  include "audio/audio_capture_api.h"
#endif
#ifdef CONFIG_AUDIOUTILS_VOICE_COMMAND
#  include "audio/audio_recognizer_api.h"
#  include "audio/audio_effector_api.h"
#  include "audio/audio_renderer_api.h"
#  include "audio/audio_capture_api.h"
#endif

#include <stdint.h>
#include <stdbool.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/** @name Reslt Code Packet length */
/** @{ */

/** NomalResponse Packet length */

#define LENGTH_AUDRLT  2

/** Maximum ErrorResponse Packet length */

#define LENGTH_AUDRLT_ERRORRESPONSE_MAX  8

/** Minimum ErrorResponse Packet length */

#define LENGTH_AUDRLT_ERRORRESPONSE_MIN  5

/** @} */

/** @name Packet length of command*/
/** @{ */

/*! \brief GetStatus command (#AUDCMD_GETSTATUS) packet length */

#define LENGTH_GETSTATUS            2

/*! \brief SetPlayerStaus command (#AUDCMD_SETPLAYERSTATUS) packet length */

#define LENGTH_SET_PLAYER_STATUS    6 

/*! \brief SetRecorderStatus command (#AUDCMD_SETRECORDERSTATUS) packet length */

#define LENGTH_SET_RECORDER_STATUS  4

/*! \brief SetBaseBandStatus command (#AUDCMD_SETBASEBANDSTATUS) packet length */

#define LENGTH_SET_BASEBAND_STATUS  9

/*! \brief SetThroughStatus command (#AUDCMD_SETTHROUGHSTATUS) packet length */

#define LENGTH_SET_THROUGH_STATUS  3

/*! \brief SetReadyStatus command (#AUDCMD_SETREADYSTATUS) packet length */

#define LENGTH_SET_READY_STATUS     2

/*! \brief PowerOn command (#AUDCMD_POWERON) packet length */

#define LENGTH_POWERON              2

/*! \brief PowerOn command (#AUDCMD_SETPOWEROFFSTATUS) packet length */

#define LENGTH_SET_POWEROFF_STATUS  2

/*! \brief InitMicGain command (#AUDCMD_INITMICGAIN) packet length */

#define LENGTH_INITMICGAIN          5

/*! \brief InitI2SParam command (#AUDCMD_INITI2SPARAM) packet length */

#define LENGTH_INITI2SPARAM         3

/*! \brief InitDEQParam command (#AUDCMD_INITDEQPARAM) packet length */

#define LENGTH_INITDEQPARAM         8

/*! \brief InitOutputSelect command (#AUDCMD_INITOUTPUTSELECT) packet length */

#define LENGTH_INITOUTPUTSELECT     2

/*! \brief InitDNCParam command (#AUDCMD_INITDNCPARAM) packet length */

#define LENGTH_INITDNCPARAM         2

/*! \brief InitClearStereo command (#AUDCMD_INITCLEARSTEREO) packet length */

#define LENGTH_INITCLEARSTEREO      2

/*! \brief SetVolume command (#AUDCMD_SETVOLUME) packet length */

#define LENGTH_SETVOLUME            3

/*! \brief SetVolumeMute command (#AUDCMD_SETVOLUMEMUTE) packet length */

#define LENGTH_SETVOLUMEMUTE        2

/*! \brief SetBeep command (#AUDCMD_SETBEEPPARAM) packet length */

#define LENGTH_SETBEEPPARAM         3

/*! \brief SetRenderingClk command ("AUDCMD_SETRENDERINGCLK)packet length */

#define LENGTH_SETRENDERINGCLK      2

/*! \brief InitSoundEffect command ("AUDCMD_INITSOUNDEFFECT)packet length */

#define LENGTH_INIT_SOUNDEFFECT     3

/*! \brief StartSoundEffect command ("AUDCMD_STARTSOUNDEFFECT)packet length */

#define LENGTH_START_SOUNDEFFECT    2

/*! \brief StopSoundEffect command ("AUDCMD_STOPSOUNDEFFECT)packet length */

#define LENGTH_STOP_SOUNDEFFECT     2

/*! \brief SetThroughPath command ("AUDCMD_SETTHROUGHPATH)packet length */

#define LENGTH_SET_THROUGH_PATH     4

/** @} */

/** @defgroup attention_sub_code Attention Code */
/** @{ */

/*! \brief DMA Underflow
 *  \details DMA tranfering queue became empty because of DMA read/write request\n
 *           may be slower than DMA transfer speed. To avoid this, request DMA transfer\n
 *           faster than transfer speed. (tranfer speed : 48000 samples/sec)
 */

#define AS_ATTENTION_SUB_CODE_DMA_UNDERFLOW         0x01

/*! \brief DMA Overflow
 *  \details DMA captureing queue became full because of DMA read/write request\n
 *           may be faster than DMA transfer speed. To avoid this, request DMA capture\n
 *           faster than capture speed. (capture speed : 48000 samples/sec)
 */

#define AS_ATTENTION_SUB_CODE_DMA_OVERFLOW          0x02

/*! \brief DMA Error
 *  \details DMA error returned from DMW H/W. It may be wrong register setting. 
 */

#define AS_ATTENTION_SUB_CODE_DMA_ERROR             0x03

/*! \brief APU Queue Full Error
 *  \details DSP response may be delayed and command buffer became full.
 */

#define AS_ATTENTION_SUB_CODE_APU_QUEUE_FULL        0x04

/*! \brief SimpleFIFO Underflow 
 *  \details Simple fifo between application and sdk became empty. Insertion speed\n
 *           may be slower than extraction. Coordinate task priority of application\n
 *           to avoid queue remain decreaseing.
 */

#define AS_ATTENTION_SUB_CODE_SIMPLE_FIFO_UNDERFLOW 0x05

/*! \brief SimpleFIFO Overflow 
 *  \details Simple fifo between application and sdk became full. Extraction speed\n
 *           may be slower than Insertion. Coordinate task priority of application\n
 *           to avoid queue remain increaseing.
 */

#define AS_ATTENTION_SUB_CODE_SIMPLE_FIFO_OVERFLOW  0x06

/*! \brief Illegal Request
 *  \details Cannot accept this event on current state.
 */

#define AS_ATTENTION_SUB_CODE_ILLEGAL_REQUEST       0x07

/*! \brief Internal State Error
 *  \details Internal State Error.
 */

#define AS_ATTENTION_SUB_CODE_INTERNAL_STATE_ERROR  0x08

/*! \brief Unexpected Parameter 
 *  \details The command parameter may be wrong. Revise command parameters.
 */

#define AS_ATTENTION_SUB_CODE_UNEXPECTED_PARAM      0x09

/*! \brief Internal Queue Pop Error
 *  \details The internal process queue is already empty but tried to extraction.
 */

#define AS_ATTENTION_SUB_CODE_QUEUE_POP_ERROR       0x0A

/*! \brief Internal Queue Push Error
 *  \details The internal process queue is already full but tried to insertion.
 */

#define AS_ATTENTION_SUB_CODE_QUEUE_PUSH_ERROR      0x0B

/*! \brief Internal Queue Missing Error
 *  \details The queue became empty unexpectedly.
 */

#define AS_ATTENTION_SUB_CODE_QUEUE_MISSING_ERROR   0x0C

/*! \brief Memory Handle Alloc Error
 *  \details All Memory handles may be used.
 *           Response from DSP may be delayed or get stacked up.
 */

#define AS_ATTENTION_SUB_CODE_MEMHANDLE_ALLOC_ERROR 0x0D

/*! \brief Memory Handle Free Error 
 *  \details The handle may be already freed.
 */

#define AS_ATTENTION_SUB_CODE_MEMHANDLE_FREE_ERROR  0x0E

/*! \brief Task Create Error
 *  \details Task context cannot create.\n
 *           Revise max task creation number on menu config.
 */

#define AS_ATTENTION_SUB_CODE_TASK_CREATE_ERROR     0x0F

/*! \brief Instance Resource Error
 *  \details A class instanse could not create or delete.\n
 *           Check if there duplicate creation of audio objects/components.
 *           And, check heap area size too.
 */

#define AS_ATTENTION_SUB_CODE_RESOURCE_ERROR        0x10

/*! \brief Decoded size equal zero
 *  \details Decoded PCM size euqals to 0, Provided ES data may be broken.
 */

#define AS_ATTENTION_SUB_CODE_DECODED_SIZE_ZERO     0x11

/*! \brief DSP Load Error
 *  \details Tried to load DSP binary to sub core but it was failed.\n
 *           DSP binary may not be stored on dsp load path.
 */

#define AS_ATTENTION_SUB_CODE_DSP_LOAD_ERROR        0x12

/*! \brief DSP Unload Error
 *  \details Tried to unload DSP binary from sub core but it was failed.\n
 *           DSP binary may not loaded.
 */

#define AS_ATTENTION_SUB_CODE_DSP_UNLOAD_ERROR      0x13

/*! \brief DSP Exec Error
 *  \details The data or command which sent to DSP may not be correct format.
 */

#define AS_ATTENTION_SUB_CODE_DSP_EXEC_ERROR        0x14

/*! \brief DSP Result Error
 *  \details DSP result error.
 */

#define AS_ATTENTION_SUB_CODE_DSP_RESULT_ERROR      0x15

/*! \brief DSP Illegal Reply
 *  \detail Command packet from DSP may be broken.
 *          If uses multi DSP, Check duplication of command buffer.
 */

#define AS_ATTENTION_SUB_CODE_DSP_ILLEGAL_REPLY     0x16

/*! \brief DSP Unload Done
 *  \details DSP unload done notification.
 */

#define AS_ATTENTION_SUB_CODE_DSP_UNLOAD_DONE       0x17

/*! \brief DSP Version Error
 *  \details Loaded DSP binary version is differ from expected.
 */

#define AS_ATTENTION_SUB_CODE_DSP_VERSION_ERROR     0x18

/*! \brief BaseBand Error
 *  \details Baseband power may be off. Power on baseband first.
 */

#define AS_ATTENTION_SUB_CODE_BASEBAND_ERROR        0x19

/*! \brief Stream Parser Error
 *  \details ES parsed result may be differ from Player initialize parameters.
 *           Match parameters and ES data.
 */

#define AS_ATTENTION_SUB_CODE_STREAM_PARSER_ERROR   0x1A

/*! \brief DSP Load Done
 *  \details DSP binary load done.
 */

#define AS_ATTENTION_SUB_CODE_DSP_LOAD_DONE         0x1B

/*! \brief Rec Start Action Done
 *  \details Recording start.
 */

#define AS_ATTENTION_SUB_CODE_RECSTART              0x1C

/*! \brief Rec Stop Action Done
 *  \details Recording stop.
 */

#define AS_ATTENTION_SUB_CODE_RECSTOP               0x1D

/*! \brief DSP Debug Dump Log Alloc Error
 *  \details Log area remain size is less than required size.
 *           The log area may be used by Other DSPs.
 */

#define AS_ATTENTION_SUB_CODE_DSP_LOG_ALLOC_ERROR   0x1E

/*! \brief DSP Assertion Fail
 *  \details DSP internal error occured and DSP cannot keep processing.
 */

#define AS_ATTENTION_SUB_CODE_DSP_ASSETION_FAIL     0x1F
  
/*! \brief DSP Send Fail
 *  \details Inter CPU commucation with DSP is failed.
 */

#define AS_ATTENTION_SUB_CODE_DSP_SEND_ERROR        0x20

#define AS_ATTENTION_SUB_CODE_NUM   AS_ATTENTION_SUB_CODE_DSP_SEND_ERROR

/** @} */

/** @defgroup error_response_code Error Code */
/** @{ */

/*! \brief Response OK */

#define AS_ECODE_OK                              0x00

/*! \brief State Violation */

#define AS_ECODE_STATE_VIOLATION                 0x01

/*! \brief Packet Length Error */

#define AS_ECODE_PACKET_LENGTH_ERROR             0x02

/*! \brief Command Code Error */

#define AS_ECODE_COMMAND_CODE_ERROR              0x03

/*! \brief Not Suppot Command */

#define AS_ECODE_COMMAND_NOT_SUPPOT              0x04

/*! \brief Audio PowerOn Error */

#define AS_ECODE_AUDIO_POWER_ON_ERROR            0x05

/*! \brief Audio PowerOff Error */

#define AS_ECODE_AUDIO_POWER_OFF_ERROR           0x06

/*! \brief DSP Load Error */

#define AS_ECODE_DSP_LOAD_ERROR                  0x07

/*! \brief DSP Unload Error */

#define AS_ECODE_DSP_UNLOAD_ERROR                0x08

/*! \brief DSP Version Error */

#define AS_ECODE_DSP_VERSION_ERROR               0x09

/*! \brief DSP Exec Error */

#define AS_ECODE_DSP_EXEC_ERROR                  0x3b

/*! \brief DSP Stop Error */

#define AS_ECODE_DSP_STOP_ERROR                  0x3c

/*! \brief DSP set Error */

#define AS_ECODE_DSP_SET_ERROR                   0x3d

/*! \brief Set Audio Data Path Error */

#define AS_ECODE_SET_AUDIO_DATA_PATH_ERROR       0x0A

/*! \brief Clear Audio Data Path Error */

#define AS_ECODE_CLEAR_AUDIO_DATA_PATH_ERROR     0x0B

/*! \brief Not Audio Data Path */

#define AS_ECODE_NOT_AUDIO_DATA_PATH             0x0C

/*! \brief Decoder Library Initialize Error */

#define AS_ECODE_DECODER_LIB_INITIALIZE_ERROR    0x0D

/*! \brief Encoder Library Initialize Error */

#define AS_ECODE_ENCODER_LIB_INITIALIZE_ERROR    0x0E

/*! \brief Filter Library Initialize Error */

#define AS_ECODE_FILTER_LIB_INITIALIZE_ERROR     0x0F

/*! \brief Dump Initialize Error */

#define AS_ECODE_DUMP_INITIALIZE_ERROR           0x10

/*! \brief Parameter Codec Type Error */

#define AS_ECODE_COMMAND_PARAM_CODEC_TYPE        0x11

/*! \brief Parameter Area Insufficient Error */

#define AS_ECODE_COMMAND_PARAM_AREA_INSUFFICIENT 0x12

/*! \brief Parameter Channel Number Error */

#define AS_ECODE_COMMAND_PARAM_CHANNEL_NUMBER    0x13

/*! \brief Parameter Sampling Rate Error */

#define AS_ECODE_COMMAND_PARAM_SAMPLING_RATE     0x14

/*! \brief Parameter Bit Rate Error */

#define AS_ECODE_COMMAND_PARAM_BIT_RATE          0x15

/*! \brief Parameter Bit Length Error */

#define AS_ECODE_COMMAND_PARAM_BIT_LENGTH        0x16

/*! \brief Parameter Complexity Error */

#define AS_ECODE_COMMAND_PARAM_COMPLEXITY        0x17

/*! \brief Parameter Active Player Error */

#define AS_ECODE_COMMAND_PARAM_ACTIVE_PLAYER     0x18

/*! \brief Parameter Input Device Error */

#define AS_ECODE_COMMAND_PARAM_INPUT_DEVICE      0x19

/*! \brief ParameterOutput Device Error */

#define AS_ECODE_COMMAND_PARAM_OUTPUT_DEVICE     0x1A

/*! \brief Parameter Input Handler Error */

#define AS_ECODE_COMMAND_PARAM_INPUT_HANDLER     0x1B

/*! \brief Parameter Output Handler Error */

#define AS_ECODE_COMMAND_PARAM_OUTPUT_HANDLER    0x1C

/*! \brief Parameter Callback Error */

#define AS_ECODE_COMMAND_PARAM_CALLBACK          0x1D

/*! \brief Parameter Function Enable Error */

#define AS_ECODE_COMMAND_PARAM_FUNCTION_ENABLE   0x1E

/*! \brief Parameter Config Table Error */

#define AS_ECODE_COMMAND_PARAM_CONFIG_TABLE      0x1F

/*! \brief Parameter With MFE Error */

#define AS_ECODE_COMMAND_PARAM_WITH_MFE          0x20

/*! \brief Parameter With MPP Error */

#define AS_ECODE_COMMAND_PARAM_WITH_MPP          0x21

/*! \brief Parameter Output Data Error */

#define AS_ECODE_COMMAND_PARAM_OUTPUT_DATE       0x22

/*! \brief Parameter Select MIC Error */

#define AS_ECODE_COMMAND_PARAM_SELECT_MIC        0x23

/*! \brief Parameter MIC Gain Error */

#define AS_ECODE_COMMAND_PARAM_MIC_GAIN          0x24

/*! \brief Parameter I2S Id Error */

#define AS_ECODE_COMMAND_PARAM_I2S_ID            0x25

/*! \brief Parameter Bypass Mode Error */

#define AS_ECODE_COMMAND_PARAM_BYPASS_MODE       0x26

/*! \brief Parameter Vollume Error */

#define AS_ECODE_COMMAND_PARAM_VOLLUME           0x27

/*! \brief Parameter Input DB Error */

#define AS_ECODE_COMMAND_PARAM_INPUT_DB          0x28

/*! \brief Parameter Master DB Error */

#define AS_ECODE_COMMAND_PARAM_MASTER_DB         0x29

/*! \brief Parameter Beep Freq Error  */

#define AS_ECODE_COMMAND_PARAM_BEEP_FREQ         0x2A

/*! \brief DMAC Initialize Error */

#define AS_ECODE_DMAC_INITIALIZE_ERROR           0x2B

/*! \brief DMAC Read Error */

#define AS_ECODE_DMAC_READ_ERROR                 0x2C

/*! \brief DMAC Write Error */

#define AS_ECODE_DMAC_WRITE_ERROR                0x2D

/*! \brief Check Memory Pool Error */

#define AS_ECODE_CHECK_MEMORY_POOL_ERROR         0x2E

/*! \brief SimpleFIFO Underflow */

#define AS_ECODE_SIMPLE_FIFO_UNDERFLOW           0x2F

/*! \brief Set Mic Gain Error */

#define AS_ECODE_SET_MIC_GAIN_ERROR              0x30

/*! \brief Set I2S Param Error */

#define AS_ECODE_SET_I2S_PARAM_ERROR             0x31

/*! \brief Set Output Select Error */

#define AS_ECODE_SET_OUTPUT_SELECT_ERROR         0x32

/*! \brief Init Clear Stereo Error */

#define AS_ECODE_INIT_CLEAR_STEREO_ERROR         0x33

/*! \brief Set Volume Error */

#define AS_ECODE_SET_VOLUME_ERROR                0x34

/*! \brief Set Volume Mute Error */

#define AS_ECODE_SET_VOLUME_MUTE_ERROR           0x35

/*! \brief Set Beep Error */

#define AS_ECODE_SET_BEEP_ERROR                  0x36

/*! \brief Internal Queue Operation Error */

#define AS_ECODE_QUEUE_OPERATION_ERROR           0x37

/*! \brief Internal Command Code Error */

#define AS_ECODE_INTERNAL_COMMAND_CODE_ERROR     0x38

/*! \brief Parameter RenderingClk Error */

#define AS_ECODE_COMMAND_PARAM_RENDERINGCLK      0x39

/*! \brief Set Rendering Clock Error */

#define AS_ECODE_SET_RENDERINGCLK_ERROR          0x3A

/** @} */

#define AS_ERROR_CODE_INFORMATION INFORMATION_ATTENTION_CODE
#define AS_ERROR_CODE_WARNING     WARNING_ATTENTION_CODE
#define AS_ERROR_CODE_ERROR       ERROR_ATTENTION_CODE
#define AS_ERROR_CODE_FATAL       FATAL_ATTENTION_CODE
#define AsErrorCode               ErrorAttensionCode

/****************************************************************************
 * Public Types
 ****************************************************************************/

/** Audio command header */

typedef struct
{
  /*! \brief [in] reserved */

  uint8_t reserved;

  /*! \brief [in] sub */

  uint8_t sub_code;

  /*! \brief [in] Command code */

  uint8_t command_code;

  /*! \brief [in] packet length */

  uint8_t packet_length;
} AudioCommandHeader;

/** Audio result header */

typedef struct
{
  /*! \brief reserved */

  uint8_t reserved;

  /*! \brief [out] sub code*/

  uint8_t sub_code;

  /*! \brief [out] result code*/

  uint8_t result_code;

  /*! \brief [out] packet length*/

  uint8_t packet_length;
} AudioResultHeader;

/** InitMicGain Command (#AUDCMD_INITMICGAIN) parameter */

typedef struct
{
  /*! \brief [in] Set Mic gain
   *
   *  -7850:-78.50dB, ... , -5:-0.05dB, 0:0dB(default),
   *  5:+0.5dB, ... , 210:+21.0dB, #AS_MICGAIN_HOLD:keep setting
   */

  int16_t mic_gain[AS_MIC_CHANNEL_MAX];
} InitMicGainParam;

/** InitI2SParam Command (#AUDCMD_INITI2SPARAM) parameter */

typedef enum
{
  AS_I2S1,
  AS_I2S2
} AsI2sId;

typedef enum
{
  AS_I2S_BYPASS_MODE_DISABLE,
  AS_I2S_BYPASS_MODE_ENABLE
} AsI2SBypassMode;

typedef struct
{
  /*! \brief [in] Select I2S ID
   * Use #AsI2sId enum type
   */

  uint8_t  i2s_id;

  /*! \brief [in] Select I2S Bypass mode disable/enable
   *
   *  Use #AsBypassModeId enum type
   */

  uint8_t  bypass_mode_en;
  uint16_t reserved2;

  /*! \brief [in] Set I2S input/output frequency */

  uint32_t rate;
} InitI2SParam;

/** InitOutputSelect Command (#AUDCMD_INITOUTPUTSELECT) parameter */

typedef enum
{
  /*! Output device none */

  AS_OUT_OFF,

  /*! Output device speaker */

  AS_OUT_SP,

  /*! Output device i2s */

  AS_OUT_I2S
} AsOutDevice;

typedef struct
{
  /*! \brief [in] Select CXD5247 output devices
   *
   * Use #AsOutDeviceId enum type
   */

  uint8_t  output_device_sel;
  uint8_t  reserved1;
  uint16_t reserved2;
} InitOutputSelectParam;

/** (__not supported__) InitDNCParam Command (#AUDCMD_INITDNCPARAM) parameter
 */

typedef enum
{
  AS_DNC_MODE_A,
  AS_DNC_MODE_B,
  AS_DNC_MODE_C
} AsDncMode;

typedef struct
{
  /*! \brief [in] Select DNC mode
   *
   * Use #AsDncModeId enum type
   */

  uint8_t  mode;
  uint8_t  reserved1;
  uint16_t reserved2;
} InitDNCParam;

/** InitClearStereo Command (#AUDCMD_INITCLEARSTEREO) parameter */

typedef struct {
  /*! \brief [in] Select ClearStereo Enable/Disable, 1:Enable, 0:Disable. */

  uint8_t cs_en;
  uint8_t reserved1;

  /*! \brief [in] Set ClearStero Volume
   *
   * -825:-82.5dB(default), ... -195:-19.5dB,
   * #AS_ CS_VOL_HOLD:keep setting
   */

  int16_t cs_vol;
} InitClearStereoParam;

/** SetVolume Command (#AUDCMD_SETVOLUME) parameter */

typedef struct
{
  /*! \brief [in] Set Master Volume
   *
   * -1020:-102.0dB, ... 120:12.0dB,
   * #AS_VOLUME_HOLD:keep setting, #AS_VOLUME_MUTE(default):Mute
   */

  int16_t  master_db;
  uint16_t reserved1;

  /*! \brief [in] Set Input1 Volume
   *
   * -1020:-102.0dB, ... 120:12.0dB,
   * #AS_VOLUME_HOLD:keep setting, #AS_VOLUME_MUTE(default):Mute
   */

  int16_t  input1_db;

  /*! \brief [in] Set Input2 Volume
   *
   * -1020:-102.0dB, ... 120:12.0dB,
   * #AS_VOLUME_HOLD:keep setting, #AS_VOLUME_MUTE(default):Mute
   */

  int16_t  input2_db;
} SetVolumeParam;

/** SetVolumeMute Command (#AUDCMD_SETVOLUMEMUTE) parameter */

typedef struct
{
  /*! \brief [in] Select Master Volume Mute/UnMute
   *
   * Use #AsVolumeMute enum type.
   */

  uint8_t  master_mute;

  /*! \brief [in] Set Input1 Volume Mute/UnMute */

  uint8_t  input1_mute;

  /*! \brief [in] Set Input2 Volume Mute/UnMute */

  uint8_t  input2_mute;
  uint8_t  reserved1;
} SetVolumeMuteParam;

/** SetBeep Command (#AUDCMD_SETBEEPPARAM) parameter */

typedef struct
{
  /*! \brief [in] Select BEEP Enable/Disable
   *
   *  1:Enable, 0:Disable.
   */

  uint8_t  beep_en;
  uint8_t  reserved1;
  uint16_t reserved2;

  /*! \brief [in] Set BEEP Volume
   *
   * -90:-90dB, ... -12:-12dB(default), ... , 0:0dB,
   * #AS_BEEP_VOL_HOLD:keep setting
   */

  int16_t beep_vol;

  /*! \brief [in] Set BEEP Frequency
   *
   * 94:94Hz, ... 4085:4085Hz,
   * #AS_BEEP_FREQ_HOLD:keep setting
   */

  uint16_t beep_freq;
} SetBeepParam;

/** PowerOn Command (#AUDCMD_POWERON) parameter */

typedef struct
{
  /*! \brief [in] Enable or disable sound-effect playback function.
   *
   * Use #AsEnableSoundEffectFunc enum type.
   */

  uint8_t  enable_sound_effect;
  uint8_t  reserved1;
  uint8_t  reserved2;
  uint8_t  reserved3;
} PowerOnParam;

/** SetRenderingClk Command (#AUDCMD_SETRENDERINGCLK) parameter */

typedef struct
{
  /*! \brief [in] set rendering clock
   *
   * Use #AsClkMode enum type.
   */

  uint8_t  clk_mode;
  uint8_t  reserved1;
  uint8_t  reserved2;
  uint8_t  reserved3;
} SetRenderingClkParam;

/** SetRenderingClk Command (#AUDCMD_SETRENDERINGCLK) parameter */

typedef enum
{
  AS_CLKMODE_NORMAL,
  AS_CLKMODE_HIRES
} AsClkMode;

/** Enable or disable effect sound playback function. */

typedef enum
{
  /*! \brief Disable effect sound */

  AS_DISABLE_SOUNDEFFECT = 0,

  /*! \brief Enable effect sound (__not supported__) */

  AS_ENABLE_SOUNDEFFECT,
  AS_SOUNDEFFECT_NUM
} AsEnableSoundEffectFunc;

/** playback mode of effect sound */

typedef enum
{
  /*! \brief Play effect sound with limited data. */

  AS_STARTSOUNDEFFECT_NORMAL = 0,

  /*! \brief Play effect sound infinitely. */

  AS_STARTSOUNDEFFECT_INFINITE,
  AS_STARTSOUNDEFFECT_MODE_NUM
} AsStartSoundEffectMode;

/** Select direct input path */

typedef enum
{
  AS_THROUGH_PATH_IN_MIC = 0,
  AS_THROUGH_PATH_IN_I2S1,
  AS_THROUGH_PATH_IN_I2S2,
  AS_THROUGH_PATH_IN_MIXER,
  AS_THROUGH_PATH_IN_NUM
} AsThroughPathIn;

/** Select direct output path */

typedef enum
{
  AS_THROUGH_PATH_OUT_MIXER1 = 0,
  AS_THROUGH_PATH_OUT_MIXER2,
  AS_THROUGH_PATH_OUT_I2S1,
  AS_THROUGH_PATH_OUT_I2S2,
  AS_THROUGH_PATH_OUT_NUM
} AsThroughPathOut;

/** Through path of audio data (used in AsSetThroughPathParam) parameter */

typedef struct
{
  /*! \brief  Select direct path Enable/Disable
   *
   *  1:Enable, 0:Disable.
   */

  bool en;

  /*! \brief  input path
   *
   * Use AsThroughPathIn
   */

  uint8_t in;

  /*! \brief  output path
   *
   * Use AsThroughPathOut
   */

  uint8_t out;

} AsThroughPath;

/** SetThroughPath Command (#AUDCMD_SETDIRECTPATH) parameter */

typedef struct
{
  /*! \brief [in] path1 */

  AsThroughPath  path1;

  /*! \brief [in] path2 */

  AsThroughPath  path2;

} AsSetThroughPathParam;

/** Audio command packet */

#if defined(__CC_ARM)
#pragma anon_unions
#endif

typedef struct
{
  /*! \brief [in] Command Header */

  AudioCommandHeader header;
  union
  {
#ifdef AS_FEATURE_EFFECTOR_ENABLE
    /*! \brief [in] for InitMFE
     * (header.command_code==#AUDCMD_INITMFE)
     */

    InitMFEParam init_mfe_param;

    /*! \brief [in] for StartBB
     * (header.command_code==#AUDCMD_STARTBB)
     */

    StartBBParam start_bb_param;

    /*! \brief [in] for StopBB
     * (header.command_code==#AUDCMD_STOPBB)
     */

    StopBBParam stop_bb_param;

    /*! \brief [in] for InitMPP
     * (header.command_code==#AUDCMD_INITMPP)
     */

    InitMPPParam init_mpp_param;

    /*! \brief [in] for SetMPPParam
     * (header.command_code==#AUDCMD_SETMPPPARAM)
     */

    SetMPPParam set_mpp_param;

    /*! \brief [in] for SetBaseBandStatus
     * (header.command_code==#AUDCMD_SETBASEBANDSTATUS)
     */

    SetBaseBandStatusParam set_baseband_status_param;
#endif
#ifdef AS_FEATURE_PLAYER_ENABLE
    /*! \brief [in] for SetPlayerStatus
     * (header.command_code==#AUDCMD_SETPLAYERSTATUS)
     */

    SetPlayerStsParam set_player_sts_param;

    /*! \brief [in] player command
     */

    PlayerCommand player;

    /*! \brief [in] for Adjust sound period
     * (header.command_code==#AUDCMD_CLKRECOVERY)
     */

    AsPlayerClockRecovery clk_recovery_param;

#endif
#ifdef AS_FEATURE_RECORDER_ENABLE

    /*! \brief [in] for SetRecorderStatus
     * (header.command_code==#AUDCMD_SETRECORDERSTATUS)
     */

    AsActivateRecorderParam set_recorder_status_param;

    /*! \brief [in] Recorder command
     */

    RecorderCommand recorder;

#endif
#ifdef AS_FEATURE_RECOGNIZER_ENABLE
    /*! \brief [in] for StratVoiceCommand
     * (header.command_code==#AUDCMD_STARTVOICECOMMAND)
     */

    StartVoiceCommandParam start_voice_command_param;
#endif

    /*! \brief [in] for InitMicGain
     * (header.command_code==#AUDCMD_INITMICGAIN)
     */

    InitMicGainParam init_mic_gain_param;

    /*! \brief [in] for InitI2SParam
     * (header.command_code==#AUDCMD_INITI2SPARAM)
     */

    InitI2SParam init_i2s_param;

    /*! \brief [in] for InitOutputSelect
     * (header.command_code==#AUDCMD_INITOUTPUTSELECT)
     */

    InitOutputSelectParam init_output_select_param;

    /*! \brief [in] for InitDNCParam
     * (header.command_code==#AUDCMD_INITDNCPARAM)
     */

    InitDNCParam init_dnc_param;

    /*! \brief [in] for InitClearStereo
     * (header.command_code==#AUDCMD_INITCLEARSTEREO)
     */

    InitClearStereoParam init_clear_stereo_param;

    /*! \brief [in] for SetVolume
     * (header.command_code==#AUDCMD_SETVOLUME)
     */

    SetVolumeParam set_volume_param;

    /*! \brief [in] for SetVolumeMute
     * (header.command_code==#AUDCMD_SETVOLUMEMUTE)
     */

    SetVolumeMuteParam set_volume_mute_param;

    /*! \brief [in] for SetBeep
     * (header.command_code==#AUDCMD_SETBEEPPARAM)
     */

    SetBeepParam set_beep_param;

    /*! \brief [in] for PowerOn
     * (header.command_code==#AUDCMD_POWERON)
     */

    PowerOnParam power_on_param;

    /*! \brief [in] for SetThrouhgPath
     * (header.command_code==#AUDCMD_SETTHROUGHPATH)
     */

    AsSetThroughPathParam set_through_path;

    /*! \brief [in] for SetRenderingClk
     * (header.command_code==#AUDCMD_SETRENDERINGCLK)
     */

    SetRenderingClkParam set_renderingclk_param;
  };

#ifdef __cplusplus
  uint8_t getCode(void)
    {
      return header.command_code;
    }
  bool isStateChange(void)
    {
      return ((getCode() & 0x40) != 0);
    }
#endif

#if !defined(__CC_ARM)
} AudioCommand ;
#else
} AudioCommand __attribute__((transparent_union));
#endif


/* Result Structures */

/* NotifyStatus */

/** Current Status */

typedef enum
{
  /*! \brief Ready */

  AS_MNG_STATUS_READY = 0,

  /*! \brief Baseband */

  AS_MNG_STATUS_BASEBAND,

  /*! \brief Player */

  AS_MNG_STATUS_PLAYER,

  /*! \brief Recorder */

  AS_MNG_STATUS_RECORDER,

  /*! \brief PowerOff */

  AS_MNG_STATUS_POWEROFF,

  /*! \brief Through */

  AS_MNG_STATUS_THROUGH,

  AS_MNG_STATUS_NUM
} AsMngStatus;

/** Current Sub Status */

typedef enum
{
  /*! \brief None */

  AS_MNG_SUB_STATUS_NONE = 0,

  /*! \brief PlayReady */

  AS_MNG_SUB_STATUS_PLAYREADY,

  /*! \brief PlayActive */

  AS_MNG_SUB_STATUS_PLAYACTIVE,

  /*! \brief PlayPause */

  AS_MNG_SUB_STATUS_PLAYPAUSE,

  /*! \brief RecorderReady */

  AS_MNG_SUB_STATUS_RECORDERREADY,

  /*! \brief RecorderActive */

  AS_MNG_SUB_STATUS_RECORDERACTIVE,

  /*! \brief BaseBandReady */

  AS_MNG_SUB_STATUS_BASEBANDREADY,

  /*! \brief BaseBandActive */

  AS_MNG_SUB_STATUS_BASEBANDACTIVE,

  /*! \brief WaitCommandword */

  AS_MNG_SUB_STATUS_WAITCMDWORD,
  AS_MNG_SUB_STATUS_NUM
} AsMngSubStatus;

/** Current VAD Status
 *(valid only NotifyStatus.sub_status_info==#AS_SUB_STATUS_WAITCOMMANDWORD)
 */

typedef enum
{
  /*! \brief Out of voice section */

  AS_VAD_STATUS_OUT_OF_VOICE_SECTION = 0,

  /*! \brief Inside voice section */

  AS_VAD_STATUS_INSIDE_VOICE_SECTION,
  AS_VAD_STATUS_NUM
} AsVadStatus;

/** Changed Status */

typedef enum
{
  /*! \brief to Ready */

  AS_STATUS_CHANGED_STS_READY = 0,

  /*! \brief to BaseBand */

  AS_STATUS_CHANGED_STS_BASEBAND,

  /*! \brief to  Player */

  AS_STATUS_CHANGED_STS_PLAYER,

  /*! \brief to  Recorder */

  AS_STATUS_CHANGED_STS_RECODER,

  /*! \brief to PowerOff */

  AS_STATUS_CHANGED_STS_POWEROFF,

  /*! \brief to Through */

  AS_STATUS_CHANGED_STS_THROUGH,

  AS_STATUS_CHANGED_STS_NUM
} AsStatusChangedSts;

/** Audio Module ID */

/** @defgroup module_id_code Module ID */
/** @{ */

typedef enum
{
  /*! \brief Audio Manager Module ID */

  AS_MODULE_ID_AUDIO_MANAGER = 0,

  /*! \brief Audio Baseband Driver Module ID */
  AS_MODULE_ID_AUDIO_DRIVER,

  /*! \brief Input Data Manager Object ID */

  AS_MODULE_ID_INPUT_DATA_MNG_OBJ,

  /*! \brief Media Recorder Object ID */

  AS_MODULE_ID_MEDIA_RECORDER_OBJ,

  /*! \brief Output Mix Object ID */

  AS_MODULE_ID_OUTPUT_MIX_OBJ,

  /*! \brief Player Object ID */

  AS_MODULE_ID_PLAYER_OBJ,

  /*! \brief Recognition Object ID */

  AS_MODULE_ID_RECOGNITION_OBJ,

  /*! \brief Sound Effect Object ID */

  AS_MODULE_ID_SOUND_EFFECT_OBJ,

  /*! \brief Capture Component ID */

  AS_MODULE_ID_CAPTURE_CMP,

  /*! \brief Decoder Component ID */

  AS_MODULE_ID_DECODER_CMP,

  /*! \brief Encoder Component ID */

  AS_MODULE_ID_ENCODER_CMP,

  /*! \brief Filter Component ID */

  AS_MODULE_ID_FILTER_CMP,

  /*! \brief Recognition Component ID */

  AS_MODULE_ID_RECOGNITION_CMP,

  /*! \brief Renderer Component ID */

  AS_MODULE_ID_RENDERER_CMP,

  /*! \brief Postfilter Component ID */

  AS_MODULE_ID_POSTFILTER_CMP,
  AS_MODULE_ID_NUM,
} AsModuleId;

/** @} */

/** Audio Manager error code */

typedef enum
{
  /*! \brief success */
  
  AS_ERR_CODE_OK = 0,
  
  /*! \brief fail to create task */
  
  AS_ERR_CODE_TASK_CREATE = -1,
  
  /*! \brief illegal state */
  
  AS_ERR_CODE_ILLEGAL_STATE = -2
} AsErrorCode_e;

/** Select volume mute/unmute */

typedef enum
{
  /*! \brief keep setting */

  AS_VOLUMEMUTE_HOLD,

  /*! \brief unmute */

  AS_VOLUMEMUTE_UNMUTE,

  /*! \brief mute */

  AS_VOLUMEMUTE_MUTE,
  AS_VOLUMEMUTE_NUM
} AsVolumeMute;

/** Select beep mode */

typedef enum
{
  /*! \brief beep disable */

  AS_BEEPEN_DISABLE,

  /*! \brief beep enable */

  AS_BEEPEN_ENABLE,
  AS_BEEPEN_NUM
} asBeepEn;

/** NotifyStatus Result (#AUDRLT_NOTIFYSTATUS) parameter */

typedef struct
{
  /*! \brief VAD status
   *
   * #AsNotifyVadStatus enum type
   */

  uint8_t  vad_status;

  /*! \brief [out] reserved */

  uint8_t  reserved;

  /*! \brief [out] Current Sub Status
   *
   * #AsNotifySubStatusInfo enum type
   */

  uint8_t  sub_status_info;

  /*! \brief [out] Current Status
   *
   * #AsNotifyStatusInfo enum type
   */

  uint8_t  status_info;
} NotifyStatus;

/** StatusChanged Result (#AUDRLT_STATUSCHANGED) parameter */

typedef struct
{
  /*! \brief [out] Changed status
   *
   *#AsStatusChangedSts enum type
   */

  uint8_t  changed_status;

  /*! \brief reserved */

  uint8_t  reserved1;

  /*! \brief reserved */

  uint8_t  reserved2;

  /*! \brief reserved */

  uint8_t  reserved3;
} StatusChangedParam;

/** ErrorResponse Result (#AUDRLT_ERRORRESPONSE) parameter */

typedef struct
{
  /*! \brief Error Infomation, T.B.D. */

  uint32_t error_code;

  /*! \brief [out] reserved */

  uint16_t reserved1;

  /*! \brief [out] for debug purpose */

  uint8_t  sub_module_id;

  /*! \brief [out] Error module infomation, T.B.D. */

  uint8_t  module_id;

  /*! \brief [out] Detailed Error Infomation, T.B.D. */

  uint32_t error_sub_code;

  /*! \brief [out] reserved */

  uint32_t reserved2;

  /*! \brief [out] Head part of the command packet that caused the Error */

  uint32_t ErrorCommand[LENGTH_AUDRLT_ERRORRESPONSE_MAX-LENGTH_AUDRLT_ERRORRESPONSE_MIN];
} ErrorResponseParam;

/** ErrorAttention Result (#AUDRLT_ERRORATTENTION) parameter */

#define ATTENTION_FILE_NAME_LEN 32

typedef struct
{
  /*! \brief [out] reserved */

  uint32_t reserved1;

  /*! \brief [out] Error Infomation, T.B.D. */

  uint8_t  error_code;

  /*! \brief [out] CPU ID (internal use only) */

  uint8_t  cpu_id;

  /*! \brief [out] for debug purpose */

  uint8_t  sub_module_id;

  /*! \brief [out] Error module infomation, T.B.D. */

  uint8_t  module_id;

  /*! \brief [out] Detailed Error Infomation, T.B.D. */

  uint32_t error_att_sub_code;

  /*! \brief [out] reserved */

  uint32_t reserved2;

  /*! \brief [out] Line No (internal use only) */

  uint16_t line_number;

  /*! \brief [out] Task ID (internal use only) */

  uint8_t  task_id;

  /*! \brief [out] reserved */

  uint8_t  reserved3;

  /*! \brief [out] File name (internal use only) */

  union
  {
    uint32_t align_dummy;
    char     error_filename[ATTENTION_FILE_NAME_LEN];
  };

} ErrorAttentionParam;

/** Audio result packet
 */
#if defined(__CC_ARM)
#pragma anon_unions
#endif

typedef struct {
  /*! \brief [out] Result Header */

  AudioResultHeader header;

  union
  {
    /*! \brief [out] for NotifyStatus
     *  (header.result_code==#AUDRLT_NOTIFYSTATUS)
     */

    NotifyStatus   notify_status;

    /*! \brief [out] for StatusChanged
     * (header.result_code==#AUDRLT_STATUSCHANGED)
     */

    StatusChangedParam status_changed_param;

    /*! \brief [out] for ErrorResponse
     * (header.result_code==#AUDRLT_ERRORRESPONSE)
     */

    ErrorResponseParam error_response_param;
  };

#if !defined(__CC_ARM)
} AudioResult ;
#else
} AudioResult __attribute__((transparent_union));
#endif

/** Audio Attention Callback function
 * @param[in] attparam: Attention detail parameter
 */

typedef void (*AudioAttentionCb)(const ErrorAttentionParam *attparam);

#ifndef ATTENTION_USE_FILENAME_LINE
typedef void (*obs_AudioAttentionCb)(uint8_t module_id,
                                     uint8_t error_code,
                                     uint8_t sub_code);
#else
typedef void (*obs_AudioAttentionCb)(uint8_t module_id,
                                     uint8_t error_code,
                                     uint8_t sub_code,
                                     FAR const char *file_name,
                                     uint32_t line);
#endif

/* Error Code */
/* [T.B.D]
 *
 * no error = 0
 * state error
 * paramater error
 * timeout
 *
 */

/** Activate function parameter */

typedef struct
{
  /*! \brief [in] MsgQueID of Application */

  uint8_t app;

  /*! \brief [in] MsgQueID of audio_manager */

  uint8_t mng;

  /*! \brief [in] MsgQueID of playerObject */

  uint8_t player_main;

  /*! \brief [in] MsgQueID of playerObject for Sound Effect */

  uint8_t player_sub;

  /*! \brief [in] MsgQueID of recorderObject */

  uint8_t recorder;

  /*! \brief [in] MsgQueID of mixerObject */

  uint8_t mixer;

  /*! \brief [in] MsgQueID of effectorObject */

  uint8_t effector;

  /*! \brief [in] MsgQueID of recognizerObject */

  uint8_t recognizer;
} AudioSubSystemIDs;

/****************************************************************************
 * Public Data
 ****************************************************************************/

/****************************************************************************
 * Inline Functions
 ****************************************************************************/

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/**
 * @brief Send Audio Command
 *
 * @param[in] packet: AudioCommand* Command packet
 *
 * @retval error code
 */

int AS_SendAudioCommand(AudioCommand* packet);

/**
 * @brief Receive Audio Result
 *
 * @param[out] packet: AudioResult*: Result packet
 *
 * @retval error code
 */

int AS_ReceiveAudioResult(AudioResult* packet);

/**
 * @brief Activate AudioSubSystem
 *
 * @param[in] ids: AudioSubSystemIDs* Message Queue ID of Audio Module
 *
 * @retval error code
 */

int AS_CreateAudioManager(AudioSubSystemIDs ids, AudioAttentionCb att_cb);

/**
 * @brief Activate AudioSubSystem[Deprecated]
 *        This API is to make it compatible with old application.
 *        Will delete most application seems to migrate to new API.
 *
 * @param[in] ids: AudioSubSystemIDs* Message Queue ID of Audio Module
 *
 * @retval error code
 */

__attribute__((deprecated("\nDeprecated attention callback type is used. \
                           \nPlease use \"AudioAttentionCb\" as callback type. \
                           \n")))
int AS_CreateAudioManager(AudioSubSystemIDs ids, obs_AudioAttentionCb obs_att_cb);

/**
 * @brief Deactivate AudioSubSystem
 *
 * @retval error code
 */

int AS_DeleteAudioManager(void);

/** @} */

#endif /* __MODULES_INCLUDE_AUDIO_AUDIO_HIGH_LEVEL_API_H */

/**
 * @}
 */
/**
 * @}
 */
