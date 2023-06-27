org 0x7c00   ; 指定计算机将代码加载到内存的0x7c00处

section .text
    ; 代码的入口点。这段代码将在计算机启动时执行
    ; 程序将根据按下的键盘按键在光标处显示相应的字符
    ; 按下键盘的方向键可以移动光标

    jmp start   ; 跳转到 start 标签开始执行代码

    start:
        mov ah, 0       ; 设置BIOS中断0x16的功能为读取键盘输入
        int 0x16        ; 调用BIOS中断0x16，等待键盘输入
                        ; 中断返回后，按键的扫描码在AH中，对应字符的ASCII码在AL中

        ; 检查按下的键是否是方向键。如果是，将光标向对应方向移动1个字符
        ; 方向键没有ASCII码，所以检查AH的值

        cmp ah, 0x4b    ; 检查是否按下了方向键：↑
        je move_up      ; 如果按下了，跳转到move_up标签

        cmp ah, 0x4d    ; 检查是否按下了方向键：↓
        je move_down    ; 如果按下了，跳转到move_down标签

        cmp ah, 0x48    ; 检查是否按下了方向键：←
        je move_left    ; 如果按下了，跳转到move_left标签

        cmp ah, 0x50    ; 检查是否按下了方向键：→
        je move_right   ; 如果按下了，跳转到move_right标签

        ; 按下的键不是方向键。显示按键对应的字符

        mov ah, 0x0e    ; 设置BIOS中断0x10的功能为显示ASCII与AL中的数据相同的一个字符
        int 0x10        ; 调用BIOS中断0x10，显示字符

        ;mov al, 7       ; 设置AL为响铃符的ASCII码
        ;int 0x10        ; “显示”响铃符。如果计算机有蜂鸣器就会发出“滴”声

        jmp start       ; 无限循环

    move_up:
        mov ah, 0x03    ; 设置BIOS中断0x10的功能为获取光标位置
        mov bh, 0       ; 将页号设置为0
        int 0x10        ; 调用BIOS中断0x10，获取光标位置
                        ; 中断返回后，光标位置的行号在DL中，列号在DH中
                        ; 几乎所有计算机在启动时都处于布局是80×25个字符的文本模式
                        ; 所以本程序假设DL的取值范围是0~24，DH的取值范围是0~79

        cmp dl, 0       ; 检查光标是否在第一行
        je start        ; 如果在第一行，不作任何处理

        dec dl          ; 行号减1
        mov ah, 0x02    ; 设置BIOS中断0x10的功能为设置光标位置
        int 0x10        ; 调用BIOS中断0x10，设置光标位置

        jmp start       ; 返回到程序开始处

    move_down:
        mov ah, 0x03
        mov bh, 0 
        int 0x10

        cmp dl, 24      ; 检查光标是否在最后一行
        je start        ; 如果在最后一行，不作任何处理

        inc dl          ; 行号加1
        mov ah, 0x02
        int 0x10

        jmp start

    move_left:
        mov ah, 0x03
        mov bh, 0 
        int 0x10

        cmp dh, 0       ; 检查光标是否在第一列
        je start        ; 如果在第一列，不作任何处理

        dec dh          ; 列号减1
        mov ah, 0x02
        int 0x10

        jmp start

    move_right:
        mov ah, 0x03
        mov bh, 0 
        int 0x10

        cmp dh, 79      ; 检查光标是否在最后一列
        je start        ; 如果在最后一列，不作任何处理

        inc dh          ; 列号加1
        mov ah, 0x02
        int 0x10

        jmp start

times 510-($-$$) db 0x00; 填充剩余的空间，使编译后的机器码正好占用510个字节
dw 0xaa55               ; 在第511和512字节处写入引导扇区标识（即0xAA 0x55）
                        ; 计算机识别到该标识后会从内存的0x7c00处开始执行代码
