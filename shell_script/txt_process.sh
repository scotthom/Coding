for x in {a..z}
do
    grep -o $x carrot.txt | wc -l
done