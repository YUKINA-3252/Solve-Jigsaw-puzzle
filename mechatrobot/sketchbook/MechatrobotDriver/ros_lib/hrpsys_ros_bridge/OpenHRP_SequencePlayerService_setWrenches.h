#ifndef _ROS_SERVICE_OpenHRP_SequencePlayerService_setWrenches_h
#define _ROS_SERVICE_OpenHRP_SequencePlayerService_setWrenches_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SEQUENCEPLAYERSERVICE_SETWRENCHES[] = "hrpsys_ros_bridge/OpenHRP_SequencePlayerService_setWrenches";

  class OpenHRP_SequencePlayerService_setWrenchesRequest : public ros::Msg
  {
    public:
      uint32_t wrenches_length;
      typedef float _wrenches_type;
      _wrenches_type st_wrenches;
      _wrenches_type * wrenches;
      typedef float _tm_type;
      _tm_type tm;

    OpenHRP_SequencePlayerService_setWrenchesRequest():
      wrenches_length(0), wrenches(NULL),
      tm(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->wrenches_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->wrenches_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->wrenches_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->wrenches_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->wrenches_length);
      for( uint32_t i = 0; i < wrenches_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->wrenches[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->tm);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t wrenches_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      wrenches_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      wrenches_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      wrenches_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->wrenches_length);
      if(wrenches_lengthT > wrenches_length)
        this->wrenches = (float*)realloc(this->wrenches, wrenches_lengthT * sizeof(float));
      wrenches_length = wrenches_lengthT;
      for( uint32_t i = 0; i < wrenches_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_wrenches));
        memcpy( &(this->wrenches[i]), &(this->st_wrenches), sizeof(float));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tm));
     return offset;
    }

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETWRENCHES; };
    const char * getMD5(){ return "8278cb0b6641cad755b5b691fb73ac22"; };

  };

  class OpenHRP_SequencePlayerService_setWrenchesResponse : public ros::Msg
  {
    public:
      typedef bool _operation_return_type;
      _operation_return_type operation_return;

    OpenHRP_SequencePlayerService_setWrenchesResponse():
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETWRENCHES; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_SequencePlayerService_setWrenches {
    public:
    typedef OpenHRP_SequencePlayerService_setWrenchesRequest Request;
    typedef OpenHRP_SequencePlayerService_setWrenchesResponse Response;
  };

}
#endif
