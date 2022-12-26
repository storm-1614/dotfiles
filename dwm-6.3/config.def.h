/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int gappx     = 10;        /* gaps between windows 窗口间隙*/
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char buttonbar[]       = "";
static const char *fonts[]          = { "Hack Nerd Font:size=14", "Source Han Sans CN:size=14" };
//static const char *fonts[]          = { "Hack NF:size=14", "LXGW WenKai:style=Regular:size=14" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#2e3440";
static const char col_gray2[]       = "#4c566a";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#2e3440";
static const char col_cyan[]        = "#5e81ac";
static const unsigned int baralpha = 0xff;
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
//打开dwm启动的命令
static const char *const autostart[] = {
	//"picom", NULL,
	"fcitx5", "-d", NULL,
	"cfw", NULL,
	"slstatus", NULL,
	//"libinput-gestures-setup", "start", NULL, 	/*已废弃*/
	"dunst", NULL,
	"conky", NULL,
	"xset", "s", "3600", NULL,
	"xset", "dpms", "0", "0", "3600", NULL,
	"redshift", "-O", "4500", NULL,
	"feh", "--recursive", "--bg-fill", "Pictures/wallpapers/.", NULL,
//	"pasystray", NULL,
	"geary", NULL,
	"telegram-desktop", NULL,
	NULL
};

/* tagging */
//tag显示图标，用的nerd
static const char *tags[] = { "¹", "²", "³","⁴", "⁵", "⁶","⁷", "⁸", "⁹" };

/* Lockfile */
static char lockfile[] = "/tmp/dwm.lock";
//窗口规则，tags mask指定打开的tag,isfloating指定是否浮动，monitor指定屏幕
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       1 << 7,       1,           -1 },
	{ "firefox",  NULL,       NULL,       1 << 2,       0,           -1 },
	{ "Zathura",  NULL, 	  NULL, 	  1 << 1,  		0, 			 -1 },
	{ "VirtualBox Manager", NULL, NULL,   1 << 5, 		0, 			 -1 },
	{ "VirtualBox Machine", NULL, NULL,   1 << 5, 		0, 			 -1 },
	{ "icalingua", NULL,      NULL, 	  1 << 4, 		0, 			 -1 },
	{ "Wine",     NULL,       NULL, 	  1 << 4, 		1, 			 -1 },
	{ "discord",  NULL,       NULL, 	  1 << 6, 		0, 			 -1 },
	{ "TelegramDesktop", NULL, NULL,      1 << 3, 		0, 			 -1 },
	{ "geary",    NULL,       NULL, 	  1 << 8, 		0, 			 -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int decorhints  = 1;    /* 1 means respect decoration hints */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "﬿",      tile },    /* first entry is default */
	{ "缾",     NULL },    /* no layout function means floating behavior */
	{ "[M]",    monocle },

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
static const char *termcmd2[] = { "st", NULL };
static const char *roficmd[]  = { "rofi", "-show", "drun", NULL };
static const char *roficmd1[]  = { "rofi", "-show", "run", NULL };
static const char *chromecmd[]  = { "firefox",  NULL };
static const char *screenshotcmd[] = { "flameshot", "gui", NULL };
static const char *firefoxcmd[]  = { "firefox",  NULL };
static const char *file[] = {"alacritty", "-e", "ranger", NULL};
static const char *lock[] = {"i3lock-fancy", NULL};
static const char *power[] = {"power.sh", NULL};
static const char *emoji[] = {"rofi", "-show", "emoji", "-modi", "emoji", NULL};
static const char *window[] = {"rofi", "-show", "window", NULL};
static const char *music[] = {"mconfig", NULL};
static const char *trayer[] = {"trayer.sh", NULL};
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = {"st", "-t",     scratchpadname,"-g", "120x34", NULL};
/*-----------------------*/
/*声音需要安装pulseaudio-ctl
 *音乐播放用的moc
 *亮度控制用的xorg自带
 * */
static const char *lightup[] = { "xbacklight", "-inc", "10",  NULL };
static const char *lightdown[] = { "xbacklight", "-dec", "10",  NULL };
static const char *mutevol[] = { "pulseaudio-ctl", "mute", NULL };
static const char *downvol[] = { "pulseaudio-ctl", "down", "5", NULL };
static const char *upvol[]   = { "pulseaudio-ctl", "up", "5", NULL };
static const char *mpc_toggle[]= { "playerctl", "play-pause", NULL };
static const char *mpc_next[]= { "playerctl", "next", NULL };
static const char *mpc_prev[]= { "playerctl", "previous", NULL };


static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_F7,     spawn,          {.v = lightdown } },/*减小亮度*/
	{ MODKEY,                       XK_F8,     spawn,          {.v = lightup } },/*增大亮度*/
	{ MODKEY,                       XK_F6,     spawn,          {.v = mutevol } },/*静音*/
	{ MODKEY,                       XK_F5,     spawn,          {.v = downvol } },/*减小音量*/
	{ MODKEY,                       XK_F4,     spawn,          {.v = upvol   } },/*增加音量*/
	{ MODKEY,                       XK_F1,     spawn,          {.v = mpc_toggle } },  /*音乐播放/暂停*/
	{ MODKEY,                       XK_F2,     spawn,          {.v = mpc_prev } },    /*音乐上一首*/
 	{ MODKEY,                       XK_F3,     spawn,          {.v = mpc_next } },    /*音乐下一首*/
	{ MODKEY|ShiftMask,           	XK_z,      spawn,          {.v = lock}},  /*锁屏*/
	{ MODKEY, 			           	XK_z,      spawn,          {.v = trayer}},  /*trayer*/
	{ MODKEY, 			           	XK_x,      spawn,          {.v = music}},  /*音乐控制*/
	{ MODKEY,                       XK_e,      spawn,          {.v = file}}, /*打开ranger*/
  	{ MODKEY,                       XK_d,      spawn,          {.v = roficmd } },/*打开ropfi*/
	{ MODKEY|ShiftMask,             XK_d,      spawn,          {.v = roficmd1 } },/*以命令模式打开rofi*/
	{ MODKEY|ShiftMask,             XK_a,      spawn,          {.v = screenshotcmd } },/*截图*/
	{ MODKEY,                       XK_c,      spawn,          {.v = chromecmd } },/*打开firefox*/
	{ MODKEY | ShiftMask,           XK_l,      spawn,          {.v = power}}, /*电源*/
	{ MODKEY | ShiftMask,           XK_m,      spawn,          {.v = emoji}}, /*emoji*/
	{ MODKEY | ShiftMask,           XK_w,      spawn,          {.v = window}}, /*window*/
  	{ MODKEY,                       XK_f,      spawn,          {.v = firefoxcmd } },/*打开firefox*/
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } }, //终端
	{ MODKEY | ShiftMask,           XK_Return, spawn,          {.v = termcmd2 } }, //终端
    { MODKEY, 						XK_r, 	   togglescratch,  {.v = scratchpadcmd}},  //打开st
	{ MODKEY,                       XK_b,      togglebar,      {0} },  //隐藏状态栏
    { MODKEY,                       XK_j,      focusstackvis,  {.i = +1 } },  //聚焦到左侧窗口 
	{ MODKEY,                       XK_k,      focusstackvis,  {.i = -1 } },  //聚焦到右侧窗口
    { MODKEY | ShiftMask, 			XK_j, 	   focusstackhid,  {.i = +1}},    
    { MODKEY | ShiftMask, 			XK_k, 	   focusstackhid,  {.i = -1}},
    { MODKEY, 			            XK_l,      aspectresize,   {.i = +24 } },  //当前窗口向左伸
    { MODKEY, 			            XK_h,      aspectresize,   {.i = -24 } },  //当前窗口向右伸																   
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_n, 	   zoom,           {0} },   //切换窗口位置
	{ MODKEY,                       XK_Tab,    view,           {0} },   //切换到上一个tag
	{ MODKEY,                       XK_q,      killclient,     {0} },   //退出窗口
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },  //平铺模式
	{ MODKEY,                       XK_n,      setlayout,      {.v = &layouts[1]} },  //无模式
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },  //全满模式
	{ MODKEY,                       XK_space,  setlayout,      {0} },   //全局切换平铺/无模式
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },   //切换窗口平铺/无模式
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },   //当前窗口全屏
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },  
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
    { MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
    { MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
    { MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	{ MODKEY,                       XK_Left,   viewtoleft,     {0} },
	{ MODKEY,                       XK_Right,  viewtoright,    {0} },
	{ MODKEY|ShiftMask,             XK_Left,   tagtoleft,      {0} },
	{ MODKEY|ShiftMask,             XK_Right,  tagtoright,     {0} },
	{ MODKEY,           			XK_i,      setcfact,       {.f = +0.25} },
	{ MODKEY,  			            XK_p,      setcfact,       {.f = -0.25} },
	{ MODKEY, 			            XK_o,      setcfact,       {.f =  0.00} },
	{ MODKEY | ShiftMask,           XK_b,      rotatestack,    {.i = +1 } },
	{ MODKEY, 						XK_y, 	   incnmaster, 	   {.i = +1}}, //左侧窗口+1
    { MODKEY | ShiftMask, 			XK_y, 	   incnmaster, 	   {.i = -1}}, //左侧窗口-1
	{ MODKEY | ShiftMask,           XK_s,      show,           {0} },
	{ MODKEY,                       XK_v,      hide,           {0} },
	{ MODKEY, 			            XK_s,      showall,        {0} },
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
	{ ClkButton,		0,		Button1,	spawn,		{.v = roficmd } },
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

void
setlayoutex(const Arg *arg)
{
	setlayout(&((Arg) { .v = &layouts[arg->i] }));
}

void
viewex(const Arg *arg)
{
	view(&((Arg) { .ui = 1 << arg->ui }));
}

void
viewall(const Arg *arg)
{
	view(&((Arg){.ui = ~0}));
}

void
toggleviewex(const Arg *arg)
{
	toggleview(&((Arg) { .ui = 1 << arg->ui }));
}

void
tagex(const Arg *arg)
{
	tag(&((Arg) { .ui = 1 << arg->ui }));
}

void
toggletagex(const Arg *arg)
{
	toggletag(&((Arg) { .ui = 1 << arg->ui }));
}

void
tagall(const Arg *arg)
{
	tag(&((Arg){.ui = ~0}));
}

/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signame> [<type> <value>]"` */
static Signal signals[] = {
	/* signum           function */
//	{ "focusstack",     focusstack },
	{ "setmfact",       setmfact },
	{ "togglebar",      togglebar },
	{ "incnmaster",     incnmaster },
	{ "togglefloating", togglefloating },
	{ "focusmon",       focusmon },
	{ "tagmon",         tagmon },
	{ "zoom",           zoom },
	{ "view",           view },
	{ "viewall",        viewall },
	{ "viewex",         viewex },
	{ "toggleview",     view },
	{ "toggleviewex",   toggleviewex },
	{ "tag",            tag },
	{ "tagall",         tagall },
	{ "tagex",          tagex },
	{ "toggletag",      tag },
	{ "toggletagex",    toggletagex },
	{ "killclient",     killclient },
	{ "quit",           quit },
	{ "setlayout",      setlayout },
	{ "setlayoutex",    setlayoutex },
};
