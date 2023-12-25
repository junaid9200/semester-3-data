[org 0x0100]   

jmp start

data:   dw 5
count:  dw 11
result: dw 0

recursion:   
        push bp
        mov bp, sp
        mov ax, [bp + 4]     ; Load the argument from the stack
        add [result], ax
        dec word[count]
        cmp word[count], 0
        jle end_recursion    ; Jump if less than or equal to zero

        ; Recursive call
        push word[result]    ; Save the current result on the stack
        push word[count]     ; Save the current count on the stack
        call recursion       ; Recursive call
        add sp, 4            ; Clean up the stack

end_recursion:
        pop bp
        ret

start:  mov ax, [data]
        push ax
        mov cx, [count]
        push cx
        call recursion

        mov ax, 0x4c00         
        int 0x21  