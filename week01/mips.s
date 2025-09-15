	.text
	# $t0 - x, z
	# int y - $t1

	# y = x * x
	mul	$t1, $t0, $t0

	# z = y * y
	# Can reuse registers ($t0)
	mul	$t0, $t1, $t1

	# If I want to store 21 in z
	li	$t7, 21		# First load 21 into a temporary register
	sw	$t7, z		# Then store the value in the temp reg into z

	.data
z:
	.word 4
string:

abc:
