#ifndef _ROS_SERVICE_OpenHRP_SequencePlayerService_playPattern_h
#define _ROS_SERVICE_OpenHRP_SequencePlayerService_playPattern_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Float64MultiArray.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SEQUENCEPLAYERSERVICE_PLAYPATTERN[] = "hrpsys_ros_bridge/OpenHRP_SequencePlayerService_playPattern";

  class OpenHRP_SequencePlayerService_playPatternRequest : public ros::Msg
  {
    public:
      typedef std_msgs::Float64MultiArray _pos_type;
      _pos_type pos;
      typedef std_msgs::Float64MultiArray _rpy_type;
      _rpy_type rpy;
      typedef std_msgs::Float64MultiArray _zmp_type;
      _zmp_type zmp;
      uint32_t tm_length;
      typedef float _tm_type;
      _tm_type st_tm;
      _tm_type * tm;

    OpenHRP_SequencePlayerService_playPatternRequest():
      pos(),
      rpy(),
      zmp(),
      tm_length(0), tm(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pos.serialize(outbuffer + offset);
      offset += this->rpy.serialize(outbuffer + offset);
      offset += this->zmp.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->tm_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tm_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tm_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tm_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tm_length);
      for( uint32_t i = 0; i < tm_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->tm[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pos.deserialize(inbuffer + offset);
      offset += this->rpy.deserialize(inbuffer + offset);
      offset += this->zmp.deserialize(inbuffer + offset);
      uint32_t tm_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      tm_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      tm_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      tm_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->tm_length);
      if(tm_lengthT > tm_length)
        this->tm = (float*)realloc(this->tm, tm_lengthT * sizeof(float));
      tm_length = tm_lengthT;
      for( uint32_t i = 0; i < tm_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_tm));
        memcpy( &(this->tm[i]), &(this->st_tm), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_PLAYPATTERN; };
    const char * getMD5(){ return "337f00a6e3b068d4dfdc1cc7b8dd965c"; };

  };

  class OpenHRP_SequencePlayerService_playPatternResponse : public ros::Msg
  {
    public:

    OpenHRP_SequencePlayerService_playPatternResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_PLAYPATTERN; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_SequencePlayerService_playPattern {
    public:
    typedef OpenHRP_SequencePlayerService_playPatternRequest Request;
    typedef OpenHRP_SequencePlayerService_playPatternResponse Response;
  };

}
#endif
