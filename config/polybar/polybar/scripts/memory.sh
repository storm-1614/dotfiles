#! /bin/sh

free_result=`free -h`
text="
可用:\t $(echo "$free_result" | sed -n 2p | awk '{print $7}')
用量:\t $(echo "$free_result" | sed -n 2p | awk '{print $3}')/$(echo "$free_result" | sed -n 2p | awk '{print $2}')
swap:\t $(echo "$free_result" | sed -n 3p | awk '{print $3}')/$(echo "$free_result" | sed -n 3p | awk '{print $2}')
"
    notify-send " Memory" "$text" -r 9527
