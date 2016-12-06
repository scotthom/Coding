echo -n 'scott'
read text
echo "$text" | wc -w > input_sed.txt
sed -i.bak "s/$(printf '\t')//g" input_sed.txt
sed -i.bak "s/$(printf ' ')//g" input_sed.txt
echo -n "\"$text\" is "   
rm *input_sed*

