date +"%r"
printf "Enter time (min): "

read time_min
printf "Enter Message: "
read -t 10 message

time_sec=$(expr $time_min \* 60)

if [ -z ${message+x} ]; then
	printf "\-\-\- no message \-\-\-"
	sleep $time_sec && afplay /Users/ScottHom/Desktop/projects/personal/general/useful/alarm_clock.mp3 

elif [ "$message" = "" ]; then
	printf "\-\-\- no message \-\-\-" 
	sleep $time_sec && afplay /Users/ScottHom/Desktop/projects/personal/general/useful/alarm_clock.mp3 
else 
	sleep $time_sec && echo "@@@@ $message @@@@" && afplay /Users/ScottHom/Desktop/projects/personal/general/useful/alarm_clock.mp3 
fi 







