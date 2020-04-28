
HEADERS += \
    CMSIS/arm_common_tables.h \
    CMSIS/arm_math.h \
    CMSIS/core_cm0.h \
    CMSIS/core_cm3.h \
    CMSIS/core_cm4.h \
    CMSIS/core_cm4_simd.h \
    CMSIS/core_cmFunc.h \
    CMSIS/core_cmInstr.h \
    CMSIS/core_sc000.h \
    CMSIS/core_sc300.h \
    inc_drivers/c_adc.h \
    inc_drivers/c_hal.h \
    inc_drivers/c_i2c.h \
    inc_perip/stm32f30x_adc.h \
    inc_perip/stm32f30x_can.h \
    inc_perip/stm32f30x_comp.h \
    inc_perip/stm32f30x_crc.h \
    inc_perip/stm32f30x_dac.h \
    inc_perip/stm32f30x_dbgmcu.h \
    inc_perip/stm32f30x_dma.h \
    inc_perip/stm32f30x_exti.h \
    inc_perip/stm32f30x_flash.h \
    inc_perip/stm32f30x_gpio.h \
    inc_perip/stm32f30x_i2c.h \
    inc_perip/stm32f30x_iwdg.h \
    inc_perip/stm32f30x_misc.h \
    inc_perip/stm32f30x_opamp.h \
    inc_perip/stm32f30x_pwr.h \
    inc_perip/stm32f30x_rcc.h \
    inc_perip/stm32f30x_rtc.h \
    inc_perip/stm32f30x_spi.h \
    inc_perip/stm32f30x_syscfg.h \
    inc_perip/stm32f30x_tim.h \
    inc_perip/stm32f30x_usart.h \
    inc_perip/stm32f30x_wwdg.h \
    main.h \
    stm32f30x_conf.h \
    stm32f30x_it.h \
    device_io.h \
    stm32f30x.h \
    system_stm32f30x.h \
    CApp.h \
    basic_func.h \
    inc_drivers/c_timer.h \
    inc_drivers/c_24Cxx.h \
    inc_drivers/c_can.h \
    inc_drivers/c_uart.h \
    stm32303c_eval_i2c_ee.h \
    inc_ui/c_led.h \
    inc_ui/c_ui.h \
    c_driver.h

SOURCES += \
    inc_drivers/c_adc.cpp \
    inc_drivers/c_i2c.cpp \
    main.cpp \
    inc_drivers/c_hal.c \
    inc_perip/stm32f30x_adc.c \
    inc_perip/stm32f30x_can.c \
    inc_perip/stm32f30x_comp.c \
    inc_perip/stm32f30x_crc.c \
    inc_perip/stm32f30x_dac.c \
    inc_perip/stm32f30x_dbgmcu.c \
    inc_perip/stm32f30x_dma.c \
    inc_perip/stm32f30x_exti.c \
    inc_perip/stm32f30x_flash.c \
    inc_perip/stm32f30x_gpio.c \
    inc_perip/stm32f30x_i2c.c \
    inc_perip/stm32f30x_iwdg.c \
    inc_perip/stm32f30x_misc.c \
    inc_perip/stm32f30x_opamp.c \
    inc_perip/stm32f30x_pwr.c \
    inc_perip/stm32f30x_rcc.c \
    inc_perip/stm32f30x_rtc.c \
    inc_perip/stm32f30x_spi.c \
    inc_perip/stm32f30x_syscfg.c \
    inc_perip/stm32f30x_tim.c \
    inc_perip/stm32f30x_usart.c \
    inc_perip/stm32f30x_wwdg.c \
    stm32f30x_it.c \
    system_stm32f30x.c \
    stm32f30x_it.cpp \
    CApp.cpp \
    basic_func.cpp \
    inc_drivers/c_timer.cpp \
    inc_drivers/c_can.cpp \
    inc_drivers/c_uart.cpp \
    stm32303c_eval_i2c_ee.c \
    inc_ui/c_led.cpp \
    inc_ui/c_ui.cpp \
    c_driver.cpp



INCLUDEPATH += inc_perip/
INCLUDEPATH += inc_drivers/
INCLUDEPATH += CMSIS/
INCLUDEPATH += inc_ui/

OTHER_FILES += startup_stm32f30x/

DISTFILES += startup_stm32f30x/ \
    startup_stm32f30x.s
