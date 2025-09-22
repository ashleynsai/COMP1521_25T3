	.text

PRINT_INT = 1
PRINT_STRING = 4
PRINT_CHAR = 11
READ_INT = 5
SQUARE_MAX = 46340

main:
	# $t0 - x
	# $t1 - y

	li	$v0, PRINT_STRING
	la	$a0, prompt
	syscall						# printf("Enter a number: ");

	li	$v0, READ_INT
	syscall
	move	$t0, $v0				# scanf("%d", &x);

	bgt	$t0, SQUARE_MAX, main__invalid_x	# if (x > SQUARE_MAX) goto invalid_x;
	b	main__valid_x				# goto valid_x;

main__valid_x: 
	mul	$t1, $t0, $t0

	li	$v0, PRINT_INT
	move	$a0, $t1
	syscall

	li	$v0, PRINT_CHAR
	li	$a0, '\n'
	syscall						# printf("%d\n", y);

	b 	main__epilogue

main__invalid_x:
	li	$v0, PRINT_STRING
	la	$a0, invalid_x_prompt
	syscall	

main__epilogue:
	li	$v0, 0
	jr	$ra					# return 0

	.data
prompt:
	.asciiz "Enter a number: "

invalid_x_prompt:
	.asciiz "square too big for 32 bits\n"

number:
	.word 42



