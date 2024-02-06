#!/usr/bin/env bash

slop=$(slop -f "%g") || exit 1
read -r G <<< $slop
bspc rule -a \* -o state=floating rectangle=$G
kitty &
