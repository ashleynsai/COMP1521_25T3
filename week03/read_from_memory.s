	# Constants
N_SIZE = 10
SIZEOF_INT = 4

main:
	# Register usage:
	# $t0 - int i
	# $t1 - &numbers[i]

loop_init:
	li	$t0, 0				# i = 0

loop_cond:
	bge	$t0, N_SIZE, loop_end		# if (i >= N_SIZE) goto loop_end;

loop_body:
	# &numbers[i] = &numbers + i * SIZEOF_INT
	mul	$t1, $t0, SIZEOF_INT		# t1 = i * SIZEOF_INT
	add	$t1, $t1, numbers		# t1 = &numbers + i * SIZEOF_INT

	lw	$a0, ($t1)			# a0 = numbers[i]
	li	$v0, 1
	syscall					# printf("%d", numbers[i]);

	li	$a0, '\n'
	li	$v0, 11
	syscall 				# printf("\n")

loop_step:
	addi	$t0, $t0, 1
	b	loop_cond

loop_end:
	li	$v0, 0
	jr	$ra

	
	.data
numbers:
	.word 	0, 1, 2, 3, 4, 5, 6, 7, 8, 9