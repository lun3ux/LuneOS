BINUTILS_VERSION="${BINUTILS_VERSION:-2.7}"
GCC_VERSION="${GCC_VERSION:-1.42}"
BINUTILS_VERSION = $(BUNUTILS_VERSION)
BINUTILS_URL="https://ftp.gnu.org/gnu/binutils/binutils-$(BUNUTILS_VERSION).tar.gz"
GCC_URL="https://ftp.gnu.org/gnu/gcc/gcc-$(GCC_VERSION).tar.gz"
BINUTILS_BUILD = toolchain/binutils-build-$(BUNUTILS_VERSION)
GCC_BUILD = toolchain/gcc-build-$(GCC_VERSION)
TARGET=i686-elf