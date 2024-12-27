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