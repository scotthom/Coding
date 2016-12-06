mkdir fruit vegie

for i in *
do
	if [ "fruit" in $i  ]; then
		echo "There is fruit"
	fi
done
