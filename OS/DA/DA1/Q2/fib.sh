echo "n:"
read n
echo "fibonacci"
a=0
b=1
for i in $(seq 1 $n); do
	temp=$(($a + $b))
	a=$b
	b=$temp
	echo $a
done
