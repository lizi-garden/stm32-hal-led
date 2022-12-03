#!/usr/bin/env bash

SOURCE=/usr/share/openocd/
INTERFACE_CFG=${SOURCE}scripts/interface/cmsis-dap.cfg
TARGET_CFG=${SOURCE}scripts/target/stm32f1x.cfg
PWD=$(dirname "$(readlink -f "$0")")

echo "开始连接"
openocd -f ${INTERFACE_CFG}                     \
        -f ${TARGET_CFG}                        \
        -c "init"                               \
        -c "halt"                               \
        -c "stm32f1x unlock 0"                  \
        -c "reset halt"                         \
        -c "exit"
