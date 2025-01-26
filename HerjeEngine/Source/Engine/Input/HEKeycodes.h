#pragma once
#include <SDL3/SDL_keycode.h>

// Key codes, wrapping these to limit the exposure between the Application project and SDL,
// If I ever want to switch off of SDL, I imagine I just need to change these to the new Input codes

typedef uint32_t HE_KeyCode;

#define HE_KEY_SCANCODE_MASK SDLK_SCANCODE_MASK
#define HE_SCANCODE_TO_KEYCODE(X) SDL_SCANCODE_TO_KEYCODE(X)
#define HE_KEY_UNKNOWN SDLK_UNKNOWN
#define HE_KEY_RETURN SDLK_RETURN
#define HE_KEY_ESCAPE SDLK_ESCAPE
#define HE_KEY_BACKSPACE SDLK_BACKSPACE
#define HE_KEY_TAB SDLK_TAB
#define HE_KEY_SPACE SDLK_SPACE
#define HE_KEY_EXCLAIM SDLK_EXCLAIM
#define HE_KEY_DBLAPOSTROPHE SDLK_DBLAPOSTROPHE
#define HE_KEY_HASH SDLK_HASH
#define HE_KEY_PERCENT SDLK_PERCENT
#define HE_KEY_DOLLAR SDLK_DOLLAR
#define HE_KEY_AMPERSAND SDLK_AMPERSAND
#define HE_KEY_APOSTROPHE SDLK_APOSTROPHE
#define HE_KEY_LEFTPAREN SDLK_LEFTPAREN
#define HE_KEY_RIGHTPAREN SDLK_RIGHTPAREN
#define HE_KEY_ASTERISK SDLK_ASTERISK
#define HE_KEY_PLUS SDLK_PLUS
#define HE_KEY_COMMA SDLK_COMMA
#define HE_KEY_MINUS SDLK_MINUS
#define HE_KEY_PERIOD SDLK_PERIOD
#define HE_KEY_SLASH SDLK_SLASH
#define HE_KEY_0 SDLK_0
#define HE_KEY_1 SDLK_1
#define HE_KEY_2 SDLK_2
#define HE_KEY_3 SDLK_3
#define HE_KEY_4 SDLK_4
#define HE_KEY_5 SDLK_5
#define HE_KEY_6 SDLK_6
#define HE_KEY_7 SDLK_7
#define HE_KEY_8 SDLK_8
#define HE_KEY_9 SDLK_9
#define HE_KEY_COLON SDLK_COLON
#define HE_KEY_SEMICOLON SDLK_SEMICOLON
#define HE_KEY_LESS SDLK_LESS
#define HE_KEY_EQUALS SDLK_EQUALS
#define HE_KEY_GREATER SDLK_GREATER
#define HE_KEY_QUESTION SDLK_QUESTION
#define HE_KEY_AT SDLK_AT
#define HE_KEY_LEFTBRACKET SDLK_LEFTBRACKET
#define HE_KEY_BACKSLASH SDLK_BACKSLASH
#define HE_KEY_RIGHTBRACKET SDLK_RIGHTBRACKET
#define HE_KEY_CARET SDLK_CARET
#define HE_KEY_UNDERSCORE SDLK_UNDERSCORE
#define HE_KEY_GRAVE SDLK_GRAVE
#define HE_KEY_A SDLK_a
#define HE_KEY_B SDLK_b
#define HE_KEY_C SDLK_c
#define HE_KEY_D SDLK_d
#define HE_KEY_E SDLK_e
#define HE_KEY_F SDLK_f
#define HE_KEY_G SDLK_g
#define HE_KEY_H SDLK_h
#define HE_KEY_I SDLK_i
#define HE_KEY_J SDLK_j
#define HE_KEY_K SDLK_k
#define HE_KEY_L SDLK_l
#define HE_KEY_M SDLK_m
#define HE_KEY_N SDLK_n
#define HE_KEY_O SDLK_o
#define HE_KEY_P SDLK_p
#define HE_KEY_Q SDLK_q
#define HE_KEY_R SDLK_r
#define HE_KEY_S SDLK_s
#define HE_KEY_T SDLK_t
#define HE_KEY_U SDLK_u
#define HE_KEY_V SDLK_v
#define HE_KEY_W SDLK_w
#define HE_KEY_X SDLK_x
#define HE_KEY_Y SDLK_y
#define HE_KEY_Z SDLK_z

#define HE_KEY_CAPSLOCK SDLK_CAPSLOCK
#define HE_KEY_F1 SDLK_F1
#define HE_KEY_F2 SDLK_F2
#define HE_KEY_F3 SDLK_F3
#define HE_KEY_F4 SDLK_F4
#define HE_KEY_F5 SDLK_F5
#define HE_KEY_F6 SDLK_F6
#define HE_KEY_F7 SDLK_F7
#define HE_KEY_F8 SDLK_F8
#define HE_KEY_F9 SDLK_F9
#define HE_KEY_F10 SDLK_F10
#define HE_KEY_F11 SDLK_F11
#define HE_KEY_F12 SDLK_F12
#define HE_KEY_PRINTSCREEN SDLK_PRINTSCREEN
#define HE_KEY_SCROLLLOCK SDLK_SCROLLLOCK
#define HE_KEY_PAUSE SDLK_PAUSE
#define HE_KEY_INSERT SDLK_INSERT
#define HE_KEY_HOME SDLK_HOME
#define HE_KEY_PAGEUP SDLK_PAGEUP
#define HE_KEY_DELETE SDLK_DELETE
#define HE_KEY_END SDLK_END
#define HE_KEY_PAGEDOWN SDLK_PAGEDOWN
#define HE_KEY_RIGHT SDLK_RIGHT
#define HE_KEY_LEFT SDLK_LEFT
#define HE_KEY_DOWN SDLK_DOWN
#define HE_KEY_UP SDLK_UP
#define HE_KEY_NUMLOCKCLEAR SDLK_NUMLOCKCLEAR

#define HE_KEY_KP_DIVIDE       SDLK_KP_DIVIDE
#define HE_KEY_KP_MULTIPLY     SDLK_KP_MULTIPLY
#define HE_KEY_KP_MINUS        SDLK_KP_MINUS
#define HE_KEY_KP_PLUS         SDLK_KP_PLUS
#define HE_KEY_KP_ENTER        SDLK_KP_ENTER
#define HE_KEY_KP_1            SDLK_KP_1
#define HE_KEY_KP_2            SDLK_KP_2
#define HE_KEY_KP_3            SDLK_KP_3
#define HE_KEY_KP_4            SDLK_KP_4
#define HE_KEY_KP_5            SDLK_KP_5
#define HE_KEY_KP_6            SDLK_KP_6
#define HE_KEY_KP_7            SDLK_KP_7
#define HE_KEY_KP_8            SDLK_KP_8
#define HE_KEY_KP_9            SDLK_KP_9
#define HE_KEY_KP_0            SDLK_KP_0
#define HE_KEY_KP_PERIOD       SDLK_KP_PERIOD
#define HE_KEY_APPLICATION    SDLK_APPLICATION
#define HE_KEY_POWER          SDLK_POWER
#define HE_KEY_KP_EQUALS      SDLK_KP_EQUALS
#define HE_KEY_F13            SDLK_F13
#define HE_KEY_F14            SDLK_F14
#define HE_KEY_F15            SDLK_F15
#define HE_KEY_F16            SDLK_F16
#define HE_KEY_F17            SDLK_F17
#define HE_KEY_F18            SDLK_F18
#define HE_KEY_F19            SDLK_F19
#define HE_KEY_F20            SDLK_F20
#define HE_KEY_F21            SDLK_F21
#define HE_KEY_F22            SDLK_F22
#define HE_KEY_F23            SDLK_F23
#define HE_KEY_F24            SDLK_F24
#define HE_KEY_EXECUTE        SDLK_EXECUTE
#define HE_KEY_HELP           SDLK_HELP
#define HE_KEY_MENU           SDLK_MENU
#define HE_KEY_SELECT         SDLK_SELECT
#define HE_KEY_STOP           SDLK_STOP
#define HE_KEY_AGAIN          SDLK_AGAIN
#define HE_KEY_UNDO           SDLK_UNDO
#define HE_KEY_CUT            SDLK_CUT
#define HE_KEY_COPY           SDLK_COPY
#define HE_KEY_PASTE          SDLK_PASTE
#define HE_KEY_FIND           SDLK_FIND
#define HE_KEY_MUTE           SDLK_MUTE
#define HE_KEY_VOLUMEUP       SDLK_VOLUMEUP
#define HE_KEY_VOLUMEDOWN     SDLK_VOLUMEDOWN
#define HE_KEY_KP_COMMA       SDLK_KP_COMMA
#define HE_KEY_KP_EQUALSAS400 SDLK_KP_EQUALSAS400
#define HE_KEY_ALTERASE       SDLK_ALTERASE
#define HE_KEY_SYSREQ         SDLK_SYSREQ
#define HE_KEY_CANCEL         SDLK_CANCEL
#define HE_KEY_CLEAR          SDLK_CLEAR
#define HE_KEY_PRIOR          SDLK_PRIOR
#define HE_KEY_RETURN2        SDLK_RETURN2
#define HE_KEY_SEPARATOR      SDLK_SEPARATOR
#define HE_KEY_OUT            SDLK_OUT
#define HE_KEY_OPER           SDLK_OPER
#define HE_KEY_CLEARAGAIN     SDLK_CLEARAGAIN
#define HE_KEY_CRSEL          SDLK_CRSEL
#define HE_KEY_EXSEL          SDLK_EXSEL
#define HE_KEY_KP_00          SDLK_KP_00
#define HE_KEY_KP_000         SDLK_KP_000
#define HE_KEY_THOUSANDSSEPARATOR SDLK_THOUSANDSSEPARATOR
#define HE_KEY_DECIMALSEPARATOR   SDLK_DECIMALSEPARATOR
#define HE_KEY_CURRENCYUNIT       SDLK_CURRENCYUNIT
#define HE_KEY_CURRENCYSUBUNIT    SDLK_CURRENCYSUBUNIT
#define HE_KEY_KP_LEFTPAREN   SDLK_KP_LEFTPAREN
#define HE_KEY_KP_RIGHTPAREN  SDLK_KP_RIGHTPAREN
#define HE_KEY_KP_LEFTBRACE   SDLK_KP_LEFTBRACE
#define HE_KEY_KP_RIGHTBRACE  SDLK_KP_RIGHTBRACE
#define HE_KEY_KP_TAB         SDLK_KP_TAB
#define HE_KEY_KP_BACKSPACE   SDLK_KP_BACKSPACE
#define HE_KEY_KP_A           SDLK_KP_A
#define HE_KEY_KP_B           SDLK_KP_B
#define HE_KEY_KP_C           SDLK_KP_C
#define HE_KEY_KP_D           SDLK_KP_D
#define HE_KEY_KP_E           SDLK_KP_E
#define HE_KEY_KP_F           SDLK_KP_F
#define HE_KEY_KP_XOR         SDLK_KP_XOR
#define HE_KEY_KP_POWER       SDLK_KP_POWER
#define HE_KEY_KP_PERCENT     SDLK_KP_PERCENT
#define HE_KEY_KP_LESS        SDLK_KP_LESS
#define HE_KEY_KP_GREATER     SDLK_KP_GREATER
#define HE_KEY_KP_AMPERSAND   SDLK_KP_AMPERSAND
#define HE_KEY_KP_DBLAMPERSAND    SDLK_KP_DBLAMPERSAND
#define HE_KEY_KP_VERTICALBAR     SDLK_KP_VERTICALBAR
#define HE_KEY_KP_DBLVERTICALBAR  SDLK_KP_DBLVERTICALBAR
#define HE_KEY_KP_COLON       SDLK_KP_COLON
#define HE_KEY_KP_HASH        SDLK_KP_HASH
#define HE_KEY_KP_SPACE       SDLK_KP_SPACE
#define HE_KEY_KP_AT          SDLK_KP_AT
#define HE_KEY_KP_EXCLAM      SDLK_KP_EXCLAM
#define HE_KEY_KP_MEMSTORE    SDLK_KP_MEMSTORE
#define HE_KEY_KP_MEMRECALL   SDLK_KP_MEMRECALL
#define HE_KEY_KP_MEMCLEAR    SDLK_KP_MEMCLEAR
#define HE_KEY_KP_MEMADD      SDLK_KP_MEMADD
#define HE_KEY_KP_MEMSUBTRACT SDLK_KP_MEMSUBTRACT
#define HE_KEY_KP_MEMMULTIPLY SDLK_KP_MEMMULTIPLY
#define HE_KEY_KP_MEMDIVIDE   SDLK_KP_MEMDIVIDE
#define HE_KEY_KP_PLUSMINUS   SDLK_KP_PLUSMINUS
#define HE_KEY_KP_CLEAR       SDLK_KP_CLEAR
#define HE_KEY_KP_CLEARENTRY  SDLK_KP_CLEARENTRY
#define HE_KEY_KP_BINARY      SDLK_KP_BINARY
#define HE_KEY_KP_OCTAL       SDLK_KP_OCTAL
#define HE_KEY_KP_DECIMAL     SDLK_KP_DECIMAL
#define HE_KEY_KP_HEXADECIMAL SDLK_KP_HEXADECIMAL
#define HE_KEY_LCTRL          SDLK_LCTRL
#define HE_KEY_LSHIFT         SDLK_LSHIFT
#define HE_KEY_LALT           SDLK_LALT
#define HE_KEY_LGUI           SDLK_LGUI
#define HE_KEY_RCTRL          SDLK_RCTRL
#define HE_KEY_RSHIFT         SDLK_RSHIFT
#define HE_KEY_RALT           SDLK_RALT
#define HE_KEY_RGUI           SDLK_RGUI
#define HE_KEY_MODE           SDLK_MODE
#define HE_KEY_AUDIONEXT      SDLK_AUDIONEXT
#define HE_KEY_AUDIOPREV      SDLK_AUDIOPREV
#define HE_KEY_AUDIOSTOP      SDLK_AUDIOSTOP
#define HE_KEY_AUDIOPLAY      SDLK_AUDIOPLAY
#define HE_KEY_AUDIOMUTE      SDLK_AUDIOMUTE
#define HE_KEY_MEDIASELECT    SDLK_MEDIASELECT
#define HE_KEY_WWW            SDLK_WWW
#define HE_KEY_MAIL           SDLK_MAIL
#define HE_KEY_CALCULATOR     SDLK_CALCULATOR
#define HE_KEY_COMPUTER       SDLK_COMPUTER
#define HE_KEY_AC_SEARCH      SDLK_AC_SEARCH
#define HE_KEY_AC_HOME        SDLK_AC_HOME
#define HE_KEY_AC_BACK        SDLK_AC_BACK
#define HE_KEY_AC_FORWARD     SDLK_AC_FORWARD
#define HE_KEY_AC_STOP        SDLK_AC_STOP
#define HE_KEY_AC_REFRESH     SDLK_AC_REFRESH
#define HE_KEY_AC_BOOKMARKS   SDLK_AC_BOOKMARKS
#define HE_KEY_BRIGHTNESSDOWN SDLK_BRIGHTNESSDOWN
#define HE_KEY_BRIGHTNESSUP   SDLK_BRIGHTNESSUP
#define HE_KEY_DISPLAYSWITCH  SDLK_DISPLAYSWITCH
#define HE_KEY_KBDILLUMTOGGLE SDLK_KBDILLUMTOGGLE
#define HE_KEY_KBDILLUMDOWN   SDLK_KBDILLUMDOWN
#define HE_KEY_KBDILLUMUP     SDLK_KBDILLUMUP
#define HE_KEY_EJECT          SDLK_EJECT
#define HE_KEY_SLEEP          SDLK_SLEEP
#define HE_KEY_APP1           SDLK_APP1
#define HE_KEY_APP2           SDLK_APP2
#define HE_KEY_AUDIOREWIND    SDLK_AUDIOREWIND
#define HE_KEY_AUDIOFASTFORWARD SDLK_AUDIOFASTFORWARD
#define HE_KEY_SOFTLEFT       SDLK_SOFTLEFT
#define HE_KEY_SOFTRIGHT      SDLK_SOFTRIGHT
#define HE_KEY_CALL           SDLK_CALL
#define HE_KEY_ENDCALL        SDLK_ENDCALL


// Key Modifiers
typedef uint16_t HE_KeyModifier;

#define HE_KEYMOD_NONE   SDL_KMOD_NONE   /**< no modifier is applicable. */
#define HE_KEYMOD_LSHIFT SDL_KMOD_LSHIFT /**< the left Shift key is down. */
#define HE_KEYMOD_RSHIFT SDL_KMOD_RSHIFT /**< the right Shift key is down. */
#define HE_KEYMOD_LCTRL  SDL_KMOD_LCTRL  /**< the left Ctrl (Control) key is down. */
#define HE_KEYMOD_RCTRL  SDL_KMOD_RCTRL  /**< the right Ctrl (Control) key is down. */
#define HE_KEYMOD_LALT   SDL_KMOD_LALT   /**< the left Alt key is down. */
#define HE_KEYMOD_RALT   SDL_KMOD_RALT   /**< the right Alt key is down. */
#define HE_KEYMOD_LGUI   SDL_KMOD_LGUI   /**< the left GUI key (often the Windows key) is down. */
#define HE_KEYMOD_RGUI   SDL_KMOD_RGUI   /**< the right GUI key (often the Windows key) is down. */
#define HE_KEYMOD_NUM    SDL_KMOD_NUM    /**< the Num Lock key (may be located on an extended keypad) is down. */
#define HE_KEYMOD_CAPS   SDL_KMOD_CAPS   /**< the Caps Lock key is down. */
#define HE_KEYMOD_MODE   SDL_KMOD_MODE   /**< the !AltGr key is down. */
#define HE_KEYMOD_SCROLL SDL_KMOD_SCROLL /**< the Scroll Lock key is down. */
#define HE_KEYMOD_CTRL   SDL_KMOD_CTRL   /**< Any Ctrl key is down. */
#define HE_KEYMOD_SHIFT  SDL_KMOD_SHIFT  /**< Any Shift key is down. */
#define HE_KEYMOD_ALT    SDL_KMOD_ALT    /**< Any Alt key is down. */
#define HE_KEYMOD_GUI    SDL_KMOD_GUI    /**< Any GUI key is down. */