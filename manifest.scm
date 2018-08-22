(use-modules (gnu packages avr)
             (gnu packages base)
             (gnu packages compression)
             (gnu packages embedded)
             (gnu packages flashing-tools)
             (gnu packages gcc)
             (gnu packages wget)
             (guix packages))


`(,dfu-util
  ,dfu-programmer
  ,gnu-make
  ,unzip
  ,wget
  ,zip
  ,gcc
  ,arm-none-eabi-toolchain-6
  ,avr-toolchain-5)
