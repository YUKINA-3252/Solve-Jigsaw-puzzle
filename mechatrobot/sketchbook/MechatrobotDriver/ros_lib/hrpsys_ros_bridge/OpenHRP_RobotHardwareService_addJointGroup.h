#ifndef _ROS_SERVICE_OpenHRP_RobotHardwareService_addJointGroup_h
#define _ROS_SERVICE_OpenHRP_RobotHardwareService_addJointGroup_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_ROBOTHARDWARESERVICE_ADDJOINTGROUP[] = "hrpsys_ros_bridge/OpenHRP_RobotHardwareService_addJointGroup";

  class OpenHRP_RobotHardwareService_addJointGroupRequest : public ros::Msg
  {
    public:
      typedef const char* _gname_type;
      _gname_type gname;
      uint32_t jnames_length;
      typedef char* _jnames_type;
      _jnames_type st_jnames;
      _jnames_type * jnames;

    OpenHRP_RobotHardwareService_addJointGroupRequest():
      gname(""),
      jnames_length(0), jnames(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_gname = strlen(this->gname);
      varToArr(outbuffer + offset, length_gname);
      offset += 4;
      memcpy(outbuffer + offset, this->gname, length_gname);
      offset += length_gname;
      *(outbuffer + offset + 0) = (this->jnames_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->jnames_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->jnames_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->jnames_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->jnames_length);
      for( uint32_t i = 0; i < jnames_length; i++){
      uint32_t length_jnamesi = strlen(this->jnames[i]);
      varToArr(outbuffer + offset, length_jnamesi);
      offset += 4;
      memcpy(outbuffer + offset, this->jnames[i], length_jnamesi);
      offset += length_jnamesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_gname;
      arrToVar(length_gname, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_gname; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_gname-1]=0;
      this->gname = (char *)(inbuffer + offset-1);
      offset += length_gname;
      uint32_t jnames_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      jnames_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      jnames_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      jnames_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->jnames_length);
      if(jnames_lengthT > jnames_length)
        this->jnames = (char**)realloc(this->jnames, jnames_lengthT * sizeof(char*));
      jnames_length = jnames_lengthT;
      for( uint32_t i = 0; i < jnames_length; i++){
      uint32_t length_st_jnames;
      arrToVar(length_st_jnames, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_jnames; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_jnames-1]=0;
      this->st_jnames = (char *)(inbuffer + offset-1);
      offset += length_st_jnames;
        memcpy( &(this->jnames[i]), &(this->st_jnames), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return OPENHRP_ROBOTHARDWARESERVICE_ADDJOINTGROUP; };
    const char * getMD5(){ return "881f11611ba4abd280ca4e66c243a533"; };

  };

  class OpenHRP_RobotHardwareService_addJointGroupResponse : public ros::Msg
  {
    public:
      typedef bool _operation_return_type;
      _operation_return_type operation_return;

    OpenHRP_RobotHardwareService_addJointGroupResponse():
      operation_return(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_operation_return;
      u_operation_return.real = this->operation_return;
      *(outbuffer + offset + 0) = (u_operation_return.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->operation_return);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_operation_return;
      u_operation_return.base = 0;
      u_operation_return.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->operation_return = u_operation_return.real;
      offset += sizeof(this->operation_return);
     return offset;
    }

    const char * getType(){ return OPENHRP_ROBOTHARDWARESERVICE_ADDJOINTGROUP; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_RobotHardwareService_addJointGroup {
    public:
    typedef OpenHRP_RobotHardwareService_addJointGroupRequest Request;
    typedef OpenHRP_RobotHardwareService_addJointGroupResponse Response;
  };

}
#endif
