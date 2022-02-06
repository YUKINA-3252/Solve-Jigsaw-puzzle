#ifndef _ROS_SERVICE_OpenHRP_SequencePlayerService_setTargetPose_h
#define _ROS_SERVICE_OpenHRP_SequencePlayerService_setTargetPose_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SEQUENCEPLAYERSERVICE_SETTARGETPOSE[] = "hrpsys_ros_bridge/OpenHRP_SequencePlayerService_setTargetPose";

  class OpenHRP_SequencePlayerService_setTargetPoseRequest : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      uint32_t xyz_length;
      typedef float _xyz_type;
      _xyz_type st_xyz;
      _xyz_type * xyz;
      uint32_t rpy_length;
      typedef float _rpy_type;
      _rpy_type st_rpy;
      _rpy_type * rpy;
      typedef float _tm_type;
      _tm_type tm;

    OpenHRP_SequencePlayerService_setTargetPoseRequest():
      name(""),
      xyz_length(0), xyz(NULL),
      rpy_length(0), rpy(NULL),
      tm(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      *(outbuffer + offset + 0) = (this->xyz_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->xyz_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->xyz_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->xyz_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->xyz_length);
      for( uint32_t i = 0; i < xyz_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->xyz[i]);
      }
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
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t xyz_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      xyz_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      xyz_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      xyz_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->xyz_length);
      if(xyz_lengthT > xyz_length)
        this->xyz = (float*)realloc(this->xyz, xyz_lengthT * sizeof(float));
      xyz_length = xyz_lengthT;
      for( uint32_t i = 0; i < xyz_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_xyz));
        memcpy( &(this->xyz[i]), &(this->st_xyz), sizeof(float));
      }
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETTARGETPOSE; };
    const char * getMD5(){ return "fbd6f07e5a5bde9514a1389b662bf2e1"; };

  };

  class OpenHRP_SequencePlayerService_setTargetPoseResponse : public ros::Msg
  {
    public:
      typedef bool _operation_return_type;
      _operation_return_type operation_return;

    OpenHRP_SequencePlayerService_setTargetPoseResponse():
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETTARGETPOSE; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_SequencePlayerService_setTargetPose {
    public:
    typedef OpenHRP_SequencePlayerService_setTargetPoseRequest Request;
    typedef OpenHRP_SequencePlayerService_setTargetPoseResponse Response;
  };

}
#endif
