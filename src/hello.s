;
; File generated by cc65 v 2.18 - N/A
;
	.fopt		compiler,"cc65 v 2.18 - N/A"
	.setcpu		"6502"
	.smart		on
	.autoimport	on
	.case		on
	.debuginfo	off
	.importzp	sp, sreg, regsave, regbank
	.importzp	tmp1, tmp2, tmp3, tmp4, ptr1, ptr2, ptr3, ptr4
	.macpack	longbranch
	.forceimport	__STARTUP__
	.import		_printf
	.import		_sleep
	.import		_clrscr
	.import		_bgcolor
	.import		_text
	.export		_i
	.export		_main

.segment	"DATA"

_i:
	.word	$0000

.segment	"RODATA"

L004C:
	.byte	$25,$73,$20,$31,$36,$35,$9B,$00
L003B:
	.byte	$25,$73,$20,$25,$69,$7F,$00

; ---------------------------------------------------------------
; int __near__ main (void)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_main: near

.segment	"CODE"

;
; bgcolor(COLOR_BLACK); // set the background color
;
	lda     #$00
	jsr     _bgcolor
;
; POKEW(709,56);  // set text color.  708 is memory address for color reg # 0.  
;
	ldx     #$00
	lda     #$38
	sta     $02C5
	stx     $02C5+1
;
; clrscr();  // clear the screen
;
	jsr     _clrscr
;
; for (i = 0; i <= 254; i++) {
;
	lda     #$00
	sta     _i
	sta     _i+1
L0030:	lda     _i
	cmp     #$FF
	lda     _i+1
	sbc     #$00
	bvc     L0037
	eor     #$80
L0037:	asl     a
	ldx     #$00
	bcc     L0052
;
; printf("%s %i\t", text, i);
;
	lda     #<(L003B)
	ldx     #>(L003B)
	jsr     pushax
	lda     #<(_text)
	ldx     #>(_text)
	jsr     pushax
	lda     _i
	ldx     _i+1
	jsr     pushax
	ldy     #$06
	jsr     _printf
;
; POKEW(710,i);  // set text color.  708 is memory address for color reg # 0.  
;
	lda     _i+1
	sta     $02C6+1
	lda     _i
	sta     $02C6
;
; sleep(1);   // x seconds
;
	ldx     #$00
	lda     #$01
	jsr     _sleep
;
; for (i = 0; i <= 254; i++) {
;
	lda     _i
	ldx     _i+1
	clc
	adc     #$01
	bcc     L0039
	inx
L0039:	sta     _i
	stx     _i+1
	jmp     L0030
;
; POKEW(710,165);  // set text color.  710 is memory address for color reg # 2.  This should be green on black  
;
L0052:	lda     #$A5
	sta     $02C6
	stx     $02C6+1
;
; printf("%s 165\n", text);
;
	lda     #<(L004C)
	ldx     #>(L004C)
	jsr     pushax
	lda     #<(_text)
	ldx     #>(_text)
	jsr     pushax
	ldy     #$04
	jsr     _printf
;
; sleep(10);   // 10 seconds
;
	ldx     #$00
	lda     #$0A
	jsr     _sleep
;
; return EXIT_SUCCESS;
;
	ldx     #$00
	txa
;
; }
;
	rts

.endproc

