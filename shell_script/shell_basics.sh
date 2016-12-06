do# shell_basics.sh

#variable: thing, represent val. no spaces between variables. access var., struct $var  NULL variable equal nothing. Dont use ?/* in naming.
a=10		#regular
echo "$a"	
b=
echo "$b"

expr 6 + 3

x=20
y=5
expr $x / $y

z=`expr $x / $y`
echo "z = x/y"
echo "  = $z"

#parameter susbstution: pu

#If Statement

d=21

if [[ $d = 10 ]]; then
	echo "d = 10"
elif [[ $d = 15 ]]; then
	echo "d = 15"
else
	echo "d must be equal to 21"
fi

#for loops: supports break

for i in {0..5} #can iterate over files seperated by spaces
	do
		echo "Welcome $i times"
	done

for (( c=0; c<5; c++ ))
do
	echo "Welcome $c times"
done

#While Loops
x=0

while [ $x -lt 10 ]
do
	echo $x
	x=`expr $x + 1`
done










#system variables

#if statement

