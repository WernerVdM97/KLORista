#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#define TAPPING_TERM 210
// #define MASTER_RIGHT

// Enable OLED updates on slave
// #define SPLIT_LED_STATE_ENABLE
#define SPLIT_HAPTIC_ENABLE

// Haptics
#define DRV2605L_FB_ERM_LRA 0
#define DRV2605L_FB_BRAKEFACTOR 6 /* For 1x:0, 2x:1, 3x:2, 4x:3, 6x:4, 8x:5, 16x:6, Disable Braking:7 */
#define DRV2605L_FB_LOOPGAIN 0 /* For  Low:0, Medium:1, High:2, Very High:3 */
#define DRV2605L_RATED_VOLTAGE 2.4
#define DRV2605L_V_PEAK 4
#define DRV2605L_DEFAULT_MODE 13
#define DRV2605L_GREETING 15

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
// #define TAPPING_FORCE_HOLD // does this even work..?
// #define RETRO_TAPPING_PER_KEY // consider trying this? activates tap beyond tapping term unless rolled

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT
