/* See LICENSE file for copyright and license details. */
//声音需要安装pulseaudio-ctl

/* appearance */
static const char *lightup[] = { "xbacklight", "-inc", "10",  NULL };
static const char *lightdown[] = { "xbacklight", "-dec", "10",  NULL };
static const char *mutevol[] = { "pulseaudio-ctl", "mute", NULL };
static const char *downvol[] = { "pulseaudio-ctl", "down", "5", NULL };
static const char *upvol[]   = { "pulseaudio-ctl", "up", "5", NULL };
static const unsigned int borderpx  = 5;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 15;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 15;       /* vert inner gap between windows */
static const unsigned int gappoh    = 15;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 15;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 9;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray             = 1;   /* 0 means no systray */
static const Bool viewontag         = True;     /* Switch view on tag switch */
static const char *fonts[]          = { "Hack NF:size=14", "Source Han Sans CN:size=14"};
static const char dmenufont[]       = "Hack NF:size=14";
static const char col_gray1[]       = "#2e3440";
static const char col_gray2[]       = "#2e3440";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#2e3440";
static const char col_cyan[]        = "#5e81ac"; //005577
												
static const unsigned int baralpha = 0x80;
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
	[SchemeHid]  = { col_cyan,  col_gray1, col_cyan  },
};
static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
}; 
/* tagging */
static const char *tags[] = {"¹", "²", "³","⁴", "⁵", "⁶","⁷", "⁸", "⁹"};
/*static const char *tags[] = { "\uf120¹", "\uf7ae²", "\uf121³", "\ue04b⁴", "\uf62e⁵", "\uf251⁶", "\ue727⁷", "\uf537⁸", "\uf684⁹" };*/
/*static const char *tags[] = { "\uf120", "\uf7ae", "\uf121", "\ue04b", "\uf62e", "\uf251", "\ue727", "\uf537", "\uf684" };*/
static const Rule rules[] = {
	 /* xprop(1):
	  *	WM_CLASS(STRING) = instance, class
	  *	WM_NAME(STRING) = title
	 
	* class      instance    title       tags mask     isfloating   monitor */
    { "Gimp",     NULL,       NULL,       0,            1,           -1 },
    { "Wine",     NULL,       NULL,       0,            1,           -1 },
	  { "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
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
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "alacritty", scratchpadname, NULL };
/*static const char *roficmd[]  = { "rofi", "-theme", "solarized_alternate", "font", "'Hack","20'", "-show", "drun", "-icon-theme" "'Papirus'", "-show-icons", NULL };*/
static const char *roficmd[]  = { "rofi", "-show", "drun", NULL };
static const char *roficmd1[]  = { "rofi", "-show", "run", NULL };
static const char *chromecmd[]  = { "firefox",  NULL };
static const char *radomchwp[]  = { "/home/storm/.config/scripts/random-change-sp.sh",  NULL };
//static const char *screenshotcmd[] = { "deepin-screenshot", NULL };
static const char *screenshotcmd[] = { "flameshot", "gui", NULL };
static const char *firefoxcmd[]  = { "firefox",  NULL };
static const char *file[] = {"", NULL};
static const char *lock[] = {"i3lock-fancy", NULL};
static const char *browsercmd[] = {"microsoft-edge-stable", "--proxy-server=socks5://127.0.0.1:20171", NULL};
static const char *power[] = {"power.sh", NULL};
static const char *emoji[] = {"rofi", "-show", "emoji", "-modi", "emoji", NULL};
static const char *window[] = {"rofi", "-show", "window", NULL};
static const char *cmus[] = {"cmus-config", NULL};
static const char *baidu[] = {"baidu-translate-client", NULL};

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY|ShiftMask,           	XK_z,      spawn,          {.v = lock}},  /*锁屏*/
	{ MODKEY, 			           	XK_f,      spawn,          {.v = baidu}},  /*翻译*/
	{ MODKEY, 			           	XK_x,      spawn,          {.v = cmus}},  /*音乐控制*/
	{ MODKEY,                       XK_e,      spawn,          {.v = file}}, /*打开gnome文件*/
  	{ MODKEY,                       XK_d,      spawn,          {.v = roficmd } },/*打开ropfi*/
	{ MODKEY|ShiftMask,             XK_d,      spawn,          {.v = roficmd1 } },/*以命令模式打开rofi*/
	{ MODKEY|ShiftMask,             XK_a,      spawn,          {.v = screenshotcmd } },/*截图*/
	{ MODKEY,                       XK_p,      spawn,          {.v = screenshotcmd } },/*截图*/
	{ MODKEY,                       XK_c,      spawn,          {.v = chromecmd } },/*打开edge*/
	{MODKEY | ShiftMask,            XK_c,      spawn,          {.v = browsercmd}}, /*以代理模式打开edge*/
	{MODKEY | ShiftMask,            XK_l,      spawn,          {.v = power}}, /*电源*/
	{MODKEY | ShiftMask,            XK_m,      spawn,          {.v = emoji}}, /*emoji*/
	{MODKEY | ShiftMask,            XK_w,      spawn,          {.v = window}}, /*window*/
	{ MODKEY,                       XK_r,      spawn,          {.v = radomchwp } },/*随机切换壁纸*/
  	{ Mod1Mask,                     XK_f,      spawn,          {.v = firefoxcmd } },/*打开firefox*/
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },//打开终端
	{ MODKEY,                       XK_b,      togglebar,      {0} },//隐藏状态栏
	{ MODKEY|ShiftMask,             XK_b,      rotatestack,    {.i = +1 } },//循环交换两个窗口的位置
	{ MODKEY|ShiftMask,             XK_p,      rotatestack,    {.i = -1 } },
	{ MODKEY,                       XK_j,      focusstackvis,  {.i = +1 } },//光标在窗口之间循环
	{ MODKEY,                       XK_k,      focusstackvis,  {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,      focusstackhid,  {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      focusstackhid,  {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },//将窗口回复垂直逻辑
	{ MODKEY|ShiftMask,             XK_i,      incnmaster,     {.i = -1 } },  //将窗口改为横着
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },//左右调整窗口占比
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },//交换两个刚打开的窗口的位置
	{ MODKEY,                       XK_Tab,    view,           {0} },//切换标签
	{ MODKEY,                       XK_q,      killclient,     {0} },//关闭当前窗口
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },//窗口改为平铺模式
	{ MODKEY,                       XK_n,      setlayout,      {.v = &layouts[1]} },//窗口改为浮动模式
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },//当前窗口占满屏幕
	{ MODKEY,                       XK_F5,    spawn,          {.v = downvol } },/*减小音量*/
	{ MODKEY,                       XK_F1,    spawn,          {.v = lightdown } },/*减小亮度*/
	{ MODKEY,                       XK_F2,    spawn,          {.v = lightup } },/*增大亮度*/
	{ MODKEY,                       XK_F4,     spawn,          {.v = mutevol } },/*静音*/
	{ MODKEY,                       XK_F6,    spawn,          {.v = upvol   } },/*增加音量*/
	{ MODKEY|ShiftMask,             XK_f,      fullscreen,     {0} },  //将当前窗口全屏
	{ MODKEY,                       XK_space,  setlayout,      {0} }, //窗口改为平铺模式
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },//窗口改为浮动模式
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },//显示全部标签
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY|Mod1Mask,              XK_h,      incrgaps,       {.i = +1 } },
	{ MODKEY|Mod1Mask,              XK_l,      incrgaps,       {.i = -1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_h,      incrogaps,      {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_l,      incrogaps,      {.i = -1 } },
	{ MODKEY|Mod1Mask|ControlMask,  XK_h,      incrigaps,      {.i = +1 } },
	{ MODKEY|Mod1Mask|ControlMask,  XK_l,      incrigaps,      {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_0,      togglegaps,     {0} },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },
	{ Mod1Mask|ControlMask,         XK_y,      incrihgaps,     {.i = +1 } },
	{ MODKEY,                       XK_o,      incrihgaps,     {.i = -1 } },
	{ MODKEY|ControlMask,           XK_y,      incrivgaps,     {.i = +1 } },
	{ MODKEY|ControlMask,           XK_o,      incrivgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_y,      incrohgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask,              XK_o,      incrohgaps,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_y,      incrovgaps,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_o,      incrovgaps,     {.i = -1 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY,                       XK_y,      togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY,                       XK_s,      show,           {0} }, //显示隐藏的窗口
	{ MODKEY,                       XK_v,      hide,           {0} }, //隐藏窗口
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button1,        togglewin,      {0} },
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
