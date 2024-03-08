echo "Enter 3 nos"
read a
read b
read c
if ((a>b))
then
	if ((a>c))
	then 
		echo "$a is greater"
	else 
		echo "$c is greater"
	fi
else
	if ((b>c))
	then 
		echo "$b is greater"
	else
		echo "$c is greater"
	fi
fi
