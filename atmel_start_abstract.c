/**
  *@file atmel_start_abstract.c
  *@brief Abstraction header for Atmel MCUs using the Atmel Start framework
  *@author Jason Berger
  *@date 2/18/2019
  */

  #include "atmel_start_abstract.h"

  void atmel_start_i2c_transmit(mrt_i2c_handle_t handle, uint8_t addr, uint8_t* data, uint8_t len, bool stop )
  {
    struct _i2c_m_msg msg;
    msg.addr   = addr;
	  msg.len    = len;
    msg.flags  = 0;
    if(stop)
      msg.flags = I2C_M_STOP;
	  msg.buffer = data;

    i2c_m_sync_transfer(handle, &msg);
  }
