
#! /bin/sh

chosen=$(printf "  Power Off\n  Restart\n  Lock\n ExitDWM" | rofi -dmenu -i -theme-str '@import "power.rasi"')

case "$chosen" in
	"  Power Off") poweroff ;;
	"  Restart") reboot ;;
	"  Lock") i3lock-fancy ;;
	" ExitDWM") killall dwm;;
	*) exit 1 ;;
esac
