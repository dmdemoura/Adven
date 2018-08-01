.thumb
.global VBAPrint
.type VBAPrint STT_FUNC
.text
VBAPrint:
    swi 0xFF
    bx lr