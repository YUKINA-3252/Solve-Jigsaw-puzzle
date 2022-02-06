#ifndef _ROS_hrpsys_ros_bridge_MotorStates_h
#define _ROS_hrpsys_ros_bridge_MotorStates_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "std_msgs/Float64MultiArray.h"

namespace hrpsys_ros_bridge
{

  class MotorStates : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t name_length;
      typedef char* _name_type;
      _name_type st_name;
      _name_type * name;
      uint32_t calib_state_length;
      typedef bool _calib_state_type;
      _calib_state_type st_calib_state;
      _calib_state_type * calib_state;
      uint32_t servo_state_length;
      typedef bool _servo_state_type;
      _servo_state_type st_servo_state;
      _servo_state_type * servo_state;
      uint32_t power_state_length;
      typedef bool _power_state_type;
      _power_state_type st_power_state;
      _power_state_type * power_state;
      uint32_t servo_alarm_length;
      typedef int32_t _servo_alarm_type;
      _servo_alarm_type st_servo_alarm;
      _servo_alarm_type * servo_alarm;
      uint32_t driver_temp_length;
      typedef int16_t _driver_temp_type;
      _driver_temp_type st_driver_temp;
      _driver_temp_type * driver_temp;
      uint32_t temperature_length;
      typedef float _temperature_type;
      _temperature_type st_temperature;
      _temperature_type * temperature;
      typedef std_msgs::Float64MultiArray _extra_data_type;
      _extra_data_type extra_data;

    MotorStates():
      header(),
      name_length(0), name(NULL),
      calib_state_length(0), calib_state(NULL),
      servo_state_length(0), servo_state(NULL),
      power_state_length(0), power_state(NULL),
      servo_alarm_length(0), servo_alarm(NULL),
      driver_temp_length(0), driver_temp(NULL),
      temperature_length(0), temperature(NULL),
      extra_data()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->name_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->name_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->name_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->name_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->name_length);
      for( uint32_t i = 0; i < name_length; i++){
      uint32_t length_namei = strlen(this->name[i]);
      varToArr(outbuffer + offset, length_namei);
      offset += 4;
      memcpy(outbuffer + offset, this->name[i], length_namei);
      offset += length_namei;
      }
      *(outbuffer + offset + 0) = (this->calib_state_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->calib_state_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->calib_state_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->calib_state_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->calib_state_length);
      for( uint32_t i = 0; i < calib_state_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_calib_statei;
      u_calib_statei.real = this->calib_state[i];
      *(outbuffer + offset + 0) = (u_calib_statei.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->calib_state[i]);
      }
      *(outbuffer + offset + 0) = (this->servo_state_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->servo_state_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->servo_state_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->servo_state_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->servo_state_length);
      for( uint32_t i = 0; i < servo_state_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_servo_statei;
      u_servo_statei.real = this->servo_state[i];
      *(outbuffer + offset + 0) = (u_servo_statei.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->servo_state[i]);
      }
      *(outbuffer + offset + 0) = (this->power_state_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->power_state_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->power_state_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->power_state_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->power_state_length);
      for( uint32_t i = 0; i < power_state_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_power_statei;
      u_power_statei.real = this->power_state[i];
      *(outbuffer + offset + 0) = (u_power_statei.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->power_state[i]);
      }
      *(outbuffer + offset + 0) = (this->servo_alarm_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->servo_alarm_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->servo_alarm_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->servo_alarm_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->servo_alarm_length);
      for( uint32_t i = 0; i < servo_alarm_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_servo_alarmi;
      u_servo_alarmi.real = this->servo_alarm[i];
      *(outbuffer + offset + 0) = (u_servo_alarmi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_servo_alarmi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_servo_alarmi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_servo_alarmi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->servo_alarm[i]);
      }
      *(outbuffer + offset + 0) = (this->driver_temp_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->driver_temp_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->driver_temp_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->driver_temp_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->driver_temp_length);
      for( uint32_t i = 0; i < driver_temp_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_driver_tempi;
      u_driver_tempi.real = this->driver_temp[i];
      *(outbuffer + offset + 0) = (u_driver_tempi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_driver_tempi.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->driver_temp[i]);
      }
      *(outbuffer + offset + 0) = (this->temperature_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->temperature_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->temperature_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->temperature_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->temperature_length);
      for( uint32_t i = 0; i < temperature_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->temperature[i]);
      }
      offset += this->extra_data.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t name_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      name_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      name_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      name_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->name_length);
      if(name_lengthT > name_length)
        this->name = (char**)realloc(this->name, name_lengthT * sizeof(char*));
      name_length = name_lengthT;
      for( uint32_t i = 0; i < name_length; i++){
      uint32_t length_st_name;
      arrToVar(length_st_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_name-1]=0;
      this->st_name = (char *)(inbuffer + offset-1);
      offset += length_st_name;
        memcpy( &(this->name[i]), &(this->st_name), sizeof(char*));
      }
      uint32_t calib_state_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      calib_state_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      calib_state_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      calib_state_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->calib_state_length);
      if(calib_state_lengthT > calib_state_length)
        this->calib_state = (bool*)realloc(this->calib_state, calib_state_lengthT * sizeof(bool));
      calib_state_length = calib_state_lengthT;
      for( uint32_t i = 0; i < calib_state_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_calib_state;
      u_st_calib_state.base = 0;
      u_st_calib_state.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_calib_state = u_st_calib_state.real;
      offset += sizeof(this->st_calib_state);
        memcpy( &(this->calib_state[i]), &(this->st_calib_state), sizeof(bool));
      }
      uint32_t servo_state_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      servo_state_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      servo_state_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      servo_state_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->servo_state_length);
      if(servo_state_lengthT > servo_state_length)
        this->servo_state = (bool*)realloc(this->servo_state, servo_state_lengthT * sizeof(bool));
      servo_state_length = servo_state_lengthT;
      for( uint32_t i = 0; i < servo_state_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_servo_state;
      u_st_servo_state.base = 0;
      u_st_servo_state.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_servo_state = u_st_servo_state.real;
      offset += sizeof(this->st_servo_state);
        memcpy( &(this->servo_state[i]), &(this->st_servo_state), sizeof(bool));
      }
      uint32_t power_state_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      power_state_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      power_state_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      power_state_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->power_state_length);
      if(power_state_lengthT > power_state_length)
        this->power_state = (bool*)realloc(this->power_state, power_state_lengthT * sizeof(bool));
      power_state_length = power_state_lengthT;
      for( uint32_t i = 0; i < power_state_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_power_state;
      u_st_power_state.base = 0;
      u_st_power_state.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_power_state = u_st_power_state.real;
      offset += sizeof(this->st_power_state);
        memcpy( &(this->power_state[i]), &(this->st_power_state), sizeof(bool));
      }
      uint32_t servo_alarm_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      servo_alarm_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      servo_alarm_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      servo_alarm_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->servo_alarm_length);
      if(servo_alarm_lengthT > servo_alarm_length)
        this->servo_alarm = (int32_t*)realloc(this->servo_alarm, servo_alarm_lengthT * sizeof(int32_t));
      servo_alarm_length = servo_alarm_lengthT;
      for( uint32_t i = 0; i < servo_alarm_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_servo_alarm;
      u_st_servo_alarm.base = 0;
      u_st_servo_alarm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_servo_alarm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_servo_alarm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_servo_alarm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_servo_alarm = u_st_servo_alarm.real;
      offset += sizeof(this->st_servo_alarm);
        memcpy( &(this->servo_alarm[i]), &(this->st_servo_alarm), sizeof(int32_t));
      }
      uint32_t driver_temp_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      driver_temp_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      driver_temp_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      driver_temp_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->driver_temp_length);
      if(driver_temp_lengthT > driver_temp_length)
        this->driver_temp = (int16_t*)realloc(this->driver_temp, driver_temp_lengthT * sizeof(int16_t));
      driver_temp_length = driver_temp_lengthT;
      for( uint32_t i = 0; i < driver_temp_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_st_driver_temp;
      u_st_driver_temp.base = 0;
      u_st_driver_temp.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_driver_temp.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_driver_temp = u_st_driver_temp.real;
      offset += sizeof(this->st_driver_temp);
        memcpy( &(this->driver_temp[i]), &(this->st_driver_temp), sizeof(int16_t));
      }
      uint32_t temperature_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      temperature_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      temperature_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      temperature_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->temperature_length);
      if(temperature_lengthT > temperature_length)
        this->temperature = (float*)realloc(this->temperature, temperature_lengthT * sizeof(float));
      temperature_length = temperature_lengthT;
      for( uint32_t i = 0; i < temperature_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_temperature));
        memcpy( &(this->temperature[i]), &(this->st_temperature), sizeof(float));
      }
      offset += this->extra_data.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/MotorStates"; };
    const char * getMD5(){ return "75f582b3495b189b341d4111731cd7fc"; };

  };

}
#endif
