wbinfo () {
	$2 | sed "s/<.*>//" > website.txt
	echo "website.txt:"
	wc -clmw website.txt
}




