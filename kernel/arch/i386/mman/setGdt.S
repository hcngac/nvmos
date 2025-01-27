.section .data

gdtr:
    .hword 0x0
gdtr_addr:
    .int 0x0

.section .text
.global setGDT
.type setGDT,   @function

setGDT:
    MOV     4(%esp),    %eax
    MOV     %eax,       gdtr_addr
    MOV     8(%esp),    %ax
    MOV     %ax,        gdtr
    LGDT    gdtr
    RET

.extern __start_tss
.global reloadGDT
.type reloadGDT,   @function

reloadGDT:
    MOV     $0x10,      %ax
    MOV     %ax,        %ds
    MOV     %ax,        %es
    MOV     %ax,        %fs
    MOV     %ax,        %gs
    MOV     %ax,        %ss
	lea		__start_tss,	%ebx
	movw	$0x10,		0x8(%ebx)
	movw	$0x10,		0x10(%ebx)
	movw	$0x10,		0x18(%ebx)
	movw	$0x10,		0x48(%ebx)
	movw	$0x8,		0x4C(%ebx)
	movw	$0x10,		0x50(%ebx)
	movw	$0x10,		0x54(%ebx)
	movw	$0x10,		0x58(%ebx)
	movw	$0x10,		0x5C(%ebx)
	movw	$0x28,		%ax
	ltr		%ax
    JMP     $0x08,      $1f
1:
    RET


