#/bin/sh
#xrandr --setprovideroutputsource modesetting NVIDIA-0
#xrandr --auto
xrandr --dpi 115
xhost +si:localuser:root
export LANG=en_US.UTF-8
export XDG_SESSION_TYPE=x11

xset s 9600 9600 
xset -dpms

export GTK_IM_MODULE=fcitx
export QT_IM_MODULE=fcitx
export XMODIFIERS=@im=fcitx
export SDL_IM_MODULE=fcitx
export GLFW_IM_MODULE=ibus

#export http_proxy=http://127.0.0.1:20171
#export https_proxy=http://127.0.0.1:20171

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


#session=${1:-dwm}
#
#case $session in
#    i3|i3wm           ) exec i3;;
#    kde               )
#		export DESKTOP_SESSION=plasma 
#		latte-dock &
#		exec startplasma-x11;;
#    dwm 		      ) 
#		export QT_QPA_PLATFORMTHEME=qt5ct
#		exec bspwm;;
#	dwmp  		     )
#		~/.config/polybar/launch.sh &
#		wallpaper.sh &
#		exec dwm;;
#	bsp 			  ) exec bspwm;;
#    # No known session, try to run it as command
#    *                 ) exec $1;;
#esac

~/.config/polybar/launch.sh & 
xsetroot -cursor_name left_ptr
export QT_QPA_PLATFORMTHEME=qt5ct
#wallpapers & 
#/data/TyphoonWeather_Archive/satellite/main.py &
feh --bg-fill /data/Wallpapers/h8.jpg &
picom & 
dunst &
fcitx5 &
nm-applet &
#pasystray &

exec bspwm

