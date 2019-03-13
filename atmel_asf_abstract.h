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

#include "Platforms/Common/mrt_platform_common.h"
#include <asf.h>

#ifdef __cplusplus
 }
 namespace Platforms
 {
#endif


//Delay Abstraction
#define MRT_DELAY_MS(ms) delay_ms(ms)
#define MRT_DELAY_US(us) delay_us(us)

/************* UART Abstraction ******************/
// typedef io_descriptor* mrt_uart_handle_t;
// #define MRT_UART_TX(handle, data, len, timeout) io_write(handle, data, len)
// #define MRT_UART_RX(handle, data, len, timeout) io_read(handle, data, len)

/************* GPIO Abstraction ******************/
typedef uint8_t mrt_gpio_t;
#define MRT_GPIO_WRITE(pin,val) port_pin_set_output_level(pin,val)
#define MRT_GPIO_READ(pin) port_pin_get_output_level(pin)

/************* I2C Abstraction ******************/
// typedef i2c_m_sync_desc* mrt_i2c_handle_t;
// #define MRT_I2C_MASTER_TRANSMIT(handle ,addr,data,len, stop, timeout)
// #define MRT_I2C_MASTER_RECEIVE(handle ,addr, data, len, stop, timeout)
// #define MRT_I2C_MEM_WRITE(handle, addr, mem_addr, mem_size, data, len, timeout ) i2c_m_sync_cmd_write(handle, mem_addr, data, len)
// #define MRT_I2C_MEM_READ(handle, addr, mem_addr, mem_size, data, len, timeout ) i2c_m_sync_cmd_read(handle, mem_addr, data, len)

/************* SPI Abstraction ******************/
// typedef spi_m_sync_descriptor* mrt_spi_handle_t;
// #define MRT_SPI_TRANSFER(handle ,tx, rx ,len, timeout)


/************* Parallel Abstraction ******************/
typedef struct{
  PortGroup* mDataPort;	//port for bus
  uint32_t	mPortMask;			//mask for port
  uint8_t mDataOffset;			//offset of data pins
  uint32_t mWR;					//WR pin mask
  uint32_t mRD;					//RD pin mask
  uint32_t mA0;					//AO pin mask
  uint8_t mDir;					//direction config
}mrt_parallel_bus_t;
typedef mrt_parallel_bus_t* mrt_pbus_handle_t;

/**
  *@brief set A0 bit on bus based on desired mode
  *@param handle ptr to pbus handle
  *@pre cmdMode True for command mode, False for data mode
  */
#define MRT_PBUS_MODE(handle, mode)											\
if(mode == PBUS_MODE_CMD)														\
	port_group_set_output_level(handle->mDataPort, handle->mA0, 0 );			\
else																			\
	port_group_set_output_level(handle->mDataPort, handle->mA0, handle->mA0 )


#define MRT_PBUS_WRITE(handle, data)																							\
		port_group_set_output_level(handle->mDataPort, handle->mPortMask, (data << handle->mDataOffset) | handle->mRD );		\
		MRT_DELAY_US(1);																										\
		port_group_set_output_level(handle->mDataPort, handle->mWR, handle->mWR)

//#define MRT_PBUS_READ(handle, data, len)


/************* PRINTF Abstraction ******************/
#define MRT_PRINTF(f_, ...) printf((f_), __VA_ARGS__)



#ifdef __cplusplus
 }
#endif
