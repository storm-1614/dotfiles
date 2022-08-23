#! /bin/bash
killall trayer
if [ $? != 0 ];then
		trayer --edge top --widthtype pixel --height 40 --transparent 30 --tint 10 --width 300
fi
