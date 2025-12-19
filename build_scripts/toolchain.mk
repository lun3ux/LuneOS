toolchain: toolchain_binutils toolchain_gcc

BINUTILS_VERSION=2.42
GCC_VERSION=13.2.0
BINUTILS_URL=https://ftp.gnu.org/gnu/binutils/binutils-$(BINUTILS_VERSION).tar.gz
GCC_URL=https://ftp.gnu.org/gnu/gcc/gcc-$(GCC_VERSION)/gcc-$(GCC_VERSION).tar.gz
TARGET=i686-elf
TOOLCHAIN_PREFIX=$(abspath toolchain/$(TARGET))
BINUTILS_BUILD = toolchain/binutils-built-$(BINUTILS_VERSION)
GCC_BUILD = toolchain/gcc-build-$(GCC_VERSION)


export PATH :=$(TOOLCHAIN_PREFIX)/bin:$(PATH)

export TARGET_CC = $(TARGET)-gcc
export TARGET_CCX = $(TARGET)-g++
export TARGET_LD = $(TARGET)-g++

toolchain_binutils:
	mkdir toolchain
	cd toolchain && wget $(BINUTILS_URL)
	cd toolchain && tar -xf binutils-$(BINUTILS_VERSION).tar.gz
	mkdir -p toolchain/binutils-built-$(BINUTILS_VERSION)
	cd toolchain/binutils-built-$(BINUTILS_VERSION) && ../binutils-$(BINUTILS_VERSION)/configure \
        --prefix="$(TOOLCHAIN_PREFIX)" \
        --target=$(TARGET) \
        --with-sysroot \
        --disable-nls \
        --disable-werror
	$(MAKE) -j8 -C $(BINUTILS_BUILD)
	$(MAKE) -C $(BINUTILS_BUILD) install

toolchain_gcc: toolchain_binutils
	cd toolchain && wget $(GCC_URL)
	cd toolchain && tar -xf gcc-$(GCC_VERSION).tar.gz
	mkdir $(GCC_BUILD)
	cd $(GCC_BUILD) && ../gcc-$(GCC_VERSION)/configure \
		--prefix="$(TOOLCHAIN_PREFIX)"	\
		--target=$(TARGET)				\
		--disable-n1s					\
		--without-headers				\
		--enable-languages=c,c++		\
		--with-newlib					\

	$(MAKE) -j8 -C $(GCC_BUILD) all-gcc all-target-libgcc
	$(MAKE) -C $(GCC_BUILD) install-gcc install-target-libgcc
	
.PHONY: toolchain_binutils toolchain_gcc
