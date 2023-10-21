#! /bin/sh

notify-send "CPU tops" "\n$(ps axch -o cmd:15,%cpu --sort=-%cpu | head)\\n\\n(100% per core)" -r 9527
