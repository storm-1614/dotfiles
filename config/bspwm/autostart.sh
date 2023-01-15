#!/bin/bash

export time=$1
(( time *= 60 ))
while true
do
	feh --bg-scale --randomize ~/Pictures/wallpapers/*
	sleep $time
done
