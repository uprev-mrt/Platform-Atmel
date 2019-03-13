/**
  *@file atmel_asf_abstract.h
  *@brief Abstraction header for Atmel MCUs using the ASF framework
  *@author Jason Berger
  *@date 2/18/2019
  */

#pragma once

#ifdef __cplusplus
 extern "C" {
#endif

#include <asf.h>

#ifdef __cplusplus
 }
 namespace Platforms
 {
#endif


//Delay Abstraction
#define MRT_DELAY_MS(ms) delay_ms(ms)

//Uart Abstraction
// typedef io_descriptor* mrt_uart_handle_t;
// #define MRT_UART_TX(handle, data, len, timeout) io_write(handle, data, len)
// #define MRT_UART_RX(handle, data, len, timeout) io_read(handle, data, len)

GPIO Abstraction
typedef uint8_t mrt_gpio_t;
#define MRT_GPIO_WRITE(pin,val) gpio_set_pin_level(pin,val)
#define MRT_GPIO_READ(pin) gpio_get_pin_level(pin)

//I2C Abstraction
// typedef i2c_m_sync_desc* mrt_i2c_handle_t;
// #define MRT_I2C_MASTER_TRANSMIT(handle ,addr,data,len, stop, timeout)
// #define MRT_I2C_MASTER_RECEIVE(handle ,addr, data, len, stop, timeout)
// #define MRT_I2C_MEM_WRITE(handle, addr, mem_addr, mem_size, data, len, timeout ) i2c_m_sync_cmd_write(handle, mem_addr, data, len)
// #define MRT_I2C_MEM_READ(handle, addr, mem_addr, mem_size, data, len, timeout ) i2c_m_sync_cmd_read(handle, mem_addr, data, len)

//SPI Abstraction
// typedef spi_m_sync_descriptor* mrt_spi_handle_t;
// #define MRT_SPI_TRANSFER(handle ,tx, rx ,len, timeout)       \
//                           struct spi_xfer xfer = {           \
//                           .txbuf =tx,                        \
//                           .rxbuf =rx,                        \
//                           .size = len,                       \
//                           };                                 \
//                           spi_m_sync_transfer(handle, &xfer);
//

//8080 Parallel abstraction

struct parallel_bus_t{
	mrt_gpio_t mDataSignals[8];
  mrt_gpio_t mWR;
  mrt_gpio_t mRD;
  mrt_gpio_t mAO;
};
typedef struct parallel_bus_t* mrt_8080_handle_t;

#define MRT_8080_CMD(handle, cmd) atmel_asf_8080_cmd(handle, )
#define MRT_8080_DATA_READ(handle, data, len)
#define MRT_8080_DATA_WRITE(handle, data, len)

void atmel_asf_8080_cmd(parallel_bus_t* bus, uint8_t cmd );
int atmel_asf_8080_read(parallel_bus_t* bus, uint8_t* data, int len);
int atmel_asf_8080_write(parallel_bus_t* bus, uint8_t* data, int len);

//printf
#define MRT_PRINTF(f_, ...) printf((f_), __VA_ARGS__)



#ifdef __cplusplus
 }
#endif
