echo "\t\t scott" > input_sed.txt 
sed -i.bak "s/$(printf '\t')//g" input_sed.txt
sed -i.bak "s/$(printf ' ')//g" input_sed.txt
cat input_sed.txt
rm *input_sed* 
output="$(ls -l)"
echo "$output"
