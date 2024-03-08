echo "Enter 2 nos"
read a
read b
echo "Enter the operator"
read op
((result=$a $op $b))
echo "result is $result"
