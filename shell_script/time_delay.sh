# Simple time Delay

# a=0
# echo "a = $a"
# echo "Enter new number: \c"
# read a
# echo "a = $a"
# sleep 10 && a=10
# echo "a = $a"

#Time Delay While Loop

num=0

echo "$num"

while [[ "$num" -lt 10 ]]; do
	sleep 1
	(( num=num+1 ))
	echo "$num"
done



