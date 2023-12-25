[org 0x0100]

 mov ax,0
 mov cx,20
 mov bx,20
square:
 add ax,bx
 dec cx
 jnz square

mov ax, 0x4c00  
int 0x21
