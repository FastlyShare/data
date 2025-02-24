data segment
org 1000h
n1 db 04h
n2 db 05h
org 2000h
n3 dw ?
data ends
code segment
assume cs:code, ds:data
start : mov ax,data
mov ds,ax
mov al,n1
mov bl,n2
add al,bl
mov dl,al
add dh,00h
mov n3,dx
mov ah,4ch
int 21h
code ends
end start

