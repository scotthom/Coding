#format specifier test
#refference: http://www.cplusplus.com/reference/cstdio/printf/
#struct: %[flags][width][.precision][length]specifier 

#print Ascii Characture 
echo "$(printf "\\$(printf '%o' "64")")"

#printf ASCII to numer
echo $(printf '%d' "'@")

