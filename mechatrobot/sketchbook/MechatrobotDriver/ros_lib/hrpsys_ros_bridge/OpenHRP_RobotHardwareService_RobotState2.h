#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_RobotHardwareService_RobotState2_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_RobotHardwareService_RobotState2_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Int32MultiArray.h"
#include "std_msgs/Float64MultiArray.h"
#include "hrpsys_ros_bridge/OpenHRP_RobotHardwareService_BatteryState.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_RobotHardwareService_RobotState2 : public ros::Msg
  {
    public:
      uint32_t angle_length;
      typedef float _angle_type;
      _angle_type st_angle;
      _angle_type * angle;
      uint32_t command_length;
      typedef float _command_type;
      _command_type st_command;
      _command_type * command;
      uint32_t torque_length;
      typedef float _torque_type;
      _torque_type st_torque;
      _torque_type * torque;
      typedef std_msgs::Int32MultiArray _servoState_type;
      _servoState_type servoState;
      typedef std_msgs::Float64MultiArray _force_type;
      _force_type force;
      typedef std_msgs::Float64MultiArray _rateGyro_type;
      _rateGyro_type rateGyro;
      typedef std_msgs::Float64MultiArray _accel_type;
      _accel_type accel;
      uint32_t batteries_length;
      typedef hrpsys_ros_bridge::OpenHRP_RobotHardwareService_BatteryState _batteries_type;
      _batteries_type st_batteries;
      _batteries_type * batteries;
      typedef float _voltage_type;
      _voltage_type voltage;
      typedef float _current_type;
      _current_type current;
      uint32_t temperature_length;
      typedef float _temperature_type;
      _temperature_type st_temperature;
      _temperature_type * temperature;

    OpenHRP_RobotHardwareService_RobotState2():
      angle_length(0), angle(NULL),
      command_length(0), command(NULL),
      torque_length(0), torque(NULL),
      servoState(),
      force(),
      rateGyro(),
      accel(),
      batteries_length(0), batteries(NULL),
      voltage(0),
      current(0),
      temperature_length(0), temperature(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->angle_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->angle_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->angle_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->angle_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle_length);
      for( uint32_t i = 0; i < angle_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->angle[i]);
      }
      *(outbuffer + offset + 0) = (this->command_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->command_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->command_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->command_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->command_length);
      for( uint32_t i = 0; i < command_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->command[i]);
      }
      *(outbuffer + offset + 0) = (this->torque_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->torque_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->torque_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->torque_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->torque_length);
      for( uint32_t i = 0; i < torque_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->torque[i]);
      }
      offset += this->servoState.serialize(outbuffer + offset);
      offset += this->force.serialize(outbuffer + offset);
      offset += this->rateGyro.serialize(outbuffer + offset);
      offset += this->accel.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->batteries_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->batteries_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->batteries_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->batteries_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->batteries_length);
      for( uint32_t i = 0; i < batteries_length; i++){
      offset += this->batteries[i].serialize(outbuffer + offset);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->voltage);
      offset += serializeAvrFloat64(outbuffer + offset, this->current);
      *(outbuffer + offset + 0) = (this->temperature_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->temperature_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->temperature_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->temperature_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->temperature_length);
      for( uint32_t i = 0; i < temperature_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->temperature[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t angle_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      angle_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      angle_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      angle_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->angle_length);
      if(angle_lengthT > angle_length)
        this->angle = (float*)realloc(this->angle, angle_lengthT * sizeof(float));
      angle_length = angle_lengthT;
      for( uint32_t i = 0; i < angle_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_angle));
        memcpy( &(this->angle[i]), &(this->st_angle), sizeof(float));
      }
      uint32_t command_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      command_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      command_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      command_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->command_length);
      if(command_lengthT > command_length)
        this->command = (float*)realloc(this->command, command_lengthT * sizeof(float));
      command_length = command_lengthT;
      for( uint32_t i = 0; i < command_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_command));
        memcpy( &(this->command[i]), &(this->st_command), sizeof(float));
      }
      uint32_t torque_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      torque_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      torque_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      torque_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->torque_length);
      if(torque_lengthT > torque_length)
        this->torque = (float*)realloc(this->torque, torque_lengthT * sizeof(float));
      torque_length = torque_lengthT;
      for( uint32_t i = 0; i < torque_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_torque));
        memcpy( &(this->torque[i]), &(this->st_torque), sizeof(float));
      }
      offset += this->servoState.deserialize(inbuffer + offset);
      offset += this->force.deserialize(inbuffer + offset);
      offset += this->rateGyro.deserialize(inbuffer + offset);
      offset += this->accel.deserialize(inbuffer + offset);
      uint32_t batteries_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      batteries_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      batteries_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      batteries_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->batteries_length);
      if(batteries_lengthT > batteries_length)
        this->batteries = (hrpsys_ros_bridge::OpenHRP_RobotHardwareService_BatteryState*)realloc(this->batteries, batteries_lengthT * sizeof(hrpsys_ros_bridge::OpenHRP_RobotHardwareService_BatteryState));
      batteries_length = batteries_lengthT;
      for( uint32_t i = 0; i < batteries_length; i++){
      offset += this->st_batteries.deserialize(inbuffer + offset);
        memcpy( &(this->batteries[i]), &(this->st_batteries), sizeof(hrpsys_ros_bridge::OpenHRP_RobotHardwareService_BatteryState));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->voltage));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->current));
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
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_RobotHardwareService_RobotState2"; };
    const char * getMD5(){ return "55bedf35a5f953cd1f113a0e7665626f"; };

  };

}
#endif
