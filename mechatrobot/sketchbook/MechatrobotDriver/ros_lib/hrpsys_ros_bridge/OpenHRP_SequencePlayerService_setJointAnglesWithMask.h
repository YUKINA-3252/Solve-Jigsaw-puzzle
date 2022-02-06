#ifndef _ROS_SERVICE_OpenHRP_SequencePlayerService_setJointAnglesWithMask_h
#define _ROS_SERVICE_OpenHRP_SequencePlayerService_setJointAnglesWithMask_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SEQUENCEPLAYERSERVICE_SETJOINTANGLESWITHMASK[] = "hrpsys_ros_bridge/OpenHRP_SequencePlayerService_setJointAnglesWithMask";

  class OpenHRP_SequencePlayerService_setJointAnglesWithMaskRequest : public ros::Msg
  {
    public:
      uint32_t jvs_length;
      typedef float _jvs_type;
      _jvs_type st_jvs;
      _jvs_type * jvs;
      uint32_t mask_length;
      typedef bool _mask_type;
      _mask_type st_mask;
      _mask_type * mask;
      typedef float _tm_type;
      _tm_type tm;

    OpenHRP_SequencePlayerService_setJointAnglesWithMaskRequest():
      jvs_length(0), jvs(NULL),
      mask_length(0), mask(NULL),
      tm(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->jvs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->jvs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->jvs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->jvs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->jvs_length);
      for( uint32_t i = 0; i < jvs_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->jvs[i]);
      }
      *(outbuffer + offset + 0) = (this->mask_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->mask_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->mask_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->mask_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mask_length);
      for( uint32_t i = 0; i < mask_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_maski;
      u_maski.real = this->mask[i];
      *(outbuffer + offset + 0) = (u_maski.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mask[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->tm);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
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
      uint32_t mask_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      mask_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      mask_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      mask_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->mask_length);
      if(mask_lengthT > mask_length)
        this->mask = (bool*)realloc(this->mask, mask_lengthT * sizeof(bool));
      mask_length = mask_lengthT;
      for( uint32_t i = 0; i < mask_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_mask;
      u_st_mask.base = 0;
      u_st_mask.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_mask = u_st_mask.real;
      offset += sizeof(this->st_mask);
        memcpy( &(this->mask[i]), &(this->st_mask), sizeof(bool));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tm));
     return offset;
    }

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETJOINTANGLESWITHMASK; };
    const char * getMD5(){ return "a788e7cc25ea1d7b0b6609203dd3c4d3"; };

  };

  class OpenHRP_SequencePlayerService_setJointAnglesWithMaskResponse : public ros::Msg
  {
    public:
      typedef bool _operation_return_type;
      _operation_return_type operation_return;

    OpenHRP_SequencePlayerService_setJointAnglesWithMaskResponse():
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETJOINTANGLESWITHMASK; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_SequencePlayerService_setJointAnglesWithMask {
    public:
    typedef OpenHRP_SequencePlayerService_setJointAnglesWithMaskRequest Request;
    typedef OpenHRP_SequencePlayerService_setJointAnglesWithMaskResponse Response;
  };

}
#endif
