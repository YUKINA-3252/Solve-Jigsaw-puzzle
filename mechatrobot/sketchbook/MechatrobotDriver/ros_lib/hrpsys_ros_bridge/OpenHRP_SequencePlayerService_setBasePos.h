#ifndef _ROS_SERVICE_OpenHRP_SequencePlayerService_setBasePos_h
#define _ROS_SERVICE_OpenHRP_SequencePlayerService_setBasePos_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SEQUENCEPLAYERSERVICE_SETBASEPOS[] = "hrpsys_ros_bridge/OpenHRP_SequencePlayerService_setBasePos";

  class OpenHRP_SequencePlayerService_setBasePosRequest : public ros::Msg
  {
    public:
      uint32_t pos_length;
      typedef float _pos_type;
      _pos_type st_pos;
      _pos_type * pos;
      typedef float _tm_type;
      _tm_type tm;

    OpenHRP_SequencePlayerService_setBasePosRequest():
      pos_length(0), pos(NULL),
      tm(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->pos_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pos_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pos_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pos_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pos_length);
      for( uint32_t i = 0; i < pos_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->pos[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->tm);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t pos_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      pos_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pos_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pos_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->pos_length);
      if(pos_lengthT > pos_length)
        this->pos = (float*)realloc(this->pos, pos_lengthT * sizeof(float));
      pos_length = pos_lengthT;
      for( uint32_t i = 0; i < pos_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_pos));
        memcpy( &(this->pos[i]), &(this->st_pos), sizeof(float));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tm));
     return offset;
    }

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETBASEPOS; };
    const char * getMD5(){ return "4b084539ddcc02779e1dcf3d438cc175"; };

  };

  class OpenHRP_SequencePlayerService_setBasePosResponse : public ros::Msg
  {
    public:
      typedef bool _operation_return_type;
      _operation_return_type operation_return;

    OpenHRP_SequencePlayerService_setBasePosResponse():
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETBASEPOS; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_SequencePlayerService_setBasePos {
    public:
    typedef OpenHRP_SequencePlayerService_setBasePosRequest Request;
    typedef OpenHRP_SequencePlayerService_setBasePosResponse Response;
  };

}
#endif
