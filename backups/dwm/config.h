/* 
                ⟋⟍ 
	      ⟋    ⟍ 
            ⟋        ⟍
          ⟋            ⟍
        ⟋                ⟍
      ⟋                    ⟍
    ⟋                        ⟍
  ⟋                            ⟍
 ╭——————————————————————————————╮
 │       _                      │
 │    __| |_      ___ __ ___    │
 │   / _` \ \ /\ / / '_ ` _ \   │ 
 │  | (_| |\ V  V /| | | | | |  │
 │   \__,_| \_/\_/ |_| |_| |_|  │
 │                              │
 ╰——————————————————————————————╯

*/

/* config by: https://github.com/lain234 */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int gappx     = 10;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int vertpad            = 0;       /* vertical padding of bar */
static const int sidepad            = 0;       /* horizontal padding of bar */
static const char *fonts[]          = { "Iosevka Nerd Font:size=10:style=medium:antialias=true:autohint=true", "Font Awesome 6 Free:size=17:antialias=true:autohint=true" };
static const char dmenufont[]       = "Terminus:size=10";
static const char col_gray1[]       = "#1d293b";
static const char col_gray2[]       = "#1d293b";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#1d293b";
static const char col_pink[]        = "#e6c6e0";
static const char col_blue2[]       = "#7ba8eb";
static const char col_red[]         = "#ef7a93";
static const char col_blue[]        = "#7ba8eb";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_blue2, col_gray1, col_red },
	[SchemeSel]  = { col_pink, col_cyan,  col_blue },
	[SchemeOcc]  = { col_red,   col_gray1, col_cyan  },
};

static const char *const autostart[] = {
	"hsetroot", "-cover", "/home/lain/Pictures/Wallpapers/yn-alt-wp.png", NULL,
	"picom", "-b", NULL,
	"slstatus", NULL,
	NULL /* terminate */
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5" };

static const char *tagsel[][2] = {
	{ "#e6c6e0", "#1d293b" },
	{ "#e6c6e0", "#1d293b" },
	{ "#e6c6e0", "#1d293b" },
	{ "#e6c6e0", "#1d293b" },
	{ "#e6c6e0", "#1d293b" },
};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "",        tile },    /* first entry is default */
	{ "﯑",        NULL },    /* no layout function means floating behavior */
	{ "",        monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "alacritty", NULL };
static const char *rofi[]  = { "rofi", "-show", "drun", NULL };
static const char *rofirun[] = { "rofi", "-show", "run", NULL };
static const char *www[]   = { "firefox", NULL };
static const char *dc[]    = { "discord", NULL };
static const char *spotify[] = { "spotify", NULL }; 
static const char *killdwm[] = { "pkill", "X", NULL };
static const char *scrot[] = { "scrot", "/home/lain/Pictures/Screenshots/%Y-%m-%d-%T-screenshot.jpg", NULL };

#include "movestack.c"
static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = rofi } },
	{ MODKEY,                       XK_r,      spawn,          {.v = rofirun } },
	{ MODKEY,                       XK_w,      spawn,          {.v = www  } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
        { MODKEY,                       XK_Print,  spawn,          {.v = scrot } },
        { MODKEY,                       XK_8,      spawn,          {.v = dc } },
	{ MODKEY,                       XK_9,      spawn,          {.v = spotify } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_p,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
        { MODKEY,                       XK_Down,   movestack,      {.i = +1 } },
	{ MODKEY,                       XK_Up,     movestack,      {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_Left,   focusmon,       {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_Right,  focusmon,       {.i = +1 } },
	{ MODKEY,                       XK_Left,   tagmon,         {.i = -1 } },
	{ MODKEY,                       XK_Right,  tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_plus,   setgaps,        {.i = +1 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = 0  } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	{ MODKEY|ShiftMask,             XK_r,      quit,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      spawn,          {.v = killdwm } },

};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

