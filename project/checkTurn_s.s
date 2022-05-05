	.arch msp430g2553
	.p2align 1,0
	.text

jt:
	.word case_0
	.word case_1
	.word case_2
	.word case_3
	.word case_4
	.word default

	.global checkState
	.extern turn

checkState:
	mov #4, r13
	mov turn, r14
	cmp r14, r13
	jc default

	add r14, r14
	mov jt(r14), pc

case_0:
	mov #0, r12
	jmp end
case_1:
	mov #1, r12
	jmp end
case_2:
	mov #2, r12
	jmp end
case_3:
	mov #3, r12
	jmp end
case_4:
	mov #4, r12
	jmp end
default:
	mov #5, r12
end:
	RETI
	
