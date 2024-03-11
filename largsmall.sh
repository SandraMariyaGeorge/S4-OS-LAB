echo "enter 3 no's"
read n1
read n2
read n3
l=$n1
s=$n1
if((n2>l))
then
	l=$n2
fi
if((n3>l))
then
	l=$n3
fi

if((n2<s))
then
	s=$n2
fi
if((n3<s))
then
	s=$n3
fi
echo "largest is $l"
echo "smallest is $s"
