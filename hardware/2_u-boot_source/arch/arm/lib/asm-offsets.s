	.arch armv8-a+fp+simd
	.file	"asm-offsets.c"
// GNU C (GCC) version 4.9 20150123 (prerelease) (aarch64-linux-android)
//	compiled by GNU C version 4.8, GMP version 5.0.5, MPFR version 3.1.1, MPC version 1.0.1
// GGC heuristics: --param ggc-min-expand=96 --param ggc-min-heapsize=125383
// options passed:  -nostdinc -I include
// -I /work/firefly-rk3399/u-boot/arch/arm/include
// -iprefix /work/firefly-rk3399/prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.9/bin/../lib/gcc/aarch64-linux-android/4.9/
// -D __KERNEL__ -D __UBOOT__ -D CONFIG_SYS_TEXT_BASE=0x00200000 -D __ARM__
// -D DO_DEPS_ONLY -D KBUILD_STR(s)=#s
// -D KBUILD_BASENAME=KBUILD_STR(asm_offsets)
// -D KBUILD_MODNAME=KBUILD_STR(asm_offsets)
// -isystem /work/firefly-rk3399/prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.9/bin/../lib/gcc/aarch64-linux-android/4.9/include
// -include /work/firefly-rk3399/u-boot/include/linux/kconfig.h
// -MD arch/arm/lib/.asm-offsets.s.d arch/arm/lib/asm-offsets.c -mbionic
// -march=armv8-a -mgeneral-regs-only -mstrict-align -mlittle-endian
// -mabi=lp64 -auxbase-strip arch/arm/lib/asm-offsets.s -g -Os -Wall
// -Wstrict-prototypes -Wno-format-security -Wno-format-nonliteral
// -Werror=date-time -fno-builtin -ffreestanding -fno-stack-protector
// -fstack-usage -fno-pic -ffunction-sections -fdata-sections -ffixed-r9
// -fno-common -ffixed-x18 -fverbose-asm
// options enabled:  -faggressive-loop-optimizations -fauto-inc-dec
// -fbranch-count-reg -fcaller-saves -fcombine-stack-adjustments
// -fcompare-elim -fcprop-registers -fcrossjumping -fcse-follow-jumps
// -fdata-sections -fdefer-pop -fdelete-null-pointer-checks
// -fdevirtualize-speculatively -fdwarf2-cfi-asm -fearly-inlining
// -feliminate-unused-debug-types -fexpensive-optimizations
// -fforward-propagate -ffunction-cse -ffunction-sections -fgcse -fgcse-lm
// -fgnu-runtime -fgnu-unique -fguess-branch-probability
// -fhoist-adjacent-loads -fident -fif-conversion -fif-conversion2
// -findirect-inlining -finline -finline-atomics -finline-functions
// -finline-functions-called-once -finline-small-functions -fipa-cp
// -fipa-profile -fipa-pure-const -fipa-reference -fipa-sra
// -fira-hoist-pressure -fira-share-save-slots -fira-share-spill-slots
// -fisolate-erroneous-paths-dereference -fivopts -fkeep-static-consts
// -fleading-underscore -flifetime-dse -fmath-errno -fmerge-constants
// -fmerge-debug-strings -fmove-loop-invariants -fomit-frame-pointer
// -foptimize-sibling-calls -fpartial-inlining -fpeel-codesize-limit
// -fpeephole -fpeephole2 -fplt -fprefetch-loop-arrays -free
// -freg-struct-return -freorder-blocks -freorder-functions
// -frerun-cse-after-loop -fsched-critical-path-heuristic
// -fsched-dep-count-heuristic -fsched-group-heuristic -fsched-interblock
// -fsched-last-insn-heuristic -fsched-rank-heuristic -fsched-spec
// -fsched-spec-insn-heuristic -fsched-stalled-insns-dep -fschedule-insns2
// -fsection-anchors -fshow-column -fshrink-wrap -fsigned-zeros
// -fsplit-ivs-in-unroller -fsplit-wide-types -fstrict-aliasing
// -fstrict-enum-precision -fstrict-overflow -fstrict-volatile-bitfields
// -fsync-libcalls -fthread-jumps -ftoplevel-reorder -ftrapping-math
// -ftree-bit-ccp -ftree-builtin-call-dce -ftree-ccp -ftree-ch
// -ftree-coalesce-vars -ftree-copy-prop -ftree-copyrename -ftree-cselim
// -ftree-dce -ftree-dominator-opts -ftree-dse -ftree-forwprop -ftree-fre
// -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
// -ftree-loop-optimize -ftree-loop-vectorize -ftree-parallelize-loops=
// -ftree-phiprop -ftree-pre -ftree-pta -ftree-reassoc -ftree-scev-cprop
// -ftree-sink -ftree-slsr -ftree-sra -ftree-switch-conversion
// -ftree-tail-merge -ftree-ter -ftree-vrp -funit-at-a-time
// -funroll-codesize-limit -fvar-tracking -fvar-tracking-assignments
// -fverbose-asm -fzero-initialized-in-bss -mandroid -mbionic
// -mfix-cortex-a53-835769 -mfix-cortex-a53-843419 -mgeneral-regs-only
// -mlittle-endian -mlra -momit-leaf-frame-pointer -mstrict-align

	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.section	.text.startup.main,"ax",%progbits
	.align	2
	.global	main
	.type	main, %function
main:
.LFB157:
	.file 1 "arch/arm/lib/asm-offsets.c"
	.loc 1 27 0
	.cfi_startproc
	.loc 1 248 0
	mov	w0, 0	//,
	ret
	.cfi_endproc
.LFE157:
	.size	main, .-main
	.text
.Letext0:
	.file 2 "/work/firefly-rk3399/u-boot/arch/arm/include/asm/types.h"
	.file 3 "include/linux/types.h"
	.file 4 "include/asm-generic/u-boot.h"
	.file 5 "include/net.h"
	.section	.debug_info,"",%progbits
.Ldebug_info0:
	.4byte	0x38a
	.2byte	0x4
	.4byte	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.4byte	.LASF56
	.byte	0x1
	.4byte	.LASF57
	.4byte	.LASF58
	.4byte	.Ldebug_ranges0+0
	.8byte	0
	.4byte	.Ldebug_line0
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.4byte	.LASF0
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.4byte	.LASF1
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.4byte	.LASF2
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.4byte	.LASF3
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.4byte	.LASF4
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.4byte	.LASF5
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.4byte	.LASF6
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.4byte	.LASF7
	.uleb128 0x4
	.string	"u64"
	.byte	0x2
	.byte	0x28
	.4byte	0x61
	.uleb128 0x5
	.4byte	.LASF8
	.byte	0x2
	.byte	0x38
	.4byte	0x30
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.4byte	.LASF9
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.4byte	.LASF10
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.4byte	.LASF11
	.uleb128 0x5
	.4byte	.LASF12
	.byte	0x3
	.byte	0x59
	.4byte	0x30
	.uleb128 0x6
	.byte	0x8
	.uleb128 0x7
	.byte	0x10
	.byte	0x4
	.byte	0x7e
	.4byte	0xc1
	.uleb128 0x8
	.4byte	.LASF13
	.byte	0x4
	.byte	0x7f
	.4byte	0x93
	.byte	0
	.uleb128 0x8
	.4byte	.LASF14
	.byte	0x4
	.byte	0x80
	.4byte	0x93
	.byte	0x8
	.byte	0
	.uleb128 0x7
	.byte	0x10
	.byte	0x4
	.byte	0x84
	.4byte	0xe2
	.uleb128 0x8
	.4byte	.LASF13
	.byte	0x4
	.byte	0x86
	.4byte	0x68
	.byte	0
	.uleb128 0x8
	.4byte	.LASF14
	.byte	0x4
	.byte	0x87
	.4byte	0x68
	.byte	0x8
	.byte	0
	.uleb128 0x9
	.4byte	.LASF36
	.2byte	0x128
	.byte	0x4
	.byte	0x1b
	.4byte	0x1e0
	.uleb128 0x8
	.4byte	.LASF15
	.byte	0x4
	.byte	0x1c
	.4byte	0x30
	.byte	0
	.uleb128 0x8
	.4byte	.LASF16
	.byte	0x4
	.byte	0x1d
	.4byte	0x73
	.byte	0x8
	.uleb128 0x8
	.4byte	.LASF17
	.byte	0x4
	.byte	0x1e
	.4byte	0x30
	.byte	0x10
	.uleb128 0x8
	.4byte	.LASF18
	.byte	0x4
	.byte	0x1f
	.4byte	0x30
	.byte	0x18
	.uleb128 0x8
	.4byte	.LASF19
	.byte	0x4
	.byte	0x20
	.4byte	0x30
	.byte	0x20
	.uleb128 0x8
	.4byte	.LASF20
	.byte	0x4
	.byte	0x21
	.4byte	0x30
	.byte	0x28
	.uleb128 0x8
	.4byte	.LASF21
	.byte	0x4
	.byte	0x22
	.4byte	0x30
	.byte	0x30
	.uleb128 0x8
	.4byte	.LASF22
	.byte	0x4
	.byte	0x24
	.4byte	0x30
	.byte	0x38
	.uleb128 0x8
	.4byte	.LASF23
	.byte	0x4
	.byte	0x25
	.4byte	0x30
	.byte	0x40
	.uleb128 0x8
	.4byte	.LASF24
	.byte	0x4
	.byte	0x26
	.4byte	0x30
	.byte	0x48
	.uleb128 0x8
	.4byte	.LASF25
	.byte	0x4
	.byte	0x32
	.4byte	0x30
	.byte	0x50
	.uleb128 0x8
	.4byte	.LASF26
	.byte	0x4
	.byte	0x33
	.4byte	0x30
	.byte	0x58
	.uleb128 0x8
	.4byte	.LASF27
	.byte	0x4
	.byte	0x34
	.4byte	0x1e0
	.byte	0x60
	.uleb128 0x8
	.4byte	.LASF28
	.byte	0x4
	.byte	0x35
	.4byte	0x37
	.byte	0x66
	.uleb128 0x8
	.4byte	.LASF29
	.byte	0x4
	.byte	0x36
	.4byte	0x30
	.byte	0x68
	.uleb128 0x8
	.4byte	.LASF30
	.byte	0x4
	.byte	0x37
	.4byte	0x30
	.byte	0x70
	.uleb128 0x8
	.4byte	.LASF31
	.byte	0x4
	.byte	0x7b
	.4byte	0x93
	.byte	0x78
	.uleb128 0x8
	.4byte	.LASF32
	.byte	0x4
	.byte	0x7c
	.4byte	0x93
	.byte	0x80
	.uleb128 0x8
	.4byte	.LASF33
	.byte	0x4
	.byte	0x81
	.4byte	0x1f0
	.byte	0x88
	.uleb128 0x8
	.4byte	.LASF34
	.byte	0x4
	.byte	0x88
	.4byte	0x200
	.byte	0x98
	.byte	0
	.uleb128 0xa
	.4byte	0x29
	.4byte	0x1f0
	.uleb128 0xb
	.4byte	0x7e
	.byte	0x5
	.byte	0
	.uleb128 0xa
	.4byte	0xa0
	.4byte	0x200
	.uleb128 0xb
	.4byte	0x7e
	.byte	0
	.byte	0
	.uleb128 0xa
	.4byte	0xc1
	.4byte	0x210
	.uleb128 0xb
	.4byte	0x7e
	.byte	0x8
	.byte	0
	.uleb128 0x5
	.4byte	.LASF35
	.byte	0x4
	.byte	0x8a
	.4byte	0xe2
	.uleb128 0xc
	.byte	0x8
	.4byte	0x210
	.uleb128 0xd
	.4byte	.LASF37
	.byte	0x60
	.byte	0x5
	.byte	0x51
	.4byte	0x2be
	.uleb128 0x8
	.4byte	.LASF38
	.byte	0x5
	.byte	0x52
	.4byte	0x2be
	.byte	0
	.uleb128 0x8
	.4byte	.LASF39
	.byte	0x5
	.byte	0x53
	.4byte	0x1e0
	.byte	0x10
	.uleb128 0x8
	.4byte	.LASF40
	.byte	0x5
	.byte	0x54
	.4byte	0x4c
	.byte	0x18
	.uleb128 0x8
	.4byte	.LASF41
	.byte	0x5
	.byte	0x55
	.4byte	0x4c
	.byte	0x1c
	.uleb128 0x8
	.4byte	.LASF42
	.byte	0x5
	.byte	0x57
	.4byte	0x2e8
	.byte	0x20
	.uleb128 0x8
	.4byte	.LASF43
	.byte	0x5
	.byte	0x58
	.4byte	0x307
	.byte	0x28
	.uleb128 0x8
	.4byte	.LASF44
	.byte	0x5
	.byte	0x59
	.4byte	0x31c
	.byte	0x30
	.uleb128 0x8
	.4byte	.LASF45
	.byte	0x5
	.byte	0x5a
	.4byte	0x32d
	.byte	0x38
	.uleb128 0x8
	.4byte	.LASF46
	.byte	0x5
	.byte	0x5e
	.4byte	0x31c
	.byte	0x40
	.uleb128 0x8
	.4byte	.LASF47
	.byte	0x5
	.byte	0x5f
	.4byte	0x2e2
	.byte	0x48
	.uleb128 0x8
	.4byte	.LASF48
	.byte	0x5
	.byte	0x60
	.4byte	0x4c
	.byte	0x50
	.uleb128 0x8
	.4byte	.LASF49
	.byte	0x5
	.byte	0x61
	.4byte	0x9e
	.byte	0x58
	.byte	0
	.uleb128 0xa
	.4byte	0x8c
	.4byte	0x2ce
	.uleb128 0xb
	.4byte	0x7e
	.byte	0xf
	.byte	0
	.uleb128 0xe
	.4byte	0x4c
	.4byte	0x2e2
	.uleb128 0xf
	.4byte	0x2e2
	.uleb128 0xf
	.4byte	0x21b
	.byte	0
	.uleb128 0xc
	.byte	0x8
	.4byte	0x221
	.uleb128 0xc
	.byte	0x8
	.4byte	0x2ce
	.uleb128 0xe
	.4byte	0x4c
	.4byte	0x307
	.uleb128 0xf
	.4byte	0x2e2
	.uleb128 0xf
	.4byte	0x9e
	.uleb128 0xf
	.4byte	0x4c
	.byte	0
	.uleb128 0xc
	.byte	0x8
	.4byte	0x2ee
	.uleb128 0xe
	.4byte	0x4c
	.4byte	0x31c
	.uleb128 0xf
	.4byte	0x2e2
	.byte	0
	.uleb128 0xc
	.byte	0x8
	.4byte	0x30d
	.uleb128 0x10
	.4byte	0x32d
	.uleb128 0xf
	.4byte	0x2e2
	.byte	0
	.uleb128 0xc
	.byte	0x8
	.4byte	0x322
	.uleb128 0x11
	.4byte	.LASF59
	.byte	0x4
	.byte	0x5
	.2byte	0x1f2
	.4byte	0x359
	.uleb128 0x12
	.4byte	.LASF50
	.sleb128 0
	.uleb128 0x12
	.4byte	.LASF51
	.sleb128 1
	.uleb128 0x12
	.4byte	.LASF52
	.sleb128 2
	.uleb128 0x12
	.4byte	.LASF53
	.sleb128 3
	.byte	0
	.uleb128 0x13
	.4byte	.LASF60
	.byte	0x1
	.byte	0x1a
	.4byte	0x4c
	.8byte	.LFB157
	.8byte	.LFE157-.LFB157
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x14
	.4byte	.LASF54
	.byte	0x5
	.byte	0x6b
	.4byte	0x2e2
	.uleb128 0x15
	.4byte	.LASF55
	.byte	0x5
	.2byte	0x1f8
	.4byte	0x333
	.byte	0
	.section	.debug_abbrev,"",%progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x55
	.uleb128 0x17
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x13
	.byte	0x1
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0x5
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x15
	.byte	0x1
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x15
	.byte	0x1
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x4
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x28
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1c
	.uleb128 0xd
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x14
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x15
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",%progbits
	.4byte	0x2c
	.2byte	0x2
	.4byte	.Ldebug_info0
	.byte	0x8
	.byte	0
	.2byte	0
	.2byte	0
	.8byte	.LFB157
	.8byte	.LFE157-.LFB157
	.8byte	0
	.8byte	0
	.section	.debug_ranges,"",%progbits
.Ldebug_ranges0:
	.8byte	.LFB157
	.8byte	.LFE157
	.8byte	0
	.8byte	0
	.section	.debug_line,"",%progbits
.Ldebug_line0:
	.section	.debug_str,"MS",%progbits,1
.LASF54:
	.string	"eth_current"
.LASF22:
	.string	"bi_arm_freq"
.LASF27:
	.string	"bi_enetaddr"
.LASF45:
	.string	"halt"
.LASF41:
	.string	"state"
.LASF49:
	.string	"priv"
.LASF31:
	.string	"bi_arch_number"
.LASF19:
	.string	"bi_flashoffset"
.LASF10:
	.string	"long int"
.LASF42:
	.string	"init"
.LASF25:
	.string	"bi_bootflags"
.LASF29:
	.string	"bi_intfreq"
.LASF55:
	.string	"net_state"
.LASF28:
	.string	"bi_ethspeed"
.LASF26:
	.string	"bi_ip_addr"
.LASF39:
	.string	"enetaddr"
.LASF40:
	.string	"iobase"
.LASF56:
	.ascii	"GNU C 4.9 2"
	.string	"0150123 (prerelease) -mbionic -march=armv8-a -mgeneral-regs-only -mstrict-align -mlittle-endian -mabi=lp64 -g -Os -fno-builtin -ffreestanding -fno-stack-protector -fstack-usage -fno-pic -ffunction-sections -fdata-sections -ffixed-r9 -fno-common -ffixed-x18"
.LASF53:
	.string	"NETLOOP_FAIL"
.LASF13:
	.string	"start"
.LASF2:
	.string	"short unsigned int"
.LASF18:
	.string	"bi_flashsize"
.LASF24:
	.string	"bi_ddr_freq"
.LASF23:
	.string	"bi_dsp_freq"
.LASF44:
	.string	"recv"
.LASF15:
	.string	"bi_memstart"
.LASF0:
	.string	"unsigned char"
.LASF58:
	.string	"/work/firefly-rk3399/u-boot"
.LASF1:
	.string	"long unsigned int"
.LASF60:
	.string	"main"
.LASF20:
	.string	"bi_sramstart"
.LASF33:
	.string	"bi_dram"
.LASF12:
	.string	"ulong"
.LASF5:
	.string	"unsigned int"
.LASF43:
	.string	"send"
.LASF36:
	.string	"bd_info"
.LASF7:
	.string	"long long unsigned int"
.LASF16:
	.string	"bi_memsize"
.LASF8:
	.string	"phys_size_t"
.LASF37:
	.string	"eth_device"
.LASF9:
	.string	"sizetype"
.LASF6:
	.string	"long long int"
.LASF51:
	.string	"NETLOOP_RESTART"
.LASF52:
	.string	"NETLOOP_SUCCESS"
.LASF48:
	.string	"index"
.LASF57:
	.string	"arch/arm/lib/asm-offsets.c"
.LASF59:
	.string	"net_loop_state"
.LASF4:
	.string	"short int"
.LASF21:
	.string	"bi_sramsize"
.LASF30:
	.string	"bi_busfreq"
.LASF50:
	.string	"NETLOOP_CONTINUE"
.LASF17:
	.string	"bi_flashstart"
.LASF11:
	.string	"char"
.LASF32:
	.string	"bi_boot_params"
.LASF3:
	.string	"signed char"
.LASF46:
	.string	"write_hwaddr"
.LASF47:
	.string	"next"
.LASF34:
	.string	"rk_dram"
.LASF14:
	.string	"size"
.LASF35:
	.string	"bd_t"
.LASF38:
	.string	"name"
	.ident	"GCC: (GNU) 4.9 20150123 (prerelease)"
	.section	.note.GNU-stack,"",%progbits
