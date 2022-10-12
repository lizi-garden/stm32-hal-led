#!/usr/bin/env bash

SOURCE=/usr/share/openocd/
INTERFACE_CFG=${SOURCE}scripts/interface/cmsis-dap.cfg
TARGET_CFG=${SOURCE}scripts/target/stm32f1x.cfg
PWD=$(dirname "$(readlink -f "$0")")
# BIN=${PWD}/build/LED.bin
HEX=${PWD}/build/LED.hex

echo "开始连接"
openocd -f ${INTERFACE_CFG}                     \
        -f ${TARGET_CFG}                        \
        -c "init"                               \
        -c "reset"                              \
        -c "halt"                               \
        -c "flash erase_sector 0 0 last"        \
        -c "flash write_image erase ${HEX}"     \
        -c "reset"                              \
        -c "shutdown"

