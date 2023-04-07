adding
adding
adding
removing $t0
removing $t1
removing $t2
adding
removing $t2
adding
removing $t2
adding
removing $t2
adding
adding
adding
removing $t2
removing $t1
removing $t0
adding
removing $t0
adding
removing $t0
adding
removing $t0
adding
adding
adding
removing $t0
removing $t1
removing $t2
adding
removing $t2
adding
removing $t2
adding
removing $t2
adding
adding
adding
removing $t2
removing $t1
removing $t0
adding
removing $t0
adding
removing $t0
adding
removing $t0
adding
adding
adding
removing $t0
removing $t1
removing $t2
adding
removing $t2
adding
removing $t2
adding
removing $t2
adding
adding
adding
removing $t2
removing $t1
removing $t0
adding
removing $t0
adding
removing $t0
adding
removing $t0
adding
adding
adding
removing $t0
removing $t1
removing $t2
adding
removing $t2
adding
removing $t2
adding
removing $t2
adding
adding
adding
removing $t2
removing $t1
removing $t0
adding
removing $t0

	.text
	.globl main
main:
	jal Lmain
	j Lhalt
Lmain:
	# prologue
	addi $sp, $sp, -8
	sw   $ra, 4($sp)
	sw   $fp, 0($sp)
	move $fp, $sp
	# body
	li $t0, 5
	li $t1, 3
	addi $sp, $sp, -8
	sw $a0, -4($sp)
	sw $a1, ($sp)
	move $a0, $t0
	move $a1, $t1
	jal LdivModChk
	move $t1, $v0
	lw $a0, -4($sp)
	lw $a1, ($sp)
	addi $sp, $sp, 8
	div $t2, $t0, $t1
	addi $sp, $sp, -4
	sw $a0, 0($sp)
	move $a0, $t2
	jal Lprinti
	lw $a0, 0($sp)
	addi $sp, $sp, 4
	li $t2, 10
	addi $sp, $sp, -4
	sw $a0, 0($sp)
	move $a0, $t2
	jal Lprintc
	lw $a0, 0($sp)
	addi $sp, $sp, 4
	li $t2, -5
	li $t1, 3
	addi $sp, $sp, -8
	sw $a0, -4($sp)
	sw $a1, ($sp)
	move $a0, $t2
	move $a1, $t1
	jal LdivModChk
	move $t1, $v0
	lw $a0, -4($sp)
	lw $a1, ($sp)
	addi $sp, $sp, 8
	div $t0, $t2, $t1
	addi $sp, $sp, -4
	sw $a0, 0($sp)
	move $a0, $t0
	jal Lprinti
	lw $a0, 0($sp)
	addi $sp, $sp, 4
	li $t0, 10
	addi $sp, $sp, -4
	sw $a0, 0($sp)
	move $a0, $t0
	jal Lprintc
	lw $a0, 0($sp)
	addi $sp, $sp, 4
	li $t0, 5
	li $t1, -3
	addi $sp, $sp, -8
	sw $a0, -4($sp)
	sw $a1, ($sp)
	move $a0, $t0
	move $a1, $t1
	jal LdivModChk
	move $t1, $v0
	lw $a0, -4($sp)
	lw $a1, ($sp)
	addi $sp, $sp, 8
	div $t2, $t0, $t1
	addi $sp, $sp, -4
	sw $a0, 0($sp)
	move $a0, $t2
	jal Lprinti
	lw $a0, 0($sp)
	addi $sp, $sp, 4
	li $t2, 10
	addi $sp, $sp, -4
	sw $a0, 0($sp)
	move $a0, $t2
	jal Lprintc
	lw $a0, 0($sp)
	addi $sp, $sp, 4
	li $t2, -5
	li $t1, -3
	addi $sp, $sp, -8
	sw $a0, -4($sp)
	sw $a1, ($sp)
	move $a0, $t2
	move $a1, $t1
	jal LdivModChk
	move $t1, $v0
	lw $a0, -4($sp)
	lw $a1, ($sp)
	addi $sp, $sp, 8
	div $t0, $t2, $t1
	addi $sp, $sp, -4
	sw $a0, 0($sp)
	move $a0, $t0
	jal Lprinti
	lw $a0, 0($sp)
	addi $sp, $sp, 4
	li $t0, 10
	addi $sp, $sp, -4
	sw $a0, 0($sp)
	move $a0, $t0
	jal Lprintc
	lw $a0, 0($sp)
	addi $sp, $sp, 4
	li $t0, 5
	li $t1, 3
	addi $sp, $sp, -8
	sw $a0, -4($sp)
	sw $a1, ($sp)
	move $a0, $t0
	move $a1, $t1
	jal LdivModChk
	move $t1, $v0
	lw $a0, -4($sp)
	lw $a1, ($sp)
	addi $sp, $sp, 8
	rem $t2, $t0, $t1
	addi $sp, $sp, -4
	sw $a0, 0($sp)
	move $a0, $t2
	jal Lprinti
	lw $a0, 0($sp)
	addi $sp, $sp, 4
	li $t2, 10
	addi $sp, $sp, -4
	sw $a0, 0($sp)
	move $a0, $t2
	jal Lprintc
	lw $a0, 0($sp)
	addi $sp, $sp, 4
	li $t2, -5
	li $t1, 3
	addi $sp, $sp, -8
	sw $a0, -4($sp)
	sw $a1, ($sp)
	move $a0, $t2
	move $a1, $t1
	jal LdivModChk
	move $t1, $v0
	lw $a0, -4($sp)
	lw $a1, ($sp)
	addi $sp, $sp, 8
	rem $t0, $t2, $t1
	addi $sp, $sp, -4
	sw $a0, 0($sp)
	move $a0, $t0
	jal Lprinti
	lw $a0, 0($sp)
	addi $sp, $sp, 4
	li $t0, 10
	addi $sp, $sp, -4
	sw $a0, 0($sp)
	move $a0, $t0
	jal Lprintc
	lw $a0, 0($sp)
	addi $sp, $sp, 4
	li $t0, 5
	li $t1, -3
	addi $sp, $sp, -8
	sw $a0, -4($sp)
	sw $a1, ($sp)
	move $a0, $t0
	move $a1, $t1
	jal LdivModChk
	move $t1, $v0
	lw $a0, -4($sp)
	lw $a1, ($sp)
	addi $sp, $sp, 8
	rem $t2, $t0, $t1
	addi $sp, $sp, -4
	sw $a0, 0($sp)
	move $a0, $t2
	jal Lprinti
	lw $a0, 0($sp)
	addi $sp, $sp, 4
	li $t2, 10
	addi $sp, $sp, -4
	sw $a0, 0($sp)
	move $a0, $t2
	jal Lprintc
	lw $a0, 0($sp)
	addi $sp, $sp, 4
	li $t2, -5
	li $t1, -3
	addi $sp, $sp, -8
	sw $a0, -4($sp)
	sw $a1, ($sp)
	move $a0, $t2
	move $a1, $t1
	jal LdivModChk
	move $t1, $v0
	lw $a0, -4($sp)
	lw $a1, ($sp)
	addi $sp, $sp, 8
	rem $t0, $t2, $t1
	addi $sp, $sp, -4
	sw $a0, 0($sp)
	move $a0, $t0
	jal Lprinti
	lw $a0, 0($sp)
	addi $sp, $sp, 4
	# epilogue
	lw   $fp, 0($sp)
	lw   $ra, 4($sp)
	addi $sp, $sp, 8
	jr $ra

	.data
LemptyString:
	.asciiz ""


# start of RTS
	.data
LtrueString:
	.asciiz "true"
LfalseString:
	.asciiz "false"
LnoReturnErrorString:
	.asciiz "Runtime error: no value returned from function"
LdivByZeroString:
	.asciiz "Runtime error: division by zero"
	.align 4
Ltrue:
	.word 1
Lfalse:
	.word 0

	.text
# $a0 - dividend
# $a1 - divisor
# checking for two things:
# division by 0: runtime error
# right operand = INT_MIN: return $v0 = 1
# we use $v1 here since we know its never used elsewhere
LdivModChk:
	beq $0, $a1, LdivByZeroError
    li $v1, -2147483648
    beq $a0, $v1, LsecondCheck
LdivModChkDone:
    move $v0, $a1
    jr $ra
LsecondCheck:
    li $v1, -1
    bne $a1, $v1, LdivModChkDone
    li $v0, 1
    jr $ra
LdivByZeroError:
	la $a0 LdivByZeroString
	jal Lprints
	jal Lhalt
LnoReturnError:
	la $a0 LnoReturnErrorString
	jal Lprints
	jal Lhalt
Lhalt:
	li $v0 10
	syscall
    jr $ra
# will populate $v0
LgetChar:
	li $v0 12
	syscall
	jr $ra

# assumes $a0 is loaded with address of string
Llen:
	# initialize length variable to 0
	addi $t0 $0 0
Lcount:
	# load in character at address in $a0
	lb $t1 ($a0)
	# we've reached EOS if the byte == 0
	beq $t1 $0 LretLen
	# else we increment length and the address
	addi $t0 $t0 1
	addi $a0 $a0 1
	j Lcount
LretLen:
	# move length to return register and return
	addi $v0 $t0 0
	jr $ra

# assumes $a0 is loaded with boolean to print
Lprintb:
	# if the boolean value is 0 then print false
	beq $0 $a0 LprintFalse
	# else print true
	addi $sp, $sp, -8
	sw $ra, -4($sp)
	sw $a0, 0($sp)
	la $a0 LtrueString
	jal Lprints
	lw $a0, 0($sp)
	lw $ra, -4($sp)
	addi $sp, $sp, 8
	jr $ra
LprintFalse:
	addi $sp, $sp, -8
	sw $ra, -4($sp)
	sw $a0, 0($sp)
	la $a0 LfalseString
	jal Lprints
	lw $a0, 0($sp)
	lw $ra, -4($sp)
	addi $sp, $sp, 8
	jr $ra

# assume $a0 is loaded with integer to print
Lprintc:
	li $v0 11
	syscall
	jr $ra

# assume $a0 is loaded with integer to print
Lprinti:
	li $v0 1
	syscall
	jr $ra

# assume $a0 is loaded with adress of string to print
Lprints:
	li $v0 4
	syscall
	jr $ra
# end of RTS

