# check if the output file exists
if test ! -f out.txt 
then
	# if it doesn't then create it with only zero inside
  	echo 0 > out.txt
else
	# create a hard link with a lock file to 
	# prevent race condition
	if ln out.txt out.lock 
	then
		echo $(($(tail -n 1 out.txt)+1)) >> out.txt
		# delete the lock file after 
		# performing the critical region
		rm out.lock
	fi
fi