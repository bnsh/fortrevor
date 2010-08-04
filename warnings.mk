WARNING_FLAGS=\
	-D__USE_FORTIFY_LEVEL=0 \
	-Werror \
	-Wall \
	-Wcast-align \
	-Wcast-qual \
	-Wchar-subscripts \
	-Wcomment \
	-Wdisabled-optimization \
	-Wextra \
	-Wformat \
	-Wformat=2 \
	-Wformat-nonliteral \
	-Wformat-security \
	-Wformat-y2k \
	-Wimplicit \
	-Wimport \
	-Winit-self \
	-Winvalid-pch \
	-Wlong-long \
	-Wmissing-braces \
	-Wmissing-field-initializers \
	-Wmissing-format-attribute \
	-Wmissing-include-dirs \
	-Wmissing-noreturn \
	-Wno-deprecated-declarations \
	-Wno-endif-labels \
	-Wno-format-extra-args \
	-Wno-import \
	-Wno-invalid-offsetof \
	-Wno-multichar \
	-Wpacked \
	-Wparentheses \
	-Wpointer-arith \
	-Wreturn-type \
	-Wsequence-point \
	-Wshadow \
	-Wsign-compare \
	-Wstack-protector \
	-Wstrict-aliasing \
	-Wstrict-aliasing=2 \
	-Wswitch \
	-Wswitch-default \
	-Wswitch-enum \
	-Wsystem-headers \
	-Wtrigraphs \
	-Wundef \
	-Wuninitialized \
	-Wunknown-pragmas \
	-Wunused \
	-Wunused-function \
	-Wunused-label \
	-Wunused-parameter \
	-Wunused-value \
	-Wunused-variable \
	-Wvariadic-macros \
	-Wwrite-strings \

# Warnings we can't use.
#	-Wconversion \
#	-Winline \
#	-Wunsafe-loop-optimizations \
#	-Wc++-compat \ is valid for C but not for C++
#	-Werror-implicit-function-declaration \ is valid for C/ObjC but not for C++
#	-Wimplicit-function-declaration \ is valid for C/ObjC but not for C++
#	-Wimplicit-int \ is valid for C/ObjC but not for C++
#	-Wno-div-by-zero \ is valid for C/ObjC but not for C++
#	-Wmain \ is valid for C/ObjC but not for C++
#	-Wnonnull \ is valid for C/ObjC but not for C++
#	-Wno-pointer-to-int-cast \ is valid for C/ObjC but not for C++
#	-Wlarger-than-LEN \ I like long variables. Pthbhtbth
#	-Wfloat-equal \ generates errors in math.h Stupid. That would have been useful to me.
#	-Wunreachable-code \ generates errors in math.h. Also, would have been useful to me. *sigh*
#	-Wredundant-decls \ generates errors in stdio.h or unistd.h about redundant redeclaration of 'char* ctermid. I could have used this too.
#	-Wpadded \ This gets triggered all over headers, and never by me.
#	-Wfatal-errors \ There's no need to stop at the first error.
#	-Wno-attributes \ Won't work on mac os x. (For Trevor)
#	-Wno-pragmas \ Won't work on mac os x. (For Trevor)
#	-Wvolatile-register-var \ Won't work on mac os x. (For Trevor)
