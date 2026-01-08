
#! /bin/sh

chosen=$(printf "󰐥  Power Off\n  Restart\n  Lock\n󰒲  Hibernate\n  Log Out" | rofi -dmenu -i -theme-str '@import "power.rasi"')

case "$chosen" in
	"󰐥  Power Off") poweroff ;;
	"  Lock") systemctl suspend ;;
	"  Restart") reboot ;;
    "󰒲  Hibernate") systemctl hibernate ;;
    "  Log Out") ~/.config/hypr/script/exit.sh ;;
	*) exit 1 ;;
esac
