/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

/* patches */
/*
	1. https://tools.suckless.org/dmenu/patches/center/dmenu-center-20240616-36c3d68.diff
*/

static int topbar = 0;                           /* -b  option; if 0, dmenu appears at bottom     */
static int centered = 1;                         /* -c option; centers dmenu on screen */
static int min_width = 500;                      /* minimum width when centered */
static const float menu_height_ratio = 4.0f;     /* This is the ratio used in the original calculation */

/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"DroidSansMNerdFontMono:size=14",
	"monospace:size=14"
};
static const char *prompt           = NULL;      /* -p  option; prompt to the left of input field */
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char col_yellow[]      = "#d79921";
static const char col_orange[]      = "#d65d0e";
static const char *colors[SchemeLast][2] = {
	/*               fg         bg       */
	[SchemeNorm] = { col_gray3, col_gray1  },
	[SchemeSel]  = { col_gray4, col_orange },
	[SchemeOut]  = { "#000000", "#00ffff"  },
};
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 10;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";
