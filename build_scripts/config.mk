export CFLAGS = -std=c99 -g
export CC = gcc
export CXX = g++
export LD = gcc
export ASM = nasm
export ASMFLAGS=
export LINKFlAGS = 
export LIBS = 

export TARGET = i686-elf
export TARGET_CFLAGS = -std=c99 -g
export TARGET_CC = $(TARGET)-gcc
export TARGET_CCX = $(TARGET)-g++
export TARGET_LD = $(TARGET)-gcc
export TARGET_ASM = nasm
export TARGET_NASMFLAGS = 
export TARGET_LINKFLAGS = 
export TARGET_LIBS = 


export BUILD_DIR=$(abspath build)

export SRC_DIR=$(abspath src)


BINUTILS_VERSION=2.45
GCC_VERSION=13.2.0
BINUTILS_URL="https://ftp.gnu.org/gnu/binutils/binutils-$(BINUTILS_VERSION).tar.gz"
GCC_URL = https://ftp.gnu.org/gnu/gcc/gcc-$(GCC_VERSION)/gcc-$(GCC_VERSION).tar.gz
BINUTILS_BUILD = toolchain/binutils-built-$(BINUTILS_VERSION)
GCC_BUILD = toolchain/gcc-build-$(GCC_VERSION)
