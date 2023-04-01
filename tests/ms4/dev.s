.globl main
.data
myLabel:
    .word 0
.text
main:
    addi    $s0, $zero, 0
    la      $s1, myLabel
    sw      $s0, 0($s1)
    jr $ra