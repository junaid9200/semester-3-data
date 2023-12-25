[org 0x0100]

jmp start ; jump to start label

operand1: dw 20 
operand2: dw 12
sum_result: dw 0
subtraction_result: dw 0
multiplication_result: dw 0
division_result: dw 0
; addition subroutine 
addition:				push bp 				; save old value of base pointer
						mov bp,sp 				; mov base pointer to stack pointer
						push ax 				; save old value of ax register
						push bx 				; save old value of bx register
						mov ax,[bp+6] 			; mov operand1 to ax from stack
						mov bx,[bp+4] 			; mov operand2 to bx from stack
						add ax,bx 				; add both operands and store result to ax
						mov [sum_result], ax 	; mov result to sum_result
						pop bx 
						pop ax
						pop bp
						ret 					; return back using instruction pointer
; substraction subroutine
substraction:			push bp					; save old value of base pointer
						mov bp,sp				; mov base pointer to stack pointer
						push ax					; save old value of ax register
						push bx					; save old value of bx register
						mov ax,[bp+6]			; mov operand1 to ax from stack
						mov bx,[bp+4]			; mov operand2 to bx from stack
						sub ax,bx				; sub both operands and store result to ax
						mov [subtraction_result], ax ; mov result to sub_result
						pop bx
						pop ax
						pop bp
						ret			
; multiply subroutine
multiply:				push bp					; save old value of base pointer
						mov bp,sp				; mov base pointer to stack pointer
						push ax					; save old value of ax register
						push bx					; save old value of bx register
						mov ax,[bp+6]			; mov operand1 to ax from stack
						mov bx,[bp+4]			; mov operand2 to bx from stack
						imul ax,bx				; mul both operands and store result to ax
						mov [multiplication_result], ax	;mov result to multiplication_result
						pop bx
						pop ax
						pop bp
						ret								
; divide subroutine
divide:					push bp					; save old value of base pointer
						mov bp,sp				; mov base pointer to stack pointer
						push ax					; save old value of ax register
						push bx					; save old value of bx register
						mov ax,[bp+6]			; mov operand1 to ax from stack
						mov bx,[bp+4]			; mov operand2 to bx from stack
						xor dx,dx 				; clear dx 	
						div bx					; div operands and store result to ax
						mov [division_result], ax ; mov result to division_result
						pop bx
						pop ax
						pop bp
						ret

start:					mov ax,operand1
						push ax
						mov ax, operand2
						push ax
						call addition
						
						mov ax,operand1
						push ax
						mov ax, operand2
						push ax
						call substraction
						
						mov ax,operand1
						push ax
						mov ax, operand2
						push ax
						call multiply
						
						mov ax,operand1
						push ax
						mov ax, operand2
						push ax
						call divide
						
						mov ax,0x4c00
						int 0x21