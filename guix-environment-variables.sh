#! $GUIX_ENVIRONMENT/bin/env sh

avr_flags="-isystem $GUIX_ENVIRONMENT/avr/include -B $GUIX_ENVIRONMENT/avr/lib/avr5 -L $GUIX_ENVIRONMENT/avr/lib/avr5 -B $GUIX_ENVIRONMENT/avr/lib/avr35 -L $GUIX_ENVIRONMENT/avr/lib/avr35 -B $GUIX_ENVIRONMENT/avr/lib/avr51 -L $GUIX_ENVIRONMENT/avr/lib/avr51"

export CFLAGS="$avr_flags"
export ASFLAGS="$avr_flags"
export C_INCLUDE_PATH=""
