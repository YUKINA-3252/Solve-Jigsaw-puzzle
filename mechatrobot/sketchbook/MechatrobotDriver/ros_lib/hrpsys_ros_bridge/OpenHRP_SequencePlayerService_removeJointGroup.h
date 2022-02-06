#ifndef _ROS_SERVICE_OpenHRP_SequencePlayerService_removeJointGroup_h
#define _ROS_SERVICE_OpenHRP_SequencePlayerService_removeJointGroup_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SEQUENCEPLAYERSERVICE_REMOVEJOINTGROUP[] = "hrpsys_ros_bridge/OpenHRP_SequencePlayerService_removeJointGroup";

  class OpenHRP_SequencePlayerService_removeJointGroupRequest : public ros::Msg
  {
    public:
      typedef const char* _gname_type;
      _gname_type gname;

    OpenHRP_SequencePlayerService_removeJointGroupRequest():
      gname("")
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
     return offset;
    }

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_REMOVEJOINTGROUP; };
    const char * getMD5(){ return "57e79d8e972ecf8416d5b8dd6477ee59"; };

  };

  class OpenHRP_SequencePlayerService_removeJointGroupResponse : public ros::Msg
  {
    public:
      typedef bool _operation_return_type;
      _operation_return_type operation_return;

    OpenHRP_SequencePlayerService_removeJointGroupResponse():
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_REMOVEJOINTGROUP; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_SequencePlayerService_removeJointGroup {
    public:
    typedef OpenHRP_SequencePlayerService_removeJointGroupRequest Request;
    typedef OpenHRP_SequencePlayerService_removeJointGroupResponse Response;
  };

}
#endif
