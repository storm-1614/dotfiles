#! /bin/bash

rsync -av --delete ~/.config/alacritty/ config/alacritty/
rsync -av --delete ~/.config/bspwm/ config/bspwm/
rsync -av --delete ~/.config/cava/ config/cava/
rsync -av --delete ~/.config/cmus/ config/cmus/
rsync -av --delete ~/.config/conky/ config/conky/
rsync -av --delete ~/.config/dunst/ config/dunst/
rsync -av --delete ~/.config/hypr/ config/hypr/
rsync -av --delete ~/.config/i3/ config/i3/
rsync -av --delete ~/.config/jgmenu/ config/jgmenu/
rsync -av --delete ~/.config/kitty/ config/kitty/
#rsync -av --delete ~/.config/mpd/ config/mpd/
#rsync -av --delete ~/.config/ncmpcpp/ config/ncmpcpp/
rsync -av --delete ~/.config/neofetch/  config/neofetch/
rsync -av --delete ~/.config/picom/ config/picom/
rsync -av --delete ~/.config/polybar/ config/polybar/
rsync -av --delete ~/.config/ranger/ config/ranger/
rsync -av --delete ~/.config/rofi/ config/rofi/
rsync -av --delete ~/.config/sxhkd/ config/sxhkd/
rsync -av --delete ~/.config/waybar/ config/waybar/
rsync -av --delete ~/.config/wofi/ config/wofi/
rsync -av --delete ~/.config/zathura/ config/zathura/

#rsync -av --delete ~/.config/ config/

