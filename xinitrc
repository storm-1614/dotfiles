#!/bin/sh

userresources=$HOME/.Xresources
usermodmap=$HOME/.Xmodmap
sysresources=/etc/X11/xinit/.Xresources
sysmodmap=/etc/X11/xinit/.Xmodmap

# merge in defaults and keymaps

if [ -f $sysresources ]; then







    xrdb -merge $sysresources

fi

if [ -f $sysmodmap ]; then
    xmodmap $sysmodmap
fi

if [ -f "$userresources" ]; then







    xrdb -merge "$userresources"

fi

if [ -f "$usermodmap" ]; then
    xmodmap "$usermodmap"
fi

# start some nice programs

if [ -d /etc/X11/xinit/xinitrc.d ] ; then
 for f in /etc/X11/xinit/xinitrc.d/?*.sh ; do
  [ -x "$f" ] && . "$f"
 done
 unset f
fi


		clash &
session=${1:-dwm}

case $session in
    i3|i3wm           ) exec i3;;
    kde               ) 
		latte-dock &
		exec startplasma-x11;;
    dwm 		      ) 
		picom -cGbf & 
		wallpaper.sh &
		fcitx5 -d &
		clash &
		slstatus &
		dunst &
		qbat &
		xset s 3600 &
		xset dpms 0 0 3600 &
		redshift -O 4500 &
		pasystray &
		exec dwm;;
	bsp 			  ) exec bspwm;;
    # No known session, try to run it as command
    *                 ) exec $1;;
esac
