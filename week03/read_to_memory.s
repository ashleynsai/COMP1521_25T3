	# Constants
N_SIZE = 10
SIZEOF_INT = 4

	.text
	# $t0 - int i
main:

loop_init:
	li	$t0, 0			# t0 = 0

loop_cond:
	bge	$t0, N_SIZE, loop_end	# if (i >= N_SIZE) goto loop_end;

loop_body:
	li	$v0, 5
	syscall				# SYSCALL 5: READ_INT (into $v0)

	# 1. calculate address of &numbers[i]
	# &arr[i] = arr + offset
	#.        = numbers + i * sizeof(int)

	mul	$t1, $t0, SIZEOF_INT		# t1 = 1 * SIZEOF_INT
	add	$t1, $t1, numbers		# t1 = numbers + i * sizeof(int)
	sw	$v0, ($t1)			# scanf("%d", &numbers[i]);

loop_step:
	addi	$t0, 1
	j	loop_cond

loop_end:
	li	$v0, 0
	jr	$ra



	.data
numbers:	
	.word	0:N_SIZE