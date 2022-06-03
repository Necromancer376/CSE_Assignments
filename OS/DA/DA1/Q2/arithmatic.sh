echo "Arithmatic"
echo "enter a and b"
read a
read b
sum=`expr $a + $b`
echo "$a + $b = $sum"

if [ $a -eq $b ] ;
then
	echo "a is equal to b"
elif [ $a -gt $b ] ;
then
	echo "a is greater than b"
else
	echo "b is greater than a"
fi
echo ""
echo "Loop"
for i in 1 2 3 4 5 
do
	echo $i
done

while [ $i -le $a ]
do
	sum=$((sum + i))
	i=$((i+1))
	echo $sum
done

echo ""
echo "Switch Case"
echo "Enter N/S/E/W:"
read dir

case "$dir" in 
	"N") echo "North";;
	"S") echo "South";;
	"E") echo "East";;
	"W") echo "West";;
esac
