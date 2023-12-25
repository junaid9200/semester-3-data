[org 0x0100]                                                        ; Explanation in the code 
jmp start

array:dw 7, 14, 21, 28, 35, 42, 49, 6, 13, 20
evenn:dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
odd  :dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

start:  
 
 mov bx, evenn
 mov si, odd     
 mov cx, 20         
 mov di, 0             
               
check:  
   
 mov ax, [array + di]    
 test ax, 1                 ; checking the least significant bit .
 jz even1               ; Jump to even label if the number is even

 mov [si], ax             ; Storing odd number in odd array.
 add si, 2          
 jmp next   

even1:		

 mov [bx], ax      ;storing even number in even array
 add bx, 2        

next:

  add di, 2			
  cmp di,cx
  jnz check
			
    mov ax, 0x4c00         
    int 0x21           
