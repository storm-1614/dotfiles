/* See LICENSE file for copyright and license details. */

/* interval between updates (in ms) */
const unsigned int interval = 1000;

/* text to show if no value can be retrieved */
static const char unknown_str[] = "null";

/* maximum output string length */
#define MAXLEN 2048

static const char get_time[] = "date '+%Y年%b%d日 周%a %T'";
static const char get_song_name[] = "echo $(mpc | sed '2,10d')";
static const char get_cpu_temp[] = "echo $[$(cat /sys/class/thermal/thermal_zone0/temp)/1000]°C";

static const struct arg args[] = {
	/* function format          argument */

		{ run_command,  "^b#e0af68^^c#15161e^ 﫭 %s ^c#15161e^", get_song_name },
        { battery_state,    "^b#bb9af6^ %s", "BAT1" },
        { battery_perc,    "^b#bb9af6^ %s%% ", "BAT1" },
		{ cpu_perc,    "^b#f7768e^  %s% ", NULL },
        { run_command, "^b#9ece6a^  %s ", get_cpu_temp },
        { ram_perc, "^b#7dcfff^ ﬙ %s%% ", NULL },
        { run_command, "^b#7aa2f7^   %s ", get_time },
};

