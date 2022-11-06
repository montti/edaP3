for i in {1..50..1}
do
	split -d -b"$i"M sources.50MB
	mv x00 "$i".test
	rm x*
done
