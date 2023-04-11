
	.text
	.globl main
main:
	jal Lmain
	j halt
Lmain:
	# prologue
	addi $sp, $sp, -8
	sw   $ra, 4($sp)
	sw   $fp, 0($sp)
	move $fp, $sp
	addi $sp, $sp, -4
	# body
	sw $0, -4($fp)		# initializing var i
	li $t0, 0
	sw $t0, -4($fp)
L2:
	lw $t0, -4($fp)
	li $t1, 23
	sle $t2, $t0, $t1
	beq $t2, $0, L3
	la $t2, L4
	move $a0, $t2
	jal Lprints
	lw $t2, -4($fp)
	move $a0, $t2
	jal Lprinti
	la $t2, L5
	move $a0, $t2
	jal Lprints
	lw $t2, -4($fp)
	move $a0, $t2
	jal Lfib
	move $t2, $v0
	move $a0, $t2
	jal Lprinti
	la $t2, L6
	move $a0, $t2
	jal Lprints
	lw $t2, -4($fp)
	li $t1, 1
	addu $t0, $t2, $t1
	sw $t0, -4($fp)
	j L2
L3:
L1:
	# epilogue
	addi $sp, $sp, 4
	lw   $fp, 0($sp)
	lw   $ra, 4($sp)
	addi $sp, $sp, 8
	jr $ra
Lfib:
	# prologue
	addi $sp, $sp, -8
	sw   $ra, 4($sp)
	sw   $fp, 0($sp)
	move $fp, $sp
	addi $sp, $sp, -4
	sw $a0, -4($fp)
	# body
	lw $t0, -4($fp)
	li $t1, 0
	seq $t2, $t0, $t1
	beq $t2, $0, L8
	li $t2, 0
	# return inst
	move $v0, $t2
	j L7
L8:
	lw $t2, -4($fp)
	li $t1, 1
	seq $t0, $t2, $t1
	beq $t0, $0, L9
	li $t0, 1
	# return inst
	move $v0, $t0
	j L7
L9:
	lw $t0, -4($fp)
	li $t1, 1
	subu $t2, $t0, $t1
	move $a0, $t2
	jal Lfib
	move $t2, $v0
	lw $t1, -4($fp)
	li $t0, 2
	subu $t3, $t1, $t0
	move $a0, $t3
	addi $sp, $sp, -4
	sw $t2, 0($sp)
	jal Lfib
	lw $t2, 0($sp)
	addi $sp, $sp, 4
	move $t3, $v0
	addu $t0, $t2, $t3
	# return inst
	move $v0, $t0
	j L7
	# error
	j noReturnError
L7:
	# epilogue
	addi $sp, $sp, 4
	lw   $fp, 0($sp)
	lw   $ra, 4($sp)
	addi $sp, $sp, 8
	jr $ra

	.data
L6:
	.byte 10
	.byte 0
emptyString:
	.byte 0
L5:
	.byte 41
	.byte 32
	.byte 61
	.byte 32
	.byte 0
L4:
	.byte 102
	.byte 105
	.byte 98
	.byte 40
	.byte 0


# start of RTS
	.data
trueString:
	.asciiz "true"
falseString:
	.asciiz "false"
noReturnErrorString:
	.asciiz "Runtime error: no value returned from function"
divByZeroString:
	.asciiz "Runtime error: division by zero"
input:  .space 2
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
divModChk:
	beq $0, $a1, divByZeroError
    li $v1, -2147483648
    beq $a0, $v1, secondCheck
divModChkDone:
    move $v0, $a1
    jr $ra
secondCheck:
    li $v1, -1
    bne $a1, $v1, divModChkDone
    li $v0, 1
    jr $ra
	
divByZeroError:
	la $a0, divByZeroString
	jal Lprints
	jal halt

noReturnError:
	la $a0, noReturnErrorString
	jal Lprints
	jal halt

halt:
	li, $v0, 10
	syscall
    jr $ra
# will populate $v0
# literally copy-pasted from Shankar's Tutorial notes "RTS Functions"
# https://pages.cpsc.ucalgary.ca/~sankarasubramanian.g/411/
LgetChar:
    addi $sp, $sp, -4
    sw $ra, 0($sp)

    li $v0, 8                       # System call for read_string
    la $a0, input                   # Pass in buffer (size = n+1)
    li $a1, 2                       # Size = n+1 as read_string adds null
    syscall

    lb $v0, input
    bne $v0, $zero, ret

    li $v0, -1                      # If 0, map to -1 and return
ret:
    lw $ra 0($sp)
    addi $sp $sp, 4
    jr $ra

# assumes $a0 is loaded with address of string
Llen:
	# initialize length variable to 0
	addi $t0, $0, 0
count:
	# load in character at address in $a0
	lb $t1, ($a0)
	# we've reached EOS if the byte == 0
	beq $t1, $0, retLen
	# else we increment length and the address
	addi $t0, $t0, 1
	addi $a0, $a0, 1
	j count
retLen:
	# move length to return register and return
	addi $v0, $t0, 0
	jr $ra

# assumes $a0 is loaded with boolean to print
Lprintb:
	# if the boolean value is 0 then print false
	beq $0 $a0 printFalse
	# else print true
	addi $sp, $sp, -8
	sw $ra, -4($sp)
	sw $a0, 0($sp)
	la $a0, trueString
	jal Lprints
	lw $a0, 0($sp)
	lw $ra, -4($sp)
	addi $sp, $sp, 8
	jr $ra
printFalse:
	addi $sp, $sp, -8
	sw $ra, -4($sp)
	sw $a0, 0($sp)
	la $a0, falseString
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

