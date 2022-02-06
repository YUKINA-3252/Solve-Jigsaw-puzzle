#ifndef _ROS_SERVICE_OpenHRP_SequencePlayerService_setJointAnglesSequenceFull_h
#define _ROS_SERVICE_OpenHRP_SequencePlayerService_setJointAnglesSequenceFull_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Float64MultiArray.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SEQUENCEPLAYERSERVICE_SETJOINTANGLESSEQUENCEFULL[] = "hrpsys_ros_bridge/OpenHRP_SequencePlayerService_setJointAnglesSequenceFull";

  class OpenHRP_SequencePlayerService_setJointAnglesSequenceFullRequest : public ros::Msg
  {
    public:
      typedef std_msgs::Float64MultiArray _jvss_type;
      _jvss_type jvss;
      typedef std_msgs::Float64MultiArray _vels_type;
      _vels_type vels;
      typedef std_msgs::Float64MultiArray _torques_type;
      _torques_type torques;
      typedef std_msgs::Float64MultiArray _poss_type;
      _poss_type poss;
      typedef std_msgs::Float64MultiArray _rpys_type;
      _rpys_type rpys;
      typedef std_msgs::Float64MultiArray _accs_type;
      _accs_type accs;
      typedef std_msgs::Float64MultiArray _zmps_type;
      _zmps_type zmps;
      typedef std_msgs::Float64MultiArray _wrenchs_type;
      _wrenchs_type wrenchs;
      typedef std_msgs::Float64MultiArray _optionals_type;
      _optionals_type optionals;
      uint32_t tms_length;
      typedef float _tms_type;
      _tms_type st_tms;
      _tms_type * tms;

    OpenHRP_SequencePlayerService_setJointAnglesSequenceFullRequest():
      jvss(),
      vels(),
      torques(),
      poss(),
      rpys(),
      accs(),
      zmps(),
      wrenchs(),
      optionals(),
      tms_length(0), tms(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->jvss.serialize(outbuffer + offset);
      offset += this->vels.serialize(outbuffer + offset);
      offset += this->torques.serialize(outbuffer + offset);
      offset += this->poss.serialize(outbuffer + offset);
      offset += this->rpys.serialize(outbuffer + offset);
      offset += this->accs.serialize(outbuffer + offset);
      offset += this->zmps.serialize(outbuffer + offset);
      offset += this->wrenchs.serialize(outbuffer + offset);
      offset += this->optionals.serialize(outbuffer + offset);
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
      offset += this->vels.deserialize(inbuffer + offset);
      offset += this->torques.deserialize(inbuffer + offset);
      offset += this->poss.deserialize(inbuffer + offset);
      offset += this->rpys.deserialize(inbuffer + offset);
      offset += this->accs.deserialize(inbuffer + offset);
      offset += this->zmps.deserialize(inbuffer + offset);
      offset += this->wrenchs.deserialize(inbuffer + offset);
      offset += this->optionals.deserialize(inbuffer + offset);
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETJOINTANGLESSEQUENCEFULL; };
    const char * getMD5(){ return "27969734fb24cec0718f6a9e8c7b6b72"; };

  };

  class OpenHRP_SequencePlayerService_setJointAnglesSequenceFullResponse : public ros::Msg
  {
    public:
      typedef bool _operation_return_type;
      _operation_return_type operation_return;

    OpenHRP_SequencePlayerService_setJointAnglesSequenceFullResponse():
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETJOINTANGLESSEQUENCEFULL; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_SequencePlayerService_setJointAnglesSequenceFull {
    public:
    typedef OpenHRP_SequencePlayerService_setJointAnglesSequenceFullRequest Request;
    typedef OpenHRP_SequencePlayerService_setJointAnglesSequenceFullResponse Response;
  };

}
#endif
