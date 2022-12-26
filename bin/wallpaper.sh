#!/bin/sh

while true; do
    find ~/Pictures/wallpapers -type f \( -name '*.jpg' -o -name '*.png' \) -print0 |
        shuf -n1 -z | xargs -0 feh --bg-fill --recursive
    sleep 120s
done

