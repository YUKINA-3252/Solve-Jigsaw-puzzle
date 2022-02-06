#ifndef _ROS_SERVICE_OpenHRP_SequencePlayerService_setJointAnglesSequence_h
#define _ROS_SERVICE_OpenHRP_SequencePlayerService_setJointAnglesSequence_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Float64MultiArray.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SEQUENCEPLAYERSERVICE_SETJOINTANGLESSEQUENCE[] = "hrpsys_ros_bridge/OpenHRP_SequencePlayerService_setJointAnglesSequence";

  class OpenHRP_SequencePlayerService_setJointAnglesSequenceRequest : public ros::Msg
  {
    public:
      typedef std_msgs::Float64MultiArray _jvss_type;
      _jvss_type jvss;
      uint32_t tms_length;
      typedef float _tms_type;
      _tms_type st_tms;
      _tms_type * tms;

    OpenHRP_SequencePlayerService_setJointAnglesSequenceRequest():
      jvss(),
      tms_length(0), tms(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->jvss.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->tms_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tms_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tms_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tms_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tms_length);
      for( uint32_t i = 0; i < tms_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->tms[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->jvss.deserialize(inbuffer + offset);
      uint32_t tms_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      tms_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      tms_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      tms_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->tms_length);
      if(tms_lengthT > tms_length)
        this->tms = (float*)realloc(this->tms, tms_lengthT * sizeof(float));
      tms_length = tms_lengthT;
      for( uint32_t i = 0; i < tms_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_tms));
        memcpy( &(this->tms[i]), &(this->st_tms), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETJOINTANGLESSEQUENCE; };
    const char * getMD5(){ return "8ae106499aed33fe44cc372b7d3e72d5"; };

  };

  class OpenHRP_SequencePlayerService_setJointAnglesSequenceResponse : public ros::Msg
  {
    public:
      typedef bool _operation_return_type;
      _operation_return_type operation_return;

    OpenHRP_SequencePlayerService_setJointAnglesSequenceResponse():
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETJOINTANGLESSEQUENCE; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_SequencePlayerService_setJointAnglesSequence {
    public:
    typedef OpenHRP_SequencePlayerService_setJointAnglesSequenceRequest Request;
    typedef OpenHRP_SequencePlayerService_setJointAnglesSequenceResponse Response;
  };

}
#endif
