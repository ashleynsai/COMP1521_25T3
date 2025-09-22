	.text
	# t0 - int i
	# t1 - int j
main:
loop_i_init:
	li	$t0, 1

loop_i_cond:
	bgt	$t0, 10, loop_i_end

loop_i_body:
loop_j_init:
	li	$t1, 0

loop_j_cond:
	bge	$t1, $t0, loop_j_end

loop_j_body:
	li	$v0, 11
	li	$a0, '*'
	syscall

loop_j_step:
	add	$t1, 1
	b	loop_j_cond

loop_j_end:
	li	$v0, 11
	li	$a0, '\n'
	syscall

loop_i_step:
	addi	$t0, $t0, 1
	b	loop_i_cond

loop_i_end:
	li	$v0, 0
	jr	$ra			# return 0