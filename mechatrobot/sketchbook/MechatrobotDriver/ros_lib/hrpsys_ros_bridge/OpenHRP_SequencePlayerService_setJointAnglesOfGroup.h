#ifndef _ROS_SERVICE_OpenHRP_SequencePlayerService_setJointAnglesOfGroup_h
#define _ROS_SERVICE_OpenHRP_SequencePlayerService_setJointAnglesOfGroup_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SEQUENCEPLAYERSERVICE_SETJOINTANGLESOFGROUP[] = "hrpsys_ros_bridge/OpenHRP_SequencePlayerService_setJointAnglesOfGroup";

  class OpenHRP_SequencePlayerService_setJointAnglesOfGroupRequest : public ros::Msg
  {
    public:
      typedef const char* _gname_type;
      _gname_type gname;
      uint32_t jvs_length;
      typedef float _jvs_type;
      _jvs_type st_jvs;
      _jvs_type * jvs;
      typedef float _tm_type;
      _tm_type tm;

    OpenHRP_SequencePlayerService_setJointAnglesOfGroupRequest():
      gname(""),
      jvs_length(0), jvs(NULL),
      tm(0)
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
      *(outbuffer + offset + 0) = (this->jvs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->jvs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->jvs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->jvs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->jvs_length);
      for( uint32_t i = 0; i < jvs_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->jvs[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->tm);
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
      uint32_t jvs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      jvs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      jvs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      jvs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->jvs_length);
      if(jvs_lengthT > jvs_length)
        this->jvs = (float*)realloc(this->jvs, jvs_lengthT * sizeof(float));
      jvs_length = jvs_lengthT;
      for( uint32_t i = 0; i < jvs_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_jvs));
        memcpy( &(this->jvs[i]), &(this->st_jvs), sizeof(float));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tm));
     return offset;
    }

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETJOINTANGLESOFGROUP; };
    const char * getMD5(){ return "a5ae0b9d89b2e0b5edde7086720cf2c5"; };

  };

  class OpenHRP_SequencePlayerService_setJointAnglesOfGroupResponse : public ros::Msg
  {
    public:
      typedef bool _operation_return_type;
      _operation_return_type operation_return;

    OpenHRP_SequencePlayerService_setJointAnglesOfGroupResponse():
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETJOINTANGLESOFGROUP; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_SequencePlayerService_setJointAnglesOfGroup {
    public:
    typedef OpenHRP_SequencePlayerService_setJointAnglesOfGroupRequest Request;
    typedef OpenHRP_SequencePlayerService_setJointAnglesOfGroupResponse Response;
  };

}
#endif
