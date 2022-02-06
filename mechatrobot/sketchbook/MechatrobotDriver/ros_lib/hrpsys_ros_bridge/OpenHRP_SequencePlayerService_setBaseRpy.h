#ifndef _ROS_SERVICE_OpenHRP_SequencePlayerService_setBaseRpy_h
#define _ROS_SERVICE_OpenHRP_SequencePlayerService_setBaseRpy_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SEQUENCEPLAYERSERVICE_SETBASERPY[] = "hrpsys_ros_bridge/OpenHRP_SequencePlayerService_setBaseRpy";

  class OpenHRP_SequencePlayerService_setBaseRpyRequest : public ros::Msg
  {
    public:
      uint32_t rpy_length;
      typedef float _rpy_type;
      _rpy_type st_rpy;
      _rpy_type * rpy;
      typedef float _tm_type;
      _tm_type tm;

    OpenHRP_SequencePlayerService_setBaseRpyRequest():
      rpy_length(0), rpy(NULL),
      tm(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->rpy_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->rpy_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->rpy_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->rpy_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rpy_length);
      for( uint32_t i = 0; i < rpy_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->rpy[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->tm);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t rpy_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      rpy_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      rpy_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      rpy_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->rpy_length);
      if(rpy_lengthT > rpy_length)
        this->rpy = (float*)realloc(this->rpy, rpy_lengthT * sizeof(float));
      rpy_length = rpy_lengthT;
      for( uint32_t i = 0; i < rpy_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_rpy));
        memcpy( &(this->rpy[i]), &(this->st_rpy), sizeof(float));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tm));
     return offset;
    }

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETBASERPY; };
    const char * getMD5(){ return "37d67d3dac68663a85d100603f9a556a"; };

  };

  class OpenHRP_SequencePlayerService_setBaseRpyResponse : public ros::Msg
  {
    public:
      typedef bool _operation_return_type;
      _operation_return_type operation_return;

    OpenHRP_SequencePlayerService_setBaseRpyResponse():
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETBASERPY; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_SequencePlayerService_setBaseRpy {
    public:
    typedef OpenHRP_SequencePlayerService_setBaseRpyRequest Request;
    typedef OpenHRP_SequencePlayerService_setBaseRpyResponse Response;
  };

}
#endif
