
echo "n1, n2, n3: "
read n1
read n2
read n3

if [ $n1 -gt $n2 ] && [ $n1 -gt $n3 ]
then
	echo "n1 is greatest"
elif [ $n2 -gt $n1 ] && [ $n2 -gt $n3 ]
then
	echo "n2 is greatest"
else
	echo "n3 is greatest"
fi
