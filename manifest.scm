(use-modules (gnu packages avr)
             (gnu packages compression)
             (gnu packages embedded)
             (gnu packages flashing-tools)
             (gnu packages gcc)
             (gnu packages wget))

(define avr-flags
  (apply string-append
         (map (lambda (flag) (string-append (car flag) " " "/gnu/store/nprgsdpm31n8n7wdrvbx358prc83n5bi-profile" (cadr flag) " "))
              `(("-isystem" "/avr/include")
                ("-B"       "/avr/lib/avr5")
                ("-L"       "/avr/lib/avr5")
                ("-B"       "/avr/lib/avr35")
                ("-L"       "/avr/lib/avr35")
                ("-B"       "/avr/lib/avr51")
                ("-L"       "/avr/lib/avr51")))))

(setenv "CFLAGS" avr-flags)
(setenv "ASFLAGS" avr-flags)
(unsetenv "C_INCLUDE_PATH")

(packages->manifest (list dfu-util
                          dfu-programmer
                          gnu-make
                          unzip
                          wget
                          zip
                          gcc
                          avr-toolchain-5
                          arm-none-eabi-toolchain-6) )
