# Race condition may appear anytime depending on
# how the OS schedules the processes

# check if the output file exists
if test ! -f out.txt
then
	# if it doesn't then create it with only zero inside
  	echo 0 > out.txt
else
	# here is the critical region because here we try to 
	# read the file and change it 
	echo $(($(tail -n 1 out.txt)+1)) >> out.txt
fi