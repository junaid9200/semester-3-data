[org 0x0100] 
 jmp start
 
operand1: dw 5
operand2: dw 10
sum_result: dw 0
subtraction_result: dw 0
multiplication_result: dw 0
division_result: dw 0


sum:
push bp ;
mov bp,sp ;
mov ax , [bp+6]
mov bx ,[bp+4]
add ax ,bx
mov [sum_result] , ax
pop bp
ret  


subtraction:
push bp ;
mov bp,sp ;
push ax
push bx
mov ax , [bp+6]
mov bx , [bp+4]
sub bx , ax 
mov [subtraction_result], bx 
pop bx
pop ax
pop bp
ret

mull:
push bp
mov bp ,sp
push ax 
push bx

mov ax , [bp+6]
mov bx ,[bp+4]
imul ax,bx
mov [multiplication_result] , ax
pop bx
pop ax
pop bp
ret

divide:
push bp
mov bp ,sp
push ax 
push bx

mov ax , [bp+6]
mov bx ,[bp+4]

div bx
mov [division_result], ax
pop bx
pop ax
pop bp
ret



start:
  mov ax,[operand1]  
  push ax   
  mov ax ,[operand2]  
  push ax; 
  call sum 
  call subtraction
  call mull
  call divv
  
 mov ax, 0x4c00					 
 int 0x21 